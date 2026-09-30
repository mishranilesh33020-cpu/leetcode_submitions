class Solution {
    static constexpr int ALL = 0x3FE;     
    int rowMask[9], colMask[9], boxMask[9];
    char* g[9];                            

    struct Cell { unsigned char r, c, b; }; 
    Cell empties[81];
    int nEmpty = 0;

    bool solve() {
        
        int bestIdx = -1, bestCand = 0, bestCnt = 10;
        for (int i = 0; i < nEmpty; ++i) {
            const Cell& e = empties[i];
            if (g[e.r][e.c] != '.') continue;              // already filled
            int cand = ~(rowMask[e.r] | colMask[e.c] | boxMask[e.b]) & ALL;
            int cnt  = __builtin_popcount(cand);
            if (cnt == 0) return false;                     
            if (cnt < bestCnt) {
                bestCnt  = cnt;
                bestIdx  = i;
                bestCand = cand;
                if (cnt == 1) break;                        
            }
        }
        if (bestIdx == -1) return true;                     

        const Cell& e = empties[bestIdx];
        const int r = e.r, c = e.c, b = e.b;

        for (int mask = bestCand; mask; mask &= mask - 1) {
            int bit = mask & -mask;
            int d   = __builtin_ctz(bit);                   

            g[r][c] = (char)('0' + d);
            rowMask[r] |= bit;
            colMask[c] |= bit;
            boxMask[b] |= bit;

            if (solve()) return true;

            g[r][c] = '.';
            rowMask[r] &= ~bit;
            colMask[c] &= ~bit;
            boxMask[b] &= ~bit;
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        
        for (int r = 0; r < 9; ++r) g[r] = board[r].data();

        for (int i = 0; i < 9; ++i) rowMask[i] = colMask[i] = boxMask[i] = 0;
        nEmpty = 0;

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = g[r][c];
                if (ch == '.') {
                    empties[nEmpty++] = {
                        (unsigned char)r,
                        (unsigned char)c,
                        (unsigned char)((r / 3) * 3 + (c / 3))
                    };
                } else {
                    int bit = 1 << (ch - '0');
                    rowMask[r] |= bit;
                    colMask[c] |= bit;
                    boxMask[(r / 3) * 3 + (c / 3)] |= bit;
                }
            }
        }

        solve();
    }
};
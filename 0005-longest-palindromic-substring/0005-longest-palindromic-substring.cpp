class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;

        string t = "^";
        for (char c : s) {
            t += '#';
            t += c;
        }
        t += "#$";

        int m = t.size();
        vector<int> p(m, 0);

        int center = 0, right = 0;
        int best = 0, bestCenter = 0;

        for (int i = 1; i < m - 1; ++i) {
            int mirror = 2 * center - i;

            if (i < right)
                p[i] = min(right - i, p[mirror]);

            while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
                ++p[i];

            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            if (p[i] > best) {
                best = p[i];
                bestCenter = i;
            }
        }

        int start = (bestCenter - best) / 2;
        return s.substr(start, best);
    }
};
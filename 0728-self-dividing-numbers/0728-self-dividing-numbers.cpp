class Solution {
public:
    bool check(int n, int num) {
        if (n == 0)
            return true;

        int digit = n % 10;

        if (digit == 0 || num % digit != 0)
            return false;

        return check(n / 10, num);
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for (int i = left; i <= right; i++) {
            if (check(i, i))
                ans.push_back(i);
        }

        return ans;
    }
};
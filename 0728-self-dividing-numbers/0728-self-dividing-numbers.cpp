class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for (int i = left; i <= right; i++) {
            int n = i;
            bool valid = true;

            while (n > 0) {
                int digit = n % 10;

                if (digit == 0 || i % digit != 0) {
                    valid = false;
                    break;
                }

                n /= 10;
            }

            if (valid ? true : false) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
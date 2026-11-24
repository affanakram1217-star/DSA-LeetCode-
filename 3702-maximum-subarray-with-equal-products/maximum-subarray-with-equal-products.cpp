class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        long long overall_lcm = 1;
        int max_val = 0;
        for (int x : nums) {
            overall_lcm = lcm(overall_lcm, (long long)x);
            max_val = max(max_val, x);
        }
        __int128 max_bound = (__int128)overall_lcm * max_val;

        for (int i = 0; i < n; i++) {
            __int128 product = 1;
            long long GCD = 0;
            long long LCM = 1;

            for (int j = i; j < n; j++) {
                long long val = nums[j];
                product *= val;
                if (product > max_bound) {
                    break;
                }

                GCD = gcd(GCD, val);
                LCM = lcm(LCM, val);

                if (product == (__int128)GCD * LCM) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;

    // Binary exponentiation
    ll findPower(ll a, ll base) {
        if (base == 0) {
            return 1;
        }

        ll half = findPower(a, base / 2);
        ll result = (half * half) % MOD;
        if (base % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    bool check(vector<int>& nums, int size, int base) {
        int n = nums.size();

        ll hash = 0;
        unordered_map<ll, int> mp;

        ll p = findPower(base, size-1); //O(log(size))

        int i = 0;
        int j = 0;

        while(j < n) { //O(n)
            hash = (hash * base + nums[j]) % MOD;

            if(j-i+1 < size) {
                j++;
            } else {
                mp[hash]++;

                hash = (hash - (p * nums[i])%MOD + MOD) % MOD;

                i++;
                j++;
            }
        }

        for(auto &it : mp) {
            if(it.second == 1) {
                return true;
            }
        }

        return false;

    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int base = *max_element(begin(nums), end(nums)) + 1;

        int l = 1;
        int r = n;

        int result = n;

        while(l <= r) { //log(n)
            int mid = l + (r-l)/2;

            if(check(nums, mid, base)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};

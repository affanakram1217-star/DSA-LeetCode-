class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int tar) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // find first occurrence
        int st = 0, end = n - 1, first = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == tar) {
                first = mid;
                end = mid - 1;
            } 
            else if (nums[mid] < tar) {
                st = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }

        if (first == -1) return {};  // no target present

        // find last occurrence
        st = 0, end = n - 1;
        int last = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == tar) {
                last = mid;
                st = mid + 1;
            } 
            else if (nums[mid] < tar) {
                st = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }

        // collect all indices
        vector<int> ans;
        for (int i = first; i <= last; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        unordered_set<int> seen;
        for(int i=1;i<n;i++){
            int curr_sum=nums[i]+nums[i-1];

            if(seen.find(curr_sum)!=seen.end()){
                count++;
            }

            seen.insert(curr_sum);
        }
        return count>=1 ? true: false;
    }
};
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();

        int minEl=INT_MAX;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            minEl=min(minEl,nums[i]);
        }

        return sum-n*minEl;
    }
};
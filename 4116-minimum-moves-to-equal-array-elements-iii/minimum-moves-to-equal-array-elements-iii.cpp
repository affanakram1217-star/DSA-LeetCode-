class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxEl=INT_MIN;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxEl=max(nums[i],maxEl);
        }

        return n*maxEl-sum;
    }
};
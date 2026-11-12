class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int currSum=nums[0];
        int maxSum=nums[0];

        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                currSum+=nums[i];
                maxSum=max(maxSum,currSum);
            }else{
                currSum=nums[i];
            }
        }

        return maxSum;
    }
};
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int result=INT_MAX;
        int n=nums.size();

        vector<int> prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=nums[i]+prefixSum[i-1];
        }

        for(int i=0;i<n;i++){
            for(int len=l;len<=r && i+len-1<n;len++){
                int j=i+len-1;
                int sum=prefixSum[j]-(i > 0 ? prefixSum[i - 1] : 0);

                if(sum>0){
                    result=min(result,sum);
                }
            }
        }

        return result==INT_MAX?-1:result;
    }
};
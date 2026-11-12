class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int result=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int j=i+1;
            int incr=1;

            while(j<n && nums[j]>nums[j-1]){
                incr++;
                j++;
            }

            j=i+1;
            int decr=1;
            while(j<n && nums[j]<nums[j-1]){
                decr++;
                j++;
            }

            result=max({result,incr,decr});
        }
        return result;
    }
};
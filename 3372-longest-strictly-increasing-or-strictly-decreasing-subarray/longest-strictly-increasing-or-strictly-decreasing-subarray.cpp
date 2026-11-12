class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int result=1;
        int inc=1;
        int dec=1;

        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc++;
                dec=1;
                result=max(result,inc);
            }else if(nums[i]<nums[i-1]){
                dec++;
                inc=1;
                result=max(result,dec);
            }else{
                inc=1;
                dec=1;
            }
        }
        return result;
    }
};
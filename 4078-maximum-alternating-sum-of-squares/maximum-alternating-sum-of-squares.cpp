class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }

        // sort(nums.begin(),nums.end());
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());

        long long LargeHalf=accumulate(nums.begin()+n/2, nums.end(),0LL);
        long long smallHalf=accumulate(nums.begin(),nums.begin()+n/2,0LL);

        return LargeHalf-smallHalf;
    }
};
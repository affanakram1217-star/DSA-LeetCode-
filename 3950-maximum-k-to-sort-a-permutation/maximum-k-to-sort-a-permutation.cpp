class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int K=-1; // all bits set(1111111)
        // int K=INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                K=(K&nums[i]);
            }
        }

        return K==-1?0:K;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            totsum+=nums[i];
        }

        int tar=totsum-x;

        if(tar<0){
            return -1;
        }

        int i=0;
        int j=0;
        int currSum=0;
        int maxLen=-1;
        while(j<n){
            currSum+=nums[j];
            
            while(i<=j && currSum>tar){
                currSum-=nums[i];
                i++;
            }

            if(currSum==tar){
                maxLen=max(maxLen,j-i+1);
            }

            j++;
        }

        return maxLen!=-1? n-maxLen:-1;
    }
};
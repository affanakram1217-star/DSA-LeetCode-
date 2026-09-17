class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();

        vector<int> BestMinLenTillIdx(n,INT_MAX);
        int result=INT_MAX;
        int bestMinLen=INT_MAX;
        int i=0;
        int j=0;
        int currSum=0;
        while(j<n){
            currSum+=arr[j];

            while(i<j && currSum>target){
                currSum-=arr[i];
                i++;
            }

            if(currSum==target){
                int len=j-i+1;
                if(i>0 && BestMinLenTillIdx[i-1]!=INT_MAX ){
                    result=min(result,len+BestMinLenTillIdx[i-1]);
                }
                bestMinLen=min(len,bestMinLen);
            }
            BestMinLenTillIdx[j]=bestMinLen;
            j++;
        }

        return result==INT_MAX ? -1 : result;
    }
};
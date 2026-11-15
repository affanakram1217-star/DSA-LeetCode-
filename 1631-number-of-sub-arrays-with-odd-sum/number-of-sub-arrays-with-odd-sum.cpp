class Solution {
public:
    int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int odd=0;
        int even=1;
        int count=0;

        vector<int> prefixSum(n);
        prefixSum[0]=arr[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=arr[i]+prefixSum[i-1];
        }

        for(int i=0;i<n;i++){
            if(prefixSum[i]%2==0){
                count=(count+odd)%M;
                even++;
            }else{
                count=(count+even)%M;
                odd++;
            }
        }

        return count;

    }
};
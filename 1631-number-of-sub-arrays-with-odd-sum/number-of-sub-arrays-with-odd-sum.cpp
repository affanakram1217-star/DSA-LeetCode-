class Solution {
public:
    int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int odd=0;
        int even=1;
        int count=0;
        int cumSum=0;

        for(int i=0;i<n;i++){
            cumSum+=arr[i];
            if(cumSum%2==0){
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
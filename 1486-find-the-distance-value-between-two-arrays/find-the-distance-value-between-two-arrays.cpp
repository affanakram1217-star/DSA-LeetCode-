class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        //Approach 2 Sorting + lower bound
        sort(arr2.begin(),arr2.end());
        int count=0;

        int n=arr2.size();

        for(int i=0;i<arr1.size();i++){
            int j=lower_bound(arr2.begin(),arr2.end(),arr1[i])-(arr2.begin());

            if(j==0){//every other element is greater than arr1[i]
                count+=(arr2[0]-arr1[i])>d;
            }else if(j>=n){//every elemnet is smaller than arr[i]
                count+=(arr1[i]-arr2[n-1])>d;
            }else{
                count+=((arr2[j]-arr1[i])>d && (arr1[i]-arr2[j-1])>d);
            }
        }

        return count;
    }
};
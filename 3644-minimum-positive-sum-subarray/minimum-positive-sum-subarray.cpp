class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int result=INT_MAX;

        vector<int> prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }

        multiset<int> st;
        st.insert(0);

        for(int j=l-1;j<n;j++){
            if(j-l>=0){
                st.insert(prefixSum[j-l]);
            }

            int oldIdxoutOfWindow=j-r-1;
            if(oldIdxoutOfWindow>=0){
                st.erase(st.find(prefixSum[oldIdxoutOfWindow]));
            }else if(oldIdxoutOfWindow==-1){
                st.erase(st.find(0));
            }

            auto it=st.lower_bound(prefixSum[j]);
            if(it!=st.begin()){
                it--;
                result=min(result,prefixSum[j]-*it);
            }
        }

        return result==INT_MAX?-1:result;
    }
};
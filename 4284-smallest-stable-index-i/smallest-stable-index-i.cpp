class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        int minEl=INT_MAX;
        vector<int> minfromIdx(n);
        for(int i=n-1;i>=0;i--){
            minEl=min(minEl,nums[i]);
            minfromIdx[i]=minEl;
        }

        int maxEl=INT_MIN;
        for(int i=0;i<n;i++){
            maxEl=max(maxEl,nums[i]);

            if(maxEl-minfromIdx[i]<=k){
                return i;
            }
        }
        return -1;
    }
};
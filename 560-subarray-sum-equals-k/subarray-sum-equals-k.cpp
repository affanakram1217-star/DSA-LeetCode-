class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int n=nums.size();
        // int count=0;
        // unordered_map <int,int> m;
        // vector<int> prefixSum(n,0);
        // prefixSum[0]=nums[0];
        // for (int i=1;i<n;i++){
        //     prefixSum[i]=prefixSum[i-1]+nums[i];
        // }
        // for (int j=0;j<n;j++){
        //     int val=prefixSum[j]-k;
        //     if (prefixSum[j]==k){
        //         count++;
        //     }
        //     if (m.find(val)!=m.end()){
        //         count+=m[val];
        //     }
        //     if (m.find(prefixSum[j])==m.end()){
        //         m[prefixSum[j]]=0;
        //     }
        //     m[prefixSum[j]]++;
        // }
        // return count;

        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        int result=0;
        int cumSum=0;

        for(int i=0;i<n;i++){
            cumSum+=nums[i];

            if(mp.find(cumSum-k)!=mp.end()){
                result+=mp[cumSum-k];
            }

            mp[cumSum]++;
        }
        return result;
    }
};
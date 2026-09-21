class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();

        vector<long long> result(k,0);
        vector<long long> prevCount(k,0);

        for(int i=0;i<n;i++){
            //idx i pe end hone wale subarrays
            vector<long long> currCount(k,0);
            int currElementRem=nums[i]%k;
            currCount[currElementRem]++;

            for(int oldRem=0; oldRem<=k-1; oldRem++){
                long long newRem=(((long long)oldRem*nums[i]%k)%k);
                currCount[newRem]+=prevCount[oldRem];
            }

            prevCount=std::move(currCount);

            for(int x=0;x<=k-1;x++){
                result[x]+=prevCount[x];
            }
        }

        return result;
    }
};
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        // unordered_map<long,int> mp[n]; //array of maps
        vector<unordered_map<long long, int>> mp(n); 
        int result=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long diff=(long)nums[i]-nums[j];
                auto it=mp[j].find(diff);
                int count_At_j=it==end(mp[j])?0:it->second;
                mp[i][diff]+=count_At_j+1;
                result+=count_At_j;
            }
        }
        return result;
    }
};
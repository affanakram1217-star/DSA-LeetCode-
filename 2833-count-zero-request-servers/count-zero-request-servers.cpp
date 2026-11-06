class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();
        int q=queries.size();
        auto lambda=[](vector<int> &vec1, vector<int> &vec2){
            return vec1[1]<vec2[1];
        };

        sort(logs.begin(), logs.end(), lambda);

        vector<int> result(q);
        vector<pair<int,int>> timeIdx(q);
        
        for(int i=0;i<q;i++){
            timeIdx[i]={queries[i],i};
        }

        sort(timeIdx.begin(), timeIdx.end());

        int i=0;
        int j=0;
        unordered_map<int,int> mp;

        for(auto [time,idx]: timeIdx){
            //Range
            int s=time-x;
            int e=time;

            //Expanding window
            while(j<m && logs[j][1]<=e){
                mp[logs[j][0]]++;
                j++;
            }

            //Shrinking
            while(i<m && logs[i][1]<s){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]]==0){
                    mp.erase(logs[i][0]);
                }
                i++;
            }

            result[idx]=n-mp.size(); //total servers- kitne active h
        }

        return result;
        
    }
};
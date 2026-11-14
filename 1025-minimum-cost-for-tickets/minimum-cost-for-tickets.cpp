class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> st(days.begin(),days.end());
        int last_day=days.back();

        vector<int> t(last_day+1,0);
        t[0]=0;

        for(int i=1;i<=last_day;i++){

            if(st.find(i)==st.end()){
                t[i]=t[i-1];
                continue;
            }

            t[i]=INT_MAX;

            int cost_1=costs[0]+t[max(i-1,0)];
            int cost_7=costs[1]+t[max(i-7,0)];
            int cost_30=costs[2]+t[max(i-30,0)];

            t[i]=min({cost_1,cost_7,cost_30});

        }

        return t[last_day];
    }
};
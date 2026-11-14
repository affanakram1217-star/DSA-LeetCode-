class Solution {
public:
    int t[366];
    int solve(int i,vector<int>& days, vector<int>& costs,int n){
        if(i>=n){
            return 0;
        }

        if(t[i]!=-1){
            return t[i];
        }


        int cost_1=costs[0]+solve(i+1,days,costs,n);
        int j=i;
        while(j<n && days[j]<days[i]+7){
            j++;
        }
        int cost_7=costs[1]+solve(j,days,costs,n);

        int k=i;
        while(j<n && days[j]<days[i]+30){
            j++;
        }
        int cost_30=costs[2]+solve(j,days,costs,n);


        return t[i]=min({cost_1,cost_7,cost_30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(t,-1,sizeof(t));
        int n=days.size();
        return solve(0,days,costs,n);
    }
};
class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(int i,int time,vector<int>& satisfaction){
        if(i==n){
            return 0;
        }

        if(t[i][time]!=-1){
            return t[i][time];
        }

        int include=satisfaction[i]*time + solve(i+1,time+1,satisfaction);
        int exclude=solve(i+1,time,satisfaction);

        return t[i][time]=max(include,exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n=satisfaction.size();
        t.assign(n+1,vector<int>(n+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return solve(0,1,satisfaction);
    }
};
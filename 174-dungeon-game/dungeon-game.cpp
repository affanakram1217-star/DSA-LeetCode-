class Solution {
public:
    int m;
    int n;
    int t[201][201];
    int solve(int i, int j, vector<vector<int>>& dungeon){
        if(i>=m || j>=n){
            return 1e9;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i==m-1 && j==n-1){
            if(dungeon[i][j]>0){
                return 1;
            }else{
                return abs(dungeon[i][j])+1;
            }
        }

        int right=solve(i,j+1,dungeon);
        int down=solve(i+1,j,dungeon);

        int result=min(right,down)-dungeon[i][j];

        return t[i][j]= result>0 ? result :1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,dungeon);
    }
};
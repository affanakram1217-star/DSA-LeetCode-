class Solution {
public:
    int m;
    int n;
    int t[501][501][2];
    int MOD=1e9+7;
    int solve(int i,int j,int dir,vector<vector<int>>& grid){
        if(i==m-1 && j==n-1){
            return 1;
        
        }

        if(i<0 || i>=m || j<0 || j>=n){
            return 0;
        }

        if(t[i][j][dir]!=-1){
            return t[i][j][dir];
        }

        int right=0;
        int down=0;

        if(grid[i][j]==1){
            if(dir==0){
                down=solve(i+1,j,1,grid);
            }else{
                right=solve(i,j+1,0,grid);
            }
        }else{
            right=solve(i,j+1,0,grid);
            down=solve(i+1,j,1,grid);
        }

        return t[i][j][dir]=(right+down)%MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,0,grid);
    }
};
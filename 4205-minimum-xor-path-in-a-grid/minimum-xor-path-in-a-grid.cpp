class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        //DP approach
        // int m=grid.size();
        // int n=grid[0].size();

        // vector<vector<bitset<1024>>> dp(m,vector<bitset<1024>>(n));

        // dp[0][0][grid[0][0]]=1;

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){

        //         if(i==0 && j==0) continue;

        //         bitset<1024> up;
        //         bitset<1024> left;

        //         if(i>0){
        //             up=dp[i-1][j];
        //         }

        //         if(j>0){
        //             left=dp[i][j-1];
        //         }

        //         bitset<1024> combined=up|left;

        //         for(int xorVal=0;xorVal<1024;xorVal++){
        //             if(combined[xorVal]){
        //                 int resultXorVal=xorVal^grid[i][j];
        //                 dp[i][j][resultXorVal]=1;
        //             }
        //         }
        //     }
        // }

        // for(int xorVal=0;xorVal<1024;xorVal++){
        //     if(dp[m-1][n-1][xorVal]){
        //         return xorVal;
        //     }
        // }

        // return -1;

        //BFS
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(1024,false)));
        queue<tuple<int,int,int>> q;
        q.push({0,0,grid[0][0]});
        vis[0][0][grid[0][0]]=true;

        while(!q.empty()){
            auto [r,c,XorVal]=q.front();
            q.pop();

            if(r+1<m){
                int nextVal=XorVal^grid[r+1][c];
                if(!vis[r+1][c][nextVal]){
                    vis[r+1][c][nextVal]=true;
                    q.push({r+1,c,nextVal});
                }
            }

            if(c+1<n){
                int nextVal=XorVal^grid[r][c+1];
                if(!vis[r][c+1][nextVal]){
                    vis[r][c+1][nextVal]=true;
                    q.push({r,c+1,nextVal});
                }
            }
        }

        for(int xorVal=0;xorVal<1024;xorVal++){
            if(vis[m-1][n-1][xorVal]){
                return xorVal;
            }
        }

        return -1;
    }
};
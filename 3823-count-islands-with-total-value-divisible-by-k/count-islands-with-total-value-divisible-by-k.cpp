class Solution {
public:
    int m;
    int n;
    long long dfs(int i, int j,vector<vector<bool>> &vis,vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || grid[i][j]==0){
            return 0;
        }

        vis[i][j]=true;
        long long sum=grid[i][j];

        sum+=dfs(i-1,j,vis,grid);
        sum+=dfs(i+1,j,vis,grid);
        sum+=dfs(i,j-1,vis,grid);
        sum+=dfs(i,j+1,vis,grid);

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();

        int count=0;

        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]!=0){
                    long long sum=dfs(i,j,vis,grid);
                    if(sum%k==0){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
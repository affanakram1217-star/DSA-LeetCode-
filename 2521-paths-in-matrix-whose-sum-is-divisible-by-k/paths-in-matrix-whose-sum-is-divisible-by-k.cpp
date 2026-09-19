class Solution {
public:
    int m;
    int n;
    int M=1e9+7;
    int solve(int i, int j, int currSum, vector<vector<int>>& grid, int k, vector<vector<vector<int>>>& t){
        if(i>=m ||j>=n){
            return 0;
        }
        if(t[i][j][currSum]!=-1){
            return t[i][j][currSum];
        }
        if(i==m-1 && j==n-1){
            return ((currSum+grid[i][j])%k==0);
        }

        int down=solve(i+1,j,(currSum+grid[i][j])%k,grid,k,t);
        int right=solve(i,j+1,(currSum+grid[i][j])%k,grid,k,t);
        return t[i][j][currSum]=(down+right)%M;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>> t(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(0,0,0,grid,k,t);
    }
};
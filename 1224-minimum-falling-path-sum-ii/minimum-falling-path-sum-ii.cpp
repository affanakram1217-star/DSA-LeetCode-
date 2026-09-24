class Solution {
public:
    int n;
    int t[201][201];
    int solve(int col, int row, vector<vector<int>>& grid){
        if(col<0 || col>=n){
            return 1e9;
        }
        if(row==n-1){
            return grid[row][col];
        }
        if(t[row][col]!=1e8){
            return t[row][col];
        }

        int ans=INT_MAX;
        for(int nextCol=0;nextCol<n;nextCol++){
            if(nextCol!=col){
                ans=min(ans,solve(nextCol,row+1,grid));
            }
        }
        return t[row][col]=grid[row][col]+ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                t[i][j]=1e8;
            }
        }
        int result=INT_MAX;
        for(int col=0;col<n;col++){
            result=min(result,solve(col,0,grid));
        }
        
        return result;
    }
};
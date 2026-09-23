class Solution {
public:
    int n;
    int t[101][101];
    int solve(int row, int col,vector<vector<int>>& matrix){
        if(col>=n || col<0){
            return 1e9;
        }
        if(row==n-1){
            return matrix[row][col];
        }
        if(t[row][col]!=1e8){
            return t[row][col];
        }
       
        int down=matrix[row][col]+solve(row+1,col,matrix);
        int leftDiag=matrix[row][col]+solve(row+1,col-1,matrix);
        int rightDiag=matrix[row][col]+solve(row+1,col+1,matrix);

        return t[row][col]=min({down,leftDiag,rightDiag});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();
        for(int i = 0; i < 101; i++)
            for(int j = 0; j < 101; j++)
                t[i][j] = 1e8;
        int result=INT_MAX;
        int row=0;
        for(int col=0;col<n;col++){
            result=min(result,solve(row,col,matrix));
        }
        return result;
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        //Approach 1 Brute Force
        int m=grid.size();
        int n=grid[0].size();

        int ans=0;
        vector<int> row(m,0);
        vector<int> col(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && (row[i]>1 || col[j]>1)){
                    ans++;
                }
            }
        }

        return ans;
    }
};
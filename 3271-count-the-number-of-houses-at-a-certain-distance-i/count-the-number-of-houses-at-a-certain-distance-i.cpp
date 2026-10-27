class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> grid(n+1,vector<int>(n+1,1e9));

        for(int i=1;i<n;i++){
            grid[i][i+1]=1;
            grid[i+1][i]=1;
        }

        grid[x][y]=1;
        grid[y][x]=1;

        //Floyd Warshall Algo
        for(int via=1;via<=n;via++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j){
                        grid[i][j]=0;
                    }
                    grid[i][j]=min(grid[i][j],grid[i][via]+grid[via][j]);
                }
            }
        }

        vector<int> result(n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                int val=grid[i][j];
                result[val-1]++;
            }
        }

        return result;
    }
};
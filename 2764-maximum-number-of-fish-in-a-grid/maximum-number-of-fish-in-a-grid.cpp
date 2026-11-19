class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};

    int bfs(int i, int j,vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        int fishCount=grid[i][j];
        grid[i][j]=0;//machli le liye

        while(!q.empty()){
            i=q.front().first;
            j=q.front().second;
            q.pop();

            for(auto& dir: directions){
                int i_=i+dir[0];
                int j_=j+dir[1];

                if(i_>=0 && i_<m && j_>=0 && j_<n && grid[i_][j_]>0){
                    q.push({i_,j_});
                    fishCount+=grid[i_][j_];
                    grid[i_][j_]=0;
                }
            }
        }

        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        int maxFish=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    maxFish=max(maxFish,bfs(i,j,grid));
                }
            }
        }

        return maxFish;

    }
};
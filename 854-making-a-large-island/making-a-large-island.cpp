class Solution {
public:
    int n;
    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};

    int DFS(int i, int j, vector<vector<int>>& grid, int id){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1){
            return 0;
        }

        grid[i][j]=id;
        int size=1;

        for(auto& dir: directions){
            int i_=dir[0]+i;
            int j_=dir[1]+j;

            size+=DFS(i_,j_,grid,id);
        }

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        int maxArea=0;
        int id=2; //2 se start kiya kyuki grid me ya to 1 h ya 0

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int size=DFS(i,j,grid,id);
                    mp[id]=size;
                    id++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> uniqueIDs;
                    for(auto& dir: directions){
                        int i_=i+dir[0];
                        int j_=j+dir[1];

                        if(i_>=0 && i_<n && j_>=0 && j_<n && grid[i_][j_]!=0){
                            uniqueIDs.insert(grid[i_][j_]);
                        }
                    }
                    int overallsize=1;
                    for(auto& id: uniqueIDs){
                        overallsize+=mp[id];
                    }

                    maxArea=max(maxArea,overallsize);
                }
            }
        }

        return maxArea==0?(n*n):maxArea;
    }
};
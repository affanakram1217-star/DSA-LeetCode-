class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int result=0;

        //bitmasking the possible branches or subsets
        for(int set=0;set<(1<<n);set++){
            vector<vector<int>> grid(n,vector<int>(n,1e9)); //graph that we make for every value of set and then floyd warshall will give us shortest distance between every pair

            for(auto& it: roads){
                int u=it[0];
                int v=it[1];
                int wt=it[2];

                if((set>>u & 1)&&(set>>v & 1)){ //check if that node is to be taken or not acc to set value
                    grid[u][v]=min(grid[u][v],wt);
                    grid[v][u]=min(grid[v][u],wt);
                }
            }

            //diagonals entry in the graph matrix is 0
            for(int i=0;i<n;i++){
                grid[i][i]=0;
            }
            //floyd warshall
            for(int via=0;via<n;via++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        grid[i][j]=min(grid[i][j],grid[i][via]+grid[via][j]);
                    }
                }
            }
            //checking if all shortest paths<=maxDist
            bool ok=true;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    if((set>>i & 1)&& (set>>j & 1)){
                        if(grid[i][j]>maxDistance){
                            ok=false;
                            break;
                        }
                    }
                }
            }

            if(ok==true){
                result++;
            }

        }

        return result;
    }
};
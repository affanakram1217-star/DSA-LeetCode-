class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> cost(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,{0,0}});
        cost[0][0]=0;

        while(!pq.empty()){
            auto [currCost,pos]=pq.top();
            auto [i,j]=pos;
            pq.pop();

            if(currCost>cost[i][j]){
                continue;
            }

            if(i==m-1 && j==n-1){
                return cost[m-1][n-1];
            }

            for(int dir_i=0;dir_i<=3;dir_i++){
                int new_i=i+directions[dir_i][0];
                int new_j=j+directions[dir_i][1];

                if(new_i>=0 && new_i<m && new_j >=0 &&new_j<n){
                    int gridDir=grid[i][j];
                    int dirCost=(gridDir-1!=dir_i)?1:0;

                    int newCost=currCost+dirCost;

                    if(newCost<cost[new_i][new_j]){
                        cost[new_i][new_j]=newCost;
                        pq.push({newCost,{new_i,new_j}});
                    }
                }
            }           
        }
        return cost[m-1][n-1];
    }
};
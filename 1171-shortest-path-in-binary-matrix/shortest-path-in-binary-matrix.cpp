class Solution {
public:
    vector<vector<int>> directions={{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //Normal BFS
        int m=grid.size();
        int n=grid[0].size();

        if(m==0 || n==0 ||grid[0][0]!=0){
            return -1;
        }

        auto isSafe=[&](int x,int y){
            return (x>=0 && x<m && y>=0 && y<n);
        };
        
        //BFS
        // queue<pair<int,int>> q;
        // q.push({0,0});
        // grid[0][0]=1;

        // int level=0;

        // while(!q.empty()){
        //     int N=q.size();

        //     while(N--){ //process Level wise
        //         auto curr=q.front();
        //         q.pop();

        //         int x=curr.first;
        //         int y=curr.second;

        //         if(x==m-1 && y==n-1){
        //             return level+1;
        //         }

        //         for(auto dir: directions){
        //             int new_x=x+dir[0];
        //             int new_y=y+dir[1];

        //             if(isSafe(new_x,new_y)&&grid[new_x][new_y]!=1){
        //                 q.push({new_x,new_y});
        //                 grid[new_x][new_y]=1;
        //             }
        //         }
        //     }
        //     level++;
        // }
        // return -1;
        

        //Dijkstra Algo
        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        result[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int d=pq.top().first;
            pair<int,int> node=pq.top().second;
            int x=node.first;
            int y=node.second;
            pq.pop();
            int dist=1;
            for(auto dir: directions){
                int x_=x+dir[0];
                int y_=y+dir[1];

                if(isSafe(x_,y_)&&grid[x_][y_]!=1 && d+dist<result[x_][y_]){
                    pq.push({d+dist,{x_,y_}});
                    result[x_][y_]=d+dist;
                    grid[x_][y_]=1;
                }
            }

        }
        if(result[m-1][n-1]==INT_MAX){
            return -1;
        }

        return result[m-1][n-1]+1;
    }
};
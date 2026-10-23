class Graph {
public:
    //Dijkstra Algo
    // unordered_map<int,vector<pair<int,int>>> adj;
    // int N;
    // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int N;
    vector<vector<int>> adjMatrix;
    Graph(int n, vector<vector<int>>& edges) {
    //     N=n;
    //     for(auto& edge: edges){
    //         int u=edge[0];
    //         int v=edge[1];
    //         int cost=edge[2];

    //         adj[u].push_back({v,cost});
    //     }
    

        //Floyd Warshall Algorithm
        N=n;
        adjMatrix=vector<vector<int>>(n,vector<int>(n,1e9));

        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            int cost=edge[2];

            adjMatrix[u][v]=cost;
        }

        //i----i pe 0 that is diagonal pe zero
        for(int i=0;i<n;i++){
            adjMatrix[i][i]=0;
        }

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adjMatrix[i][j]=min(adjMatrix[i][j],adjMatrix[i][via]+adjMatrix[via][j]);
                }
            }
        }
    }

    void addEdge(vector<int> edge) {
        // int u=edge[0];
        // int v=edge[1];
        // int cost=edge[2];

        // adj[u].push_back({v,cost});

        //naya edge h u->v
        int u=edge[0];
        int v=edge[1];
        int cost=edge[2];
        //ab is naye edge ka har vertices se check karo u->v ka cost diya hua h
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                adjMatrix[i][j]=min(adjMatrix[i][j],adjMatrix[i][u]+cost+adjMatrix[v][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        // //source is node1 and destination is node2
        // vector<int> result(N,INT_MAX);

        // result[node1]=0;
        // pq.push({0,node1});

        // while(!pq.empty()){
        //     int d=pq.top().first;
        //     int node=pq.top().second;
        //     pq.pop();

        //     for(auto& vec:adj[node]){
        //         int adjNode=vec.first;
        //         int dist=vec.second;

        //         if(d+dist<result[adjNode]){
        //             result[adjNode]=d+dist;
        //             pq.push({result[adjNode],adjNode});
        //         }
        //     }
        // }

        // return result[node2]==INT_MAX?-1:result[node2];

        return adjMatrix[node1][node2]==1e9?-1:adjMatrix[node1][node2];
    }
};


class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){
            return 0;
        }

        unordered_map<int,vector<int>> adj; //key=stops values={indices}

        for(int route=0;route<routes.size();route++){
            for(auto& stop:routes[route]){
                adj[stop].push_back(route);
            }
        }

        queue<int> q;
        vector<bool> vis(501,false);

        for(auto& route:adj[source]){
            q.push(route);
            vis[route]=true;
        }

        int busCount=1;

        while(!q.empty()){
            int size=q.size();

            while(size--){
                int route=q.front();
                q.pop();

                for(auto& stop: routes[route]){
                    if(stop==target){
                        return busCount;
                    }

                    for(auto& nextRoute:adj[stop]){
                        if(vis[nextRoute]==false){
                            vis[nextRoute]=true;
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }

        return -1;
    }
};
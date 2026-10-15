class Solution {
public:
    bool isCycleDFS(int u,vector<vector<int>>& graph,vector<bool> &vis,vector<bool> &recPath){
        vis[u]=true;
        recPath[u]=true;

        for(int& v: graph[u]){
            if(!vis[v]){
                if(isCycleDFS(v,graph,vis,recPath)){
                    return true;
                }
            }else if(recPath[v]==true){
                return true;
            }
        }

        recPath[u]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //Approach-1 by DFS
        int V=graph.size();
        vector<bool> vis(V,false);
        vector<bool> recPath(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                isCycleDFS(i,graph,vis,recPath);
            }
        }

        vector<int> SafeNodes;
        for(int i=0;i<V;i++){
            if(recPath[i]==false){
                SafeNodes.push_back(i);
            }
        }

        return SafeNodes;
    }
};
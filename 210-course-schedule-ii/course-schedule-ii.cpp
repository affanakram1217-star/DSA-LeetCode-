class Solution {
public:
    // bool isCycleDFS(int src, vector<bool>& vis, vector<bool>& recPath,vector<vector<int>>& prerequisites){
    //     vis[src]=true;
    //     recPath[src]=true;

    //     for(int i=0;i<prerequisites.size();i++){
    //         int v=prerequisites[i][0];
    //         int u=prerequisites[i][1];

    //         if(u==src){
    //             if(!vis[v]){
    //                 if(isCycleDFS(v,vis,recPath,prerequisites)){
    //                     return true;
    //                 }
    //             }else if(recPath[v]){
    //                 return true;
    //             }
    //         }
    //     }
    //     recPath[src]=false;
    //     return false;
    // }

    // void topoSort(int src, vector<bool>& vis, stack<int>& s, vector<vector<int>>& prerequisites){
    //     vis[src]=true;

    //     for(int i=0;i<prerequisites.size();i++){
    //         int v=prerequisites[i][0];
    //         int u=prerequisites[i][1];

    //         if(u==src){
    //             if(!vis[v]){
    //                 topoSort(v,vis,s,prerequisites);
    //             }
    //         }
    //     }
    //     s.push(src);
    // }
    vector<int> topoSort(vector<vector<int>>& adj, int numCourses, vector<int>& indegree){
        queue<int> q;
        vector<int> result;
        int cnt=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                result.push_back(i);
                cnt++;
            }
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int& v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    result.push_back(v);
                    q.push(v);
                    cnt++;
                }
            }
        }
        if(cnt==numCourses){
            return result;
        }
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<bool> vis(numCourses,false);
        // vector<bool> recPath(numCourses,false);
        // vector<int> ans;

        // for(int i=0;i<numCourses;i++){
        //     if(!vis[i]){
        //         if(isCycleDFS(i,vis,recPath,prerequisites)){
        //             return {};
        //         }
        //     }
        // }

        // //Topological Sort->DAG
        // vis.assign(numCourses,false);
        // stack<int> s;

        // for(int i=0;i<numCourses;i++){
        //     if(!vis[i]){
        //         topoSort(i,vis,s,prerequisites);
        //     }
        // }

        // while(s.size()>0){
        //     ans.push_back(s.top());
        //     s.pop();
        // }

        // return ans;

        //By Kahn's Algo BFS
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto& vec:prerequisites){
            int u=vec[0];
            int v=vec[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        return topoSort(adj,numCourses,indegree);
    }
};
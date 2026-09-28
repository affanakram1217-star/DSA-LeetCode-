class Solution {
public:
    // //Cycle Detection
    // bool isCycleDFS(int src, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& prerequisites){
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
    bool topologicalCheckBFS(vector<vector<int>>& adj, int numCourses, vector<int>& indegree){
        queue<int> q;
        int cnt=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                cnt++;
            }
        }

        // int count=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            // count++;
            
            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    cnt++;
                }
            }
        }
        // return count==numCourses;
        return cnt==numCourses;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<bool> vis(numCourses,false);
        // vector<bool> recPath(numCourses, false);

        // for(int i=0;i<numCourses;i++){
        //     if(!vis[i]){
        //         if(isCycleDFS(i,vis,recPath,prerequisites)){
        //             return false;//return false when cycle is detected
        //         }
        //     }
        // }
        // return true;

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto& vec:prerequisites){
            int u=vec[0];
            int v=vec[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        return topologicalCheckBFS(adj,numCourses,indegree);
    }
};
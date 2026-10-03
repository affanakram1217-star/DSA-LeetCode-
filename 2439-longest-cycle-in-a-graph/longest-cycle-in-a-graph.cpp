class Solution {
public:
    int result=-1;

    void dfs(int u,vector<bool> &vis,vector<bool> &recPath,vector<int> &count,vector<int>& edges){
        if(u!=-1){
            vis[u]=true;
            recPath[u]=true;

            int v=edges[u];
            if(v!=-1 && !vis[v]){
                count[v]=count[u]+1;
                dfs(v,vis,recPath,count,edges);
            }else if(v!=-1 && recPath[v]){
                result=max(result,count[u]-count[v]+1);
            }
            recPath[u]=false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();

        vector<bool> vis(n,false);
        vector<bool> recPath(n,false);
        vector<int> count(n,1);

        for(int i=0;i<n;i++){
            dfs(i,vis,recPath,count,edges);
        }

        return result;
    }
};
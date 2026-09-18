class Solution {
public:
    bool BfsCheck(int i, vector<int> &color, vector<vector<int>>& adj){
        queue<int> q;
        q.push(i);
        color[i]=1;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int v: adj[u]){
                if(color[u]==color[v]){
                    return false;
                }
                if(color[v]==-1){
                    q.push(v);
                    color[v]=1-color[u];
                    
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> adj(n+1);

        for(auto dislike : dislikes){
            int u=dislike[0];
            int v=dislike[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n+1,-1);

        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!BfsCheck(i,color,adj)){
                    return false;
                }
            }
        }

        return true;
    }
};
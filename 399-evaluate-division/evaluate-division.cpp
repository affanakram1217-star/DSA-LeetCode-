class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,double>>> &adj,string src, string dest, unordered_set<string> &vis, double product, double &ans){

        if(vis.find(src)!=vis.end()){
            return;
        }

        vis.insert(src); //mark visited

        if(src==dest){
            ans=product;
            return;
        }

        for(auto& p:adj[src]){
            string v=p.first;
            double val=p.second;

            dfs(adj,v,dest,vis,product*val,ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();

        unordered_map<string,vector<pair<string,double>>> adj;

        for(int i=0;i<n;i++){
            string u=equations[i][0]; //'a'
            string v=equations[i][1]; //'b'
            double val=values[i];
            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});

        }

        vector<double> result;

        for(auto& query: queries){
            string src=query[0];
            string dest=query[1];
            double ans=-1.0;
            double product=1.0;

            if(adj.find(src)!=adj.end()){
                unordered_set<string> vis;
                dfs(adj,src,dest,vis,product,ans);
            }

            result.push_back(ans);
        }

        return result;
    }
};
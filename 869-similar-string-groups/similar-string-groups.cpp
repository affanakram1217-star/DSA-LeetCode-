class Solution {
public:
    bool isSimilar(string& s1, string& s2){
        int m=s1.length();
        int diffCount=0;

        for(int i=0;i<m;i++){
            if(s1[i]!=s2[i]){
                diffCount++;
            }
        }

        return diffCount==0||diffCount==2;
    }

    void dfs(int u,unordered_map<int,vector<int>> &adj,vector<bool>& visited){
        visited[u]=true;
        for(int& v: adj[u]){
            if(!visited[v]){
                dfs(v,adj,visited);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();

        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                if(isSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<bool> visited(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                count++;
            }
        }

        return count;
    }
};
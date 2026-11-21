class Solution {
public:
    unordered_map<int,vector<int>> adj;
    vector<int> lastSeen;
    vector<int> result;

    void dfs(int currNode,string &s,vector<int>& parent){
        int c=s[currNode]-'a';
        int nearestAncestor=lastSeen[c];

        lastSeen[c]=currNode;

        for(int child: adj[currNode]){
            dfs(child,s,parent);
        }

        lastSeen[c]=nearestAncestor;

        if(currNode!=0){ //0th node has no ancestor
            int newParent=parent[currNode];
            if(nearestAncestor!=-1){
                newParent=nearestAncestor;
            }

            parent[currNode]=nearestAncestor;
            result[newParent]+=result[currNode];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();

        for(int i=0;i<n;i++){
            int u=parent[i];
            int v=i;

            adj[u].push_back(v);
        }

        lastSeen.assign(26,-1);
        result.assign(n,1);

        dfs(0,s,parent);

        return result;
    }
};
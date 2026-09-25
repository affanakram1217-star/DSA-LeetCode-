class Solution {
public:
    int result;
    int DFS(vector<vector<int>>& adj, int curr, int parent, string &s){
        int longest=0;
        int secondLongest=0;

        for(int& child:adj[curr]){
            if(child==parent){
                continue;
            }
            int child_longest_path=DFS(adj,child,curr,s);

            if(s[child]==s[curr]){
                continue;
            }

            if(child_longest_path>secondLongest){
                secondLongest=child_longest_path;
            }

            if(secondLongest>longest){
                swap(longest,secondLongest);
            }
        }
        int neeche_ans_mil_gya=longest+secondLongest+1;
        int sirf_ek_accha=max(longest,secondLongest)+1;
        int root_only=1;

        result=max({result,neeche_ans_mil_gya,sirf_ek_accha,root_only});

        return max(root_only,sirf_ek_accha);
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> adj(n);

        result=0;
        for(int i=1;i<n;i++){
            int u=i;
            int v=parent[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        DFS(adj,0,-1,s);
        return result;
    }
};
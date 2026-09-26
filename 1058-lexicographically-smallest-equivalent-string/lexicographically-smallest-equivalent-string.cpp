class Solution {
public:
    char DFSfindMinChar(char ch, vector<int>& visited, unordered_map<char,vector<char>>& adj){
        visited[ch-'a']=1;
        char minChar=ch;
        for(char& v: adj[ch]){
            if(visited[v-'a']==0){
                minChar=min(minChar,DFSfindMinChar(v,visited,adj));
            }
        }

        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.length();

        unordered_map<char,vector<char>> adj;
        for(int i=0;i<n;i++){
            char u=s1[i];
            char v=s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result="";
        for(char &ch: baseStr){
            vector<int> visited(26,0);
            char minChar=DFSfindMinChar(ch,visited,adj);
            result.push_back(minChar);
        }

        return result;
    }
};
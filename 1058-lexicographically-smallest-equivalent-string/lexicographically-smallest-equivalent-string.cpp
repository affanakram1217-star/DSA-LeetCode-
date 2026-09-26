class Solution {
public:
    // char DFSfindMinChar(char ch, vector<int>& visited, unordered_map<char,vector<char>>& adj){
    //     visited[ch-'a']=1;
    //     char minChar=ch;
    //     for(char& v: adj[ch]){
    //         if(visited[v-'a']==0){
    //             minChar=min(minChar,DFSfindMinChar(v,visited,adj));
    //         }
    //     }

    //     return minChar;
    // }
    vector<int> parent;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void Union(int a, int b){
        int parA=find(a);
        int parB=find(b);

        if(parA!=parB){
            if(parA>parB){
                parent[parA]=parB;
            }else{
                parent[parB]=parA;
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // int n=s1.length();

        // unordered_map<char,vector<char>> adj;
        // for(int i=0;i<n;i++){
        //     char u=s1[i];
        //     char v=s2[i];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }

        // string result="";
        // for(char &ch: baseStr){
        //     vector<int> visited(26,0);
        //     char minChar=DFSfindMinChar(ch,visited,adj);
        //     result.push_back(minChar);
        // }

        // return result;

        int n=s1.length();

        parent.resize(26);

        for(int i=0;i<26;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
            Union(s1[i]-'a',s2[i]-'a');
        }

        string result="";
        int m=baseStr.length();
        for(int i=0;i<m;i++){
            char ch=(char)(find(baseStr[i]-'a')+'a');
            result+=ch;
        }

        return result;
    }
};
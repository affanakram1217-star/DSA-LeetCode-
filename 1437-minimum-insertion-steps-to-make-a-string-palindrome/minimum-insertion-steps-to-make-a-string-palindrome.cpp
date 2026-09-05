class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>> t(n,vector<int>(n));

        for(int i=0;i<n;i++){
            t[i][i]=0;
        }

        for(int L=2;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(s[i]==s[j]){
                    t[i][j]=t[i+1][j-1];
                }else{
                    t[i][j]=1+min(t[i+1][j],t[i][j-1]);
                }
            }
        }
        return t[0][n-1];
    }
};
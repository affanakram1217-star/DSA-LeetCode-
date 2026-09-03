class Solution {
public:
    //Recursion + Memoization 
    // int t[1001][1001];
    // bool solve(int i, int j, string&s){
    //     if(i>=j){
    //         return true;
    //     }
    //     if(t[i][j]!=-1){
    //         return t[i][j];
    //     }

    //     if(s[i]==s[j]){
    //         return t[i][j]=solve(i+1,j-1,s);
    //     }
    //     return false;
    // }
    string longestPalindrome(string s) {
        int n=s.length();
        // memset(t,-1,sizeof(t));
        // int maxlen=0;
        // int sp=-1;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(solve(i,j,s)){
        //             if(j-i+1>maxlen){
        //                 maxlen=j-i+1;
        //                 sp=i;
        //             }
        //         }
        //     }
        // }
        // return s.substr(sp,maxlen);

        //Bottom Up 
        vector<vector<bool>> t(n,vector<bool>(n));
        int maxL=1;//one length strings are always palindrome
        int idx=0;

        for(int i=0;i<n;i++){
            t[i][i]=true;
        }

        for(int L=2;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(s[i]==s[j] && L==2){
                    t[i][j]=true;
                    maxL=2;
                    idx=i;
                }else if(s[i]==s[j] && t[i+1][j-1]){
                    t[i][j]=true;
                    if(L>maxL){
                        maxL=L;
                        idx=i;
                    }
                }else{
                    t[i][j]=false;
                }
            }
        }
        return s.substr(idx,maxL);
    }
};
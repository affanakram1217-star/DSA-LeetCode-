class Solution {
public:
    int n;
    int t[101][101];
    bool solve(int i,int open,string s){
        if(i==n){
            return open==0;
        }

        if(t[i][open]!=-1){
            return t[i][open];
        }

        bool isValid=false;

        if(s[i]=='('){
            isValid|=solve(i+1,open+1,s);
        }else if(s[i]=='*'){
            isValid|=solve(i+1,open+1,s);
            isValid|=solve(i+1,open+1,s);
            isValid|=solve(i+1,open,s);

            if(open>0){
                isValid|=solve(i+1,open-1,s);
            }
        }else if(open>0){
            isValid|=solve(i+1,open-1,s);

        }
        return t[i][open]=isValid;
    }
    bool checkValidString(string s) {
        memset(t,-1,sizeof(t));
        int open=0;
        n=s.length();
        return solve(0,open,s);
    }
};
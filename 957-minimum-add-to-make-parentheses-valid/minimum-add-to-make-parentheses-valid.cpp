class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        int openBracket=0;
        int close=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                openBracket++;
            }else if(openBracket>0){
                openBracket--;
            }else{
                close++;
            }
        }

        return openBracket+close;
    }
};
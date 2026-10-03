class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        int result=0;

        int open=0;
        int close=0;

        //left to right
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }else{
                close++;
            }
            if(close>open){
                open=0;
                close=0;
            }else if(close==open){
                result=max(result,open+close);
            }
        }

        //right to left
        open=0;
        close=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                close++;
            }else{
                open++;
            }
            if(open>close){
                open=0;
                close=0;
            }else if(close==open){
                result=max(result,open+close);
            }
        }

        return result;
    }
};
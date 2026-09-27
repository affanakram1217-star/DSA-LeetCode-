class Solution {
public:
    string reverseParentheses(string s) {
        stack <int> lastSkipPt;

        string result="";
        for(char& ch: s){
            if(ch=='('){
                lastSkipPt.push(result.length());
            }else if(ch==')'){
                int l=lastSkipPt.top();
                lastSkipPt.pop();
                reverse(result.begin()+l,result.end());
            }else{
                result.push_back(ch);
            }
        }
        return result;
    }
};
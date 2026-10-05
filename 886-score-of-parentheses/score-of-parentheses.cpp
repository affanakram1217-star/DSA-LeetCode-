class Solution {
public:
    int scoreOfParentheses(string s) {
        //Approach 1-> TC O(n), SC O(n)
        int n=s.length();
        stack<int> st;
        int score=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(score);
                score=0;
            }else{//')'
                if(s[i-1]=='('){//'()' simplest case
                    score=st.top()+1;
                }else{// nested paranthesis case
                    score=st.top()+(2*score);
                }
                st.pop();
            }
        }
        return score;
    }
};
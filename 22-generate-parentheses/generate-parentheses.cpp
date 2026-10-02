class Solution {
public:
    vector<string> result;

    // bool isValid(string &str){
    //     stack<char> st;

    //     for(char &ch:str){
    //         if(ch=='('){
    //             st.push(ch);
    //         }else {
    //             if(st.empty()) return false;

    //             if(st.top()=='(' && ch==')'){
    //                 st.pop();
    //             }else{
    //                 return false;
    //             }
    //         }
    //     }
    //     return st.size()==0;
    // }
    // void solve(string& curr, int n){
        // if(curr.length()==2*n){
        //     if(isValid(curr)){
        //         result.push_back(curr);
               
        //     }
        //     return;
        // }

    //     curr.push_back('(');
    //     solve(curr,n);
    //     curr.pop_back();

    //     curr.push_back(')');
    //     solve(curr,n);
    //     curr.pop_back();
    // }

    void solve(string& curr,int n, int open , int close){
        if(curr.length()==2*n){
            result.push_back(curr);
            return;
        }

        if(open<n){
            curr.push_back('(');
            solve(curr,n,open+1,close);
            curr.pop_back();
        }

        if(close<open){
            curr.push_back(')');
            solve(curr,n,open,close+1);
            curr.pop_back();
        }
        

    }
    vector<string> generateParenthesis(int n) {
        // string curr="";
        // solve(curr,n);

        // return result;

        //approach 2
        string curr="";
        int open=0;
        int close=0;

        solve(curr,n,open,close);

        return result;
    }
};
class Solution {
public:
    // int n;
    // int t[101][101];
    // bool solve(int i,int open,string s){
    //     if(i==n){
    //         return open==0;
    //     }

    //     if(t[i][open]!=-1){
    //         return t[i][open];
    //     }

    //     bool isValid=false;

    //     if(s[i]=='('){
    //         isValid|=solve(i+1,open+1,s);
    //     }else if(s[i]=='*'){
    //         isValid|=solve(i+1,open+1,s);
    //         isValid|=solve(i+1,open+1,s);
    //         isValid|=solve(i+1,open,s);

    //         if(open>0){
    //             isValid|=solve(i+1,open-1,s);
    //         }
    //     }else if(open>0){
    //         isValid|=solve(i+1,open-1,s);

    //     }
    //     return t[i][open]=isValid;
    // }
    bool checkValidString(string s) {
        // memset(t,-1,sizeof(t));
        // int open=0;
        // n=s.length();
        // return solve(0,open,s);

        //Approach-3 using Stacks
        // int n=s.length();
        // stack<int> openSt;
        // stack<int> asteriskSt;

        // for(int i=0;i<n;i++){
        //     if(s[i]=='('){
        //         openSt.push(i);
        //     }else if(s[i]=='*'){
        //         asteriskSt.push(i);
        //     }else{
        //         if(!openSt.empty()){
        //             openSt.pop();
        //         }else if(!asteriskSt.empty()){
        //             asteriskSt.pop();
        //         }else{
        //             return false;
        //         }
        //     }
        // }

        // while(!openSt.empty() && !asteriskSt.empty()){
        //     if(openSt.top()>asteriskSt.top()){
        //         return false;
        //     }
        //     openSt.pop();
        //     asteriskSt.pop();
        // }

        // return openSt.empty();

        //Approach 4-> left to right and right to left traversal
        int n=s.length();
        int open=0;
        int close=0;

        //left to right
        for(int i=0;i<n;i++){
            if(s[i]=='*'||s[i]=='('){
                open++;
            }else{
                open--;
            }
            if(open<0){
                return false;
            }
        }

        //right to left
        for(int i=n-1;i>=0;i--){
            if(s[i]=='*'||s[i]==')'){
                close++;
            }else{
                close--;
            }
            if(close<0){
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int n;

    int solve(int currIdx, int prev, string& s,vector<vector<int>> &t){
        if(currIdx>=n){
            return 0;
        }

        if(t[currIdx][prev]!=-1){
            return t[currIdx][prev];
        }

        int flip=INT_MAX;
        int no_flip=INT_MAX;

        if(s[currIdx]=='0'){
            if(prev==0){
                flip=1+solve(currIdx+1,1,s,t);
                no_flip=solve(currIdx+1,0,s,t);
            }else{
                flip=1+solve(currIdx+1,1,s,t);
            }
        }else if(s[currIdx]=='1'){
            if(prev==1){
                no_flip=solve(currIdx+1,1,s,t);
            }else{
                flip=1+solve(currIdx+1,0,s,t);
                no_flip=solve(currIdx+1,1,s,t);
            }
        }

        return t[currIdx][prev]=min(flip,no_flip);
    }
    int minFlipsMonoIncr(string s) {
        n=s.length();
        vector<vector<int>> t(n+1,vector<int>(2,-1));
        return solve(0,0,s,t);
    }
};
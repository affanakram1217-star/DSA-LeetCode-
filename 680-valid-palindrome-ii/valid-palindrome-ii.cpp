class Solution {
public:
    int n;
    bool solve(string&s,int i,int j,bool deleted){
        if(i>=j){
            return true;
        }
        if(s[i]==s[j]){
            return solve(s,i+1,j-1,deleted);
        }

        if(deleted==true){
            return false;
        }

        return solve(s,i+1,j,true)||solve(s,i,j-1,true);
    }
    bool validPalindrome(string s) {
        n=s.length();
        return solve(s,0,n-1,false);
    }
};
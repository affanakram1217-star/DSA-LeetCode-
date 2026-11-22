class Solution {
public:
    bool checkString(string s) {
        int n=s.length();

        for(int i=1;i<n;i++){
            if(s[i]=='a' && s[i-1]=='b'){
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool checkString(string s) {
        int count_a=count(s.begin(),s.end(),'a');

        for(int i=0;i<count_a;i++){
            if(s[i]!='a'){
                return false;
            }
        }
        return true;
    }
};
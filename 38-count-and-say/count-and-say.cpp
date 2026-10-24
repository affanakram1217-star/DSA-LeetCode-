class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }

        string say=countAndSay(n-1);
        string res="";
        int i=0;
        while(i<say.length()){
            char curr_char=say[i];
            int count=0;

            while(i<say.length() && say[i]==curr_char){
                count++;
                i++;
            }

            res+=to_string(count);
            res.push_back(curr_char);
        }

        return res;
    }
};
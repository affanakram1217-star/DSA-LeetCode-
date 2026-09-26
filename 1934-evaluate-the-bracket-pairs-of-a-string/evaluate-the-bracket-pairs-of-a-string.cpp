class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        int n=s.length();
        for(auto& vec: knowledge){
            mp[vec[0]]=vec[1];
        }

        string result="";
        int i=0;
        while(i<n){
            if(s[i]=='('){
                int j=s.find(")",i+1);
                string sub=s.substr(i+1,j-i-1);
                result+=mp.count(sub)?mp[sub]:"?";
                // i=j; this also works
                i=j+1;
            }else{
                result.push_back(s[i]);
                i++;
            }
            // i++; this also works
        }

        return result;
    }
};
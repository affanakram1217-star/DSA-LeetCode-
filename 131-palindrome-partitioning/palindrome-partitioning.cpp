class Solution {
public:
    bool isPalin(string partition){
        string s2=partition;
        reverse(partition.begin(),partition.end());
        return s2==partition;

    }
    void getallParts(string s,vector<string> &part,vector<vector<string>> &ans ){
        if (s.size()==0){
            ans.push_back(part);
            return;
        }
        for (int i=0;i<s.size();i++){
            string partition=s.substr(0,i+1);
            if (isPalin(partition)){
                part.push_back(partition);
                getallParts(s.substr(i+1),part,ans);
                part.pop_back();//backtracking
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        getallParts(s, part, ans);
        return ans;
    }
};
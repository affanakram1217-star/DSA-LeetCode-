class Solution {
public:
    // bool isPalin(string partition){
    //     string s2=partition;
    //     reverse(partition.begin(),partition.end());
    //     return s2==partition;

    // }
    // void getallParts(string s,vector<string> &part,vector<vector<string>> &ans ){
    //     if (s.size()==0){
    //         ans.push_back(part);
    //         return;
    //     }
    //     for (int i=0;i<s.size();i++){
    //         string partition=s.substr(0,i+1);
    //         if (isPalin(partition)){
    //             part.push_back(partition);
    //             getallParts(s.substr(i+1),part,ans);
    //             part.pop_back();//backtracking
    //         }
    //     }
    // }

    void solve(string& s, int i, vector<string>&part, vector<vector<string>>& ans, vector<vector<bool>>&t){
        if(i==s.length()){
            ans.push_back(part);
            return;
        }

        for(int j=i;j<s.length();j++){
            if(t[i][j]==true){
                string partition=s.substr(i,j-i+1);
                part.push_back(partition);//partition
                solve(s,j+1,part,ans,t);//explore
                part.pop_back();//no partition
            }
        }
    }

    vector<vector<string>> partition(string s) {
        // vector<vector<string>> ans;
        // vector<string> part;
        // getallParts(s, part, ans);
        // return ans;

        //Recursion + Backtracking + Blueprint
        int n=s.length();
        vector<vector<string>> ans;
        vector<string> part;
        vector<vector<bool>> t(n,vector<bool>(n,false));

        for(int i=0;i<n;i++){
            t[i][i]=true;
        }

        for(int L=2;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(s[i]==s[j]){
                    if(L==2){
                        t[i][j]=true;
                    }else{
                        t[i][j]=t[i+1][j-1];
                    }
                }
            }
        }

        solve(s,0,part,ans,t);
        return ans;
    }
};
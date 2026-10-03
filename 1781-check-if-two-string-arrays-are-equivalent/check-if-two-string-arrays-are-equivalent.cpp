class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1="";
        for(int i=0;i<word1.size();i++){
            s1+=word1[i];
        }

        string s2="";
        for(int i=0;i<word2.size();i++){
            s2+=word2[i];
        }

        int m=s1.length();
        int n=s2.length();

        if(m!=n){
            return false;
        }
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }else{
                return false;
            }
        }

        if(i==m && j==n){
            return true;
        }
        return false;
    }
};
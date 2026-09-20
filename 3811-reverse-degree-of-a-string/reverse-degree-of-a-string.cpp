class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            ans+=('z'-s[i]+1)*(i+1);
        }

        return ans;
    }
};
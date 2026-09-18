class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> startIdx(26,-1);
        vector<int> endIdx(26,0);
        vector<bool> isValid(26,false);
        vector<string> result;
        int n=s.length();

        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(startIdx[idx]==-1){
                startIdx[idx]=i;
            }
            endIdx[idx]=i;
        }

        for(int c=0;c<26;c++){
            if(startIdx[c]==-1){
                continue;
            }
            isValid[c]=true;
            for(int i=startIdx[c];i<=endIdx[c];i++){
                if(startIdx[s[i]-'a']<startIdx[c]){
                    isValid[c]=false;
                    break;
                }
                endIdx[c]=max(endIdx[c],endIdx[s[i]-'a']);
            }
        }
        int lastTakenStartIdx=INT_MAX;
        for(int i=n-1;i>=0;i--){
            int idx=s[i]-'a';
            if(!isValid[idx]) continue;

            if(i==startIdx[idx] && endIdx[idx]<lastTakenStartIdx){
                result.push_back(s.substr(i,endIdx[idx]-i+1));
                lastTakenStartIdx=i;
            }
        }
        return result;
    }
};
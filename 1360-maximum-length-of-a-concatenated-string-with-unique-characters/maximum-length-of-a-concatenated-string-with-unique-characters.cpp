class Solution {
public:
    bool hasDuplicate(string s1, string s2){
        vector<int> freq(26,0);
        for(char& ch: s1){
            if(freq[ch-'a']>0){
                return true;
            }
            freq[ch-'a']++;
        }

        for(char& ch:s2){
            if(freq[ch-'a']>0){
                return true;
            }
        }
        return false;
    }
    int solve(int i,vector<string>& arr, string temp, int n){
        if(i>=n){
            return temp.length();
        }

        int include=0;
        int exclude=0;

        if(hasDuplicate(arr[i],temp)){
            exclude=solve(i+1,arr, temp,n);
        }else{
            include=solve(i+1,arr,temp+arr[i],n);
            exclude=solve(i+1,arr, temp,n);
        }

        return max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        int i=0;
        string temp="";
        return solve(i,arr,temp,n);
    }
};
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.length();
        int count_of_ones=0;
        int flips=0;

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count_of_ones++;
            }else{
                flips=min(flips+1,count_of_ones);
            }
        }

        return flips;
    }
};
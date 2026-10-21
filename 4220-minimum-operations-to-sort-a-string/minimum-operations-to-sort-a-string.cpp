class Solution {
public:
    int minOperations(string s) {
        int n=s.length();

        if(is_sorted(s.begin(),s.end())){
            return 0;
        }

        if(n==2){
            return -1;
        }

        char mn=*min_element(s.begin(),s.end());
        char mx=*max_element(s.begin(),s.end());

        if(s[0]==mn || s[n-1]==mx){
            return 1;
        }

        char mid_min=*min_element(s.begin()+1,s.end()-1);
        char mid_max=*max_element(s.begin()+1,s.end()-1);

        if(s[0]>mid_max && s[n-1]< mid_min){
            return 3;
        }

        return 2;

    }
};
class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int depth=0;
        int countOpen=0;
        int countClose=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                countOpen++;
                
            }else if(s[i]==')'){
                countClose++;
            }

            depth=max(depth,countOpen-countClose);
        }
        return depth;
    }
};
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.length();
        vector<int> result(n);

        int depth=0;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                depth++;
                result[i]=(depth%2==0)?0:1;
            }else{
                result[i]=(depth%2==0)?0:1;
                depth--;
            }
        }

        return result;
    }
};
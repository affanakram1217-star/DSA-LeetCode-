class Solution {
public:
    int countAsterisks(string s) {
        int barCount=0;
        int countAst=0;

        for(char &c: s){
            if(c=='|'){
                barCount++;
            }
            else if(c=='*' && barCount%2==0){
                countAst++;
            }
        }
        return countAst++;
    }
};
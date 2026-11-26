class Solution {
public:
    bool canAliceWin(int n) {
        int moves=10;
        int turns=0;

        while(moves<=n){
            n-=moves;
            moves--;
            turns++;
        }

        return turns%2==1;
    }
};
class Solution {
public:
    bool t[101][101][201];
    // int m;
    // int n;
    // int t[101][101][201];
    // bool solve(int i, int j, int openCount, vector<vector<char>>& grid){
    //     openCount+=grid[i][j]=='('?1:-1;
        
    //     if(openCount<0){
    //         return false;
    //     }
    //     if(t[i][j][openCount]!=-1){
    //         return t[i][j][openCount];
    //     }
    //     if(i==m-1 && j==n-1){
    //         return t[i][j][openCount]=(openCount==0);
    //     }

    //     if(i+1<m){
    //         if(solve(i+1,j,openCount,grid)==true){
    //             return t[i][j][openCount]=true;
    //         }
    //     }
    //     if(j+1<n){
    //         if(solve(i,j+1,openCount,grid)==true){
    //             return t[i][j][openCount]=true;
    //         }
    //     }
    //     return t[i][j][openCount]=false;

    // }
    bool hasValidPath(vector<vector<char>>& grid) {
        // memset(t,-1,sizeof(t));
        // m=grid.size();
        // n=grid[0].size();

        // if((m+n-1)%2==1){ // jo paranthesis ka string hoga uska length hoga m+n-1 aur wo even size ka hona chahiye kyunki open and close bracket equal number me hone chahiye
        //     return false;
        // }
        // if(grid[0][0]==')' || grid[m-1][n-1]=='('){
        //     return false;
        // }
        // return solve(0,0,0,grid);

        int m=grid.size();
        int n=grid[0].size();

        if((m+n-1)%2==1){
            return false;
        }
        if(grid[0][0]==')' || grid[m-1][n-1]=='('){
            return false;
        }

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){

                for(int openCount=0;openCount<=i+j+1;openCount++){
                    if(i==m-1 && j==n-1){
                        t[i][j][openCount]=(openCount==0);
                        continue;
                    }
                    t[i][j][openCount]=false;

                    //down
                    if(i+1<m){
                        int newOpenCnt=(grid[i+1][j]=='(')?openCount+1:openCount-1;
                        if(newOpenCnt>=0 && t[i+1][j][newOpenCnt]==true){
                            t[i][j][openCount]=true;
                        }
                    }

                    if(j+1<n){
                        int newOpenCnt=(grid[i][j+1]=='(')?openCount+1:openCount-1;
                        if(newOpenCnt>=0 && t[i][j+1][newOpenCnt]==true){
                            t[i][j][openCount]=true;
                        }
                    }
                }
            }
        }
        return t[0][0][1];

    }
};
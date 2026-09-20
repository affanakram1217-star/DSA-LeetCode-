class Solution {
public:
    // int n;
    // vector<vector<int>> t;
    // int child1Collect(vector<vector<int>>& fruits){
    //     int count=0;
    //     for(int i=0;i<n;i++){
    //         count+=fruits[i][i];
    //     }
    //     return count;
    // }

    // int child2Collect(int i, int j,vector<vector<int>>& fruits){
    //     if(i<0 || i>=n || j<0 || j>=n){
    //         return 0;
    //     }

    //     if(i==n-1 && j==n-1){
    //         return 0;
    //     }

    //     if(i==j || j<i){
    //         return 0;
    //     }

    //     if(t[i][j]!=-1){
    //         return t[i][j];
    //     }

    //     int bottom=fruits[i][j]+child2Collect(i+1,j,fruits);
    //     int bottomLeft=fruits[i][j]+child2Collect(i+1,j-1,fruits);
    //     int diag=fruits[i][j]+child2Collect(i+1,j+1,fruits);

    //     return t[i][j]=max({bottom, bottomLeft, diag});
    // }

    // int child3Collect(int i, int j,vector<vector<int>>& fruits){
    //     if(i<0 || i>=n || j<0 || j>=n){
    //         return 0;
    //     }

    //     if(i==n-1 && j==n-1){
    //         return 0;
    //     }

    //     if(i==j || j>i){
    //         return 0;
    //     }

    //     if(t[i][j]!=-1){
    //         return t[i][j];
    //     }

    //     int upRight=fruits[i][j]+child3Collect(i-1,j+1,fruits);
    //     int right=fruits[i][j]+child3Collect(i,j+1,fruits);
    //     int diag=fruits[i][j]+child3Collect(i+1,j+1,fruits);

    //     return t[i][j]=max({upRight,right, diag});
    // }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        // n=fruits.size();
        // t.resize(n,vector<int>(n,-1));
        // int c1=child1Collect(fruits);
        // int c2=child2Collect(0,n-1,fruits);
        // int c3=child3Collect(n-1,0,fruits);

        // return c1+c2+c3;

        int n=fruits.size();
        vector<vector<int>> t(n,vector<int>(n));

        //child 1->diagonal sum
        int count=0;
        for(int i=0;i<n;i++){
            count+=fruits[i][i];
        }

        //negate and handle the cells that we dont need to visit
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>j && i+j<n-1){
                    t[i][j]=0;
                }else if(j>i && i+j<n-1){
                    t[i][j]=0;
                }else{
                    t[i][j]=fruits[i][j];
                }
            }
        }

        //child 2 collect fruits where j>i

        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                t[i][j]+=max({t[i-1][j-1],t[i-1][j],(j+1<n )?t[i-1][j+1]:0});
            }
        }

        //child 3 collect fruits where i>j

        for(int j=1;j<n;j++){
            for(int i=j+1;i<n;i++){
                t[i][j]+=max({t[i][j-1],t[i-1][j-1], (i+1<n)? t[i+1][j-1]:0});
            }
        }

        return count+t[n-2][n-1]+t[n-1][n-2];
    }
};
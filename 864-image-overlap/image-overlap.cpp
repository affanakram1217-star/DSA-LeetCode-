class Solution {
public:
    int countOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int row_off, int  col_off){
        int n=img1.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int img2_i=i+row_off;
                int img2_j=j+col_off;

                if(img2_i<0 || img2_i>=n || img2_j<0 || img2_j>=n){
                    continue;
                }
                if(img1[i][j]==1 && img2[img2_i][img2_j]==1){
                    count++;
                }
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int maxOverlap=0;
        for(int row_off=-n+1;row_off<n;row_off++){
            for(int col_off=-n+1;col_off<n;col_off++){
                int count=countOverlap(img1,img2,row_off,col_off);
                maxOverlap=max(maxOverlap,count);
            }
        }
        return maxOverlap;
    }
};
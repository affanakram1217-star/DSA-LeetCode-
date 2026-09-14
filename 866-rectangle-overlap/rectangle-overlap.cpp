class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int left=max(rec1[0],rec2[0]);
        int right=min(rec1[2],rec2[2]);
        int bottom=max(rec1[1],rec2[1]);
        int top=min(rec1[3],rec2[3]);

        int width=max(0,right-left);
        int height=max(0,top-bottom);
        if(width<=0 || height<=0){
            return false;
        }
        return true;
    }
};
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        int a1=(ax2-ax1)*(ay2-ay1);
        int a2=(bx2-bx1)*(by2-by1);
        int area=a1+a2;
        int left=max(bx1,ax1);
        int right=min(bx2,ax2);
        int top=min(ay2,by2);
        int bottom=max(ay1,by1);

        int width=max(0,right-left);
        int height=max(0,top-bottom);

        int totarea=area-abs(width*height);

        return totarea;
    }
};
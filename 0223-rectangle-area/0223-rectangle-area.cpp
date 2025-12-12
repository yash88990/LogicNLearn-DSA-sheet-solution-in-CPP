class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int len_ov = max(0 , min(ax2 , bx2) - max(ax1 , bx1));
        int wid_ov = max(0 , min(ay2 , by2) - max(by1 , ay1));
        int area_ans = ((ax2 - ax1) * (ay2 - ay1)) + ((bx2 - bx1) *  (by2 - by1)) - (len_ov * wid_ov);
        return area_ans;
    }
};
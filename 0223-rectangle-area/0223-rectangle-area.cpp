class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int len_a = ax2 - ax1;
        int wid_a = ay2 - ay1;
        int area_a = len_a * wid_a;

        int len_b = bx2 - bx1;
        int wid_b = by2 - by1;
        int area_b = len_b * wid_b;

        int len_ov = max(0 , min(ax2 , bx2) - max(ax1 , bx1));
        int wid_ov = max(0 , min(ay2 , by2) - max(by1 , ay1));
        int area_ov = len_ov * wid_ov;

        int area_ans = area_a + area_b - area_ov;
        return area_ans;
    }
};
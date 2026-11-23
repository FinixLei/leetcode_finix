class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long s1 = (ax2-ax1) * (ay2-ay1);
        long s2 = (bx2-bx1) * (by2-by1);

        long long overlapX1 = max(ax1, bx1);
        long long overlapY1 = max(ay1, by1);
        long long overlapX2 = min(ax2, bx2);
        long long overlapY2 = min(ay2, by2);

        long long w = overlapX2 - overlapX1;
        long long h = overlapY2 - overlapY1;
        long long overlap = (w>0 && h>0) ? w*h : 0;
        return s1 + s2 - overlap;
    }
};

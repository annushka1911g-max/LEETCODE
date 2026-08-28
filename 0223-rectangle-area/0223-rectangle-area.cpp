class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {

        // Area of first rectangle
        long long area1 = (long long)(ax2 - ax1) * (ay2 - ay1);

        // Area of second rectangle
        long long area2 = (long long)(bx2 - bx1) * (by2 - by1);

        // Width of overlapping rectangle
        long long overlapWidth =
            max(0, min(ax2, bx2) - max(ax1, bx1));

        // Height of overlapping rectangle
        long long overlapHeight =
            max(0, min(ay2, by2) - max(ay1, by1));

        // Overlapping area
        long long overlap = overlapWidth * overlapHeight;

        return area1 + area2 - overlap;
    }
};
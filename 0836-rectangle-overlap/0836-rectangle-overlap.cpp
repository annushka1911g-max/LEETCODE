class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];

        int a = rec2[0];
        int b = rec2[1];
        int c = rec2[2];
        int d = rec2[3];

        return x1 < c && a < x2 && y1 < d && b < y2;
    }
};
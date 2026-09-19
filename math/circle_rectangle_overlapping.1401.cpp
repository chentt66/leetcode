class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int dx = std::clamp(xCenter, x1, x2) - xCenter;
        int dy = std::clamp(yCenter, y1, y2) - yCenter;
        return dx * dx + dy * dy <= radius * radius;
    }
};
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        std::sort(asteroids.begin(), asteroids.end());
        long long total_mass = mass; // use long long to avoid overflow
        for (int m : asteroids) {
            if (total_mass < m) return false;
            total_mass += m;
        }
        return true;
    }
};
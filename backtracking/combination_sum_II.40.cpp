#include <vector>

class Solution {
    public:
        std::vector<std::vector<int>> combinationSum(std::vector<int> candidates, int target)  {
            std::vector<std::vector<int>> result;
            std::sort(candidates.begin(), candidates.end());
            std::vector<int> current;
            backtrack(result, current, target, 0);
            return result;
        }
    private:
        void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& current, int rest, int start,
                       std::vector<int>& candidates) {
            if (rest == 0) {
                result.push_back(current);
                return;
            }
            for (int i = start; i < candidates.size(); i++) {
                if (candidates[i] > rest) {
                    break;
                }
                if (i > start && candidates[i] == candidates[i-1]) {
                    continue;
                }
                current.push_back(candidates[i]);
                backtrack(result, current, rest - candidates[i], i + 1, candidates);
                current.pop_back();
            }
        }
}

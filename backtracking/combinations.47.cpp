class Solution {
  public:
      vector<vector<int>> combine(int n, int k) {
          std::vector<std::vector<int>> cnk;
          std::vector<int> current;
          backtrack(cnk, current, 1, n, k);
          return cnk;
      }

  private:
      void backtrack(std::vector<vector<int>>& cnk, std::vector<int>& current, int start, int n, int k) {
          if ((int)current.size() == k) {
              cnk.push_back(current);
              return;
          }
          for (int i = start; i < n+1; i++) {
              current.push_back(i);
              backtrack(cnk, current, i+1, n, k);
              current.pop_back();
          }
      }
  };
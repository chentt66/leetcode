// XOR
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (int m : nums) {
            a = m ^ a;
        }
        return a;
    }
};

// Track non-duplicate using a list
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         std::vector<int> no_duplicate_list;
//         for (int m : nums) {
//             std::vector<int>::iterator it = std::find(no_duplicate_list.begin(), no_duplicate_list.end(), nums[i]);
//             if (it == no_duplicate_list.end()) {
//                 no_duplicate_list.push_back(nums[i]);
//             }
//             else {
//                 no_duplicate_list.erase(std::remove(no_duplicate_list.begin(), no_duplicate_list.end(), nums[i]), no_duplicate_list.end());
//             }
//         }
//         return no_duplicate_list[0];
//     }
// };

// Track occurrences using a hash table
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         std::unordered_map<int, int> seen;
//         for (int m : nums) {
//             ++seen[m];
//         }
//         for (int m : nums) {
//             if (seen[m] == 1) {
//                 return m;
//             }
//         }
//         // for (std::unordered_map<int,int>::iterator it = seen.begin(); it != seen.end(); ++it) {
//         //     if (it->second == 1) return it->first;
//         // }
//         return 0;
//     }
// };

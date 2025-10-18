class Solution {
  public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0, power = 31;
    while (n != 0) {
        // while is more efficient than for loop. Consider n like 00000000.
        ret += (n & 1) << power; // Extract bit at position 0, shift left to position 'power'
        n = n >> 1; // Shift n right by 1 (discard rightmost bit, examine next bit)by 1)
        power -= 1; // Move to next reversed position (31 → 30 → 29 ... → 0)
        }
    return ret;
  }
};

// class Solution {
// public:
//     int reverseBits(int n) {
//         int reversed = 0; // extra space
//         for (int i = 0; i < 32; ++i) {
//             int bit = (n >> i) & 1; // (1) Extract the single bit from position i in the number n
//             reversed = reversed | bit << (31 - i); // (2) Place the bit in the reversed position
//         }
//         return reversed;
//     }
// };
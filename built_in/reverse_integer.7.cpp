#include <climits>
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7) ) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8) ) return 0;
            rev = rev * 10 + digit;
        }
        return rev;
    }
};

// One thing I don’t understand is: digit > 7
// Say my input number is 1463847412, the inverse is 2147483641, which is 6 less than INT_MAX and satisfies (rev == INT_MAX / 10 && digit > 7) when x=463847412 and digit=1.
// If the input number is 2463847412, the reverse is 5 less than INT_MAX, so it satisfies (rev == INT_MAX / 10 && digit > 7) when x is 463847412 and digit=2. But 246387412 itself is larger than INT_MAX so it cannot be a valid input. Why don’t we write the constraint to digit > 1？
// 1463847412: the largest valid number which is also valid after reversed.
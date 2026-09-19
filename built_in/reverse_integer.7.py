class Solution:
    def reverse(self, x: int) -> int:
        INT32_MAX, INT32_MIN = 2**31-1, -2**31
        sign = 1 if x >= 0 else -1
        x = abs(x)
        rev = 0
        while x != 0:
            digit = x % 10
            x //= 10
            if rev > INT32_MAX//10 or (rev == INT32_MAX // 10 and digit > 7):
                return 0
            rev = rev * 10 + digit
        return rev * sign
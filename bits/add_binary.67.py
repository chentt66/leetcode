# O(max(m, n)) time
# O(max(m, n)) space
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        m, n = int(a), int(b)
        carry = 0
        result= []
        i, j = len(a)-1, len(b)-1
        while i>=0 or j>=0 or carry>0:
            total = carry
            if i >= 0:
                total += int(a[i])
                i -= 1
            if j >= 0:
                total += int(b[j])
                j -= 1
            result.append(str(total % 2))
            carry = total // 2
        return ''.join(reversed(result))

# First solution
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        m = int(a)
        n = int(b)
        carry = 0
        result = []
        if m == 0 and n == 0:
            return "0"
        while m > 0 or n > 0 or carry > 0:
            dm, dn = m%10, n%10
            s = dm + dn + carry
            if s == 0 or s == 1:
                result.append(str(s))
                carry = 0
            elif s == 2:
                result.append('0')
                carry = 1
            elif s == 3:
                result.append('1')
                carry = 1
            m //= 10
            n //= 10
        return ''.join(result[::-1])
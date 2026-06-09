from collections import deque
class Solution:
    def isValid(self, s: str) -> bool:
        st = deque()
        map_open_to_close = {'(': ')',
                            '[': ']',
                            '{': '}'}
        for char in s:
            if st and char == map_open_to_close.get(st[-1], 0):
                st.pop()
            else:
                st.append(char)
        if st:
            return False
        return True

        
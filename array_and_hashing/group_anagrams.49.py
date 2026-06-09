# O(n*klogk) time: k is max word length. For each word, sorted(word) costs O(k log k), done n times.
# O(n*k) space: The hash map stores every word once, total characters across all words is n·k                                   
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        from collections import defaultdict
        groups = defaultdict(list)
        for word in strs:
            key = ''.join(sorted(word)) # built in sorted() for any iterable, returns a new list
            groups[key].append(word) # safe, strings can't be mutated. no need for copy [:]
        return list(groups.values())
    
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}
        for word in strs:
            key = ''.join(sorted(word))
            if key not in groups:
                groups[key] = []
            groups[key].append(word)
        return list(groups.values())
    
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}
        for word in strs:
            key = ''.join(sorted(word))
            groups.setdefault(key, []).append(word)
        return list(groups.values())
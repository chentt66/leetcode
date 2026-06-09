# Exchange argument
# 排好序后，每个免费名额都直接给当前能拿到的最贵的那颗糖果，不去比较"如果把免费名额留到后面会不会更省"——因为局部最优（让最贵的糖果免费）能保证全局最优。

class Solution(object):
    def minimumCost(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        # cost = sorted(cost, reverse=True)
        cost.sort(reverse=True)
        return sum(p for i, p in enumerate(cost) if i % 3 != 2)

class Solution(object):
    def minimumCost(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        cost = sorted(cost, reverse=True)
        c = 0
        for i, p in enumerate(cost):
            if i % 3 == 2:
                continue
            c += p
        return c
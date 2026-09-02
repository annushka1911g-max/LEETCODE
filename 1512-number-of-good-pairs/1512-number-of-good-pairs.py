class Solution:
    def numIdenticalPairs(self, nums):
        count = {}
        ans = 0

        for num in nums:
            if num in count:
                ans += count[num]
                count[num] += 1
            else:
                count[num] = 1

        return ans
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        map = {}
        for i, n in enumerate(nums):
            if target - n in map:
                return [i, map[target - n]]
            else:
                map[n] = i

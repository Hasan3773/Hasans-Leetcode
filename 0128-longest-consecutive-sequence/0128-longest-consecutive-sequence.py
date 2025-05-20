class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_count = 0
        num_set = set(nums)

        for num in num_set:
            if num - 1 not in num_set:
                current_num = num
                current_count = 1
                while(current_num + 1 in num_set):
                    current_count += 1
                    current_num += 1
                max_count = max(current_count, max_count)
        return max_count
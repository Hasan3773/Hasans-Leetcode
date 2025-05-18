class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        map = {}
        for i, n in enumerate(nums):
            if n not in map:
                map[n] = 1
            else:
                map[n] += 1
        sorted_map = sorted(map.items(), key=lambda x:x[1], reverse=True)
        # sorted_map = dict(sorted_map)
        print(sorted_map)
        result = [0] * k
        j = 0
        while(j < k):
            result[j] = sorted_map[j][0]
            print(j)
            j += 1
        return result
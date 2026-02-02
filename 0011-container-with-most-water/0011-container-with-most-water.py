class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        # given an array where each index repersents the y axis of a chart of water
        # find the two indexes where their lines hold the most between them
        # by default you want to keep the container lines near the ends
        # loop through and calculate water stored, keep track of best end points
        first = 0
        last = len(height) - 1
        best_sum = 0
        while(first < last):
            # calc water stored 
            current_sum = 0
            y_axis = min(height[first], height[last])
            x_axis = last - first
            current_sum += y_axis * x_axis
            best_sum = max(current_sum, best_sum)
            if height[last] > height[first]:
                first += 1 
            else:
                last -= 1
        
        return best_sum
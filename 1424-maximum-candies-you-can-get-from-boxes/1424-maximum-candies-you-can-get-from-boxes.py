class Solution(object):
    def maxCandies(self, status, candies, keys, containedBoxes, initialBoxes):
        """
        :type status: List[int]
        :type candies: List[int]
        :type keys: List[List[int]]
        :type containedBoxes: List[List[int
        :type initialBoxes: List[int]
        :rtype: int
        """
        # given n boxes with arrays storing different information about each box
        # status says whether the ith box is open or closes (bool)
        # candies is the # of candies in the ith box
        # after opening a certain box you get a # of keys which you can use to open future closed boxes
        # containedBoxes - boxes are stored in boxes, so you only get access to sed boxes once youve opened the 
        # -- boxes they are contained in
        # return the max number of candies you can get folowing the above rules

        # check the initial boxes and which boxes are stored inside it
        # check which keys you now have -> open the boxes you now have (check the box status if you need the key)
        # as you keep opening boxes, keep updating which keys, boxes and total # of candies you have
        # key is that you can only get the candy from the box if you own the box and can open it - > how to calc the goal
        # the goal of the question is to calc the maximum of a number of posibilities -> bfs search
    
        numCandy = 0
        q = deque(initialBoxes) # add initial boxes to a double ended queue
        visit = set()

        while q:
            for i in range(len(q)):
                cur = q.popleft()
                # checks if we already visited it and if not add to q?
                if cur in visit:
                    continue # skips to the end of the for
                visit.add(cur)

                if status[cur]:
                    numCandy += candies[cur]
                    # main logic loop for each step
                    for k in keys[cur]: # deals with keys
                        if k in visit and status[k] == 0:
                            status[k] = 1
                            q.append(k)
                            visit.remove(k)
                        else: 
                            status[k] = 1
                    # add new boxes to q
                    for box in containedBoxes[cur]:
                        q.append(box)
        return numCandy






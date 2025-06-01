class Solution(object):
    def snakesAndLadders(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        n = len(board) # number of rows
        cells = [0] * (n**2 + 1) # not sure why we would add 1 to this
        label = 1
        columns = list(range(0, n))
        for row in range(n - 1, -1, -1):
            for column in columns:
                cells[label] = (row, column)
                label += 1
            columns.reverse()

        dist = [-1] * (n**2 + 1)
        dq = deque([1])
        dist[1] = 0
        while dq:
            curr = dq.popleft()
            for next in range(curr + 1, min(curr + 6, n**2) + 1):
                row, column = cells[next]
                if board[row][column] != -1:
                    destination = board[row][column]
                else:
                    destination = next
                if dist[destination] == -1:
                    dist[destination] = dist[curr] + 1
                    dq.append(destination)
        return dist[n * n]




        # given a 2d matrix of a board, where there are snakes and ladders 
        # a snake or ladder is indicated by a non -1 number, giving the resultant square to go to
        # the goal is to find the least number of dice rolls to get to the end of the board
        # the answer is a graph and then searchning it but mannnn i hate graphs
        '''
        [-1, -1, -1, -1]
        [-1, -1,  7, -1] 
        [-1, -1, -1, -1]
        [-1,  5, -1, -1]
        '''

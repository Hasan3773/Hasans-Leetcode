class Solution(object):
    def closestMeetingNode(self, edges, node1, node2):
        """
        :type edges: List[int]
        :type node1: int
        :type node2: int
        :rtype: int
        """
        def bfs(startNode, edges, dist):
            # perform traversal 
            # dist stores shortest distance from start node to all other nodes
            n = len(edges)
            queue = []
            queue.append(startNode)

            visited = [0] * n # set all to false
            dist[startNode] = 0 # what

            while queue:
                currentNode = queue.pop(0)
                if visited[currentNode]:
                    continue
                visited[currentNode] = True
                neighbor = edges[currentNode]
                if (neighbor != -1 and not visited[neighbor]):
                    dist[neighbor] = 1 + dist[currentNode] # what
                    queue.append(neighbor)
        dist1 = [float('inf')] * len(edges)
        dist2 = [float('inf')] * len(edges)
        n = len(edges)

        bfs(node1, edges, dist1)
        bfs(node2, edges, dist2)

        minDistNode = -1
        minDistTillNow = float('inf')

        for currentNode in range(n):
            if (minDistTillNow > max(dist1[currentNode], dist2[currentNode])):
                minDistNode = currentNode
                minDistTillNow = max(dist1[currentNode], dist2[currentNode])
        return minDistNode
        
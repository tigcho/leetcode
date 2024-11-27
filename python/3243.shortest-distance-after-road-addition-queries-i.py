class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        for i in range(n - 1):
            graph[i].append(i + 1)

        def bfs() -> int:
            queue = deque([(0, 0)])
            visited = [False] * n
            visited[0] = True

            while queue:
                currNode, currDist = queue.popleft()

                if currNode == n - 1:
                    return currDist
                
                for neighbor in graph[currNode]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        queue.append((neighbor, currDist + 1))

            return -1
        
        res = []
        for u, v in queries:
            graph[u].append(v)
            res.append(bfs())

        return res
#
# @lc app=leetcode id=2290 lang=python3
#
# [2290] Minimum Obstacle Removal to Reach Corner
#

# @lc code=start
class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        # Priority queue: (obstaclesRemoved, x, y)
        pq = [(0, 0, 0)]
        visited = set()
        visited.add((0, 0))

        while pq:
            obstaclesRemoved, x, y = heapq.heappop(pq)

            # If we reach the bottom-right corner
            if (x, y) == (m - 1, n - 1):
                return obstaclesRemoved

            # Explore neighbors
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and (nx, ny) not in visited:
                    visited.add((nx, ny))
                    # Add to the priority queue with updated obstacle count
                    heapq.heappush(pq, (obstaclesRemoved + grid[nx][ny], nx, ny))

        return -1
# @lc code=end


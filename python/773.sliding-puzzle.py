#
# @lc app=leetcode id=773 lang=python3
#
# [773] Sliding Puzzle
#

# @lc code=start
class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        start = ''.join(str(num) for row in board for num in row)
        target = "123450"

        moves = {
            0: [1, 3],
            1: [0, 2, 4],
            2: [1, 5],
            3: [0, 4],
            4: [1, 3, 5],
            5: [2, 4]
        }

        queue = deque([(start, start.index('0'), 0)])
        visited = {start}

        while queue:
            state, zero, moveCount = queue.popleft()

            if state == target:
                return moveCount

            for move in moves[zero]:
                newState = list(state)
                newState[zero], newState[move] = newState[move], newState[zero]
                newState = ''.join(newState)

                if newState not in visited:
                    visited.add(newState)
                    queue.append([newState, move, moveCount + 1])
        
        return -1
# @lc code=end


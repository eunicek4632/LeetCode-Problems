class Solution(object):

    def getMaximumGold(self, grid):
        
        def dfs(m, n, visited, grid):
            if visited[m][n] == 1 or grid[m][n] == 0:
                return 0
            
            visited[m][n] = 1
            up = down = left = right = 0
            
            if m - 1 >= 0 and visited[m - 1][n] == 0:
                up = dfs(m - 1, n, visited, grid)

            if m + 1 < len(grid) and visited[m + 1][n] == 0:
                down = dfs(m + 1, n, visited, grid)

            if n - 1 >= 0 and visited[m][n - 1] == 0:
                left = dfs(m, n - 1, visited, grid)

            if n + 1 < len(grid[0]) and visited[m][n + 1] == 0:
                right = dfs(m, n + 1, visited, grid)
                
            visited[m][n] = 0       
            return max(up, max(down, max(left, right))) + grid[m][n]     

        visited = [[0 for i in range(len(grid[0]))] for j in range(len(grid))]
    
        max_sum = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] > 0:
                    ret = dfs(i, j, visited, grid)
                    max_sum = max(ret, max_sum)
        
        return max_sum
        
            
# Decisions to make
# where to start
# when to stop
# which one to visit next
# Algorithm: DFS and Backtracking
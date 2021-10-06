class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row = len(matrix)
        # find the correct row
        for i in range(row - 1, -1, -1):
            if target < matrix[i][0]:
                print(matrix[i][0])
                row -= 1
            else:
                break
        row -= 1
        ptr = 0

        # find the correct column
        while ptr < len(matrix[row]):
            print(matrix[row][ptr])
            if target > matrix[row][ptr]:
                ptr += 1
            
            elif target == matrix[row][ptr]:
                return True
            
            else:
                return False    
                
        return False
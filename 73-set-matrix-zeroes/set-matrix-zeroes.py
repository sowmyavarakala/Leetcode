class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return []
        
        rowz = [False] * len(matrix)
        colz = [False] * len(matrix[0])
        
        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                if matrix[row][col] == 0:
                    rowz[row] = True
                    colz[col] = True
        
        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                if rowz[row] or colz[col]:
                    matrix[row][col] =0
        
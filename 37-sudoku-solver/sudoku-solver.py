class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        solve(board)

def solve(board):
    # Traverse the entire board to find an empty cell
    for r in range(9):
        for c in range(9):
            if board[r][c] == '.':
                # Try digits from 1 to 9
                for num in '123456789':
                    if is_valid(board, r, c, num):
                        # Place the number if valid
                        board[r][c] = num
                        
                        # Recursively solve the rest of the board
                        if solve(board):
                            return True
                        
                        # If not solvable, backtrack by removing the number
                        board[r][c] = '.'
                
                # If no number is valid, return False (triggers backtracking)
                return False
    
    # If the entire board is filled correctly, return True
    return True

def is_valid(board, row, col, num):
    # Check if num is already in the row, column, or 3x3 sub-grid
    for i in range(9):
        # Check row
        if board[row][i] == num:
            return False
        # Check column
        if board[i][col] == num:
            return False
        # Check 3x3 box
        if board[(row // 3) * 3 + i // 3][(col // 3) * 3 + i % 3] == num:
            return False
    
    # If the number is valid in all three conditions, return True
    return True

        
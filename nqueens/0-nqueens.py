#!/usr/bin/python3

import sys


def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    if not sys.argv[1].isdigit():
        print("N must be a number")
        sys.exit(1)
    elif int(sys.argv[1]) < 4:
        print("N must be at least 4")
        sys.exit(1)
    else:
        N = int(sys.argv[1])
        solve_nqueens(N)


def solve_nqueens(N):
    board = [[0] * N for _ in range(N)]
    solutions = []
    solve(board, 0, solutions)

    # Print each solution in the required format
    for solution in solutions:
        print(solution)


def solve(board, row, solutions):
    N = len(board)
    if row == N:
        # Extract queen positions from the completed board
        solution = []
        for r in range(N):
            for c in range(N):
                if board[r][c] == 1:
                    solution.append([r, c])
        solutions.append(solution)
        return

    for col in range(N):
        if is_safe(board, row, col):
            board[row][col] = 1
            solve(board, row + 1, solutions)
            board[row][col] = 0


def is_safe(board, row, col):
    N = len(board)

    # Check column
    for i in range(row):
        if board[i][col] == 1:
            return False

    # Check upper-left diagonal
    for i, j in zip(range(row-1, -1, -1), range(col-1, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check upper-right diagonal
    for i, j in zip(range(row-1, -1, -1), range(col+1, N)):
        if board[i][j] == 1:
            return False

    return True


if __name__ == "__main__":
    main()
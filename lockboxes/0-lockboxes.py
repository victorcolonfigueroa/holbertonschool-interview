#!/usr/bin/python3
# /holbertonschool-interview/lockboxes/0-lockboxes.py

"""
Problem:
    You have n number of locked boxes in front of you.
    Each box is numbered sequentially
    from 0 to n - 1 and each box may contain keys to the other boxes.

Task:
    Write a method that determines if all the boxes can be opened.

Prototype: def canUnlockAll(boxes)
boxes is a list of lists
A key with the same number as a box opens that box
You can assume all keys will be positive integers
There can be keys that do not have boxes
The first box boxes[0] is unlocked
Return True if all boxes can be opened, else return False
"""

from typing import List
from collections import deque


def canUnlockAll(boxes: List[List[int]]) -> bool:
    # If boxes is empty I return False because
    # I can't open any boxes
    if not boxes:
        return False

    n = len(boxes)
    visited = [False] * n
    visited[0] = True
    queue = deque(boxes[0])

    while queue:
        key = queue.popleft()
        if 0 <= key < n and not visited[key]:
            visited[key] = True
            queue.extend(boxes[key])

    return all(visited)
#!/usr/bin/python3
def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened using BFS approach.
    
    Args:
        boxes: List of lists where each sublist contains keys to other boxes.
    
    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    n = len(boxes)
    visited = set()
    queue = []
    queue.append(0)
    visited.add(0)
    while queue:
        current_box = queue.pop(0)
        for key in boxes[current_box]:
            if key < n and key not in visited:
                visited.add(key)
                queue.append(key)
    return len(visited) == n
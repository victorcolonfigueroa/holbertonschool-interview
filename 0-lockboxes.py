def canUnlockAll(boxes):

    n= len(boxes)
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
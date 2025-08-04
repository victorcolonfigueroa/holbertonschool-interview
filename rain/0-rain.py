#!/usr/bin/python3
"""
0-rain
"""


def rain(walls):
    """
    Calculate the total amount of rainwater retained after it rains.

    Args:
    walls (list): List of non-negative integers representing wall heights.

    Returns:
    int: Total amount of rainwater retained.
    """
    if not walls:
        return 0

    left = 0
    right = len(walls) - 1
    left_max = 0
    right_max = 0
    water = 0

    while left < right:
        if walls[left] < walls[right]:
            if walls[left] > left_max:
                left_max = walls[left]
            else:
                water += left_max - walls[left]
            left += 1
        else:
            if walls[right] > right_max:
                right_max = walls[right]
            else:
                water += right_max - walls[right]
            right -= 1
    return water
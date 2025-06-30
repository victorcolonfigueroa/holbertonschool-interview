#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n: int) -> int:
    """
    Method that calculates the fewest number of operations
    needed to result in exactly n H characters in the file.

    The approach involves finding the prime factors of the target number.
    The number of operations is then the sum of the prime factors.

    Parameters:
        n (int): The target number of H characters.

    Returns:
        int: The minimum number of operations required.
    """
    # If n is less than or equal to 1,
    # it's not possible to perform any operations
    if n <= 1:
        return 0

    # This variable will keep track of the total number of operations needed
    operations = 0
    # Start checking for factors from 2 (the smallest prime number)
    possibleFactor = 2

    # Continue until we've reduced n to 1 by dividing out all its factors
    while n > 1:
        # If n is divisible by possibleFactor,
        # then possibleFactor is a prime factor of n
        if n % possibleFactor == 0:
            # Divide n by this factor (simulating repeated "Paste"
            # operations after a "Copy All")
            n = n / possibleFactor
            # Add the factor to the operation count
            # (1 "Copy All" + (factor-1)
            # "Paste" operations = factor operations)
            operations += possibleFactor
        else:
            # If not divisible, increment possibleFactor
            # to check the next integer
            # (looking for the next possible factor)
            possibleFactor += 1

    # After the loop, operations contains the sum
    # of all prime factors of the original n
    # This is the minimum number of operations required
    return operations
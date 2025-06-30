#!/usr/bin/python3
"""
UTF-8 Validation Module

This module provides a function to validate if a given data set represents
a valid UTF-8 encoding. The function checks if the sequence of bytes follows
the UTF-8 encoding rules.
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
        data (list): A list of integers representing bytes of data.
                    Each integer should be between 0 and 255.

    Returns:
        bool: True if data is a valid UTF-8 encoding, False otherwise.
    """
    # Number of bytes to process in the current character
    num_bytes = 0

    # Masks for checking the most significant bits
    mask1 = 1 << 7  # 10000000
    mask2 = 1 << 6  # 01000000

    for num in data:
        # Get the 8 least significant bits
        byte = num & 0xFF

        # If we're not processing any bytes, check the first byte
        if num_bytes == 0:
            # Count the number of leading 1s
            mask = 1 << 7
            while mask & byte:
                num_bytes += 1
                mask = mask >> 1

            # Handle invalid cases
            if num_bytes == 0:
                continue  # Single byte character
            if num_bytes == 1 or num_bytes > 4:
                return False  # Invalid UTF-8 sequence
        else:
            # Check if the byte is a valid continuation byte
            if not (byte & mask1 and not (byte & mask2)):
                return False

        num_bytes -= 1

    # If we still have bytes to process, the sequence is incomplete
    return num_bytes == 0
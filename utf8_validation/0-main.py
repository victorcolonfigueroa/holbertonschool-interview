#!/usr/bin/python3
"""
Main file for testing UTF-8 validation
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

# Test case 1: Single byte character
data = [65]
print(validUTF8(data))  # Expected: True

# Test case 2: ASCII string "Python is cool!"
data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))  # Expected: True

# Test case 3: Invalid UTF-8 sequence
data = [229, 65, 127, 256]
print(validUTF8(data))  # Expected: False

# Test case 4: Valid 2-byte character
data = [194, 128]
print(validUTF8(data))  # Expected: True

# Test case 5: Invalid continuation byte
data = [194, 65]
print(validUTF8(data))  # Expected: False

# Test case 6: Incomplete sequence
data = [240, 144, 128]
print(validUTF8(data))  # Expected: False 
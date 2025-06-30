# UTF-8 Validation

This project provides a solution for validating whether a given data set represents a valid UTF-8 encoding.

## Requirements

- Python 3.x

## Usage

The main function to validate UTF-8 data is implemented in `0-validate_utf8.py`.

Example usage:
```python
from 0-validate_utf8 import validUTF8

data = [197, 130, 1]
print(validUTF8(data))  # Output: True
```

## Files

- `0-validate_utf8.py`: Contains the `validUTF8` function.
- `README.md`: Project documentation.

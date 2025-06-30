# Log Parsing

This project contains a Python script that parses logs and computes metrics.

## Description

The script reads lines from standard input, processes log entries, and outputs statistics such as total file size and the number of lines for each HTTP status code.

## Usage

```bash
cat access.log | python3 0-stats.py
```

## Files

- `0-stats.py`: Main script for log parsing.

## Requirements

- Python 3.x

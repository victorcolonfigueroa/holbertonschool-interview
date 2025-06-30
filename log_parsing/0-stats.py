#!/usr/bin/python3

"""
This script reads stdin line by line and computes metrics:
- Input format: <IP Address> - [<date>]
"GET /projects/260 HTTP/1.1" <status code>
  <file size> (if the format is not this one, the line must be skipped)
- After every 10 lines and/or a keyboard interruption (CTRL + C), print these
  statistics from the beginning:
  - Total file size: File size: <total size>
    - where <total size> is the sum of all previous <file size>
    (see input format above)
  - Number of lines by status code:
    - possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
    - if a status code doesn't appear or is not an integer,
    don't print anything for this status code
    - format: <status code>: <number>
    - status codes should be printed in ascending order
"""

import sys


def main():
    total_size = 0
    status_codes = {
        200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0
    }
    line_count = 0

    try:
        for line in sys.stdin:
            line = line.strip()
            parts = line.split()
            if len(parts) < 2:
                continue  # Skip lines that don't have at least two fields
            status_code = parts[-2]
            file_size = parts[-1]
            line_count += 1
            try:
                total_size += int(file_size)
                if status_code.isdigit():
                    code = int(status_code)
                    if code in status_codes:
                        status_codes[code] += 1
            except Exception:
                pass  # Skip lines with invalid status code or file size

            if line_count % 10 == 0:
                print("File size: {}".format(total_size))
                for code in sorted(status_codes.keys()):
                    if status_codes[code] > 0:
                        print("{}: {}".format(code, status_codes[code]))
    except KeyboardInterrupt:
        pass
    finally:
        print("File size: {}".format(total_size))
        for code in sorted(status_codes.keys()):
            if status_codes[code] > 0:
                print("{}: {}".format(code, status_codes[code]))


if __name__ == "__main__":
    main()
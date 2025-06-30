#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers
 * @line: Points to an array of integers
 * @size: Number of elements in @line
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, pos;
    int merged = 0;

    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);

    /* Handle left movement */
    if (direction == SLIDE_LEFT)
    {
        /* Move all non-zero numbers to the left */
        for (i = 0, pos = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (pos != i)
                {
                    line[pos] = line[i];
                    line[i] = 0;
                }
                pos++;
            }
        }

        /* Merge identical adjacent numbers */
        for (i = 0; i < size - 1; i++)
        {
            if (line[i] != 0 && line[i] == line[i + 1])
            {
                line[i] *= 2;
                line[i + 1] = 0;
                merged = 1;
            }
        }

        /* Move all non-zero numbers to the left again after merging */
        if (merged)
        {
            for (i = 0, pos = 0; i < size; i++)
            {
                if (line[i] != 0)
                {
                    if (pos != i)
                    {
                        line[pos] = line[i];
                        line[i] = 0;
                    }
                    pos++;
                }
            }
        }
    }
    /* Handle right movement */
    else
    {
        /* Move all non-zero numbers to the right */
        for (i = size - 1, pos = size - 1; i < size; i--)
        {
            if (line[i] != 0)
            {
                if (pos != i)
                {
                    line[pos] = line[i];
                    line[i] = 0;
                }
                pos--;
            }
        }

        /* Merge identical adjacent numbers */
        for (i = size - 1; i > 0; i--)
        {
            if (line[i] != 0 && line[i] == line[i - 1])
            {
                line[i] *= 2;
                line[i - 1] = 0;
                merged = 1;
            }
        }

        /* Move all non-zero numbers to the right again after merging */
        if (merged)
        {
            for (i = size - 1, pos = size - 1; i < size; i--)
            {
                if (line[i] != 0)
                {
                    if (pos != i)
                    {
                        line[pos] = line[i];
                        line[i] = 0;
                    }
                    pos--;
                }
            }
        }
    }

    return (1);
}
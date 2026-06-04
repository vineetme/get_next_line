#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *line;

    // Pass 0 directly into the function
    while ((line = get_next_line(0)) != NULL)
    {
        printf("GNL Output: %s", line);
        free(line); // Clean memory after printing
    }
    return (0);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_word.h"

int get_word(char *buf, int size, FILE *stream)
{
    if(fgets(buf,size,stream) == NULL)
    {
        return EOF;
    }
    buf[strlen(buf) - 1] = 0;
    return 1;
}

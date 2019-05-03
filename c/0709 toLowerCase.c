#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char * toLowerCase(char * str){
    if(str == NULL)
        return NULL;
    char * s = str;
    while(*str)
    {
        if( (*str <= 90) &&(*str >= 65) )
            *str +=32;
        str++;
    }
    return s;
}

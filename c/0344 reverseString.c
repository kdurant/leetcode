#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

void reverseString(char* s, int sSize) {
    char *n = (char *)malloc(sizeof(char)*sSize);
    for(size_t i = sSize; i > 0; i--)
    {
        n[sSize-i] = s[i-1];
    }
  
    memcpy(s, n , sSize);
    free(n);
}

int main()
{
    // int nums[] = {0,11,0,3};
    char nums1[] = {'a', 'b', 'c', 'd'};
    reverseString(nums1, 4);
    for(size_t i = 0; i < 4; i++)
    {
        printf("%c ", nums1[i]);
    }
    return 0;
} 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char ** letterCasePermutation(char * S, int* returnSize){
    char * save = S;
    int ch_num = 0;
    while(*S != '\0')
    {
        if(isalpha(*S))
            ch_num++;
        S++;
    }
    int n = pow(2, ch_num);
    char **result = malloc(sizeof(char*) * n);

    for (size_t i = 0; i < n; i++)
    {
        result[i] = malloc(sizeof(char)*(strlen(S)+1));
    }
    
    int row = 0;
    int idx = 0;
    S = save;
    while(*S != '\0')
    {
        if(isalpha(*S))
        {
            strcpy(result[row++], save);
            strcpy(result[row], save);
            if((*S >= 'a') && (*S <= 'z'))
                result[row][idx] = *S-0x20;
            else
                result[row][idx] = *S+0x20;
            row++;
        }
        S++;
        idx++;
    }
    *returnSize = n;
    return result;
}


int main()
{
    int size;
    char *s = "a1b2";
#if 0
    char *s1 = "123111ddddddddddddd1111111111";
    char **r = &s1;
    printf("%d\n", r);
    printf("%d\n", r+1);
#else
    
    char ** r = letterCasePermutation(s, &size);
    printf("%p\n", r);
    printf("%p\n", r+1);
    for (size_t i = 0; i < size; i++)
    {
        printf("%s\n", *(r+i));
    }
#endif



    

    
    return 0;
} 
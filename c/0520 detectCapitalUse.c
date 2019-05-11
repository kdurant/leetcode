#include <stdio.h>
#include <stdbool.h>

bool detectCapitalUse(char * word){
    int mode;
    if( (*word >= 'A') && (*word <= 'Z') )
    {
        if( (*(word+1) >= 'A') && (*(word+1) <= 'Z') )
            mode = 1;
        else
            mode = 3;
    }
    else
        mode = 2;
    
    word++;

    while(*word)
    {
        if(mode == 1)
        {
            if( (*word >= 'A') && (*word <= 'Z') )
                word++;
            else
                return false;
        }
        else if( (mode == 2) || (mode == 3) )
        {
            if( (*word >= 'a') && (*word <= 'z') )
                word++;
            else
                return false;            
        }
    }
    return true;
}

int main()
{
    printf("%d\n", detectCapitalUse("FlaG"));
}
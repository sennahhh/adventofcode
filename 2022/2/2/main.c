#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
    char buf[1024];
    FILE* fp;
    int tot = 0;

    fp = fopen("../input2.txt", "r");

    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        if(buf[0] == 'A')
        {
            if(buf[2] == 'X')
            {
                tot += 3;
            } else if(buf[2] == 'Y') 
            {
                tot += 1 + 3;
            } else 
            {
                tot += 2 + 6;
            }
        } else if (buf[0] == 'B')
        {
            if(buf[2] == 'X')
            {
                tot += 1;
            } else if(buf[2] == 'Y') 
            {
                tot += 2 + 3;
            } else 
            {
                tot += 3 + 6;
            }
        } else
        {
            if(buf[2] == 'X')
            {
                tot += 2;
            } else if(buf[2] == 'Y') 
            {
                tot += 3 + 3;
            } else 
            {
                tot += 1 + 6;
            }
        }
    }

    fclose(fp);

    printf("%d\n", tot);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
    FILE* fp;
    char buf[1024];
    int tot = 0;

    fp = fopen("../input3.txt", "r");

    while(fgets(buf, sizeof(buf), fp) != NULL)
    {   
        int len = strlen(buf);
        char common_item;
   
        for(int i = 0; i < len / 2; i++)
        {
            for(int j = len / 2; j < len; j++)
            {
                if(buf[i] == buf[j])
                {
                    common_item = buf[i];
                }
            }
        }

        if(common_item < 97)
        {
            tot += common_item - 38;
        } else {
            tot += common_item - 96;
        }

    }

    fclose(fp);

    printf("%d\n", tot);

    return 0;
}
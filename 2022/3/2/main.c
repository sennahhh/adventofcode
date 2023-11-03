#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*
buf2malloc(char b[1024])
{
    char* ptr;
    ptr = (char*) malloc(1024);
    for(int i = 0; i < 1024; i++)
    {
        ptr[i] = b[i];
    }

    return ptr;
}

int
main(void)
{
    FILE* fp;
    char buf[1024];
    char* r[3];
    int counter = 0;
    int tot = 0;

    fp = fopen("../input3.txt", "r");

    while(fgets(buf, sizeof(buf), fp) != NULL)
    {   
        if(counter < 2)
        {
            r[counter] = buf2malloc(buf);
            counter++;
        } else
        {   
            r[counter] = buf2malloc(buf);

            int len[] = {strlen(r[0]), strlen(r[1]), strlen(r[2])};

            char common_item;

            for(int i = 0; i < len[0]; i++)
            {
                for(int j = 0; j < len[1]; j++)
                {
                    if(r[0][i] > 64 && r[0][i] == r[1][j])
                    {
                        for(int x = 0; x < len[2]; x++)
                        {
                            if(r[0][i] == r[2][x])
                            {
                                common_item = r[0][i];
                            }
                        }
                    }
                }
            }

            if(common_item < 97)
            {
                tot += common_item - 38;
            } else {
                tot += common_item - 96;
            }

            counter = 0;
        }
    }

    fclose(fp);

    printf("%d\n", tot);

    return 0;
}
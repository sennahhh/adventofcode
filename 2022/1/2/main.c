#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
    FILE* fp;
    int cals = 0;
    int top_3_cals[] = {0, 0, 0};
    char buf[1024];

    fp = fopen("../input1.txt", "r");

    while(fgets(buf, sizeof(buf), fp))
    {
        if(strcmp(buf, "\n") != 0)
        {
            cals += atoi(buf);
        } else {
            int temp1 = 0;
            int temp2 = 0;
            for(int i = 0; i < 3; i++)
            {
                if(cals > top_3_cals[i])
                {
                    temp1 = top_3_cals[i];
                    top_3_cals[i] = cals;
                    if(i == 2)
                    {
                        temp2 = top_3_cals[1];
                        top_3_cals[1] = temp1;
                        top_3_cals[0] = temp2;
                    } else if(i == 1) {
                        top_3_cals[0] = temp1;
                    }
                }
            }
            cals = 0;
        }
    }
    fclose(fp);
    printf("%d\n", top_3_cals[0] + top_3_cals[1] + top_3_cals[2]);
    return 0;
}
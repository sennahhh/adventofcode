#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
    FILE* fp;
    char buf[1024];
    int tot = 0;

    fp = fopen("../input.txt", "r");

    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        int len = strlen(buf);
        char to_become_num[2];
        int intervals[4];
        int j = 0;
        int x = 0;

        for(int i = 0; i < len; i++)
        {
            if(i == len - 1)
            {
                to_become_num[x] = buf[i];
                intervals[j] = atoi(to_become_num);
            } else if(buf[i] != '-' || buf[i] != ',')
            {
                to_become_num[x] = buf[i];
                x++;
            } else
            {
                intervals[j] = atoi(to_become_num);
                x = 0;
                j++;
            }
            
        }
        printf("%d\n", intervals[3]);
        int start_interval = intervals[0] - intervals[2];
        int end_interval = intervals[1] - intervals[3];

        if(start_interval >= 0 && end_interval <= 0)
        {
            tot++;
        } else if(start_interval <= 0 && end_interval >= 0)
        {
            tot++;
        }
    }

    printf("%d\n", tot);

    return 0;
}
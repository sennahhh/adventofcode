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
            if(buf[i] == '-' || buf[i] == ',')
            {
                if(x == 1)
                {
                    intervals[j] = to_become_num[0] - 48;
                } 
                else
                {
                    intervals[j] = ((to_become_num[0] - 48) * 10) + (to_become_num[1] - 48);
                }
                
                j++;
                x = 0;
            } 
            else if(i == (len - 1))
            {
                to_become_num[x] = buf[i];
                x++;

                if(x == 1)
                {
                    intervals[j] = to_become_num[0] - 48;
                } 
                else
                {
                    intervals[j] = ((to_become_num[0] - 48) * 10) + (to_become_num[1] - 48);
                }
            } 
            else
            {
                to_become_num[x] = buf[i];
                x++;
            }
        }

        if((intervals[1] >= intervals[2] && intervals[0] <= intervals[3]) || (intervals[3] >= intervals[0] && intervals[2] <= intervals[1]))
        {
            tot++;
        }
    }

    printf("%d\n", tot);

    return 0;
}
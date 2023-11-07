#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int start;
    int end;
}Interval;

int
get_num_of_intervals(FILE* fp)
{
    int num = 0;
    char buf[1024];

    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        num++;
    }
    
    rewind(fp);
    num *= 2;
    return num;
}

int
main(void)
{
    FILE* fp;
    char buf[1024];
    int tot = 0;
    
    fp = fopen("../input.txt", "r");

    int num_of_intervals = get_num_of_intervals(fp);

    Interval intervals[num_of_intervals];
    int counter = 0;

    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        int len = strlen(buf);
        char to_become_num[2];
        int x = 0;

        for(int i = 0; i < len; i++)
        {
            if(buf[i] == '-')
            {
                if(x == 1)
                {
                    intervals[counter].start = to_become_num[0] - 48;
                } 
                else
                {
                    intervals[counter].start = ((to_become_num[0] - 48) * 10) + (to_become_num[1] - 48);
                }
                
                x = 0;
            } else if(buf[i] == ',' || i == (len - 1))
            {
                if(x == 1)
                {
                    intervals[counter].end = to_become_num[0] - 48;
                } 
                else
                {
                    intervals[counter].end = ((to_become_num[0] - 48) * 10) + (to_become_num[1] - 48);
                }
                counter++;
            }
            else
            {
                to_become_num[x] = buf[i];
                x++;
            }
        }

        // int start_interval = intervals[0] - intervals[2];
        // int end_interval = intervals[1] - intervals[3];

        // if(start_interval >= 0 && end_interval <= 0)
        // {
        //     tot++;
        // } else if(start_interval <= 0 && end_interval >= 0)
        // {
        //     tot++;
        // }
    }

    printf("%d\n", tot);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
    FILE* fp;
    int temp_cals = 0;
    int most_cals = 0;
    char buf[1024];

    fp = fopen("../input.txt", "r");

    while(fgets(buf, sizeof(buf), fp))
    {
        if(strcmp(buf, "\n") != 0)
        {
            temp_cals += atoi(buf);
        } else {
            if(most_cals < temp_cals) 
            {
                most_cals = temp_cals;
            }
            temp_cals = 0;
        }
    }
    fclose(fp);
    printf("%d\n", most_cals);

    return 0;
}
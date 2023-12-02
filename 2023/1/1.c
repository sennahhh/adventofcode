#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fp;
    fp = fopen("./input.txt", "r");
    char buf[1024];
    int tot = 0;

    while(fgets(buf, sizeof(buf), fp) != NULL) {
        int num1 = -1;
        int num2 = -1;
        int num;
        int position = 0;
        int len = strlen(buf);
        for(int i = 0; i < len; i++) {
            if(buf[i] < 58 && buf[i] > 47) {
                if(position == 0) {
                    num1 = buf[i] - 48;
                    position++;
                } else {
                    num2 = buf[i] - 48;
                }
            } 
        }

        if(num2 == -1) {
            num = 10 * num1 + num1;
        } else {
            num = 10 * num1 + num2;
        }
        
        tot += num;
    }

    printf("%d\n", tot);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char* name;
    int value;
} number;

int check_for_substring(char* str, char* sub_str, int start_index) {
    int len = strlen(sub_str);
    for(int i = start_index, j = 0; j < len; i++, j++) {
        if(str[i] != sub_str[j]) {
            return FALSE;
        }
    }
    return TRUE;
}

int main(void) {
    FILE *fp;
    fp = fopen("./input.txt", "r");
    char buf[1024];
    number numbers[9] = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    int tot = 0;

    while(fgets(buf, sizeof(buf), fp) != NULL) {
        int first_num = 0;
        int last_num = 0;
        int len = strlen(buf);
        for(int i = 0; i < len; i++) {
            if(buf[i] > '0' && buf[i] <= '9') {
                if(first_num == 0) {
                    first_num = buf[i] - '0';
                    continue;
                }
                last_num = buf[i] - '0';
            } else {
                for(int j = 0; j < 9; j++) {
                    if(check_for_substring(buf, numbers[j].name, i)) {
                        if(first_num == 0) {
                            first_num = numbers[j].value;
                            continue;
                        }
                        last_num = numbers[j].value;
                    }
                }
            }
        }
        last_num = last_num ? last_num : first_num;
        tot += 10 * first_num + last_num;
    }

    printf("%d\n", tot);

    return 0;
}
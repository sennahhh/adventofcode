#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char* name;
    int value;
} color;

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
    char buf[1024];
    fp = fopen("./input.txt", "r");
    color colors[3] = {{"red", 12}, {"green", 13}, {"blue", 14}}; 
    int tot = 0;

    while(fgets(buf, sizeof(buf), fp) != NULL) {
        int ID = (buf[6] >= '0' && buf[6] <= '9') ? (buf[5] - '0') * 10 + (buf[6] - '0') : (buf[5] - '0');
        ID = (buf[7] >= '0' && buf[7] <= '9') ? 100 : ID;

        int len = strlen(buf);
        for(int i = 8; i < len; i++) {
            int num = 0;
            if(buf[i] >= '0' && buf[i] <= '9') {
                num = (buf[i + 1] >= '0' && buf[i + 1] <= '9') ? (buf[i] - '0') * 10 + (buf[i + 1] - '0') : (buf[i] - '0');

                for(int j = 0; j < 3; j++) {
                    if(check_for_substring(buf, colors[j].name, (num > 9) ? i + 3 : i + 2)) {
                        ID = (colors[j].value >= num) ? ID : 0;
                    }
                }
                i += 3;
            }
        }
        tot += ID;

    }

    printf("%d\n", tot);

    return 0;
}
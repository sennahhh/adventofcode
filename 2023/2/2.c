#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char *name;
    int list[10];
    int list_index;
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

void sort_list(int *list, int len) {
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len - 1; j++) {
            if(*(list + j) > *(list + j + 1)) {
                int temp = *(list + j + 1);
                *(list + j + 1) = *(list + j);
                *(list + j) = temp;
            }
        }
    }
}

int main(void) {
    FILE *fp;
    char buf[1024];
    fp = fopen("./input.txt", "r");
    int tot = 0;

    while(fgets(buf, sizeof(buf), fp) != NULL) {
        color colors[3] = {{"red"}, {"green"}, {"blue"}};
        int num = 1;

        int len = strlen(buf);
        for(int i = 8; i < len; i++) {
            int num = 0;
            if(buf[i] >= '0' && buf[i] <= '9') {
                num = (buf[i + 1] >= '0' && buf[i + 1] <= '9') ? (buf[i] - '0') * 10 + (buf[i + 1] - '0') : (buf[i] - '0');

                for(int j = 0; j < 3; j++) {
                    if(check_for_substring(buf, colors[j].name, (num > 9) ? i + 3 : i + 2)) {
                        colors[j].list[colors[j].list_index++] = num;
                    }
                }
                i += 3;
            }
        }

        for(int i = 0; i < 3; i++) {
            sort_list(colors[i].list, 10);
            num *= colors[i].list[9];
        }
        tot += num;
        
    }

    printf("%d\n", tot);


    return 0;
}
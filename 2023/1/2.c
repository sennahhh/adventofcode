#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int value;
} number;

typedef struct {
    int index;
    int value;
} pointerarr_object;

int main(void) {
    FILE *fp;
    fp = fopen("./input.txt", "r");
    char buf[1024];
    number numbers[10] = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    int tot = 0;

    int yeah = 0;

    while(fgets(buf, sizeof(buf), fp) != NULL) {
        pointerarr_object num_pointer_arr[30];
        size_t len = strlen(buf);
        int j = 0;
        int num = 0;
        
        //number words
        for(int i = 0; i < 10; i++) {
            char* ret = NULL;
            char* temp_buf = buf;
            while((ret = strstr(temp_buf, numbers[i].name)) != NULL) {
                num_pointer_arr[j].index = ret - temp_buf;
                // printf("%d\n", num_pointer_arr[j].index);
                num_pointer_arr[j].value = numbers[i].value;
                temp_buf = ret + 1;
                j++;
            }
        }

        //number values
        for(int i = 0; i < len; i++) {
            if(buf[i] < 58 && buf[i] > 47) {
                num_pointer_arr[j].index = i;
                num_pointer_arr[j].value = buf[i] - 48;
                j++;       
            }
        }

        //sorting ish
        for(int i = 0; i <= j; i++) {
            for(int x = 0; x <= j - 1; x++) {
                if(num_pointer_arr[x].index > num_pointer_arr[x + 1].index) {
                    pointerarr_object temp = {num_pointer_arr[x + 1].index, num_pointer_arr[x + 1].value};
                    // printf("%d %d %d %d\n", num_pointer_arr[x + 1].index, num_pointer_arr[x + 1].value, temp.index, temp.value);
                    // printf("1: %d %d %d %d\n", num_pointer_arr[x + 1].index, num_pointer_arr[x + 1].value, num_pointer_arr[x].index, num_pointer_arr[x].value);
                    num_pointer_arr[x + 1].index = num_pointer_arr[x].index;
                    num_pointer_arr[x + 1].value = num_pointer_arr[x].value;
                    // printf("2: %d %d %d %d\n", num_pointer_arr[x + 1].index, num_pointer_arr[x + 1].value, num_pointer_arr[x].index, num_pointer_arr[x].value);
                    num_pointer_arr[x].index = temp.index;
                    num_pointer_arr[x].value = temp.value;
                    // printf("3: %d %d %d %d\n", num_pointer_arr[x + 1].index, num_pointer_arr[x + 1].value, num_pointer_arr[x].index, num_pointer_arr[x].value);
                }
            }
        }
        // for(int i = 0; i <= j; i++) {
        //     printf("%d: %d\n", yeah, num_pointer_arr[i].index);
        // }

       
        num = 10 * num_pointer_arr[0].value + num_pointer_arr[j].value;
        printf("%s", buf);
        printf("%d\n", num);
        tot += num;     
        yeah++;
        
    }

    printf("%d\n", tot);

    return 0;
}
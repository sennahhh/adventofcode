#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int value;
} number;

typedef struct {
    char* p;
    int value;
} pointerarr_object;

int main(void) {
    FILE *fp;
    fp = fopen("./input.txt", "r");
    char buf[1024];
    number numbers[10] = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    int tot = 0;

    while(fgets(buf, sizeof(buf), fp) != NULL) {
        pointerarr_object num_pointer_arr[20];
        size_t len = strlen(buf);
        int j = 0;
        int x = 0;
        int num1 = -1;
        int num2 = -1;
        int num = 0;
        
       //number words
       for(int i = 0; i < 10; i++) {
            char* ret = NULL;
            char* temp_buf = buf;
            while((ret = strstr(temp_buf, numbers[i].name)) != NULL) {
                num_pointer_arr[j].p = ret;
                num_pointer_arr[j].value = numbers[i].value;
                temp_buf = ret + 1;
                j++;
            }
       }

        //number values
       for(int i = 0; i < len; i++) {
            if(buf[i] < 58 && buf[i] > 47) {
                num_pointer_arr[j].p = &buf[i];
                num_pointer_arr[j].value = buf[i] - 48;
                j++;       
            }
       }

        //value
        for(int i = 0; i < len; i++) {
            for(int y = 0; y <= j; y++) {
                if(&buf[i] == num_pointer_arr[y].p) {
                    if(x < 1) {
                        num1 = num_pointer_arr[y].value;
                        x++;
                    } else {
                        num2 = num_pointer_arr[y].value;
                    }
                    
                }
            }
       }

        if(num2 == -1) {
            num = 10 * num1 + num1;
        } else {
            num = 10 * num1 + num2;
        }
        // printf("%s", buf);
        // printf("%d\n", num);
        tot += num;     
        
    }

    printf("%d\n", tot);

    return 0;
}
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp;
    fp = fopen("./input.txt", "r");
    char buf[1024];
    int tot = 0;

    char **map = (char**)malloc(1000 * sizeof(char *));
    for(int i = 0; i < 1000; i++) {
        map[i] = (char *)malloc(1024 * sizeof(char));
    }
    
    int i = 0;
    while(fgets(buf, sizeof(buf), fp) != NULL) {
        map[i++] = buf; 
    }



    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    if(argc < 3) {
        printf("To few arguments");
        return 1;
    }

    FILE* src = fopen(argv[1], "r");
    if(src == NULL) {
        printf("src* is NULL");
        return 1;
    }
    FILE* dest = fopen(argv[2], "w");
    if(dest == NULL) {
        printf("dest* is NULL");
        return 1;
    }

    char* vrstica = (char*) malloc(1000000 * sizeof(char));
    char* najdalsaVrstica = NULL;
    int biggestLength = 0;
    int length = 0;
    
    while(fgets(vrstica, 1000000, src) != NULL) {
        length = strlen(vrstica);
        if(length > biggestLength) {
            biggestLength = length;
            free(najdalsaVrstica);
            najdalsaVrstica = (char*) malloc((length+1) * sizeof(char));
            strncpy(najdalsaVrstica, vrstica, length+1);
            najdalsaVrstica[length] = '\0';
        }
    }
    fprintf(dest, "%s", najdalsaVrstica);


    free(vrstica);
    free(najdalsaVrstica);
    fclose(src);
    fclose(dest);
    return 0;
}
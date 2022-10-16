#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    char** paths = (char**) malloc(n * sizeof(char*));
    for(int i = 0; i < n; i++) {
        paths[i] = (char*) malloc(100 * sizeof(char));
        scanf("%s", paths[i]);
    }

    FILE** srcFiles = (FILE**) malloc(n * sizeof(FILE*));
    for(int i = 0; i < n; i++) {
        srcFiles[i] = fopen(paths[i], "r");
        if(srcFiles[i] == NULL) {
            printf("Source file NULL");
            return 1;
        }
    }
    char* destPath = malloc(100 * sizeof(char));
    scanf("%s", destPath);
    FILE* dest = fopen(destPath, "w");
    if(dest == NULL) {
        printf("Destination file NULL");
        return 1;
    }

    int* arr = (int*) calloc(n, sizeof(int));
    int writtenIndex = -1;

    for(int i = 0; i < n; i++) {
        if(arr[i] != -1) {
            int res = fscanf(srcFiles[i], "%d", &arr[i]);
            if(res < 1) arr[i] = -1;
        }
    }

    while(1) {
        if(writtenIndex != -1) {
            int res = fscanf(srcFiles[writtenIndex], "%d", &arr[writtenIndex]);
            if(res < 1) arr[writtenIndex] = -1;
        }

        int currentlySmallest = INT_MAX;
        writtenIndex = 0;        
        for(int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
            if(arr[i] != -1) {
                if(arr[i] < currentlySmallest && arr[i] != -1) {
                    currentlySmallest = arr[i];
                    writtenIndex = i;
                }
            }
        }
        printf("\n");
        if(currentlySmallest == INT_MAX) break;
        fprintf(dest, "%d\n", currentlySmallest);

    }

    // int a = 0;
    // while(fscanf(srcFiles[0], "%d", &a) != EOF) {
    //     printf("%d ", a);
    // }


    for(int i = 0; i < n; i++) {
        free(paths[i]);
    }
    free(paths);
    for(int i = 0; i < n; i++) {
        fclose(srcFiles[i]);
    }
    free(srcFiles);
    fclose(dest);
    return 0;
}
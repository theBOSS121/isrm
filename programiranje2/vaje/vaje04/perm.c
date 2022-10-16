#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// void printArr(bool* a, int n) {
//     for(int i = 0; i < n; i++) {
//         printf("%s, ", a[i] ? "true" : "false");
//     }
//     printf("\n");
// }

int main() {
    int n;
    scanf("%d", &n);
    
    bool* arr = (bool*) calloc(n, sizeof(bool));

    int index = -1;
    bool ok = true;
    for(int i = 0; i < n; i++) {
        scanf("%d", &index);
        if(index < 0 || index >= n || arr[index]) {
            ok = false;
            break;
        }
        // printArr(arr, n);
        arr[index] = true;
    }

    if(ok) printf("DA");
    else printf("NE");

    return 0;
}
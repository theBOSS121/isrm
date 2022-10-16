#include <stdio.h>
#include <stdlib.h>

int vsote(int n, int k) {
    if(n == 0) return 1;
    if(k == 0) return 0;
    if(n < 0) return 0;

    int kk = k-1;
    return vsote(n-k, k) + vsote(n, kk);
}

void vsote2(int n, int k, int* arr, int index) {
    if(n == 0) {
        for(int i = 0; i < index; i++) {
            if(i != 0) printf("+ ");
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    if(k == 0) return;
    if(n < 0) return;

    arr[index] = k;
    vsote2(n-k, k, arr, index+1);
    vsote2(n, k-1, arr, index);
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", vsote(n, k));

    int* arr = calloc(n, sizeof(int));
    vsote2(n, k, arr, 0);
}
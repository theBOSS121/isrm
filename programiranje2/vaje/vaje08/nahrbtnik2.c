#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int najvecjaCena(int volume, int n, int* v, int* c, int index, bool hasOneOdd, int* memo) {
    if(index == n) return 0;
    if(volume <= 0) return 0;

    if(memo[index + volume * n] > 0) return memo[index + volume * n];

    int cena = najvecjaCena(volume, n, v, c, index+1, hasOneOdd, memo);
    int with = 0;
    if(volume - v[index] >= 0 && (!hasOneOdd || v[index] % 2 == 0)) {
        if(v[index] % 2 == 1) hasOneOdd = true;
        with = c[index] + najvecjaCena(volume-v[index], n, v, c, index+1, hasOneOdd, memo);
    }
    if(cena < with) cena = with;
    memo[index + volume * n] = cena;
    return cena;
}

int main() {
    int volume, n;
    scanf("%d%d", &volume, &n);
    int* v = (int*) malloc(n * sizeof(int));
    int* c = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // printf("Volume: %d\n", volume);
    // printf("Number of stuff: %d\n", n);
    // for(int i = 0; i < n; i++) {
    //     printf("v[%d]=%d, c[%d]=%d\n", i, v[i], i, c[i]);
    // }

    int* memo = (int*) calloc(n*(volume+1), sizeof(int));

    int price = najvecjaCena(volume, n, v, c, 0, false, memo);
    printf("%d\n", price);

    free(v);
    free(c);
    return 0;
}
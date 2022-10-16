
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"
#define N 1000

int globalna[N];

int vsota(int* zac, int* kon) {
    int* p = zac;
    int sum = *p;
    while(p != kon) {
        p++;
        sum += *p;
    }

    return sum;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
    if(*indeks == -1) {
        *indeks = *kazalec - t;
    }else {
        *kazalec = &t[*indeks];
    }
}

void frekvenceCrk(char* niz, int** frekvence) {
    int n = 'z'-'a';
    int* freq = calloc(n, sizeof(int));
    int i = 0;
    while(niz[i] != '\0') {
        if(niz[i] >= 'a' && niz[i] <= 'z') freq[niz[i]-'a']++;
        if(niz[i] >= 'A' && niz[i] <= 'Z') freq[niz[i]-'A']++;
        i++;
    }
    *frekvence = freq;
}

int main() {
    int* frekvence;
    frekvenceCrk("O VrBa! sRecNa, dRAgA vaS DomACa", &frekvence);
    for (int c = 'A';  c <= 'Z';  c++) {
        if (frekvence[c - 'A'] > 0) {
            printf("%c -> %d\n", c, frekvence[c - 'A']);
        }
    }

    free(frekvence);

    return 0;
}

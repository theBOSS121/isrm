
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

// struct Vozlisce {
//     int podatek;
//     Vozlisce* naslednje;
// };

int vsotaI(Vozlisce* zacetek) {
    if(zacetek == NULL) return 0;
    Vozlisce* p = zacetek;
    int sum = zacetek->podatek;
    while(p->naslednje != NULL) {
        p = p->naslednje;
        sum += p->podatek;
    }
    return sum;
}

int vsotaR(Vozlisce* zacetek) {
    if(zacetek == NULL) return 0;
    if(zacetek->naslednje == NULL) return zacetek->podatek;
    return zacetek->podatek + vsotaR(zacetek->naslednje);
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    Vozlisce* v = (Vozlisce*) malloc(sizeof(Vozlisce));
    v->podatek = element;
    v->naslednje = NULL;
    if(zacetek == NULL) {
        return v;
    }else {
        if(element < zacetek->podatek) {
            v->naslednje = zacetek;
            return v;
        }else {
            Vozlisce* p = zacetek;
            while(p->naslednje != NULL && element > p->naslednje->podatek) {
                p = p->naslednje;
            }
            v->naslednje = p->naslednje;
            p->naslednje = v;

            return zacetek;
        }
    }    
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
    if(zacetek == NULL) {
        Vozlisce* v = (Vozlisce*) malloc(sizeof(Vozlisce));
        v->podatek = element;
        v->naslednje = NULL;
        return v;
    }else {
        if(element < zacetek->podatek) {
            Vozlisce* v = (Vozlisce*) malloc(sizeof(Vozlisce));
            v->podatek = element;
            v->naslednje = zacetek;
            return v;
        }
        zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);
    }
    return zacetek;
}



char NIZ[1000];

Vozlisce* zgradi(int* t) {
    Vozlisce* zacetek = NULL;
    Vozlisce* prejsnje = NULL;
    int* p = t;

    while (*p != INT_MAX) {
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->podatek = *p;
        novo->naslednje = NULL;
        if (p == t) {
            zacetek = novo;
        } else {
            prejsnje->naslednje = novo;
        }
        prejsnje = novo;
        p++;
    }
    return zacetek;
}

void pocisti(Vozlisce* v) {
    if (v != NULL) {
        pocisti(v->naslednje);
        free(v);
    }
}

char* vNiz(Vozlisce* zacetek) {
    char* pNiz = NIZ;
    *pNiz++ = '[';
    Vozlisce* v = zacetek;
    while (v != NULL) {
        if (v != zacetek) {
            pNiz += sprintf(pNiz, ", ");
        }
        pNiz += sprintf(pNiz, "%d", v->podatek);
        v = v->naslednje;
    }
    sprintf(pNiz, "]");
    return NIZ;
}

void testiraj(Vozlisce* v, int element) {
    printf("%s", vNiz(v));
    v = vstaviUrejenoR(v, element);
    printf(" + %d -> %s\n", element, vNiz(v));
    pocisti(v);
}

int main() {
    testiraj(zgradi((int[]) {6, 10, 15, INT_MAX}), 20);

    testiraj(zgradi((int[]) {5, 13, 20, 34, 48, 60, INT_MAX}), 70);

    testiraj(zgradi((int[]) {42, INT_MAX}), 50);

    testiraj(zgradi((int[]) {-30, -20, -10, INT_MAX}), -5);
    testiraj(zgradi((int[]) {-30, -20, -10, INT_MAX}), 0);

    testiraj(zgradi((int[]) {INT_MAX}), 0);
    testiraj(zgradi((int[]) {INT_MAX}), -33);
    testiraj(zgradi((int[]) {INT_MAX}), 42);


    return 0;
}

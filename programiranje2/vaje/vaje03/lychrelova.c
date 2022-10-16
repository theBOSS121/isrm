#include <stdio.h>
#include <stdbool.h>

unsigned long long mirrored(unsigned long long n) {
    unsigned long long num = 0;

    while(n > 0) {
        num *= 10;
        num += n % 10;
        n /= 10;
    }
    return num;
}

bool palindrom(unsigned long long n) {
    if(n == mirrored(n)) return true;
    else return false;
}

bool lychrelovo(unsigned long long n, int k) {
    for(int i = 0; i < k; i++) {
        n += mirrored(n);
        if(palindrom(n)) {
            return false; 
        }
    }
    return true;
}

int countLychrelov(int k, int a, int b) {
    int counter = 0;

    for(int i = a; i < b; i++) {
        if(lychrelovo(i, k)) {
            counter++;
            printf("%d\n", i);
        } 
    }

    return counter;
}

int main() {
    int k;
    int a;
    int b;
    scanf("%d%d%d", &k, &a, &b);

    int numOfLychrelov = countLychrelov(k, a, b);
    printf("%d\n", numOfLychrelov);


    return 0;
}
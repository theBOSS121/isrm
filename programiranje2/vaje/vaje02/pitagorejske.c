#include <stdio.h>

int find(int a, int b);


int main() {
    int n, m;

    scanf("%d%d", &n, &m);
    
    printf("Number of pitagoras numbers: %d\n", find(n, m));
    return 0;
}

int find(int a, int b) {
    int counter = 0;
    int c2 = 0;
    for(int k = a; k < b+1; k++) {
        c2 = k*k;
        for(int i = 2; i < b+1; i++) {
            for(int j = i; j < b+1; j++) {
                if(i*i + j*j > c2) break;
                if(i * i + j * j == c2) {
                    counter++;
                    printf("%d^2 + %d^2 = %d^2\n", i, j, k);
                }
            }
        }
    }

    return counter;
}

#include <stdio.h>
#include <math.h>

int sumOfDeviders(int n) {
    int sum = 1;

    int sqrtOfn = (int) (sqrt(n)) + 1;
    for(int i = 2; i < sqrtOfn; i++) {
        if(n % i == 0) {
            // printf("%d\n", i);
            int s = n / i;
            sum += i;
            if(s != i) {
                sum += s;
            }
        }
    }
    return sum;
}

void prijateljsko(int n) {
    int m = sumOfDeviders(n);
    if(n == sumOfDeviders(m)) {
        printf("%d\n", m);
    }else {
        // printf("m: %d\n", m);
        // printf("n: %d\n", n);
        printf("NIMA\n");
    }    
}

int main() {
    int n;
    scanf("%d", &n);
    prijateljsko(n);

    return 0;
}

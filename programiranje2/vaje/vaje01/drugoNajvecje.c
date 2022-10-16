#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int biggest = -1;
    int secondBiggest = -1;
    int current = -1;
    for(int i = 0; i < n; i++) {
        scanf("%d", &current);
        
        if(current == biggest || current < biggest && current > secondBiggest) {
            secondBiggest = current;
        }
        if(current > biggest) {
            secondBiggest = biggest;
            biggest = current;
        }
        
    }
    printf("%d\n", secondBiggest);

    return 0;
}

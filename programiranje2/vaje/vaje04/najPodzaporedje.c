#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*) calloc(n, sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    int biggestSum = INT_MIN;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum > biggestSum) biggestSum = sum;
        if(sum < 0) sum = 0;
    }
    
    printf("%d\n", biggestSum);

    return 0;
}
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int num = -1;
    int a = -1;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            scanf("%d", &num);
        }else {
            scanf("%d", &a);
            if(a != num) {
                printf("0");
                return 0;
            }
        }
    }
    printf("1");

    return 0;
}

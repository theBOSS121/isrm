#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int middle = (a + b) / 2;
    int c = 1;
    while(c != 0) {
        scanf("%d", &c);
        if(c == 1) {
            a = middle + 1;
            middle = (a + b) / 2;
        }else if(c == -1) {
            b = middle - 1;
            middle = (a + b) / 2;
        }else if(c == 0) {
            break;
        }
    }

    if(b < a) printf("PROTISLOVJE");
    else if(b == a) printf("%d", a);
    else printf("[%d, %d]", a, b);

    return 0;
}
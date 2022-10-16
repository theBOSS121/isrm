#include <stdio.h>

int main() {
    char c;

    int num1 = 0, num2 = 0;
    int bNext = 0;
    int bNum1Neg = 0, bNum2Neg = 0;
    while (1) {
        c = getchar();
        
        if (c == '\n') break;
        if(c == ' ') bNext = 1;
        if(c == '-') {
            if(bNext == 0) bNum1Neg = 1;
            if(bNext == 1) bNum2Neg = 1;
        }

        int zeroToTen = c - '0';
        if(zeroToTen > -1 && zeroToTen < 10) {
            if(bNext == 0) num1 = num1 * 10 + zeroToTen;
            if(bNext == 1) num2 = num2 * 10 + zeroToTen;

        } 
    }
    if(bNum1Neg == 1) num1 *= -1;
    if(bNum2Neg == 1) num2 *= -1;
    int sum = num1 + num2;
    int temp = sum;
    int count;
    while (temp != 0) {
        temp /= 10;
        count++;
    }

    if(sum < 0) {
        putchar('-');
        sum *= -1;
    }
    
    while(count > 0) {
        temp = sum;
        int a = 1;
        for(int i = 1; i < count; i++) a *= 10;
        temp /= a;
        putchar((temp%10) + '0');
        count--;
    }
    if(sum == 0) putchar('0');

    return 0;
}
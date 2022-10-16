#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum operation { addition, subtraction, multiplication, division};
typedef enum operation operation;

char* removeBrackets(char* string) {
    int open = 0;
    int openN = 0;
    int close = 0;
    int outer = 0;
    bool begining = true;
    int len = strlen(string);
    for(int i = 0; i < len; i++) {
        if(string[i] == '(') {
            if(begining == true) {
                outer++;
                open++;
            }else {
                openN++;
            }
        }else if(string[i] == ')') {
            if(openN > 0) {
                openN--;
            }else {
                close++;
            }
        }else {
            begining = false;
            if(outer > 0 && close > 0) {
                outer--;
                close--;
                open--;
            }
        }

    }
    // printf("numOfOuter: %d\n", outer);    
    
    string[len-outer] = '\0';
    string = &string[outer];
    // printf("withoutBrackets: %s\n", string);
    return string;
    
}

int findMostRightOperation(char* string, operation* operation) {
    int len = strlen(string);
    int lastPlusMinus = -1;
    int lastMulDiv = -1;
    int bracketSum = 0;
    for(int i = 0; i < len; i++) {
        if(string[i] == '(') {
            bracketSum++;
        }else if(string[i] == ')') {
            bracketSum--;
        }

        if(bracketSum == 0) {
            if(string[i] == '+') {
                *operation = addition;
                lastPlusMinus = i;
            }else if(string[i] == '-') {
                *operation = subtraction;
                lastPlusMinus = i;
            }else if(string[i] == '*' && lastPlusMinus == -1) {
                *operation = multiplication;
                lastMulDiv = i;
            }else if(string[i] == '/' && lastPlusMinus == -1) {
                *operation = division;
                lastMulDiv = i;
            }
        }
    }

    if(lastPlusMinus != -1) {
        return lastPlusMinus;
    }else {
        if(lastMulDiv != -1) {
            return lastMulDiv;
        }else {
            return -1;
        }
    }
}

int calc(char* string) {
    string = removeBrackets(string);
    operation typeOfOperation = -1;
    // printf("After removed: %s %d\n", string, strlen(string));
    int index = findMostRightOperation(string, &typeOfOperation);
    // printf("operation index: %d %d\n", index, typeOfOperation);
    if(index != -1) {
        char* left = string;
        left[index] = '\0';
        char* right = &string[index+1];
        int result = 0;
        if(typeOfOperation == addition) {
            result = calc(left) + calc(right);
        }else if(typeOfOperation == subtraction) {
            result = calc(left) - calc(right);
        }else if(typeOfOperation == multiplication) {
            result = calc(left) * calc(right);
        }else if(typeOfOperation == division) {
            result = calc(left) / calc(right);
        }
        // printf("left: %s, right: %s, result: %d\n", left, right, result);
        return result;
    }else {
        return atoi(string);
    }
}

int main() {
    char* string = (char*) malloc(1000 * sizeof(char));
    scanf("%s", string);
    
    int result = calc(string);
    printf("%d\n", result);

    return 0;
}
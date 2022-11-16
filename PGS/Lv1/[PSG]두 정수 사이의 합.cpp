#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    long long c = 0;
    if(a == b){
        c = a;
    }
    else if(b > a){
        while (b >= a){
            c += b;
            b -= 1;
        }
    }
    else if(a > b){
        while (a >= b){
            c += b;
            b += 1;
        }
    }
    answer = c;
    return answer;
}
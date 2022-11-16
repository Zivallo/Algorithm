#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    int* answer = (int*)malloc(1);
    int same_nums=0;
    int zero_nums=0;
    for (int i=0;i<lottos_len;i++)
    {
        for(int j=0;j<win_nums_len;j++)
        {
            if (lottos[i]==win_nums[j])
            {
                if(lottos[i]>=0){
                  if(lottos[i]<=45) same_nums++; 
                }
            }
        }
    }
    for (int k=0;k<lottos_len;k++)
    {
        if(lottos[k] == 0)
        {
            zero_nums++;
        }
    }
    answer[0]=7-same_nums-zero_nums;
    answer[1]=7-same_nums;
    if (zero_nums == 6) answer[1]=6;
    if (same_nums == 0){
        if(zero_nums == 0){
            answer[0]=6;
            answer[1]=6;
        }
    }
    return answer;
}
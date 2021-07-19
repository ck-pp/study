//
//  Week4_2.c
//  alg_study
//
//  Created by 박채경 on 2021/07/18.
//
// 2292번 (+6, +6*2, +6*3, ...)
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N, i = 1, sum = 1;
    scanf("%d", &N);
    if (N == 1)
        printf("1");
    else
    {
        while(1) // break 걸리기 전까지 무한 루프
        {
            if (N <= sum)
                break;
            sum += 6*i;
            i++;
        }
        printf("%d", i);
    }
}
*/

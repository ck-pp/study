//
//  Week7_1.c
//  alg_study
//
//  Created by 박채경 on 2021/08/19.
// 백준 2798번_블랙잭
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, temp, max = 0;
    scanf("%d%d", &N, &M);
    int* list = (int*)malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++)
        scanf("%d", &list[i]);
    /*
    // 선택정렬
    for (int j = 0; j < N-1; j++)
    {
        for (int k = j+1; k < N; k++)
        {
            if (list[j] > list[k])
            {
                temp = list[j];
                list[j] = list[k];
                list[k] = temp;
            }
        }
    }
    */
    for (int a = 0; a < N; a++)
    {
        for (int b = a+1; b < N; b++)
        {
            for (int c = b+1; c < N; c++)
            {
                if (list[a] + list[b] + list[c] <= M && max < list[a] + list[b] + list[c])
                    max = list[a] + list[b] + list[c];
            }
        }
    }
    printf("%d", max);
    return 0;
}

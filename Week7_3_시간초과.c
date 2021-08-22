//
//  Week7_3_시간초과.c
//  alg_study
//
//  Created by 박채경 on 2021/08/22.
// 백준 10814 (나이순정렬)
#include <stdio.h>
#include <stdlib.h>
#define SIZE_m 100000
#define SIZE 101

typedef struct
{
    int age;
    char name[SIZE];
} member;

int main()
{
    int N, temp, list[SIZE_m];
    scanf("%d", &N);
    member* m=(member*)malloc(N*sizeof(member));
    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &m[i].age, m[i].name);
        list[i] = i;
    }
    // 선택정렬
    for (int j = 0; j < N-1; j++)
    {
        for (int k = j+1; k < N; k++)
        {
            if (m[j].age > m[k].age)
            {
                temp = list[j];
                list[j] = list[k];
                list[k] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++)
        printf("%d %s\n", m[list[i]].age, m[list[i]].name);

    return 0;
}
// 시간 초과 (선택&버블 정렬)

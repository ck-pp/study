//
//  11_4.c
//  EPEER
//
//  Created by 박채경 on 2021/09/16.
// EPEER_17회기출_하(4)_solution 함수&main 험수 작성
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000000

int solution(int N, int* A, int B, int C)
{
    int answer = 0, need;
    for (int i = 0; i < N; i++)
    {
        answer++; // 총감독관 수 카운트
        need = A[i] - B;
        if (need != 0)
        {
            while(need > 0)
            {
                answer++;
                need -= C;
            }
        }
    }
    
    return answer;
}

int main()
{
    int N, B, C;
    int A[SIZE];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    scanf("%d%d", &B, &C);
    printf("%d", solution(N, A, B, C));

    return 0;
}

//
//  Week8_6.c
//  EPEER
//
//  Created by 박채경 on 2021/08/29.
// 백준_2565_전깃줄(교차x)
#include <stdio.h>
#include <stdlib.h>
#define SIZE 500

int absolute_num(int a)
{
    return a > 0 ? a : -a;
}

int main()
{
    int N, cnt = 0;
    int A[SIZE], B[SIZE];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &A[i], &B[i]);
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if(A[i] > A[j])
            {
                int temp = A[i]; A[i] = A[j]; A[j] = temp;
                temp = B[i]; B[i] = B[j]; B[j] = temp;
            }
        }
    }
    for (int j = N-1; j > -1; j--)
    {
        for (int k = N-1; k > j; k--)
        {
            if (B[j] > B[k] && A[j] < A[k])
            {
                if (absolute_num(B[j]-A[j]) > absolute_num(B[k]-A[k]))
                    A[j]=B[j]=501;
                else if (absolute_num(B[j]-A[j]) < absolute_num(B[k]-A[k]))
                    A[k]=B[k]=501;
                cnt++;
                break;
            }
        }
    }
    printf("%d", cnt);
    
    return 0;
}

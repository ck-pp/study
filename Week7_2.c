//
//  Week7_2.c
//  alg_study
//
//  Created by 박채경 on 2021/08/19.
// 백준 2231번_분해합(브루트포스)
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, q, i = 1, min = 1000001;
    scanf("%d", &N);
    while(i < N+1)
    {
        int sum = 0;
        q = N-i;
        sum += q;
        while (1)
        {
            sum += (q % 10);
            q /= 10;
            if (q < 10)
                break;
        }
        sum += q;
        //printf("%d sum %d\n", N-i, sum);
        if (sum == N && min > N-i)
            min = N-i;
        i++;
    }
    if (min == 1000001)
        printf("0");
    else
        printf("%d", min);
    
    return 0;
}

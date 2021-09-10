//
//  Week10_1.c
//  EPEER
//
//  Created by 박채경 on 2021/09/09.
// EPEER_2019_13회(c)_3번
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n); // 3<=n<=100
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (j < n-i+1)
                printf(" ");
            else
                printf("*");
        }
        //for (int k = j; k < n+1; k++)
            //printf("*");
        printf("\n");
    }

    return 0;
}

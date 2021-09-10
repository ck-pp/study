//
//  Week10_2.c
//  EPEER
//
//  Created by 박채경 on 2021/09/09.
// EPEER_2019_13회(c)_4번
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

int main()
{
    int n, X, r, d, ten, one; // r : 반올림값, d : 버림(내림)값
    scanf("%d", &n); // 1<=n<=100
    for (int i = 0; i < n; i++)
    {
        int list[SIZE] = {0}, k = 0;
        scanf("%d", &X); // 1000<=X<=30000
        while (X > 10)
        {
            list[k] = X%10;
            X /= 10;
            k++;
        }
        list[k] = X;
        d = 100*list[2] + 1000*list[3] + 10000*list[4];
        if (list[1] >= 5)
        {
            list[2]++;
            for (int i = 2; i <= k; i++)
            {
                if (list[i] >= 10)
                {
                    list[i+1]++;
                    list[i] -= 10;
                }
            }
            r = 100*list[2] + 1000*list[3] + 10000*list[4];
        }
        else
            r = d;
        printf("%d %d\n", r, d);
        
    }

    return 0;
}

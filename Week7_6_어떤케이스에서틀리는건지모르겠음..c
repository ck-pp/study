//
//  Week7_6_어떤케이스에서틀리는건지모르겠음..c
//  EPEER
//
//  Created by 박채경 on 2021/08/22.
// 백준_1912_연속합(미완)
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

int main()
{
    int n, max = -1001, idx, max_sum = -1001, sum = 0;
    int l, r;
    scanf("%d", &n);
    int* list = (int*)malloc(n*sizeof(int));
    //int* sum = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);
    for (int j = 0; j < n; j++)
    {
        if (max < list[j])
        {
            max = list[j];
            idx = j;
        }
    }
    l = idx - 1, r = idx + 1;
    sum += list[idx];
    while (-1 < l && r < n)
    {
        if (max_sum < sum)
            max_sum = sum;
        if (list[l] < list[r])
        {
            sum += list[r];
            r++;
        }
        else if (list[l] >= list[r])
        {
            sum += list[l];
            l--;
        }
        
        else if (n-1 < r && list[r-1] < list[l])
        {
            sum += list[l];
            l--;
        }
    }
    while (r < n)
    {
        if (max_sum < sum)
            max_sum = sum;
        sum += list[r];
        r++;
    }
    while (-1 < l)
    {
        if (max_sum < sum)
            max_sum = sum;
        sum += list[l];
        l--;
    }
    printf("%d", max_sum);
    
    return 0;
}

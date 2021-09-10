//
//  Week10_4.c
//  EPEER
//
//  Created by 박채경 on 2021/09/11.
// EPEER_2019_13회(c)_6번
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1, x2, x3, k, cnt = 0;
    scanf("%d%d%d", &x1, &x2, &x3);
    scanf("%d", &k);
    if (x1 == k || x2 == k || x3 == k) // 원소 하나인 부분집합
        cnt++;
    if (x1+x2 == k)
        cnt++;
    if (x2+x3 == k)
        cnt++;
    if (x1+x3 == k) // 원소 두 개로 구성된 부분집합
        cnt++;
    if (x1+x2+x3 == k) // 원소 세 개로 구성된 부분집합
        cnt++;
    
    printf("%d", cnt);
    return 0;
}

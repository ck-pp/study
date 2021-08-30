//
//  Week9_1.c
//  EPEER
//
//  Created by 박채경 on 2021/08/30.
// EPEER_2020_15회_3번(재고없는날)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int m)
{
    int answer = 0, i = 0;
    while ((m-1)*i <= n)
        i++;
    //  while 빠져나오기전에 i++이 되어서 나오므로 i를 한번 빼줘야하는게 맞음!
    answer += (i-1)*m;
    answer += (n-(m-1)*(i-1));
    
    return answer;
}

int main()
{
    int n = 23, m = 4;
    printf("%d", solution(n, m));

    return 0;
}

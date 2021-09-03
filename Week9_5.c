//
//  Week9_5.c
//  EPEER
//
//  Created by 박채경 on 2021/09/02.
// EPEER_2020_15회_7번(도서관예약)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int solution(int s[], size_t s_len, int e[], size_t e_len)
{
    int answer = 0, seat1, seat2;
    for (int i = 0; i < e_len-1; i++)
    {
        for (int j = i+1; j < e_len; j++)
        {
            if (e[i] > e[j])
            {
                int temp = e[i];
                e[i] = e[j];
                e[j] = temp;
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    //for (int i = 0; i < e_len; i++)
        //printf("s %d e %d\n", s[i], e[i]);
    seat1 = e[0];
    seat2 = e[1];
    answer += 2; // answer = 2 : seat1, seat2 초기값
    for (int k = 2; k < e_len; k++)
    {
        if (!(s[k] < seat1 && s[k] < seat2))
        {
            if (s[k] < seat1 && s[k] >= seat2)
                seat2 = e[k];
            else if (s[k] < seat2 && s[k] >= seat1)
                seat1 = e[k];
            else
            {
                if (s[k] - seat1 < s[k] - seat2)
                    seat1 = e[k];
                else
                    seat2 = e[k];
            }
            answer++;
        }
    }
    return answer;
}

int main()
{
    int s[] = {0, 6, 3, 1, 1, 2};
    int e[] = {3, 7, 10, 5, 9, 8};
    printf("%d",solution(s, sizeof(s)/sizeof(int), e, sizeof(e)/sizeof(int))); // sizeof -> 자료형크기 * 원소개수(배열길이)!!

    return 0;
}

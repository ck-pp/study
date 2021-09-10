//
//  Week10_3.c
//  EPEER
//
//  Created by 박채경 on 2021/09/10.
// EPEER_2019_13회(c)_5번
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 16
void print(int a);

int main()
{
    int year, month, day, g;
    char gender, number[SIZE] = "";
    scanf("%s", number);
    year = (number[0]-48)*10 + (number[1]-48); // -48 : 문자형->정수형 변환(아스키코드사용)
    month = (number[2]-48)*10 + (number[3]-48);
    day = (number[4]-48)*10 + (number[5]-48);
    g = number[7]-48;
    if (g % 2 == 0)
    {
        if (g == 2)
            year += 1900;
        else
            year += 2000;
        gender = 'F';
    }
    else
    {
        if (g == 1)
            year += 1900;
        else
            year += 2000;
        gender = 'M';
    }
    printf("%d-", year);
    print(month);
    printf("-");
    print(day);
    printf(" %c", gender);
    return 0;
}

void print(int a)
{
    if (a < 10)
        printf("0%d", a);
    else
        printf("%d", a);
}

//
//  Week10_5.c
//  EPEER
//
//  Created by 박채경 on 2021/09/11.
// EPEER_2019_13회(c)_8번
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 23

int main()
{
    int m, result, k = 0;
    char str[SIZE];
    scanf("%d", &m); getchar();
    fgets(str, SIZE, stdin);
    for (int i = 0; i < strlen(str); i++)
    {
        if (i == 0 || (i % 2 == 0 && i % 4 != 0))
            str[i] = str[i]-48;
        //printf("%d\n", str[i]);
    }
    switch(str[4])
    {
        case '+': result = str[0]+str[2]; break;
        case '-': result = str[0]-str[2]; break;
        case '/': result = str[0]/str[2]; break;
        case '*': result = str[0]*str[2]; break;
    }
    for (int i = 8; i < strlen(str); i+=4)
    {
        switch(str[i])
        {
        case '+': result += str[i-2]; break;
        case '-': result -= str[i-2]; break;
        case '/':result /= str[i-2]; break;
        case '*': result *= str[i-2]; break;
        }
    }
    printf("%d", result);
    return 0;
}

//
//  Week9_3.c
//  EPEER
//
//  Created by 박채경 on 2021/08/30.
// EPEER_2020_15회_5번(문자열압축)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 10000

char* solution(const char* s)
{
    char* str = (char*)malloc(sizeof(char)*strlen(s));
    int k = 0, cnt = 0;
    if (s[k] == '1')
    {
        str[k] = '1';
        k++;
    }
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == s[i+1])
            cnt++;
        else
        {
            str[k] = cnt+'A';
            cnt = 0;
            k++;
        }
    }
    //str[k] = cnt+'A';
    char* answer = (char*)malloc(sizeof(char)*strlen(str));
    strcpy(answer, str);
    return answer;
}

int main()
{
    char s[SIZE];
    scanf("%s", s);
    printf("%s",solution(s));

    return 0;
}

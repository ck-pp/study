//
//  Week9_4.c
//  EPEER
//
//  Created by 박채경 on 2021/09/02.
// EPEER_2020_15회_6번(후위표기법.계산식.)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int solution(int m, const char* s)
{
    int answer = 0;
    switch(s[4])
    {
        case '+': answer = (s[0]-48) + (s[2]-48); break;
        case '-': answer = (s[0]-48) - (s[2]-48); break;
        case '/': answer = (s[0]-48) / (s[2]-48); break;
        default: answer = (s[0]-48) * (s[2]-48); break;
    }
    for (int i = 6; i < strlen(s); i+=4)
    {
        switch(s[i+2])
        {
            case '+': answer += (s[i]-48); break;
            case '-': answer -= (s[i]-48); break;
            case '/': answer /= (s[i]-48); break;
            case '*': answer *= (s[i]-48); break;
        }
    }
    return answer;
}

int main()
{
    char* s = "2 3 + 2 * 2 /";
    int m = 7;
    printf("%d",solution(m, s));

    return 0;
}

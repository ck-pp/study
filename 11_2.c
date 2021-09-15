//
//  11_2.c
//  EPEER
//
//  Created by 박채경 on 2021/09/15.
// // EPEER_17회기출_하(2)_solution 함수&main 험수 작성
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(char* input)
{
    int answer = 0, cnt = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == 'O')
            cnt++;
        else if (input[i] == 'X' && input[i-1] == 'O')
            cnt = 0;
        answer += cnt;
    }
    return answer;
}

int main() {
    char input[100];
    scanf("%s",input);
    //printf("Hello Goorm! Your input is %s",input);
    printf("%d", solution(input));
    return 0;
}

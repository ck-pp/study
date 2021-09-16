//
//  11_3.c
//  EPEER
//
//  Created by 박채경 on 2021/09/15.
// EPEER_17회기출_하(3)_solution 함수&main 함수 작성
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char answer[5];
char* solution(char* input)
{
    strcpy(answer, "yes");
    int len = strlen(input);
    switch(len)
    {
        case 1: break;
        case 2:
            if (input[0] != input[1])
                strcpy(answer, "no");
            break;
        case 3:
            if (input[0] != input[2])
                strcpy(answer, "no");
            break;
        case 4:
            if (input[0] != input[3] || input[1] != input[2])
                strcpy(answer, "no");
            break;
        case 5:
            if (input[0] != input[4] || input[1] != input[3])
                strcpy(answer, "no");
            break;
        default: printf("1~99999사이의 정수를 입력해주세요.\n"); break;
    }
    return answer;
}

int main()
{
    char input[5];
    while(1)
    {
        scanf("%s", input);
        if (input[0] == '0')
            exit(0);
        printf("%s\n", solution(input));
    }

    return 0;
}

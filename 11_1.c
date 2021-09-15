//
//  11_1.c
//  EPEER
//
//  Created by 박채경 on 2021/09/13.
// EPEER_17회기출_하(1)_solution 함수 작성
#include <stdio.h>
#include <stdlib.h>

char** solution(int r, int c, int zr, int zc, char** words) {
    char** answer;
    int cnt_r = 0, cnt_c = 0;
    answer = (char**)malloc(sizeof(char*) * (zr*r));
    for (int i = 0; i < zr*r; i++)
    {
        answer[i] = (char*)malloc(sizeof(char) * (zc*c + 1));
        for (int j = 0; j < zc*c; j++)
        {
            answer[i][j] = words[cnt_r][cnt_c];
            if ((j+1) % zc == 0 && (i+1) % zr == 0)
                cnt_c++;
        }
        if ((i+1) % zr == 0)
        {
            cnt_r++;
            cnt_c = 0;
        }
    }
    // 코드를 작성해주세요.
    return answer;
}
// 제시되어있는 테스트 케이스는 다 일치하나, 제출했을때 일치하지않는 테스트케이스 발생

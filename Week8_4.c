//
//  Week8_4.c
//  EPEER
//
//  Created by 박채경 on 2021/08/27.
// 백준_9251_LCS(최장공통부분수열)
// 완성코드
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1001

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    char str1[SIZE], str2[SIZE];
    int LCS[SIZE][SIZE];
    scanf("%s", str1);
    scanf("%s", str2);
    int len_str1 = strlen(str1), len_str2 = strlen(str2);
    for (int i =  0; i < len_str1+1; i++)
        LCS[i][0] = 0;
    for (int j = 0; j < len_str2+1; j++)
        LCS[0][j] = 0;
    for (int i = 0; i < len_str1; i++)
    {
        for (int j = 0; j < len_str2; j++)
        {
            if (str1[i] == str2[j])
                LCS[i+1][j+1] = LCS[i][j]+1;
            else
                LCS[i+1][j+1] = max(LCS[i][j+1], LCS[i+1][j]);
        }
    }
    printf("%d", LCS[len_str1][len_str2]);
    return 0;
}

// 실페코드
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1001

int main()
{
    char str1[SIZE], str2[SIZE];
    char LCS[SIZE];
    int k = 0, max = -1;
    scanf("%s", str1);
    scanf("%s", str2);
    for (int i = 0; i < strlen(str1); i++)
    {
        for (int j = 0; j < strlen(str2); j++)
        {
            if (str1[i] == str2[j] && (k == 0 || j > LCS[k-1]))
            {
                LCS[k] = j;
                printf("j %d str %c\n", j, str1[i]);
                k++;
                break;
            }
        }
    }
    printf("%d", k);
    
    return 0;
}

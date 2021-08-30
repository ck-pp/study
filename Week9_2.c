//
//  Week9_2.c
//  EPEER
//
//  Created by 박채경 on 2021/08/30.
// EPEER_2020_15회_4번(100만들기)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int numbers[])
{
    int* answer = (int*)malloc(sizeof(int)*7);
    int sum = 0, a, b, k = 0;
    for (int i = 0; i < 9; i++)
        sum += numbers[i];
    for (int i = 0; i < 9; i++)
    {
        for (int j = i+1; j < 9; j++)
        {
            if (numbers[i] + numbers[j] == sum-100) // 7개 찾는것보다 나머지 2개 찾는게 더 효율적!
            {
                a = i;
                b = j;
                break;
            }
        }
    }
    for (int j = 0; j < 9; j++)
    {
        if (j != a && j != b)
        {
            answer[k] = numbers[j];
            k++;
        }
    }
    for (int i = 0; i < 7; i++)
        printf("%d ", answer[i]);
    
    return answer;
}

int main()
{
    int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 79};
    solution(numbers);
    //for (int i = 0; i < 7; i++)
    //    printf("%d ", answer[i]);

    return 0;
}

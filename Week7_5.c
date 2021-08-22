//
//  Week7_5.c
//  alg_study
//
//  Created by 박채경 on 2021/08/22.
// 백준 1541번_잃어버린괄호
#include <stdio.h>
#include <stdlib.h>
#define SIZE 51

int main()
{
    char str[SIZE];
    int i = 0, sum = 0, conti = 0; // conti == 0 : 연속숫자x, 부호 다음 등장하는 숫자라는 뜻
    int num = 0, minus = 0; // minus == 0 : 마이너스 부호 아직 안나왔다는 뜻
    scanf("%s", str);
    while (str[i] != '\0')
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            num*=10;
            num+=str[i]-'0';
            // 아래 방법으로 하면 자릿수가 포함이 안됨 (550-400=500 -> -35가 나옴)
            //if (conti == 0)
                //num += (str[i] - '0') * 10;
            //else
            //    num += str[i] - '0';
            //conti = 1;
        }
        else
        {
            conti = 0;
            if (minus == 0 && str[i] == '-')
            {
                minus = 1;
                sum += num;
            }
            else if (minus == 1)
                sum -= num;
            else
                sum += num;
            num = 0;
        }
        i++;
    }
    if (minus == 1)
        sum -= num;
    else
        sum += num;
    printf("%d", sum);
    
    return 0;
}

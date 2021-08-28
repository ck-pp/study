//
//  Week8_2.c
//  EPEER
//
//  Created by 박채경 on 2021/08/27.
// 백준_4949_균형잡힌세상(괄호쌍)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 102

typedef struct
{
    char data[SIZE];
    int top;
} StackType;
void init_stack(StackType* s)
{
    s->top = -1;
}
int is_empty(StackType* s)
{
    return s->top == -1;
}
int is_full(StackType* s)
{
    return s->top == SIZE-1;
}
void push(StackType* s, char item)
{
    if (is_full(s))
        return;
    else
        s->data[++(s->top)] = item;
}
char pop(StackType* s)
{
    if (is_empty(s))
        return 0;
    else
        return s->data[(s->top)--];
}
char peek(StackType* s)
{
    if (is_empty(s))
        return 0;
    else
        return s->data[s->top];
}
int main()
{
    StackType s; // 왜 StackType* s로 선언하고 함수 호출할때 인자에 s넣으면 왜 결과가 틀리게 나오는건지 의문...스택 다시 공부하기
    char str[SIZE];
    while(1)
    {
        init_stack(&s);
        int result = 0; // 0 -> yes, 1 -> no
        fgets(str, SIZE, stdin); // 공백포함문자열
        if (str[0] == '.')
            exit(0);
        for (int i = 0; i < strlen(str)-1; i++)
        {
            if (str[i] == '(' || str[i] == '[')
                push(&s, str[i]);
            else if (str[i] == ')')
            {
                if (peek(&s) != '(' || is_empty(&s))
                {
                    result = 1;
                    break;
                }
                else if (peek(&s) == '(')
                    pop(&s);
                
            }
            else if (str[i] == ']')
            {
                if (peek(&s) != '[' || is_empty(&s))
                {
                    result = 1;
                    break;
                }
                else if (peek(&s) == '[')
                    pop(&s);
                
            }
        }
        if (result == 0 && is_empty(&s))
            printf("yes\n");
        else
            printf("no\n");
        
    }
    return 0;
}

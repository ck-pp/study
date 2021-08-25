//
//  Week8_1.c
//  EPEER
//
//  Created by 박채경 on 2021/08/24.
// 백준_10828_스택(LIFO)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000

typedef struct
{
    int data[SIZE];
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
void push(StackType* s, int item)
{
    if (is_full(s))
        return;
    else
        s->data[++(s->top)] = item;
}
int pop(StackType* s)
{
    if (is_empty(s))
        return -1;
    else
        return s->data[(s->top)--];
}
int peek(StackType* s) {
    if (is_empty(s))
        return -1;
    else
        return s->data[s->top];
}

int main()
{
    int N, X;
    char str[10];
    StackType s;
    init_stack(&s);
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++)
    {
        scanf("%s", str);
        //fgets (str, 10, stdin);
        //scanf ("%[^\n]%*c", str);// 공백 포함 문자열 입력받기
        if (strcmp(str, "push") == 0) // push 부분이 포인트 (공백포함 문자열을 받는게 아니라 따로 받음) -> 정수 X는 바로 변수로!
        {
            scanf("%d", &X);
            getchar();
            push(&s, X);
        }
        else if (strcmp(str, "pop") == 0)
            printf("%d\n", pop(&s));
        else if (strcmp(str, "empty") == 0)
            printf("%d\n", is_empty(&s));
        else if (strcmp(str, "top") == 0)
            printf("%d\n", peek(&s));
        else if (strcmp(str, "size") == 0)
            printf("%d\n", s.top + 1);
        /*
         else
            {
                token = strtok(str, " ");
                printf("tok %s\n",token);
                token = strtok(NULL, " ");
                printf("tok %s\n",token);
                for (int j = 0; j < strlen(token); j++)
                    x[j] = token[j] - '0';
                for (int k = strlen(token); k > -1; k--)
                {
                    X += x[k]*position;
                    position *= 10;
                }
                push(&s, X);
            }
         */
    }

    return 0;
}

//
//  Week8_3.c
//  EPEER
//
//  Created by 박채경 on 2021/08/27.
// 백준_18258_큐(연결리스트 큐(FIFO)로 구현함)
// 연결리스틀 큐를 구현하면 is_full() 구현할 필요 x, 계속 늘려나갈 수 있기 떄문에!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 2000000

typedef struct QueueNode
{
    int data;
    struct QueueNode* link;
} QueueNode;
typedef struct
{
    QueueNode* front;
    QueueNode* rear;
    int size;
} QueueType;
void init_queue(QueueType* q)
{
    q->front = q->rear = NULL;
    q->size = 0;
}
int is_empty(QueueType* q)
{
    return q->size == 0;
}
void push(QueueType* q, int item) // enqueue
{
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = item;
    temp->link == NULL;
    if (is_empty(q)) // 연결리스트 첫번째 노드 insert
        q->front = temp;
    else // 이미 연결리스트 노드가 존재하는 경우
        q->rear->link = temp;
    q->rear = temp;
    q->size++;
    
}
int pop(QueueType* q) // dequeue
{
    QueueNode* delNode;
    int delData;
    if (is_empty(q))
        return -1;
    else
    {
        delNode = q->front;
        delData = delNode->data;
        q->front = delNode->link;
        q->size--;
        free(delNode); // !노드 삭제 필수!
        return delData;
    }
}
int Q_front(QueueType* q)
{
    if (is_empty)
        return -1;
    else
        return q->front->data;
}
int Q_back(QueueType* q)
{
    if (is_empty(q))
        return -1;
    else
        return q->rear->data;
}
int size(QueueType* q)
{
    return q->size;
}

int main()
{
    int N, X;
    char str[7];
    QueueType q;
    init_queue(&q);
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++)
    {
        scanf("%s", str);
        if (strcmp(str, "push") == 0)
        {
            scanf("%d", &X);
            getchar();
            push(&q, X);
        }
        else if (strcmp(str, "pop") == 0)
            printf("%d\n", pop(&q));
        else if (strcmp(str, "size") == 0)
            printf("%d\n", size(&q));
        else if (strcmp(str, "empty") == 0)
            printf("%d\n", is_empty(&q));
        else if (strcmp(str, "front") == 0)
            printf("%d\n", Q_front(&q));
        else if (strcmp(str, "back") == 0)
            printf("%d\n", Q_back(&q));
            
    }
    
    return 0;
}

//
//  Week8_5.c
//  EPEER
//
//  Created by 박채경 on 2021/08/29.
// 백준_2164_큐(카드2)
#include <stdio.h>
#include <stdlib.h>

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
int size(QueueType* q)
{
    return q->size;
}

int main()
{
    int N;
    QueueType q;
    init_queue(&q);
    scanf("%d", &N);
    for (int i = 1; i < N+1; i++)
        push(&q, i);
    while(1)
    {
        if (size(&q) == 1)
            break;
        pop(&q);
        push(&q, pop(&q));
    }
    printf("%d", q.rear->data);

    return 0;
}

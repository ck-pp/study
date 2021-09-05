//
//  Week9_7_메모리초과.c
//  EPEER
//
//  Created by 박채경 on 2021/09/05.
// 백준_11725(트리 부모 찾기)
// SIZE를 줄이면 답이 나오는데 100,000으로 설정하면 컴파일에러가 남 (그래서 동적할당으로 해봤는데 그러면 답도 안나오고 메모리초과가 나옴)
// 수정 필요
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define SIZE 100000

bool BFSvisited[SIZE];
int map[SIZE][SIZE];
int queue[SIZE];
int parent[SIZE];
int front = -1;
int rear = -1;

void BFS(int V, int N)
{
  queue[rear] = V;
  rear = (rear+1) % SIZE;
  BFSvisited[V] = 1;

  while(front < rear)
  {
    int x = queue[front];
    front = (front+1) % SIZE;
    BFSvisited[x] = 1;
    
    for(int i = 1; i < N+1; i++)
    {
      if(!BFSvisited[i] && map[i][x])
      {
        parent[i] = x;
        queue[rear] = i;
        rear = (rear+1) % SIZE;
       // BFSvisited[i] = 1;
      }
    }
  }
}

int main()
{
    int N, s, e;
    scanf("%d", &N);
    //map = (int**)malloc(sizeof(int*)*N);
    //for (int i = 0; i < N; i++)
        //map[i] = (int*)malloc(sizeof(int)*N);
    for(int i = 0; i < N-1; i++)
    {
        scanf("%d%d", &s,&e);

        map[s][e] = 1;
        map[e][s] = 1;
    }
    BFS(1, N);
    for(int i = 2; i < N+1; i++)
    {
        printf("%d\n", parent[i]);
    }
    return 0;
}


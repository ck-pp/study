//
//  Week9_6.c
//  EPEER
//
//  Created by 박채경 on 2021/09/03.
// 백준_1260(DFS, BFS)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10000

int map[SIZE][SIZE];
bool DFSvisited[SIZE];
bool BFSvisited[SIZE];
int front=0;
int rear=0;
int queue[SIZE];

void DFS (int V, int N)
{
  DFSvisited[V] = 1;
  printf("%d ",V);

  for(int i = 1; i <= N; i++)
  {
    if(!DFSvisited[i] && map[i][V])
      DFS(i, N);
  }
}

void BFS(int V, int N)
{
  queue[rear] = V;
  rear = (rear+1) % SIZE;
  BFSvisited[V] = 1;

  while(front != rear)
  {
    int x = queue[front];
    front = (front+1) % SIZE;
    
    printf("%d ", x);
    
    for(int i = 1; i <= N; i++)
    {
      if(!BFSvisited[i] && map[i][x]){
        queue[rear] = i;
        rear = (rear+1) % SIZE;
        BFSvisited[i] = 1;
      }
    }
  }
}

int main()
{
    int N, M, V, s, e;
    scanf("%d%d%d", &N, &M, &V);
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &s, &e);
        map[s][e]=1;
        map[e][s]=1;
    }
    DFS(V, N);
    printf("\n");
    BFS(V, N);
    return 0;
}

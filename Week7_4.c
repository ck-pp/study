//
//  Week7_4.c
//  alg_study
//
//  Created by 박채경 on 2021/08/22.
// 백준 2751 (합병정렬)
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000000

void merge_sort(int list[], int left, int right);
void merge(int list[], int left, int mid, int right);

int main()
{
    int N;
    scanf("%d", &N);
    int* list = (int*)malloc(N*sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &list[i]);
    merge_sort(list, 0, N-1);
    for (int i = 0; i < N; i++)
        printf("%d\n", list[i]);
    return 0;
}

void merge_sort(int list[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left,mid, right);
    
    }
}
void merge(int list[], int left, int mid, int right)
{
    int i,j,k,l, sorted[SIZE];
    i = left; // 첫번째 리스트
    j = mid+1; // 두번째 리스트
    k = left;
    
    
    while(i <= mid && j <= right)
    {
        if(list[i] <= list[j])
        {
            sorted[k++] = list[i++];
        }
        else
        {
            sorted[k++] = list[j++];
        }
    }
    
    
    if(i > mid)
    {
        for(l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    else
    {
        for(l = i; l <= mid; l++)
        {
            sorted[k++] = list[l];
        }
        
    }
    
    for (l = left; l <= right; l++)
    {
        list[l] = sorted[l]; // 리스트 재복사
    }
}

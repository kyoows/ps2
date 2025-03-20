/*
2750 - 수 정렬하기
3909060 helloneo 2750 맞았습니다!! 1116 0 C99 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int comp(const void* x, const void* y)
{
    int* a = (int*)x;
    int* b = (int*)y;
    return *a - *b;
}
int main()
{
    int n, i;
    int num[1001];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    qsort(num, n, sizeof(int), comp);
    for (i = 0; i < n; i++) {
        printf("%d\n", num[i]);
    }
    return 0;
}
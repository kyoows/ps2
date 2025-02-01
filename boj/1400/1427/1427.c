/*
 * 1427 - 소트인사이드
 * 3932669  helloneo 1427 맞았습니다!! 944 0 C99
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int comp(const void* x, const void* y)
{
    char* a = (char*)x;
    char* b = (char*)y;
    return *b - *a;
}
int main()
{
    char buf[1000];
    scanf("%s", buf);
    qsort(buf, strlen(buf), sizeof(char), comp);
    printf("%s\n", buf);
    return 0;
}

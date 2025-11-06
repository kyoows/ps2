/*
 * 27323 - 長方形 (Rectangle)
 * 100012550 helloneo  27323 맞았습니다!! 1112 0 C99
 */
#include <stdio.h>
#include <string.h>
int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) == 2) {
        printf("%d\n", a*b);
    }
    return 0;
}
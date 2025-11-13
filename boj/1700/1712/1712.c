/*
1712 - 손익분기점
100198668 helloneo  1712 맞았습니다!! 1116 0 C99 / 수정
*/
#include <stdio.h>
#include <string.h>
int main()
{
    long long a, b, c;
    while (scanf("%lld%lld%lld", &a, &b, &c) == 3) {
        if (c <= b) {
            printf("-1\n");
            continue;
        }
        printf("%lld\n", a / (c-b) + 1);
    }
    return 0;
}
/*
 * 17009 - Winning Score
 * 89371137 helloneo 17009  맞았습니다!! 1116 0 C99
 */
#include <stdio.h>
#include <string.h>
int main()
{
    int a1, a2, a3, b1, b2, b3;
    int sum1, sum2;
    while (scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &b1, &b2, &b3) == 6) {
        sum1 = a1*3 + a2*2 + a3;
        sum2 = b1*3 + b2*2 + b3;
        if (sum1 > sum2)
            printf("A\n");
        else if (sum1 < sum2)
            printf("B\n");
        else
            printf("T\n");
    }
    return 0;
}

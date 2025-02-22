/*
 * 25600 - Triathlon
 * 90438964 helloneo 25600  맞았습니다!! 1112 0 C99
 */
#include <stdio.h>
#include <string.h>
int main()
{
    long long a, d, g, max1, sum;
    int n;
    max1 = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%lld%lld%lld", &a, &d, &g);
        sum = a * (d + g);
        if (a == (d+g))
            sum *= 2;
        if (sum > max1)
            max1 = sum;
    }
    printf("%lld\n", max1);
    return 0;
}

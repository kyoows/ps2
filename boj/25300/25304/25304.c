/*
 * 25304 - 영수증
 * 94590896	helloneo 25304 맞았습니다!! 1116 0 C99
 */
#include <stdio.h>
#include <string.h>
int main()
{
    long long sum, sum2;
    int n;
    long long a, b;
    while (scanf("%lld", &sum) == 1 && sum) {
        scanf("%d", &n);
        sum2 = 0;
        while (n--) {
            scanf("%lld%lld", &a, &b);
            sum2 += a*b;
        }
        if (sum == sum2)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
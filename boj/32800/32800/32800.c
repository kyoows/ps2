/*
 * 32800 - Bus Assignment
 * 89422906 helloneo 32800  맞았습니다!! 1112 36  C99 
 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    int i;
    long long max1, sum;
    long long a, b;
    while (scanf("%d", &n) == 1 && n) {
        max1 = 0;
        sum = 0;
        for (i = 0; i < n; i++) {
            scanf("%lld%lld", &a, &b);
            sum -= a;
            sum += b;
            if (sum > max1)
                max1 = sum;
        }
        printf("%lld\n", max1);
    }
    return 0;
}

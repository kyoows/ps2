#include <stdio.h>
int main()
{
    int n, a;
    int min1, max1;
    long long res;
    min1 = 999999999;
    max1 = -999999999;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (a > max1)
            max1 = a;
        if (a < min1)
            min1 = a;
    }
    printf("%lld\n", (long long)min1 * max1);
    return 0;
}

/*
 * 1009 - 분산처리
 * 89371640 helloneo 1009 맞았습니다!! 1116 0 C99
 */
#include <stdio.h>
#include <string.h>
long long bigmod(long long a, long long b, long long m)
{
    long long res;
    if (b == 0)
        return 1;
    if (b & 1)
        return ((a%m) * (bigmod(a, b-1, m) % m)) % m;
    res = bigmod(a, b/2, m);
    return ((res%m) * (res%m)) % m;
}
int main()
{
    int tc;
    int a, b;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &a, &b);
        a = (int)bigmod((long long)a, (long long)b, 10LL);
        if (a == 0)
            a = 10;
        printf("%d\n", a);
    }
    return 0;
}

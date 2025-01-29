#include <stdio.h>
#include <string.h>
long long dp0[50];
long long dp1[50];
int main()
{
    int tc, n, i;
    dp0[0] = 1;
    dp0[1] = 0;
    dp0[2] = 1;
    dp1[0] = 0;
    dp1[1] = 1;
    dp1[2] = 1;
    for (i = 3; i <= 40; i++) {
        dp0[i] = dp0[i-1] + dp0[i-2];
        dp1[i] = dp1[i-1] + dp1[i-2];
    } 
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        printf("%lld %lld\n", dp0[n], dp1[n]);
    }
    return 0;
}

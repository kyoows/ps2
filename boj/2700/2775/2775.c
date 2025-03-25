/*
 * 2775 - 부녀회장이 될테야
 * 91994799 helloneo  2775 맞았습니다!! 1112 0 C99
 */
#include <stdio.h>
#include <string.h>
long long dp[15][15];
int main()
{
    int tc;
    int i, j;
    int n, k;
    for (i = 0; i < 15; i++) {
        dp[0][i] = i;
    }
    for (i = 1; i <= 14; i++) {
        dp[i][0] = 0;
        for (j = 1; j <= 14; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &k, &n);
        printf("%lld\n", dp[k][n]);
    }
    return 0;
}
/*
 * 1149 - RGB거리
 * 4417371 helloneo  1149 맞았습니다!! 1116 0 1 C99 / 수정 634
 * 2016-10-03
 */
#include <stdio.h>
#include <string.h>
#define min(x, y) ((x) > (y) ? (y) : (x))
int main()
{
    int n;
    int rgb[1001][3];
    int dp[1001][3];
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d%d", &rgb[i][0], &rgb[i][1], &rgb[i][2]);
    }
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i-1][1]+rgb[i][0], dp[i-1][2]+rgb[i][0]);
        dp[i][1] = min(dp[i-1][0]+rgb[i][1], dp[i-1][2]+rgb[i][1]);
        dp[i][2] = min(dp[i-1][0]+rgb[i][2], dp[i-1][1]+rgb[i][2]);
    }
    printf("%d\n", min(dp[n][0], min(dp[n][1], dp[n][2])));
    return 0;
}

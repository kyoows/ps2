/*
 * 1010 - 다리 놓기
 * 89460078 helloneo 1010 맞았습니다!! 1124 0 C99
 */
#include <stdio.h>
#include <string.h>
#define MAXN 33

long long choose[MAXN][MAXN];
void pascal(int n)
{
    int i, j;
    for (i = 0; i <= n; i++) {
        choose[i][i] = 1;
        choose[i][0] = 1;
    }
    for (i = 0; i <= n; i++) {
        for (j = 1; j < i; j++) {
            choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
        }
    }
}


int main()
{
    int tc;
    int a, b;
    pascal(30);
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &a, &b);
        if (a > b)
            printf("%lld\n", choose[a][b]);
        else
            printf("%lld\n", choose[b][a]);
    }
    return 0;
}

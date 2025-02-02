/*
 * Combination (Pascal's Triangle)
 *
 * test: boj-1010 다리놓기
 */

#include <stdio.h>
#include <string.h>
#define MAXN 33

/* choose[n][r] = nCr */
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
    return 0;
}

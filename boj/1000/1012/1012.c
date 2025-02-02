/*
 * 1012 - 유기농 배추
 * 5930796  helloneo 1012 맞았습니다!! 1300 0 C99
 */
#include <stdio.h>
#include <string.h>
int n, m;
char map[55][55];
char check[55][55];
void dfs(int x, int y)
{
    check[x][y] = 1;
    if (x+1 < n && !check[x+1][y] && map[x+1][y]) {
        dfs(x+1, y);
    }
    if (y+1 < m && !check[x][y+1] && map[x][y+1]) {
        dfs(x, y+1);
    }
    if (x-1 >= 0 && !check[x-1][y] && map[x-1][y]) {
        dfs(x-1, y);
    }
    if (y-1 >= 0 && !check[x][y-1] && map[x][y-1]) {
        dfs(x, y-1);
    }
}
int main()
{
    int tc;
    int i, j, k;
    int x, a, b;
    int cnt;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d%d", &n, &m, &x);
        memset(map, 0, sizeof(map));
        for (i = 0; i < x; i++) {
            scanf("%d%d", &a, &b);
            map[a][b] = 1;
        }
        memset(check, 0, sizeof(check));
        cnt = 0;
        for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (map[i][j] == 1 && !check[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

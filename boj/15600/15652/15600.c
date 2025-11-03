/*
 * 15652 - N과 M (4)
 * 99931173 helloneo  15652 맞았습니다!! 1116 4 C99
 */
#include <stdio.h>
#include <string.h>
int n, m;
int arr[10];

void recur(int u, int v)
{
    int i;

    arr[v] = u;
    if (v == m-1) {
        for (i = 0; i < m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return ;
    }
    for (i = u; i <= n; i++) {
        recur(i, v+1);
    }
}

void solve()
{
    int i;
    for (i = 1; i <= n; i++) {
        recur(i, 0);
    }
}
int main()
{
    while (scanf("%d%d", &n, &m) == 2 && n) {
        solve();
    }
    return 0;
}
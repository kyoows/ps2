/*
 * 1392 - Music Notes
 * 88930717 helloneo 1392 맞았습니다!! 1116 0
 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n, q;
    int b[110], sum[110];
    int t;
    int i;
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    sum[0] = b[0];
    for (i = 1; i < n; i++) {
        sum[i] = sum[i-1] + b[i];
    }
    while (q--) {
        scanf("%d", &t);
        for (i = 0; i < n; i++) {
            if (t < sum[i]) {
                break;
            }
        }
        printf("%d\n", i+1);
    }
    return 0;
}

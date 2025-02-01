/*
 * 1004 - 어린 왕자
 * 4399761  helloneo 1004 맞았습니다!! 944 0 C99
 */
#include <stdio.h>
#include <string.h>
typedef struct _circle {
    double x, y, r;
} CIRCLE;
CIRCLE cir[55];
int main()
{
    int tc, n;
    int i, j, k;
    int check[55];
    int cnt;
    double x1, y1, x2, y2;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        scanf("%d",&n);
        memset(check, 0, sizeof(check));
        for (i = 0; i < n; i++) {
            scanf("%lf%lf%lf", &cir[i].x, &cir[i].y, &cir[i].r);
            if ((cir[i].x-x1)*(cir[i].x-x1)+(cir[i].y-y1)*(cir[i].y-y1) < cir[i].r*cir[i].r) {
                check[i]++;
            }
            if ((cir[i].x-x2)*(cir[i].x-x2)+(cir[i].y-y2)*(cir[i].y-y2) < cir[i].r*cir[i].r) {
                check[i]++;
            }
        }
        cnt = 0;
        for (i = 0; i < n; i++) {
            if (check[i] == 1)
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}

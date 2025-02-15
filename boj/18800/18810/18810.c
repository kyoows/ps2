/*
 * 18810 - Amazing Sushi
 * 90129887 helloneo 18810  맞았습니다!! 1116 0 C99
 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    int m;
    int sum1, sum2, remain;
    int x1, y1, x2, y2;
    while (scanf("%d", &n) == 1 && n) {
        scanf("%d%d", &x1, &y1);
        scanf("%d%d", &x2, &y2);
        sum1 = sum2 = 0;
        remain = 0;
        while (n--) {
            scanf("%d", &m);
            if (m % 2 == 0) {
                sum1 += m/2;
                sum2 += m/2;
            }
            else {
                sum1 += m/2;
                sum2 += m/2;
                remain++;
            }
        }
        if (sum1 < x1) {
            remain -= x1-sum1;
            sum1 = x1;
        }
        if (sum2 < x2) {
            remain -= x2-sum2;
            sum2 = x2;
        }
        if (remain < 0) {
            printf("No\n");
            continue;
        }
        if (sum1 > y1 || sum2 > y2) {
            printf("No\n");
            continue;
        }
        if (remain > (y1-sum1) + (y2-sum2)) {
            printf("No\n");
            continue; 
        }
        printf("Yes\n");
    }
    return 0;
}

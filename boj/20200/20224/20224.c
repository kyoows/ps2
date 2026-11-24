/*
 * Count Down Up 2020
 * 105259148 helloneo 20224 맞았습니다!! 1128 5 2 C99 / 수정 454 
 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    int num[1010];
    int i;
    int sum;
    while (scanf("%d", &n) == 1 && n) {
        sum = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        for (i = 3; i < n; i++) {
            if (num[i-3] == 2 && num[i-2] == 0 && num[i-1] == 2 && num[i] == 0) {
                sum++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}

/*
 * 3276 - ICONS
 * 89038316 helloneo 3276 맞았습니다!! 1112 0 C99 
 */
#include <stdio.h>
#include <string.h>
int main()
{
    int i, j;
    int n;
    int min1, minr, minc;
    while (scanf("%d", &n) == 1) {
        min1 = 99999999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (i*j >= n) {
                    if (i+j < min1) {
                        min1 = i+j;
                        minr = i;
                        minc = j;
                    }
                }
            }
        }
        printf("%d %d\n", minr, minc);
    }
    return 0;
}

/*
 * 4909 - Judging Olympia
 * 89085722 helloneo 4909 맞았습니다!! 1116 0 C99
 */
/*
4084 - Judging Olympia
2008-07-12 08:44:17  Accepted 0.012 Minimum 4653 C
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int comp(const void* x, const void* y)
{
    int* a = (int*)x;
    int* b = (int*)y;
    return *a - *b;
}
int main()
{
    int num[10];
    int sum;
    while (scanf("%d%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]) == 6) {
        qsort(num, 6, sizeof(int), comp);
        sum = num[0] + num[1] + num[2] + num[3] + num[4] + num[5];
        if (sum == 0)
            break;
        sum -= num[0] + num[5];
        if (sum % 4 == 0) {
            printf("%d\n", sum / 4);
        }
        else {
            sum *= 25;
            if (sum % 10 == 0) {
                printf("%d.%d\n", sum / 100, (sum % 100) / 10);
            }
            else {
                printf("%d.%d\n", sum / 100, sum % 100);
            }
        }
    }
    return 0;
}

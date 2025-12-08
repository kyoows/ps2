/*
 * 1138 - 한 줄로 서기
 * 5400555 helloneo 1138 맞았습니다!! 1116KB 0 MSC/수정 657B
 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    int num[11];
    int i, j, k;
    int check[11];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    memset(check, -1, sizeof(check));
    for (i = 0; i < n; i++) {
        k = 0;
        for (j = 0; j < n; j++) {
            if (check[j] == -1) {
                k++;
                if (k == num[i]+1) {
                    check[j] = i;
                    break;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", check[i]+1);
    }
    printf("\n");
    return 0;
}
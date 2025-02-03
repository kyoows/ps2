/*
1032 - 명령 프롬프트
5382308 helloneo 1032 맞았습니다!! 1116 KB 0 MS C / 수정 676 B
*/
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    char cmd[55][55];
    int i, j, k;
    int len;
    char check[55];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", cmd[i]);
    }
    len = strlen(cmd[0]);
    memset(check, 0, sizeof(check));
    for (i = 0; i < len; i++) {
        for (j = 1; j < n; j++) {
            if (cmd[j][i] != cmd[j-1][i]) {
                check[i] = 1;
                break;
            }
        }
    }
    for (i = 0; i < len; i++) {
        if (check[i])
            printf("?");
        else
            printf("%c", cmd[0][i]);
    }
    printf("\n");
    return 0;
}

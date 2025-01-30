/*
 * 1159 - TRENER
 * 89347847 helloneo 1159 맞았습니다!! 1116 0 C99
 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    int i;
    int chcnt[128];
    char buf[100];
    int fl;
    while (scanf("%d", &n) == 1 && n) {
        memset(chcnt, 0, sizeof(chcnt));
        for (i = 0; i < n; i++) {
            scanf("%s", buf);
            chcnt[buf[0]]++;
        }
        fl = 0;
        for (i = 'a'; i <= 'z'; i++) {
            if (chcnt[i] >= 5) {
                printf("%c", (char)i);
                fl = 1;
            }
        }
        if (!fl)
            printf("PREDAJA\n");
        else
            printf("\n");
    }
    return 0;
}

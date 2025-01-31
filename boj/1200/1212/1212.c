/*
 * 1212 - 8진수 2진수
 * 4176073  helloneo 1212 맞았습니다!! 1440 24  C9
 */
#include <stdio.h>
#include <string.h>
char buf[333335];
int main()
{
    int len, i, j;
    while (scanf("%s", buf) == 1) {
        len = strlen(buf);
        if (!strcmp(buf, "0")) {
            printf("0\n");
            continue;
        }
        i = 0;
        if (buf[i] == '1')
            printf("1");
        else if (buf[i] == '2')
            printf("10");
        else if (buf[i] == '3')
            printf("11");
        else if (buf[i] == '4')
            printf("100");
        else if (buf[i] == '5')
            printf("101");
        else if (buf[i] == '6')
            printf("110");
        else if (buf[i] == '7')
            printf("111");

        for (i = 1; i < len; i++) {
            if (buf[i] == '0')
                printf("000");
            else if (buf[i] == '1')
                printf("001");
            else if (buf[i] == '2')
                printf("010");
            else if (buf[i] == '3')
                printf("011");
            else if (buf[i] == '4')
                printf("100");
            else if (buf[i] == '5')
                printf("101");
            else if (buf[i] == '6')
                printf("110");
            else if (buf[i] == '7')
                printf("111");
        }
        printf("\n");
    }
    return 0;
}

/*
 * 15813 - 너의 이름은 몇 점이니?
 * 90745625 helloneo 15813  맞았습니다!! 1112 0 C99
 */
#include <stdio.h>
#include <string.h>
int main()
{
    char buf[110];
    int len, sum, i;
    while (scanf("%d%s", &len, buf) == 2) {
        sum = 0;
        for (i = 0; i < len; i++) {
            sum += buf[i]-'A'+1;
        }
        printf("%d\n", sum);
    }
    return 0;
}

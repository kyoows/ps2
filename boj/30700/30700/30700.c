/*
 * 30700 - KOREA 문자열 만들기
 * 89341274 helloneo 30700  맞았습니다!! 1112 0 C99
 */
#include <stdio.h>
#include <string.h>
int main()
{
    char str[1010];
    char* next = "KOREA";
    int idx;
    int len;
    int i;
    int sum;
    while (scanf("%s", str) == 1) {
        len = strlen(str);
        idx = 0;
        sum = 0;
        for (i = 0; i < len ;i++) {
            if (str[i] == next[idx]) {
                sum++;
                idx = (idx+1) % 5;
            }
            else
                continue;
        }
        printf("%d\n", sum);
    }
    return 0;
}

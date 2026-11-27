/*
1152 - 단어의 개수
3915683 helloneo  1152 맞았습니다!! 2088 24 1 C99 / 수정 167
2016-08-20
*/
#include <stdio.h>
char buf[1000001];
int main()
{
    int cnt;
    cnt = 0;
    while (scanf("%s", buf) == 1)
        cnt++;
    printf("%d\n", cnt);
    return 0;
}

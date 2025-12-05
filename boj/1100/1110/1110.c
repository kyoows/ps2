/*
1110 - 더하기 사이클
4035327	helloneo 1110 맞았습니다!! 1116 0 C99
*/
#include <stdio.h>
#include <string.h>
int main()
{
    int n, m;
    int a, b;
    int cnt;
    char check[100];
    while (scanf("%d", &n) == 1) {
    m = n;
    cnt = 1;
    while (1) {
        a = m/10 + m%10;
        b = (m%10)*10 + (a%10);
        if (b == n)
            break;
        cnt++;
        m = b;
    }
    printf("%d\n", cnt);
    }
    return 0;
}
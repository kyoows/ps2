/*
 * 1145 - 적어도 대부분의 배수
 * 29806873 helloneo  1145 맞았습니다!! 1116 0 C99 / 수정 658
 * 2021-06-04
 */
#include <stdio.h>
#include <string.h>
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}
long long lcm(long long a, long long b)
{
    return a*(b/gcd(a, b));
}
int main()
{
    long long num[5];
    int i, j, k;
    long long min1, temp;
    for (i = 0; i < 5; i++) {
        scanf("%lld", &num[i]);
    }
    min1 = lcm(lcm(num[0], num[1]), num[2]);
    for (i = 0; i < 5; i++) {
    for (j = i+1; j < 5; j++) {
    for (k = j+1; k < 5; k++) {
        temp = lcm(lcm(num[i], num[j]), num[k]);
        if (temp < min1)
            min1 = temp;
    }
    }
    }
    printf("%lld\n", min1);
    return 0;
}

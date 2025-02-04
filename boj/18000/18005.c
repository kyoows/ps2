/*
 * 18005 - Even or Odd
 * 27593340	helloneo	 18005	맞았습니다!!	1116	0	C99
 */
#include <stdio.h>
#include <string.h>
int main()
{
    long long n;
    while (scanf("%lld", &n) == 1 && n) {
        if ((n % 2) == 1) {
            printf("0\n");
        }
        else {
            n /= 2;
            if (n % 2 == 0) {
                printf("2\n");
            }
            else {
                printf("1\n");
            }
        }
    }
    return 0;
}
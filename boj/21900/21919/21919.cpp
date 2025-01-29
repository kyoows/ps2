/*
 * 21919 - 소수 최소 공배수
 * 89307617 helloneo 21919  맞았습니다!! 2980 8 C++17
 *
 */
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN (1000010)

char is_prime[MAXN];
int prime_cnt;
vector<int> prime;

void sieve(int n)
{
    int i, j;
    memset(is_prime, -1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for (i = 2; i <= n; i++) {
        if (is_prime[i]) {
            for (j = i; i+j <= n; j += i) {
                is_prime[i+j] = 0;
            }
            prime.push_back(i);
        }
    }
}

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    int n, i;
    long long num;
    long long l;
    sieve(1000000);
    while (scanf("%d", &n) ==1 && n) {
        l = -1;
        for (i = 0; i < n; i++) {
            scanf("%lld", &num);
            if (is_prime[num]) {
                if (l == -1)
                    l = num;
                else
                    l = lcm(l, num);
            }
        }
        printf("%lld\n", l);
    }
    return 0;
}

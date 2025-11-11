/*
 * 4948 - Chebyshev's Theorem
 * 100142898 helloneo  4948 맞았습니다!! 2336 4 C++17
 */
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN (1000010)

char is_prime[MAXN];
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

int main()
{
    int n;
    int i, cnt;
    sieve(123456*2);
    while (scanf("%d", &n) == 1 && n != 0) {
        cnt = 0;
        for (i = n+1; i <= 2*n; i++) {
            if (is_prime[i]) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}
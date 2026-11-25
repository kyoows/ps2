/*
 * Sieve of Eratosthenes
 *
 * test: boj-21919 소수 최소 공배수
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
    prime.clear();
    sieve(1000000);
    return 0;
}

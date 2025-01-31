/*
 * Big Mod
 *
 * (a^b) % m
 *
 * testing: boj-1009
 */
#include <stdio.h>
#include <string.h>
long long bigmod(long long a, long long b, long long m)
{
    long long res;
    if (b == 0)
        return 1;
    if (b & 1)
        return ((a%m) * (bigmod(a, b-1, m) % m)) % m;
    res = bigmod(a, b/2, m);
    return ((res%m) * (res%m)) % m;
}

int main()
{
    return 0;
}

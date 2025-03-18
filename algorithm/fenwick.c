/* Fenwick Tree (Binary Indexed Tree) */

#include <stdio.h>
#include <string.h>
#define MAXN 200001
int n, num[MAXN], bit[MAXN];

/* add w to num[i] */
void add(int i, int w)
{
    while (i <= n) {
        bit[i] += w;
        i += (i & (i ^ (i-1)));
    }
}

/* return the cumulative sum up to num[i] */
int rank(int i)
{
    int sum;
    sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= (i & (i ^ (i-1)));
    }
    return sum;
}


int main()
{
    int i, a, b;
    scanf("%d", &n);
    memset(bit, 0, sizeof(bit));
    for (i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
        add(i, num[i]);
    }
    return 0;
}
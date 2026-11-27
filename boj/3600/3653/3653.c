/*
5902 - Movie collection
1724970 helloneo Accepted ANSI C 0.148 2015-07-19 12:34:12
*/
/*
1513 - Movie collection
13197709 helloneo Accepted ANSI C 0.192  2014-02-23 12:55:04
*/
/* Binary Indexed Tree */

#include <stdio.h>
#include <string.h>
#define MAXN 200011
int n, num[MAXN], bit[MAXN];
int pos[MAXN];

/* add w to num[i] */
void add(int i, int w)
{
    while (i <= n) {
        bit[i] += w;
        i += (i & (i ^ (i-1)));
    }
}

/* return the cumulative sum up to num[i] */
int rank(i)
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
    int tc;
    int a, b;
    int i, j, k;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &a, &b);
        n = a+b+1;
        memset(bit, 0, sizeof(bit));
        for (i = 1; i <= a; i++) {
            pos[i] = b+i;
            add(b+i, 1);
        }
        for (i = 0; i < b; i++) {
            scanf("%d", &k);
            printf("%d", rank(pos[k])-1);
            if (i == b-1)
                printf("\n");
            else
                printf(" ");
            add(pos[k], -1);
            pos[k] = b-i;
            add(pos[k], 1);
        }
    }
    return 0;
}

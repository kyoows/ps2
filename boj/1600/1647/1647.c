/*
 * 1647 - 도시 분할 계획
 * 88984941 helloneo 1647 맞았습니다!! 24944 552 C99
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 100001
#define MAXM 1000001
typedef struct _edge {
    int v1, v2;
    int w;
} EDGE;
EDGE edge[MAXM];
int union_no[MAXN];
int n, m;
int comp(const void* x, const void* y)
{
    EDGE* a = (EDGE*)x;
    EDGE* b = (EDGE*)y;
    if (a->w < b->w)
        return -1;
    else if (a->w > b->w)
        return 1;
    return 0;
}
int union_find(int u)
{
    if (union_no[u] == u)
        return u;
    return union_no[u] = union_find(union_no[u]);
}
int kruskal()
{
    int i, r1, r2;
    int sum;
    int lastw;
    /* 1-based index */
    for (i = 1; i <= n; i++) {
        union_no[i] = i;
    }
    qsort(edge, m, sizeof(EDGE), comp);
    sum = 0;
    lastw = 0;
    for (i = 0; i < m; i++) {
        r1 = union_find(edge[i].v1);
        r2 = union_find(edge[i].v2);
        if (r1 == r2)
            continue;
        else if (r1 > r2)
            union_no[r2] = r1;
        else
            union_no[r1] = r2;
        sum += edge[i].w;
        lastw = edge[i].w;
        //printf("connect %d-%d cost=%d\n", edge[i].v1, edge[i].v2, edge[i].w);
    }
    return sum - lastw;
}


int main()
{
    int i, j, k;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &edge[i].v1, &edge[i].v2, &edge[i].w);
    }
    printf("%d\n", kruskal());
    return 0;
}


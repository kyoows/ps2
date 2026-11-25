/* MST (Kruskal) */

/*
 * 1197 - 최소 스패닝 트리
 * 4266882 helloneo  1197 맞았습니다!! 4280 52 1 C99 / 수정 1260
 * 2016-09-19
 */

#include <stdio.h>
#include <string.h>
#define MAXN 10001
#define MAXM 100001
typedef struct _edge {
    int v1, v2;
    double w;
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
double kruskal()
{
    int i, r1, r2;
    double sum;
    /* 1-based index */
    for (i = 1; i <= n; i++) {
        union_no[i] = i;
    }
    qsort(edge, m, sizeof(EDGE), comp);
    sum = 0;
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
        /*printf("connect %d - %d\n", edge[i].v1, edge[i].v2);*/
    }
    return sum;
}


int main()
{
    int i, j, k;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d%d%lf", &edge[i].v1, &edge[i].v2, &edge[i].w);
    }
    printf("%.0lf\n", kruskal());
    return 0;
}

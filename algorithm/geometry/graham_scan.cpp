#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define EPS 1e-12

typedef struct _p {
    double x, y;
} POINT;
POINT base_pt;

double distance(POINT p1, POINT p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

int ccw(POINT a, POINT b, POINT c)
{
    double l = (a.x*b.y+b.x*c.y+c.x*a.y) - (a.y*b.x+b.y*c.x+c.y*a.x);
    if (fabs(l) < EPS)
        return 0;
    if (l > 0)
        return 1;
    return -1;
}

bool comp(const POINT& a, const POINT& b)
{
    int r;
    double d1, d2;
    r = ccw(base_pt, a, b);
    if (r == 0) {
        d1 = distance(base_pt, a);
        d2 = distance(base_pt, b);
        return d1 < d2;
    }
    if (r > 0)
        return true;
    return false;
}

/* make convex hull in counter-clockwise manner */
void graham_scan(vector<POINT> a, vector<POINT>& convex)
{
    int i, size, min_idx;

    convex.clear();
    size = a.size();
    min_idx = 0;
    for (i = 1; i < size; i++) {
        if (a[min_idx].y > a[i].y)
            min_idx = i;
        else if (a[min_idx].y == a[i].y && a[min_idx].x > a[i].x)
            min_idx = i;
    }
    base_pt = a[min_idx];
    a[min_idx] = a[size-1];
    a.pop_back();
    sort(a.begin(), a.end(), comp);

    convex.push_back(base_pt);
    convex.push_back(a[0]);

    for (i = 1; i < (int)a.size(); i++) {
        size = convex.size();
        /* if the points ON LINE is allowed, change '<=' to '<' */
        while(ccw(convex[size-2], convex[size-1], a[i]) <= 0 && size > 1) {
            convex.pop_back();
            size--;
        }
        convex.push_back(a[i]);
    }
}


int main()
{
    int n, i;
    POINT pt;
    vector<POINT> pts;
    vector<POINT> convex;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%lf%lf", &pt.x, &pt.y);
        pts.push_back(pt);
    }
    graham_scan(pts, convex);
    printf("%lu\n", convex.size());
    return 0;
}
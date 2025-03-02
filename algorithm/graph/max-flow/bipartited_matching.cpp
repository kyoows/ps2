#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <iostream>  
#include <queue>  
#include <vector>  
#include <algorithm>  
using namespace std;  
#define MAXN 8000

int n;
vector<int> graph[MAXN];
int match[MAXN];
char used[MAXN];

int dfs(int u)  
{  
    int i, v, w;
    used[u] = 1;
    for(i = 0; i < graph[u].size(); i++) {
        v = graph[u][i];
        w = match[v];
        if (w < 0 || (!used[w]&&dfs(w))) { 
            match[u]=v;  
            match[v]=u;  
            return 1;
        }  
    }  
    return 0;
}  

int bipartite_matching()  
{  
    int res, i;
    res = 0;
    memset(match,-1,sizeof(match));  
    for(i = 0; i < n; i++){  
        if(match[i] < 0) {  
            memset(used, 0, sizeof(used));  
            if (dfs(i)) {
                res++;  
            }  
        }  
    }  
    return res;  
}  


int main()  
{  
    return 0;  
}  


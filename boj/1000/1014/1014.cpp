/*
 * 1014 - No Cheating (Small)
 * 20389229 helloneo 1014 맞았습니다!! 2220 0 C++17
 */
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


void add_edge(int u, int v)
{  
    graph[u].push_back(v);  
    graph[v].push_back(u);  
}  

const int dx[]={-1,-1,1,1};  
const int dy[]={-1,0,-1,0};  

int M,N;  
char seat[100][100];  

void solve()  
{  
    int num=0;  
    n = N*M;
    for(int v=0; v < n; v++){  
        graph[v].clear();  
    }  
    for(int y=0;y<M;y++){  
        for(int x=0;x<N;x++){  
            if(seat[y][x]=='.'){  
                num++;  
                for(int k=0;k<4;k++){  
                    int y2=y+dy[k];  
                    int x2=x+dx[k];  
                    if(0<=x2&&x2<N&&0<=y2&&y2<M&&seat[y2][x2]=='.'){  
                        add_edge(x*M+y,x2*M+y2);  
                    }  
                }  
            }  
        }  
    }  
    printf("%d\n",num-bipartite_matching());  
}  

int main()  
{  
    int tc;
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d%d",&M,&N);  
        for(int i=0;i<M;i++){  
            for(int j=0;j<N;j++){  
                cin>>seat[i][j];  
            }  
        }  
        solve();  
    }  
    return 0;  
}  


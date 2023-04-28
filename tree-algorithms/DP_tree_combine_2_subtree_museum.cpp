//https://oj.vnoi.info/problem/lqdnt_dptree11_museum

#include <bits/stdc++.h>
#define MAXN 10005
#define TASK "1"
#define ff first
#define ss second
#define pb push_back
#define SET_decimal(n) cout << std::fixed << std::setprecision(n);
#define WATCH_arr(a,l,r) { for (int i=(l);i<=(r);i++) cerr<<a[i]<<' '; }
#define WATCH_a2D(a, n, m) { cerr << #a << ":\n" ; for(int i=1;i<=(n);i++, cerr <<'\n') for(int j=1;j<=(m);j++) cerr << ' ' << a[i][j]; }
#define WATCH_vec(a) { cerr << #a << ":\n"; for(auto _:a) cerr << ' ' << _; cerr << "\n"; }
using namespace std;
typedef  pair<int,int> pii;
//-----------------------------------------------------
int n, k ,x , sz[MAXN] , dp[MAXN][MAXN][2];     //dp[u][x][0] = Tổng thời gian nhỏ nhất khi xp tại u, thăm x nút con (kể cả u) và 0: không trở lại u ;  1: trở lại u
vector<pii> adj[MAXN];                          
int const INF = 1e9;
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    cin>>n>>k>>x;
    int u,v,w;
    for(int i=1;i<n;i++){
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
}
void findsz(int u, int par){
    sz[u] = 1;
    for(auto x: adj[u]){
        int v = x.ff, w = x.ss;
        if (v==par) continue;
        findsz(v,u);
        for(int i = sz[u]+sz[v]; i>=2 ; i--)
            for(int j = max(0,i-sz[u]); j<=min(i,sz[v]); j++)
                {
                dp[u][i][0] = min(dp[u][i][0], dp[u][i-j][0] + dp[v][j][1]+2*w);
				        dp[u][i][0] = min(dp[u][i][0], dp[u][i-j][1] + dp[v][j][0]+w);
				        dp[u][i][1] = min(dp[u][i][1], dp[u][i-j][1] + dp[v][j][1]+2*w);
	              }
        sz[u]+=sz[v];
    }
}

signed main(){
    enter();
    for(int i=1; i<=n; i++){
        for(int j=2; j<=n; j++){
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    findsz(x,0);
    cout << dp[x][k][0];
    return 0;
}

#include <bits/stdc++.h>
#define MAXN 200005
#define TASK "1"
#define ff first
#define ss second
#define pb push_back
#define SET_decimal(n) cout << std::fixed << std::setprecision(n);
#define WATCH_arr(a,l,r) { for (int i=(l);i<=(r);i++) cerr<<a[i]<<' '; };
#define WATCH_a2D(a, nrow, ncol) { cerr << #a << ":\n"; for(int i=1;i<=(nrow);i++, cerr <<'\n') for(int j=1;j<=(ncol);j++) cerr << ' ' << a[i][j]; }
#define WATCH_vec(a) { cerr << #a << ':'; for(auto _:a) cerr << ' ' << _; cerr << '\n'; }
#define pii pair<int,int>
#define int long long
using namespace std;
int n,dp0[MAXN],dp1[MAXN];
vector<int> adj[MAXN];
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
void dfs(int u, int par){
    for(int v:adj[u]){
        if (v==par) continue;
        dfs(v,u);
        int _old = dp0[u];                          //Luu lai dp0[u] truoc khi bi cap nhat gia tri moi. Đoạn này có thể chuyển xuống dưới thì ko cần biến _old
        dp0[u]+=max(dp0[v],dp1[v]);
        int tmp1 = dp1[u] + max(dp0[v],dp1[v]);     //TH1: Ko lay canh u->v
        int tmp2 = _old + 1 + dp0[v];               //TH2: Lay canh u->v
        dp1[u] = max(tmp1,tmp2);
    }
}
signed main()
{
     enter();
     dfs(1,0);
     cout<<max(dp0[1],dp1[1]);
     return 0;
}

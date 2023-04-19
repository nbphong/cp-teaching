//https://cses.fi/problemset/task/1130/
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
        dp0[u]+=max(dp0[v],dp1[v]);   //Tính tổng số cạnh được chọn trong cây gốc u mà không chọn bất kì cạnh con nào từ u
        }
    for(int v:adj[u]){                //Khi đã tính xong dp0[u] cho mọi nút con của u, ta duyệt lại lần nữa các nút v con u
        if (v==par) continue;         //Tìm 1 nút v để chọn sao cho dp1[u] đạt max
        dp1[u] = max(dp1[u], dp0[u] - max(dp0[v],dp1[v])+dp0[v] + 1);
    }
 
}
signed main()
{
     enter();
     dfs(1,0);
     cout<<max(dp0[1],dp1[1]);
     return 0;
}

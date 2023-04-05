#include <bits/stdc++.h>
#define MAXN 10
#define TASK "1"
#define ff first
#define ss second
#define pb push_back
#define SET_decimal(n) cout << std::fixed << std::setprecision(n);
#define WATCH_arr(a,l,r) { for (int i=(l);i<=(r);i++) cerr<<a[i]<<' '; }
#define WATCH_a2D(a, n, m) { cerr << #a << ":\n"; for(int i=1;i<=(n);i++, cerr <<'\n') for(int j=1;j<=(m);j++) cerr << ' ' << a[i][j]; }
#define WATCH_vec(a) { cerr << #a << ":"; for(auto _:a) cerr << ' ' << _; cerr << "\n"; }
#define pii pair<int,int>
#define pll pair<long long, long long>
#define ll long long
using namespace std;
int n, toleaf[MAXN],maxlen[MAXN];
vector<int> adj[MAXN];
//---------------------------------------------
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen(TASK".inp","r",stdin);//    freopen(TASK".out","w",stdout);
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
void dfs(int u, int par){
for(int v:adj[u])
    if (v!=par)
    {
    dfs(v,u);
    int _old = toleaf[u], _new = toleaf[v]+1;
    toleaf[u] = max(toleaf[u],toleaf[v]+1);
    maxlen[u] = max(maxlen[u],_old + _new);
    }
}

int main()
{
    enter();
    dfs(1,0);
    cout<<*max_element(&maxlen[1],&maxlen[n+1]);
    return 0;
}

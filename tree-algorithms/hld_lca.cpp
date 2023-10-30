#include <bits/stdc++.h>
#define MAXN 200005
#define TASK "1"
#define ff first
#define ss second
#define pb push_back
#define SET_decimal(n) cout << std::fixed << std::setprecision(n);
#define WATCH_arr(a,l,r) { for (int i=(l);i<=(r);i++) cerr<<a[i]<<' '; }
#define WATCH_a2D(a, n, m) { cerr << #a << ":\n"; for(int i=1;i<=(n);i++, cerr <<'\n') for(int j=1;j<=(m);j++) cerr << ' ' << a[i][j]; }
#define WATCH_vec(a) { cerr << #a << ":"; for(auto _:a) cerr << ' ' << _; cerr << "\n"; }
#define INIT(a,v) memset(a,v,sizeof(a))
//#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
//template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }
#define ll long long
#define pii pair<int,int>
using namespace std;
int n,q,sz[MAXN],t_in[MAXN],id[MAXN],timer,tp[MAXN],par[MAXN],depth[MAXN];
vector<int> adj[MAXN];
//---------------------------------------------
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    cin>>n>>q;
    int x;
    for(int i=1;i<n;i++){
        cin>>x;
        adj[i+1].pb(x), adj[x].pb(i+1);
        par[i+1]=x;
    }
}
void getsz(int u,int par){    // Lấy kích thước các cây gốc u, đồng thời tính độ sâu các nút
sz[u]=1;
for(int v:adj[u])
if (v!=par) {
    depth[v]=depth[u]+1;
    getsz(v,u);
    sz[u]+=sz[v];

    }
}
void dfs(int u, int par, int top){
t_in[u]=++timer; id[timer]=u; tp[u] = top;        
int mx=-1, bigchild = -1;
for(auto v:adj[u])
    if (v!=par && sz[v]>mx) mx=sz[v], bigchild = v;
if (bigchild==-1) return;
//-------------------------------------------------
dfs(bigchild,u,top);
for(auto v:adj[u])
    if (v!=par && v!=bigchild)
    dfs(v,u,v);
}
int lca(int u, int v){
while (tp[u]!=tp[v]){
    if (depth[tp[u]]<depth[tp[v]]) swap(u,v);
    u = par[tp[u]];
    }
return (t_in[u]<t_in[v]?u:v);

}
int main()
{
    enter();
    getsz(1,0);
    dfs(1,0,1);
    int x,y;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<lca(x,y)<<'\n';
        }
    return 0;
}

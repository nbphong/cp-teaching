//https://oj.vnoi.info/problem/mincost - Chú ý là đồ thị được cho là vô hướng
#include <bits/stdc++.h>
#define MAXN 222
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
#define int long long
using namespace std;
int n,m,k,s,t,tot_flow, tot_cost;
struct Edges{
int u, v, cap, flow, cost;
};
vector<int> adj[MAXN];
vector<Edges> edge;
int cha[MAXN],inQ[MAXN],d[MAXN];
int const INF = 1e15;
//---------------------------------------------
void addEgde(int u, int v, int cap, int cost){
int m = edge.size();
edge.pb({u,v,cap,0,cost});
edge.pb({v,u,0,0,-cost});
adj[u].pb(m); adj[v].pb(m+1);
}
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    cin>>n>>m>>k>>s>>t;
    int u,v,c,d;
    for(int i=1;i<=m;i++) {
        cin>>u>>v>>c>>d;
        addEgde(u,v,d,c);
        addEgde(v,u,d,c);
    }
    addEgde(0,s,k,0); addEgde(s,0,0,0); s = 0;
}
bool findpath(){
fill(d,d+n+1,INF); d[s] = 0; memset(cha,0,sizeof(cha)); memset(inQ,0,sizeof(inQ));
deque<int> Q; Q.pb(s); inQ[s]=true; d[s] = 0;
while (!Q.empty()){
    int u = Q.front(); Q.pop_front(); inQ[u] = false;
    for(int i: adj[u]){
        auto e = edge[i]; int v = e.v;
        if (e.cap>e.flow && d[v]>d[u]+e.cost)
            {
            d[v] = d[u]+e.cost;
            cha[v] = i;
            if (!inQ[v]) inQ[v]=true, Q.pb(v);
            }
    }
    }
return(d[t]<INF);
}
void incFlow(){
int v = t, delta(INF);
while (v!=s){
    auto e = edge[cha[v]];
    delta = min(delta, e.cap - e.flow);
    v = e.u;
}
v = t;
while (v!=s){
    int xx = cha[v];
    edge[cha[v]].flow  +=delta;
    edge[cha[v]^1].flow-=delta;
    v = edge[cha[v]].u;
}
tot_flow+= delta;
tot_cost+=d[t]*delta;
}
signed main()
{
    enter();
    int S = k;
    while (findpath())
        incFlow();
    if (tot_cost < S) {
        cout << -1;
        return 0;}
    cout << tot_cost <<'\n';
    for(int u=1;u<=n;u++)
        for(int i:adj[u])
            if (edge[i].flow > 0)
        cout << u << " " << edge[i].v << " "<< edge[i].flow << '\n';
    cout << "0 0 0\n";
    return 0;
}

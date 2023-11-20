#include <bits/stdc++.h>
#define MAXN 205
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
#define INIT(a,v) memset(a,v,sizeof(a))
#define ll long long
using namespace std;
int n, c[MAXN][MAXN],matchX[MAXN],matchY[MAXN], cha[MAXN], res;
bool vsX[MAXN],vsY[MAXN];
vector<int> adjX[MAXN];
//---------------------------------------------
int findpath(int u){
INIT(vsX,0); INIT(vsY,0); INIT(cha,0);
deque<int>Q; Q.pb(u);
while (!Q.empty()){
    int u = Q.front(); Q.pop_front();vsX[u]=true;
    for(int v:adjX[u])
    if (c[u][v]==0 && !vsY[v]){
        cha[v]=u, vsY[v]=true;
        if (matchY[v]==0) return v;
            else
                Q.pb(matchY[v]);
        }
    }
return 0;
}
void enlarge(int v){
while (v!=0){
    int u = cha[v], next = matchX[u];
    matchX[u] = 0; matchY[next] = 0;
    matchX[u] = v; matchY[v] = u;
    v = next;
    }
}
void enter(){
ios::sync_with_stdio(false); cin.tie(NULL);
freopen(TASK".inp","r",stdin);
memset(c,0x3f,sizeof(c));
cin>>n;
while(!cin.eof()) {
    int x,y,z; cin>>x>>y>>z; c[x][y] = z;
    adjX[x].pb(y);
    }
}
void change(){
int delta = (int)1e9;
for(int u=1;u<=n;u++)
    if (vsX[u])
        for(int v=1;v<=n;v++)
            if (!vsY[v] && c[u][v]<delta) delta = c[u][v];
for(int u=1;u<=n;u++)
    if (vsX[u])
        for(int v=1;v<=n;v++) c[u][v]-=delta;
for(int v=1;v<=n;v++)
    if (vsY[v])
        for(int u=1;u<=n;u++) c[u][v]+=delta;
res+=delta;
}
//-----------------------------------------------------------------------------
int main(){
    enter();
    /*Xet tuan tu cac dinh CHUA GHEP, voi moi dinh u, tim DUONG PHA di tu u . Co 2 kha nang:
    TH1: - Ket thuc tai v thuoc Y chua ghep -> Day la DUONG MO ->findpath(u)=v -> Noi rong bo ghep
    TH2: - Ket thuc tai u thuoc X ->Day la DUONG PHA ->findpath(u)=0 ->Bien doi do thi.
    Chu y: Neu duong pha co do dai > 0 thi no la duong xen ke: u->v(chua ghep)->u1(da ghep)->v1(chua ghep)->...->vn (da ghep)
           Neu duong pha co do dai =0, tuc la tu u khong di chuyen duoc buoc nao. Ca 2 TH tren, findpath(u) deu cho ra KQ = 0.
    Do phuc tap: findpath(): O(n+m) = O(m), change(): O(n^2).
    Vong lap while: Moi luot thuc hien, co it nhat 1 canh tro thanh 0_canh. Do do vong while thuc hien toi da m lan
    Do phuc tap chung O(n^2*m^2)
    */
    for(int u=1;u<=n;u++)
    while (true){
        int v = findpath(u);
        if (v!=0)
            {enlarge(v); break;}
        else
            change();
        }
    cout<<res<<'\n';
    for(int u=1;u<=n;u++)
        if (matchX[u]!=0) cout<<u<<" "<<matchX[u]<<'\n';
    return 0;
}

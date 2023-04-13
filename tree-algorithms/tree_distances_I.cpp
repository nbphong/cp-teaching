//https://cses.fi/problemset/task/1133

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
#define pii pair<int,int>
#define pll pair<long long, long long>
#define ll long long
using namespace std;
int n, fpath[MAXN], spath[MAXN],fchild[MAXN],schild[MAXN];
vector<int>adj[MAXN];
//---------------------------------------------
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen(TASK".inp","r",stdin);//    freopen(TASK".out","w",stdout);
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++) {
        cin>>u>>v;
        adj[u].pb(v);adj[v].pb(u);
    }
}
 
void dfs1(int u, int par){
for(int v:adj[u]){
    if (v==par) continue;
    dfs1(v,u);
    if (fpath[u] < fpath[v]+1){     //Nếu đường đi từ u đến v dài hơn đường đi dài nhất thì cập nhật đ.đi dài nhất -> đường đi mới
        spath[u] = fpath[u];                                                                //đ.đi dài nhì = đường đi dài nhất cũ
        fpath[u] = fpath[v]+1;      //Cập nhật v thuộc đ.đi dài nhất từ v và nút con cũ sẽ thuộc đường đi dài nhì
        schild[u] = fchild[u];
        fchild[u] = v;
        }
        else
            if (spath[u]<fpath[v]+1){
                spath[u] = fpath[v]+1;
                schild[u] = v;
            }
        }
}
void dfs2(int u, int par){          //dfs từ trên xuống, điều này cho phép ta tạo ra các đường đi ngược từ dưới lên rồi vào các nhánh khác
for(int v:adj[u]){
    if (v==par) continue;
    if (fchild[u]==v){              //TH1: v nằm trên đ.đi dài nhất từ u
        if (fpath[v]<spath[u]+1){   //Chỉnh lại đ.đi dài nhất từ v = max (fpath[v], spath[u]+1)
            spath[v] = fpath[v];
            fpath[v] = spath[u]+1;
            schild[v] = fchild[v];
            fchild[v] = u;
            }
            else                    //Nếu ko chỉnh được đ.đi dài nhất thì chỉnh lại đ.đi dài nhì
            if (spath[v]<spath[u]+1){
                spath[v]=spath[u]+1;
                schild[v] = u;
                }
    }
    else                            //TH2: v không nằm trên đ.đi dài nhất từ u
    if (fpath[v]<fpath[u]+1){
        spath[v] = fpath[v];
        fpath[v] = fpath[u]+1;
        schild[v] = fchild[v];
        fchild[v] = u;
        }
        else
            if (spath[v]<fpath[u]+1){
                spath[v]=fpath[u]+1;
                schild[v] = u;
                }
    dfs2(v,u);
    }
}
int main()
{
    enter();
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++) cout<<fpath[i]<<" ";
    return 0;
}

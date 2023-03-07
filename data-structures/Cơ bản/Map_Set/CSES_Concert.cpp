//https://cses.fi/problemset/result/5571047/
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
//---------------------------------------------
int n,m,k,ans,a[MAXN],x;
multiset<int> S;
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen(TASK".inp","r",stdin);//    freopen(TASK".out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>x;
        S.insert(x);    //price ticket
    }
    for(int i=1;i<=m;i++) cin>>a[i];    //maximum price can pay
    for(int i=1;i<=m;i++){
        auto id = S.upper_bound(a[i]);
        if (id==S.begin()) cout<<-1<<'\n';
            else{
            cout<<*(--id)<<'\n';
            S.erase(id);
            }
    }
}
int main()
{
    enter();
    return 0;
}

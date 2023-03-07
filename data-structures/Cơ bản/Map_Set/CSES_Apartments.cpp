//https://cses.fi/problemset/view/1084/
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
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];    //size of demand
    for(int i=1;i<=m;i++) {
        cin>>x;
        S.insert(x);    //size of apartment
    }
    sort(&a[1],&a[n+1]);
    for(int i=1;i<=n;i++)
    {
        auto L = S.lower_bound(a[i]-k);
        auto R = S.upper_bound(a[i]+k);
        int tmp = *L, tmp2 = *R;
        if (L==R--) continue;
        ans++;
        S.erase(L);
    }
cout<<ans;
}
 
 
int main()
{
    enter();
    return 0;
}

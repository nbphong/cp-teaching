//https://cses.fi/problemset/task/1163/
#include <bits/stdc++.h>
#define MAXN 10
#define TASK "1"
//#define ff first
//#define second ss
#define pb push_back
#define SET_decimal(n) cout << std::fixed << std::setprecision(n);
#define WATCH_arr(a,l,r) { for (int i=(l);i<=(r);i++) cerr<<a[i]<<' '; }
#define WATCH_a2D(a, n, m) { cerr << #a << ":\n"; for(int i=1;i<=(n);i++, cerr <<'\n') for(int j=1;j<=(m);j++) cerr << ' ' << a[i][j]; }
#define WATCH_vec(a) { cerr << #a << ":"; for(auto _:a) cerr << ' ' << _; cerr << "\n"; }
#define pii pair<int,int>
#define piii pair<int,pii>
#define pll pair<long long, long long>
#define ll long long
using namespace std;
int x, n,pos;
set<piii> S;
set<int>T;
//---------------------------------------------
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    cin>>x>>n;
    S.insert({x,{0,x}});
    T.insert(0); T.insert(x);
    for(int i=1;i<=n;i++){
        cin>>pos;
        T.insert(pos);
        int L = *(--T.lower_bound(pos));
        int R = *(++T.lower_bound(pos));
        S.erase({R-L,{L,R}});
        S.insert({R-pos,{pos,R}});
        S.insert({pos-L,{L,pos}});
        cout<<S.rbegin()->first<<" ";
    }
}
int main()
{
    enter();
 
    return 0;
}

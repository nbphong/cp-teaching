//https://cses.fi/problemset/task/1164/
#include <bits/stdc++.h>
#define MAXN 200005
#define TASK "1"
#define ff first
 
#define pb push_back
#define SET_decimal(n) cout << std::fixed << std::setprecision(n);
#define WATCH_arr(a,l,r) { for (int i=(l);i<=(r);i++) cerr<<a[i]<<' '; }
#define WATCH_a2D(a, n, m) { cerr << #a << ":\n"; for(int i=1;i<=(n);i++, cerr <<'\n') for(int j=1;j<=(m);j++) cerr << ' ' << a[i][j]; }
#define WATCH_vec(a) { cerr << #a << ":"; for(auto _:a) cerr << ' ' << _; cerr << "\n"; }
#define ll long long
using namespace std;
typedef  pair<int,int> pii;
struct Person{
int t_in, t_out,id;};
Person p[MAXN];
set<pii> S,T;
int n,ans(0),a[MAXN];
//---------------------------------------------
bool cmp(Person &lhs, Person &rhs){
return (lhs.t_in<=rhs.t_in);
}
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    cin>>n;
    int x,y;
    for(int i=1;i<=n;i++) {
        cin>>x>>y;
        p[i] = {x,y,i};
        T.insert({0,i});
    }
    sort(&p[1],&p[n+1],cmp);
 
    for(int i=1;i<=n;i++){
        if (!S.empty() && p[i].t_in>S.begin()->ff)
            {
            T.erase({1,S.begin()->second});
            T.insert({0,S.begin()->second});
            S.erase(S.begin());
            }
        int x = T.begin()->second;
        S.insert({p[i].t_out,x});
        a[p[i].id] = x;
        ans =  max(ans,int(S.size()));
        T.erase(T.begin());
        T.insert({1,x});
        }
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
 
}
int main()
{
    enter();
    return 0;
}

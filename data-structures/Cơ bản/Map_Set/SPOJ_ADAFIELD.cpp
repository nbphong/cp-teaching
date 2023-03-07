//https://www.spoj.com/problems/ADAFIELD/
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
#define int long long
using namespace std;
multiset<int> dh,dv,X,Y;     //doc: luu hoanh do cac duong doc, ngang: luu tung do cac duong ngang
int n,m,Q,T;
//---------------------------------------------
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
   // freopen(TASK".inp","r",stdin);//    freopen(TASK".out","w",stdout);
    cin>>T;
}
void init(){
X.clear(); Y.clear(); dh.clear(); dv.clear();
}
void update(multiset<int> &S, int val, int new_val1, int new_val2){
auto it  = S.find(val);
    S.erase(it);
    S.insert(new_val1);
    S.insert(new_val2);
 
}
void solve(int T){
cin>>n>>m>>Q;
X.insert(0); X.insert(n);Y.insert(0); Y.insert(m);
dh.insert(n);dv.insert(m);
pii line;
 
for(int i=1;i<=Q;i++){
    cin>>line.ff>>line.ss;
    if (line.ff==0)
        {
        auto it = X.find(line.ss);
        if (it==X.end()){
            X.insert(line.ss);
            it = X.find(line.ss);
            int L = *(--it); it++;
            int R = *(++it); it--;
            update(dh,R-L,*it-L,R-*it);
            }
        }
    else
        {
        auto it = Y.find(line.ss);
        if (it==Y.end()){
            Y.insert(line.ss);
            it = Y.find(line.ss);
            int L = *(--it); it++;
            int R = *(++it); it--;
            update(dv,R-L,*it-L,R-*it);
            }
        }
    cout<<(*dh.rbegin())*(*dv.rbegin())<<'\n';
    }
}
 
 
signed main()
{
    enter();
    for(int i=1;i<=T;i++){
        init();
        solve(i);
    }
    return 0;
}

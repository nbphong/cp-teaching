// https://oj.vnoi.info/problem/mink - Test yếu, do đó có thể AC với độ phức tạp O(Nlog(N)) thậm chí là O(N^2))
#include <bits/stdc++.h>
#define MAXN 17005
#define TASK "1"
#define ff first
#define ss second
#define pb push_back
#define SET_decimal(n) cout << std::fixed << std::setprecision(n);
#define WATCH_arr(a,l,r) { for (int i=(l);i<=(r);i++) cerr<<a[i]<<' '; }
#define WATCH_a2D(a, n, m) { cerr << #a << ":\n"; for(int i=1;i<=(n);i++, cerr <<'\n') for(int j=1;j<=(m);j++) cerr << ' ' << a[i][j]; }
#define WATCH_vec(a) { cerr << #a << ":"; for(auto _:a) cerr << ' ' << _; cerr << "\n"; }
#define INIT(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
using namespace std;
int n, k, T, a[MAXN];
deque<int> Q;
//---------------------------------------------
void enter(){
    memset(a,0,sizeof(a));
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
}
void solve(){
for(int i=1;i<=n;i++){
    while(!Q.empty() && Q.back()>a[i])		//Lập monotonic Queue để duy trì 1 dãy KHÔNG GIẢM dài nhất 
        Q.pop_back();						//Chú ý nếu đặt điều kiện là Q.back()>=a[i] ta sẽ sai trong test sau: 
    Q.pb(a[i]);								//4 2    
    if (i<k) continue;						//2 2 2 1
    if (i==k)
        cout<<Q.front()<<" ";
        else
            {
            if (!Q.empty() && a[i-k]==Q.front())
                Q.pop_front();
            cout<<Q.front()<<" ";
            }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen(TASK".inp","r",stdin);
    cin>>T;
    while(T)
    {
        enter();
        Q.clear();
        solve();
        T--;
        cout<<'\n';
    }
    return 0;
}


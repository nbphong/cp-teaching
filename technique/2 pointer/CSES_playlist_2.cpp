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
int n, a[MAXN];
set<int>s;
//---------------------------------------------

void solve(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans(1),i(1),j(1);						//Cửa số được xét từ a[i]..a[j]
    s.insert(a[1]);
    while(i<n)
        {
        while (j<n && s.find(a[j+1])!=s.end())	//Xét phần tử tiếp theo a[j+1], nếu nó thuộc cửa số đang xét thì xóa cho đến khi a[j+1] không còn nữa
            {
            s.erase(a[i++]);
            //i++;
            }
        s.insert(a[++j]);						//push a[j+1] vào và cập nhật độ dài max của cửa số
        ans = max(ans,j-i+1);
        if (j==n) break;						//Khi đã xét đến hết các phần tử rồi thì thoát
        }
cout<<ans;
}
int main()
{
    solve();
    return 0;
}

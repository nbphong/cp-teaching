//Bài này có thể được giải bằng nhiều cách: Dùng Order_Set, Segment Tree hoặc BIT đều được. Cách dưới đây minh họa cho kĩ thuật CDQ
//Ý tưởng: Load hết dữ liệu vào mảng a lưu tọa độ các ngôi sao; sort tăng dần theo x. Như vậy, với mỗi a[i] ta cần đếm số ngôi sao có tung độ bé hơn a[i].y
//Chia a thành 2 tập, bên trái (L) và bên phải ta load vào tung độ của các ngôi sao; bên phải ta cần lưu thêm id của chúng
//Xử lý offline bằng cách sort mảng L; lấy mỗi phần tử bên R và truy vấn
#include <bits/stdc++.h>
#define MAXN 200005
#define TASK "stars"
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
int n,star[MAXN],rk[MAXN];
pii a[MAXN];
//---------------------------------------------
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].ff>>a[i].ss;
    sort(&a[1],&a[n+1]);
}
void offline(vector<int> &L, vector<pii> &R){
sort(L.begin(),L.end());
for(auto [i,v]:R)
    star[i]+=upper_bound(L.begin(),L.end(),v)-L.begin();
}
void solve(int l, int r){
if (l==r) return;
int mid = (l+r)/2;
vector<int> L;
vector<pii> R;
for(int i=l;i<=r;i++)
    if (i<=mid) L.pb(a[i].ss);
        else R.pb({i,a[i].ss});
offline(L,R);
solve(l,mid);
solve(mid+1,r);
}
int main()
{
    enter();
    solve(1,n);
    for(int i=1;i<=n;i++) rk[star[i]]++;
    for(int i=0;i<n;i++) cout<<rk[i]<<'\n';
    return 0;
}

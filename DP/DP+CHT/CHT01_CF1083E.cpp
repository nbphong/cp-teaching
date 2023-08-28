//https://codeforces.com/blog/entry/63823 - Convex Hull trick
#include <bits/stdc++.h>
#define MAXN 1000005
#define TASK "1"
#define ff first
#define ss second
#define pb push_back
#define SET_decimal(n) cout << std::fixed << std::setprecision(n);
#define WATCH_arr(a,l,r) { for (int i=(l);i<=(r);i++) cerr<<a[i]<<' '; }
#define WATCH_a2D(a, n, m) { cerr << #a << ":\n"; for(int i=1;i<=(n);i++, cerr <<'\n') for(int j=1;j<=(m);j++) cerr << ' ' << a[i][j]; }
#define WATCH_vec(a) { cerr << #a << ":"; for(auto _:a) cerr << ' ' << _; cerr << "\n"; }
#define INIT(a,v) memset(a,v,sizeof(a))
#define ll long long
#define pii pair<int,int>
using namespace std;
struct rect{
ll x, y, a;
bool operator <(rect other){return x<other.x;};
};
struct line{
ll m,b;
ll eval(ll x){return m*x+b;}
double intersect(line other){
    return double(other.b - b)/(m-other.m);
    }
};
int n;
rect a[MAXN];
deque<line> Q;
ll ans(0);
//---------------------------------------------
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    cin>>n;						//Sắp xếp tăng dần các HCN theo hoành độ
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].a;
    sort(&a[1],&a[n+1]);
}
void solve(){
Q.pb({0,0});
for(int i=1;i<=n;i++)
    {	//Thực hiện truy vấn tại a[i].y: Xét tuần tự từ Q.back(). 
		//Nếu tung độ của Q.back() thấp hơn đường Q.back()-- thì Q.back() là đường vô dụng->loại bỏ
		//Điều này được mô tả như việc kéo 1 "tấm màn" đến vị trí a[i].y. Khi đó các đường trong 
		//bao lồi không bị che bởi "tấm màn" này sẽ giữ lại, ngược lại thì cần xóa chúng đi
    while (Q.size()>=2 && Q.back().eval(a[i].y)<Q[Q.size()-2].eval(a[i].y)) Q.pop_back();
    ll tmp = -a[i].a + a[i].x*a[i].y+ Q.back().eval(a[i].y);
    ans = max(ans, tmp);
    line cur = {-a[i].x,tmp};
		//Chèn đường cur vào Q. Nếu cur khiến cho đường trái cùng của bao lồi trở thành vô dụng
		//thì cần xóa đường trái cùng tại Q[0]
		//Đường d là vô dụng nếu HĐGD của d và cur >= HĐGD của d và đường trước nó trong bao lồi
    while (Q.size()>=2 && cur.intersect(Q[0]) >=Q[0].intersect(Q[1])) Q.pop_front();
    Q.push_front(cur);
    }
cout<<ans;
}
int main()
{
    enter();
    solve();
    return 0;
}

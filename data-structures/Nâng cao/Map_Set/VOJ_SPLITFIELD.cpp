//https://oj.vnoi.info/problem/lqdnt_mapset02_splitfarm
// Nhận xét quan trọng: Để có 1 hcn bao phủ tập hợp các điểm, ta cần biết hoành độ nhỏ nhất, lớn nhất, tung độ nhỏ nhất, tung độ lớn nhất của các điểm
//- Tạo 4 multiset leftX, leftY, rightX, rightY để truy vấn giá trị nhỏ nhất, giá trị lớn nhất của hoành độ, tung độ hai miền.
//- Ban đầu leftX, leftY rỗng và rightX, rightY chứa mọi điểm.
//- Nếu quét ngang, sắp tăng dần các điểm theo hoành độ. Với mỗi điểm được xét: 
    //Đẩy vào leftX, leftY và xóa khỏi rightX, rightY.
    //Tính diện tích hcn bao phủ mỗi bên với điều kiện rightX, rightY khác rỗng
    //Cập nhật kết quả.
//- Lặp lại tương tự với việc quét dọc.
#include <bits/stdc++.h>
#define MAXN 50005
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
multiset<int> LX, LY, RX, RY;
pii a[MAXN];
int n;
int ans1,ans2;
bool cmp(const pii &lhs, const pii &rhs){
if (lhs.ss==rhs.ss)
        return (lhs.ff<rhs.ff);
    else return (lhs.ss<rhs.ss);
}
//---------------------------------------------
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen(TASK".inp","r",stdin);//freopen(TASK".out","w",stdout);
    cin>>n;
    int x,y;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        a[i] = {x,y};
        RX.insert(x);     //Đưa mọi điểm vào RX và tính được hcn bao phủ mọi điểm-> ans1 = diện tích nếu không xây 2 hàng rào
        RY.insert(y);     
    }
    ans1 = (*RX.rbegin()- *RX.begin())*(*RY.rbegin()- *RY.begin());
}
void solve(multiset<int> RX, multiset<int> LX, multiset<int> RY, multiset<int> LY){
for(int i=1;i<=n;i++)                         //Xét tuần tự các điểm, nếu các điểm được xếp tăng theo hoành độ -> quét ngang
    {                                         //                      nếu các điểm được xếp tăng theo tung độ -> quét dọc
    int tmp1(0), tmp2(0);
    auto it = RX.find(a[i].ff); RX.erase(it); //Xóa điểm thứ i và đưa nó vào LX, LY; tính diện tích bao phủ mỗi bên   
         it = RY.find(a[i].ss); RY.erase(it);

    if (!RX.empty())
        tmp1 = (*RX.rbegin()- *RX.begin())*(*RY.rbegin()- *RY.begin());
    LX.insert(a[i].ff); LY.insert(a[i].ss);
    tmp2 = (*LX.rbegin()- *LX.begin())*(*LY.rbegin()- *LY.begin());
    ans2 = max(ans2,ans1 - tmp1 - tmp2);
    }
}

signed main()
{
    enter();
    sort(&a[1],&a[n+1]);
    solve(RX,LX, RY, LY);
    sort(&a[1],&a[n+1],cmp);
    solve(RX,LX, RY, LY);
    cout<<ans2;
    return 0;
}

//https://oj.vnoi.info/problem/lqdnt_sweep04

#include <bits/stdc++.h>
#define MAXN 100005
#define MAXM 100005
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
struct line{
int x, y, h, type;} a[MAXN];
int n,m(-1e5);
int segtree[4*MAXM],cnt[4*MAXM];
bool cmp(line &lhs, line &rhs){					//Mỗi đoạn thẳng ta lưu 4 thông tin: tọa độ điểm dưới, độ dài; type=1: đường bắt đầu, type=2: đường kết thúc
if (lhs.x==rhs.x) return (lhs.type>rhs.type);	//Sắp xếp tăng dần theo hoành độ; nếu 2 đường trùng nhau, đường kết thúc được xếp trước để xử lý
else											//Ta lập segment tree để tìm độ dài các tung độ bị phủ. Tổng độ dài các đoạn bị phủ là segtree[1]
    return (lhs.x<rhs.x);						//Và 1 mảng tương ứng là cnt[4*MAXM] để đếm số lần bị phủ của các đoạn
}
//---------------------------------------------
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    cin>>n;
    int x, y, z, t,minX(1e5), minY(1e5);		//Vì segment tree ko thể xử lý giá trị âm nên tất cả các tung độ được dời lên 1 lượng là minY
    for(int i=1;i<=2*n;i+=2){					//Có thể làm khác bằng cách cộng toàn bộ cho 5000 nhưng khó debug
        cin>>x>>y>>z>>t;
        minX = min(minX,x); minY = min(minY,y); m = max(m,t);
        a[i]   = {x,y,t-y,1};
        a[i+1] = {z,y,t-y,2};
    }
    for(int i=1;i<=2*n;i++){
        a[i].x-=minX; a[i].y-=(minY-1);
        }
    sort(&a[1],&a[2*n+1],cmp);
    m-=(minY-1);
}

void upd(int x, int l, int r, int i, int j, int val){
if (i>r || j<l) return;
if (i<=l && j>=r){
    cnt[x]+=val;
    if (cnt[x]>0)								//Nếu số lần bị phủ của đoạn [l;r]>0 thì độ dài đoạn đó là (r-l+1)
        segtree[x] = (r-l+1);
        else									//Nếu 1 đoạn bị xóa dẫn tới số lần bị phủ của đoạn đó = 0 thì cập nhật lại thông tin cho đoạn đó dựa vào 2 nút con
        segtree[x]= segtree[2*x] + segtree[2*x+1];	//Lưu ý rằng lúc này thông tin của 2 nút con là OK
    return;
    }
int mid = (l+r)/2;

upd(2*x,  l,  mid,i,j,val);
upd(2*x+1,mid+1,r,i,j,val);
if (cnt[x]==0)									//Khi đẩy thông tin từ 2 nút con lên nút x thì cnt[x] phải bằng 0 vì nếu cnt[x] khác 0 segtree[x] sẽ phải là (r-l+1)
    segtree[x] = segtree[2*x]+segtree[2*x+1];
}

void process(){
int ans(0),h;
upd(1,1,m,a[1].y,a[1].y+a[1].h-1,1);
//h = segtree[1];
for(int i=2;i<=2*n;i++){
    line cur = a[i], prev = a[i-1];
    ans += (cur.x - prev.x)*segtree[1];
    if (a[i].type==1)
        upd(1,1,m,cur.y,cur.y+cur.h-1,1);
        else
            {
            upd(1,1,m,cur.y,cur.y+cur.h-1,-1);
            }
    }
cout<<ans;
}
int main()
{
    enter();
    process();
    return 0;
}

#include <bits/stdc++.h>
#define MAXN 10
#define TASK "name"
#define ff first
#define ss second
#define pb push_back
#define SET_decimal(n) cout << std::fixed << std::setprecision(n);
#define WATCH_arr(a,l,r) { for (int i=(l);i<=(r);i++) cerr<<a[i]<<' '; }
#define WATCH_a2D(a, n, m) { cerr << #a << ":\n"; for(int i=1;i<=(n);i++, cerr <<'\n') for(int j=1;j<=(m);j++) cerr << ' ' << a[i][j]; }
#define WATCH_vec(a) { cerr << #a << ":"; for(auto _:a) cerr << ' ' << _; cerr << "\n"; }
#define ll long long
using namespace std;
typedef  pair<int,int> pii;
//---------------------------------------------
int n, segtree[4*MAXN],lazy[4*MAXN];

void update(int x, int l, int r, int i, int j, int val){
if (lazy[x]!=0){    		//Với mọi nút: nếu lazy[x]!=0 nghĩa là đoạn [l,r] chưa được cập nhật. Ta cập nhật nó và đẩy lazy[x] xuống 2 con
    segtree[x]+=(r-l+1)*lazy[x];
    if (l!=r){      		//Nếu x là nút gốc thì đẩy xuống 2 con
        lazy[2*x]+=lazy[x];
        lazy[2*x+1]+=lazy[x];
    }
    lazy[x] = 0;			//Và xóa hiệu ứng cập nhật trên x
    }
//Đến đây thì nút x có lazy[x]==0
if (i>r || j<l) return;		
if (i<=l && j>=r){			//Nếu miền cần cập nhật là [l;r] thì segtree[x] = (r-l+1)*val và lazy 2 nút con sẽ nhận thêm val
    segtree[x] += (r-l+1)*val;
    if (l!=r){      
        lazy[2*x]+=val;
        lazy[2*x+1]+=val;
    }
    return;
}
int mid = (l+r)/2;
update(2*x,  l,  mid,i,j,val);
update(2*x+1,mid+1,r,i,j,val);
segtree[x] = segtree[2*x]+segtree[2*x+1];
}
int query(int x, int l, int r, int i, int j){
if (i>r || j<l) return 0;
if (lazy[x]!=0){    		//Với mọi nút: nếu lazy[x]!=0 nghĩa là đoạn [l,r] chưa được cập nhật. Ta cập nhật nó và đẩy lazy[x] xuống 2 con
    segtree[x]+=(r-l+1)*lazy[x];
    if (l!=r){      		//Nếu x là nút gốc thì đẩy xuống 2 con
        lazy[2*x]+=lazy[x];
        lazy[2*x+1]+=lazy[x];
    }
    lazy[x] = 0;			//Và xóa hiệu ứng cập nhật trên x
    }
if (i<=l && j>=r){
    return segtree[x];
    }
int mid = (l+r)/2;
int t1 = query(2*x,  l,  mid,i,j);
int t2 = query(2*x+1,mid+1,r,i,j);
return t1+t2;
}
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);

}
int main()
{
    enter();
    int n = 8;
    update(1,1,n,1,6,1);
    update(1,1,n,5,7,2);
    cout<<query(1,1,n,8,8);
    return 0;
}

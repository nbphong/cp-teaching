//Lời giải bài NKINV bằng kỹ thuật CDQ - Author: Nguyen Bang Phong - Độ phức tạp n*logn
//Tận dụng kỹ thuật merge-Sort, khi chia [l;r] thành 2 dãy thì mỗi bên được xếp tăng dần. Khi đó, quá trình merge diễn ra bằng cách cho 2 con trỏ i,j chay song song
//nếu a[j] <a[i] nghĩa là từ a[i]..mid đều là số lớn hơn a[j], nên ans+=mid-i+1 (tương tự phép truy vấn upper_bound) và xét a[j] kế tiếp
//ngược lại thì tăng i vì a[i]<=a[j] thì không thu được thêm nghịch thế.
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ii pair<ll,ll>
#define TASKS "1."
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
#define FORU(i,a,b) for(int i = a, _b = b; i <= _b ; i++)
#define FORD(i,a,b) for(int i = a, _b = b; i >= _b ; i--)
using namespace std;
const int maxn = 1e6 ;
const ll oo = 1e17 ;
int n , a[maxn+1] ;
int ans ;
void solve(int l, int r)
{
    if(l == r) return ;
    int mid = (l+r)>>1 ;
    solve(l,mid) ;
    solve(mid+1,r) ;
    int i(l), j(mid+1),sum(0);
    vector<int>tmp;
    while(i<=mid && j<=r)
        if (a[j]<a[i]) ans+=mid-i+1, tmp.pb(a[j++]);
        else tmp.pb(a[i++]);
    while(j<=r) tmp.pb(a[j++]);
    while(i<=mid) tmp.pb(a[i++]);
    for(int i=l;i<=r;i++) a[i] = tmp[i-l];
    vector<int>().swap(tmp);
}
int main()
{
    fast ;
    //freopen(TASKS"INP","r",stdin) ;
    //freopen(TASKS"OUT","w",stdout) ;
    cin >> n ;
    FORU(i,1,n) cin >> a[i] ;
    solve(1,n) ;
    cout << ans ;
        return 0 ;
}


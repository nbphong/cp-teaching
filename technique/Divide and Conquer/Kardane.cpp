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
#define INIT(a,v) memset(a,v,sizeof(a))
#define ll long long
#define pii pair<int,int>
using namespace std;
int n, a[MAXN],sum[MAXN];
//---------------------------------------------
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
int ans(-1e9);
for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    ans = max(ans, sum[j]-sum[i-1]);            //Subtask 1: Kiểm tra kết quả bằng mảng tổng cộng dồn
cout<<ans;
}
int findcross(int x, int y, int md){
int lsum(-1e9),rsum(-1e9),tmp(0);
for(int i=md;i>=x;i--)
    lsum = max(lsum,tmp+=a[i]);
tmp = 0;
for(int i=md+1;i<=y;i++)
    rsum = max(rsum,tmp+=a[i]);
return lsum+rsum;

}
int findmax(int L, int R){
if (L==R) return a[L];
int mid = (L+R)/2;
int t1 = findmax(L,mid);                        //Chia bài toán thành 3 loại: Loại 1: max-sum trong [L;mid]
int t2 = findmax(mid+1,R);                      //Loại 2: max-sum trong [mid+1;R]; loại 3: max-sum trong [L;R] và phải vượt qua mid
int t3 = findcross(L,R,mid);                    //Với loại 3: ta tính tổng lớn nhất bên trái mid + tổng lớn nhất bên phải và cộng chúng lại
return max(1LL*t1,max(1LL*t2,1LL*t3));          //Hàm max của C++ được thiết kế cho kiểu long long nên để tránh lỗi khi debug, ta ép các tham số về kiểu LL
}
int main()
{
    enter();
    cout<<findmax(1,n);
    return 0;
}
/* Test case:
5
5 7 6 10 3
5
-3 2 -1 4 -2
7
-4 5 7 -6 10 -15 3
*/


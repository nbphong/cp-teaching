//Lời giải bài NKINV bằng kỹ thuật CDQ - Author: Thang Nguyen - Chuyen tin 2022-2024
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ii pair<ll,ll>
#define TASKS "i."
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
#define FORU(i,a,b) for(int i = a, _b = b; i <= _b ; i++)
#define FORD(i,a,b) for(int i = a, _b = b; i >= _b ; i--)
using namespace std;
const int maxn = 1e6 ;
const ll oo = 1e17 ;
int n , a[maxn+1] ;
int ans ;
void solve(int L, int R)
{
    if(L == R) return ;
    int mid = (L+R)>>1 ;        
    solve(L,mid) ;
    sort(a+L,a+mid+1);      //Các phần tử a[L]..a[mid] tương ứng với thao tác insert và mỗi phần tử a[mid+1]..a[R] tương ứng với 1 phép query
    FORU(i,mid+1,R)         //Câu hỏi: tại sao lại đặt solve(L,mid) lên trên-> Lý do là khi thực hiện các query bên phải ta cần phải biết kết quả của tất cả
    {                       //các query trước đó. Nói cách khác là các query cần được thực hiện theo thứ tự từ trái qua phải. 
                            //Cũng có thể viết lại thành int solve(l,r) và lúc tổng hợp thì sum lại
        int d = upper_bound(&a[L],&a[mid+1],a[i])-&a[0] ;
        ans += mid-d +1;
    }
    solve(mid+1,R) ;
}
int main()
{
    fast ;
//    freopen(TASKS"INP","r",stdin) ;
//    freopen(TASKS"OUT","w",stdout) ;
    cin >> n ;
    FORU(i,1,n) cin >> a[i] ;
    solve(1,n) ;
    cout << ans ;
        return 0 ;
}

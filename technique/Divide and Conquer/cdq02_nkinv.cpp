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
    FORU(i,mid+1,R)
    {
        int d = upper_bound(&a[L],&a[mid+1],a[i])-&a[0] ;
        ans += mid-d +1;
    }
    solve(mid+1,R) ;
    sort(a+L,a+R+1) ;
    return ;
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

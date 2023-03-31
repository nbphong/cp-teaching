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
#define pii pair<int,int>
#define pll pair<long long, long long>
#define ll long long
using namespace std;
using matrix = array<array<ll,MAXN>,MAXN>;
array<ll,MAXN> INF_arr;
ll const INF = 4e18;                                  //Hằng số +vc của kiểu ll. Nếu để lớn hơn sẽ bị tràn do phép cộng 2.
int n,m,k;
matrix a,I;
//---------------------------------------------------
matrix operator *(const matrix &a,const matrix &b){   //Ta định nghĩa lại phép nhân ma trận phù hợp với công thức tính độ dài đường đi ngắn nhất      
matrix ans;
ans.fill(INF_arr);
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        for(int k=0;k<n;k++)
        ans[i][j] = min(ans[i][j], a[i][k]+b[k][j]);
return ans;
}
//---------------------------------------------
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen(TASK".inp","r",stdin);//    freopen(TASK".out","w",stdout);
    INF_arr.fill(INF);
    a.fill(INF_arr);   
    cin>>n>>m>>k;
    ll x,y,z;
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        a[x-1][y-1] = min(a[x-1][y-1],z);
    }
    I.fill(INF_arr);                              //Ma trận đơn vị cũng được định nghĩa lại cho khớp với phép nhân. I phải thỏa tính chất A*I = A
    for(int i=0;i<n;i++) I[i][i] = 0;             //Giả sử A =|a b| thì ta thấy ngay rằng I phải là |0 INF|
}                                                 //          |c d|                                 |INF 0|
matrix poww(matrix x, int n){
matrix ans = I;
while(n>0){
    if (n%2)
        ans = ans*x;
    n/=2;
    x = x*x;
}
return ans;
}

int main()
{
    enter();
    matrix ans = poww(a,k);
    if (ans[0][n-1]==INF) cout<<-1;
        else cout<<ans[0][n-1];
    return 0;
}

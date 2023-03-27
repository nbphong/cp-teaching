//https://cses.fi/problemset/task/1723/
#include <bits/stdc++.h>
#define mod 1000000007
#define TASK "1"
#define ll unsigned long long
#define pii pair<int,int>
#define MAXN 105
#define ff first
#define ss second
#define pb push_back
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
using matrix = array<array<ll,MAXN>,MAXN>;        //Sử dụng array 2 chiều. Kiểu dữ liệu này linh hoạt hơn mảng. Nếu dùng vector, ta không khởi trị được một cách thuận tiện
ll const MOD = 1e9+7;                             //mà phải thông qua các constructor. Ngoài ra để sử dụng toán tử [] quen thuộc thì ta cũng phải định nghĩa lại trong 
int n,m,k;                                        //struct. Xem ở link: https://vnoi.info/wiki/algo/trick/matrix-multiplication
matrix a, I;
//-----------------------------------------
matrix operator *(matrix a, matrix b){
matrix ans = {0};
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        for(int k=0;k<n;k++)
            {
            ans[i][j] += (1LL*a[i][k]*b[k][j]);
            ans[i][j] = ans[i][j]%MOD;
            }
return ans;
}
matrix poww(matrix a, int n){     //Code tính a^n. Nếu viết bằng đệ quy, CodeBlock sẽ tràn. Do đó để an toàn thì nên viết bằng vòng lặp
//matrix ans = I;
//    while(n){
//        if(n%2){
//            ans=(ans*pow);
//        }
//        pow=(pow*pow);
//        n/=2;
//    }
//return ans;
//if(b==0) return I;
//    matrix y = poww(x, b/2);
//    y = y*y;
//    if(b%2) y = y*x;
//    return y;

if (n==0) return I;
matrix tmp = poww(a,n/2);
if (n%2==0) return tmp*tmp;
    else return (tmp*tmp)*a;
}
void enter(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen(TASK".inp", "r", stdin);//freopen(TASK".out", "w", stdout);
    cin>>n>>m>>k;
    int x,y;
    for(int i=0;i<m;i++)
        {
        cin>>x>>y;
        a[x-1][y-1]++;
        }
    for(int i=0;i<n;i++)
        I[i][i] = 1;
}
int main() {
enter();
matrix ans = poww(a,k);
cout<<ans[0][n-1];
return 0;
}

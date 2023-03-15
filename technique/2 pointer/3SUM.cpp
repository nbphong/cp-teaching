//https://cses.fi/problemset/task/1641/ : Đề bài: Cho một dãy gồm n số nguyên a_1,a_2,…,a_n và một giá trị x. Tìm ba vị trí i,j,k sao cho a_i+a_j+a_k=x.
//Sắp xếp tăng dần dãy (a)
//Cố định i; Xét cặp vị trí (2 con trỏ) j,k sao cho a[j]+a[k] = x - a[i]. Nếu có thì out kết quả. Nếu a[j]+a[k] < x - a[i] thì tăng j, ngược lại thì giảm k

#include <bits/stdc++.h>
#define MAXN 5005
#define TASK "1"
#define ff first
using namespace std;
int n, x;
pii a[MAXN];
//---------------------------------------------
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen(TASK".inp","r",stdin);//    freopen(TASK".out","w",stdout);
    cin>>n>>x;
    int t;
    for(int i=1;i<=n;i++) {
        cin>> t;
        a[i] = {t,i};
        }
    sort(&a[1],&a[n+1]);
}
void solve(){
for(int i=1;i<=n;i++)
    for(int j=i+1, k=n;j<=n, k>j;)
    {
        if (a[i].ff+a[j].ff+a[k].ff==x)
            {
            cout<<a[i].ss<<" "<<a[j].ss<<" "<<a[k].ss;
            return;
            }
        else
            if (a[i].ff+a[j].ff+a[k].ff>x) k--;
                else
                j++;
    }
cout<<"IMPOSSIBLE";
}

int main()
{
    enter();
    solve();
    return 0;
}

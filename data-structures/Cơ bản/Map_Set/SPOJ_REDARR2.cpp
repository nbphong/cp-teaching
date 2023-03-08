//https://www.spoj.com/problems/REDARR2/
//Ý tưởng: Mỗi số có thể được lấy tối đa (n-1) lần và tối thiểu 1 lần. Sau mỗi lượt lấy, độ dài dãy giảm 1. Kết quả cuối của tổng là không đổi
//Rõ ràng để giảm thiểu chi phí, mỗi lượt ta nên lấy 2 giá trị nhỏ nhất (Tham lam)
//Dùng 1 set để lưu các giá trị, lấy 2 phần tử đầu cộng lại, xóa chúng đi và insert tổng của chúng vào trở lại set.
#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x;
multiset<int> S;
//---------------------------------------------
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen(TASK".inp","r",stdin);//     freopen(TASK".out","w",stdout);
    cin>>T;
}
void solve(int i){
cin>>n;
S.clear();
for(int i=1;i<=n;i++) {
    cin>>x;
    S.insert(x);
    }
int ans(0);
while(S.size()>1){
    auto it = S.begin();
    int tmp = *it + *(++it);
    S.erase(S.begin(),++it);
    ans+=tmp;
    S.insert(tmp);
}
cout<<ans<<'\n';
}
signed main()
{
    enter();
    for(int i=1;i<=T;i++)
        solve(i);
    return 0;
}

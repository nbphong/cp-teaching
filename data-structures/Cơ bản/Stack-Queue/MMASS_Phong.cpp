//Ý tưởng: Mô phỏng cơ chế nạp stack của đệ quy:
//Để đơn giản ta thêm vào ( và ) cho chuỗi S. Lập một stack level gồm nhiều tầng, mỗi tầng có 4 tham số id, co: hệ số của tầng,mass: khối lượng, mole: chuỗi của tầng đó
//Nếu gặp '(': thêm 1 tầng mới. Nếu gặp ')': tính hệ số, khối lượng của tầng đó, đẩy kết quả về tầng dưới và xóa nó
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define SET_decimal(n) cout << std::fixed << std::setprecision(n);
#define WATCH_arr(a,l,r) { for (int i=(l);i<=(r);i++) cerr<<a[i]<<' '; }
#define WATCH_a2D(a, n, m) { cerr << #a << ":\n"; for(int i=1;i<=(n);i++, cerr <<'\n') for(int j=1;j<=(m);j++) cerr << ' ' << a[i][j]; }
#define WATCH_vec(a) { cerr << #a << ":"; for(auto _:a) cerr << ' ' << _; cerr << "\n"; }
#define pii pair<int,int>
#define pci pair<char,int>
#define pll pair<long long, long long>
#define ll long long
using namespace std;
struct Points{int id,co,mass;
            string mole="";};
deque<Points> level;
string S;
deque<char> Q;
map<char,int> m={{'C',12},{'H',1},{'O',16}};
//---------------------------------------------
int calc(Points lv){
string s = lv.mole; int tmp(0);
for(int i=s.length()-1;i>=0;i--)
    if (s[i]>='2' && s[i]<='9')
        {
        int t = s[i--]-'0';
        tmp+=t*m[s[i]];
        }
    else
        tmp+=m[s[i]];
return tmp;
}
void enter(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen(TASK".inp","r",stdin); //freopen(TASK".out","w",stdout);
    cin>>S; S='('+S; S+=')';
    int id(0),i(0);
    while (i<S.length()){
    if (S[i]=='(') level.pb({id++,0,0});
        else
            if (S[i]==')') {
                level.back().co = (S[i+1]>='2' && S[i+1]<='9')? (S[++i]-'0'):1;
                int tmp = (calc(level.back())+level.back().mass)*level.back().co ;
                if (level.back().id>0){
                    level.pop_back();
                    level.back().mass+= tmp;
                    }
                    else
                        level.back().mass= tmp;
                }
                else
                    level.back().mole+=S[i];
    i++;
    }
cout<<level.back().mass;
}
int main()
{
    enter();
    return 0;
}

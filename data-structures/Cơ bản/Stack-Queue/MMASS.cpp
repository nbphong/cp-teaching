//https://oj.vnoi.info/problem/mmass
//Author: Trần Văn Nhân - Chuyên Anh K15
#include <bits/stdc++.h>
using namespace std;
stack<int> st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]=='(') st.push(0);         //Nếu gặp '(' push vào số 0, nếu là các kí tự 'C','H','O' thì push vào khối lượng tương ứng
        else if(s[i]=='C') st.push(12);
        else if(s[i]=='H') st.push(1);
        else if(s[i]=='O') st.push(16);
        else if(s[i]==')')                //Nếu gặp ')' thì lấy dần trong stack cộng lại cho đến khi gặp '(' <=> số 0
        {                                 //Như vậy biểu thức (...) là 1 số trong stack.top()
            int sum(0);
            while(true)
            {
                int val = st.top();
                st.pop();
                if(val==0) break;
                sum+=val;
            }
            st.push(sum);
        }
        else                            //Nếu gặp 1 số thì số đó phải là hệ số của stack.top() nên ta nhân nó cho stack.top()
        {
            int val = st.top();
            st.pop();
            val*=s[i]-'0';
            st.push(val);
        }
    }
    int res = 0;
    while(!st.empty())                  //Cộng các giá trị ngoài ngoặc chưa được tính
    {
        int val=st.top();
        st.pop();
        res+=val;
    }
    cout << res;
    return 0;
}

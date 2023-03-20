#include <bits/stdc++.h>
#define int long long
#define inf 1e15

using namespace std;

const int maxn = 2e5 + 10, maxk = 201;
int n, m, k, a[maxn], dp[maxk][maxn];

void enter()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

void solution()
{
    dp[1][0] = -inf;
    for (int j = 1; j <= n; ++j) // Cơ sở quy hoạch động dp[1][j] = a[j];
        dp[1][j] = a[j];

    for (int i = 2; i <= k; ++i)
    {
        dp[i][0] = -inf;

        deque < int > qu_max;
        for (int j = 1; j <= n; ++j)
        {
            while (!qu_max.empty() && qu_max.front() < j - m)
                qu_max.pop_front();

            while (!qu_max.empty() && dp[i - 1][qu_max.back()] <= dp[i - 1][j - 1])
                qu_max.pop_back();
            qu_max.push_back(j - 1);

            dp[i][j] = dp[i - 1][qu_max.front()] + a[j] * i;
        }
    }

    int res = *max_element(dp[K], dp[K] + 1 + N);
    cout << res;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    enter();
    solution();

    return 0;
}

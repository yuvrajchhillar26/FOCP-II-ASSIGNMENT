#include <bits/stdc++.h>
using namespace std;

const int N = 10000000;

int cnt[N + 1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i <= N; i++)
    {
        if (cnt[i] == 0)
        {
            for (int j = i; j <= N; j += i)
            {
                cnt[j]++;
            }
        }
    }

    vector<int> p(25);
    p[0] = 1;
    for (int i = 1; i < 25; i++)
        p[i] = p[i - 1] * 2;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << p[cnt[n]] << "\n";
    }
}
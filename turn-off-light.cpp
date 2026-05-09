#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int f(int l)
{
    int i = 0, c = 0;

    while (i < n)
    {
        if (s[i] == '1')
        {
            c++;
            i += l;
        }
        else
            i++;
    }

    return c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    cin >> s;

    int lo = 1, hi = n, ans = n;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        if (f(mid) <= k)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    cout << ans;
}
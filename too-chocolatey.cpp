#include <bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> arr)
{
    sort(arr.begin(), arr.end(), greater<int>());

    int alex_now = -1, alex_total = 0;
    int bob_now = -1, bob_total = 0;

    int i = 0;

    while (i < n)
    {

        if (arr[i] != alex_now)
        {
            alex_now = arr[i];
            alex_total += arr[i];
            i++;
        }
        else
        {
            i++;
            continue;
        }

        if (i >= n)
            break;

        if (arr[i] != bob_now)
        {
            bob_now = arr[i];
            bob_total += arr[i];
            i++;
        }
        else
        {
            i++;
        }

        if (i < n && arr[i] == alex_now && arr[i] == bob_now)
        {
            i++;
        }
    }

    return (alex_total > bob_total) ? "Alex" : "Bob";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << solve(n, arr) << '\n';
    }
}
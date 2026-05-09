#include <iostream>
using namespace std;

int main()
{
    long long l, r;
    cin >> l >> r;

    long long oddCount = (r + 1) / 2 - l / 2;

    if (oddCount % 2 == 0)
        cout << "even";
    else
        cout << "odd";

    return 0;
}
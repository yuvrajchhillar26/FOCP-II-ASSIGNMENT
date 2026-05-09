#include <bits/stdc++.h>
using namespace std;

class Bank
{
private:
    unordered_map<string, long long> userAccounts;

public:
    bool CREATE(string userId, long long money)
    {
        if (userAccounts.find(userId) == userAccounts.end())
        {
            userAccounts[userId] = money;
            return true;
        }
        else
        {
            userAccounts[userId] += money;
            return false;
        }
    }

    bool DEBIT(string userId, long long money)
    {
        if (userAccounts.find(userId) == userAccounts.end())
        {
            return false;
        }

        if (userAccounts[userId] < money)
        {
            return false;
        }

        userAccounts[userId] -= money;
        return true;
    }

    bool CREDIT(string userId, long long money)
    {
        if (userAccounts.find(userId) == userAccounts.end())
        {
            return false;
        }

        userAccounts[userId] += money;
        return true;
    }

    long long BALANCE(string userId)
    {
        if (userAccounts.find(userId) == userAccounts.end())
        {
            return -1;
        }

        return userAccounts[userId];
    }
};

int main()
{
    int totalQueries;
    cin >> totalQueries;
    cin.ignore();

    Bank bankSystem;

    while (totalQueries--)
    {
        string queryLine;
        getline(cin, queryLine);

        stringstream input(queryLine);

        string queryType, userId;
        long long money;

        input >> queryType;

        if (queryType == "CREATE")
        {
            input >> userId >> money;

            cout << (bankSystem.CREATE(userId, money) ? "true" : "false") << endl;
            // this ? : is the ternary operator which is used instead of if else statements to return a value based on a condition. It is a shorthand for if else statements and is often used for simple conditions. The syntax is: condition ? value_if_true : value_if_false.
            /* if (bank.CREATE(X, Y))
                cout << "true" << endl;
            else
                cout << "false" << endl; */
        }
        else if (queryType == "DEBIT")
        {
            input >> userId >> money;

            if (bankSystem.DEBIT(userId, money))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if (queryType == "CREDIT")
        {
            input >> userId >> money;

            if (bankSystem.CREDIT(userId, money))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if (queryType == "BALANCE")
        {
            input >> userId;
            cout << bankSystem.BALANCE(userId) << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class MovieTicket
{
private:
    unordered_map<int, unordered_set<int>> bookedUsers;
    unordered_map<int, int> availableSlots;

public:
    bool BOOK(int userID, int movieID)
    {
        if (availableSlots.find(movieID) == availableSlots.end())
        {
            availableSlots[movieID] = 100;
        }

        if (bookedUsers[movieID].count(userID))
        {
            return false;
        }

        if (availableSlots[movieID] == 0)
        {
            return false;
        }

        bookedUsers[movieID].insert(userID);
        availableSlots[movieID]--;

        return true;
    }

    bool CANCEL(int userID, int movieID)
    {
        if (!bookedUsers[movieID].count(userID))
        {
            return false;
        }

        bookedUsers[movieID].erase(userID);
        availableSlots[movieID]++;

        return true;
    }

    bool IS_BOOKED(int userID, int movieID)
    {
        return bookedUsers[movieID].count(userID) > 0;
    }

    int AVAILABLE_TICKETS(int movieID)
    {
        if (availableSlots.find(movieID) == availableSlots.end())
        {
            return 100;
        }

        return availableSlots[movieID];
    }
};

int main()
{
    int Q;
    cin >> Q;

    MovieTicket ticketSystem;

    while (Q--)
    {
        string query;
        cin >> query;

        if (query == "BOOK")
        {
            int userID, movieID;
            cin >> userID >> movieID;

            if (ticketSystem.BOOK(userID, movieID))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        else if (query == "CANCEL")
        {
            int userID, movieID;
            cin >> userID >> movieID;

            if (ticketSystem.CANCEL(userID, movieID))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        else if (query == "IS_BOOKED")
        {
            int userID, movieID;
            cin >> userID >> movieID;

            if (ticketSystem.IS_BOOKED(userID, movieID))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        else if (query == "AVAILABLE_TICKETS")
        {
            int movieID;
            cin >> movieID;

            cout << ticketSystem.AVAILABLE_TICKETS(movieID) << endl;
        }
    }

    return 0;
}
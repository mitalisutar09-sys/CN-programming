#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string ip;
    int address[4];
    char dot;

    cout << "Enter IP address: ";
    cin >> ip;
    int dots = 0;

    for (char ch : ip)
    {
        if (ch == '.')
            dots++;
    }
    if (dots != 3)
    {
        cout << "Invalid IP address";
        return 0;
    }
    stringstream ss(ip);

    for (int i = 0; i < 4; i++)
    {
        ss >>address[i];

        if (i < 3)
            ss >> dot;
    }
    for (int i = 0; i < 4; i++)
    {
        if (address[i] < 0 ||address[i] > 255)
        {
            cout << "Invalid IP address";
        }
    }

    cout << "Valid IP address" << endl;
    if (address[0] >= 1 && address[0] <= 127)
    {
        cout << "Class: A" << endl;

        cout << "Net ID: "
             << address[0] << ".0.0.0" << endl;

        cout << "Host ID: "
             << address[3] << endl;
    }
    else if (address[0] >= 128 && address[0] <= 191)
    {
        cout << "Class: B" << endl;

        cout << "Net ID: "
             << address[0] << "."
             << address[1] << ".0.0" << endl;

        cout << "Host ID: "
             <<address[3] << endl;
    }
    else if (address[0] >= 192 && address[0] <= 223)
    {
        cout << "Class: C" << endl;

        cout << "Net ID: "
             <<address[0] << "."
             << address[1] << "."
             <<address[2] << ".0" << endl;

        cout << "Host ID: "
             << address[3] << endl;
    }
    else if (address[0] >= 224 &&address[0] <= 239)
    {
        cout << "Class: D" << endl;
        cout << "Net ID: Not applicable" << endl;
        cout << "Host ID: Not applicable" << endl;
    }
    else if (address[0] >= 240 && address[0] <= 255)
    {
        cout << "Class: E" << endl;
        cout << "Net ID: Not applicable" << endl;
        cout << "Host ID: Not applicable" << endl;
    }

    else
    {
        cout << "Invalid IP address";
    }
}

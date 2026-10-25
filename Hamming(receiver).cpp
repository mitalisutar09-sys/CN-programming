#include <iostream>
using namespace std;

int main()
{
    int recv[7], calc[3], err_pos = 0;

    cout << "Enter 7-bit received Hamming code (bit 1 to 7):" << endl;

    for (int i = 0; i < 7; i++)
    {
        cin >> recv[i];
    }

    calc[0] = recv[0] ^ recv[2] ^ recv[4] ^ recv[6];
    calc[1] = recv[1] ^ recv[2] ^ recv[5] ^ recv[6];
    calc[2] = recv[3] ^ recv[4] ^ recv[5] ^ recv[6];

    err_pos = calc[0] * 1 + calc[1] * 2 + calc[2] * 4;

    if (err_pos == 0)
    {
        cout << "\nNo error in the received data." << endl;
    }
    else
    {
        cout << "\nError detected at position: " << err_pos << endl;

        recv[err_pos - 1] = !recv[err_pos - 1];

        cout << "Corrected code: ";

        for (int i = 0; i < 7; i++)
        {
            cout << recv[i] << " ";
        }

        cout << endl;
    }
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include<unistd.h>
using namespace std;

int main()
{
    int total_frames;
    int current_frame = 1;
    int is_lost;

    srand(time(NULL));

    cout << "Example Console Output:" << endl;
    cout << "Stop and Wait ARQ" << endl;

    total_frames = (rand() % 3) + 3;

    while (current_frame <= total_frames)
    {
        cout << "Sending frame " << current_frame << endl;

        is_lost = rand() % 2;

        if (is_lost)
        {
            cout << "Frame " << current_frame << " lost!" << endl;
            cout << "Retransmitting frame " << current_frame << endl;
        }
        else
        {
            cout << "Frame " << current_frame
                 << " received successfully." << endl;

            cout << "ACK received for frame "
                 << current_frame << "." << endl;

            current_frame++;
        }

        sleep(1);
    }

    cout << "\nAll frames transmitted successfully." << endl;
    cout << "Stop and Wait ARQ completed." << endl;
}

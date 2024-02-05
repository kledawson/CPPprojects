#include<iostream>
#include<cstdlib>
#include <conio.h>
#include<time.h>
using namespace std;

int rep;
int coinFlip();
void output();
char restart = 'Y';
int coin, counter, tails = 0, heads = 0;
string t;

int main()
{
    srand(time(NULL));
    while (restart == 'Y' || restart == 'y') {
        cout << "How many times do you want to flip the coin? ";
        cin >> rep;

        for (counter = 1; counter <= rep; counter++)
        {
            coin = coinFlip();

            if (coin == 0)
            {
                cout << "T ";
                tails = tails + 1;
            }
            else if (coin == 1)
            {
                cout << "H ";
                heads = heads + 1;
            }
        }

        output();
        tails = 0;
        heads = 0;

        cout << "Do you want to flip again? Y/N ";
        cin >> restart;
        cout << endl;
    }

    if (restart == 'N' || restart == 'n') {
        cout << "Thanks for flipping. Enter any key to quit.";
    }

    cin >> t;

    return 0;
}

int coinFlip()
{
    return rand() % 2;
}

void output() {
    cout << endl;
    cout << "Tails was tossed " << tails << " times" << endl;
    cout << "Heads was tossed " << heads << " times" << endl;
}
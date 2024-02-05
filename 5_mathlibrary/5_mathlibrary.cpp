#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    string choice = "YxDjK";

    do
    {
        int r1 = rand() % (20) + 1;
        int r2 = rand() % (20) + 1;
        double sqrtr = sqrt(r1);
        double sqrtr2 = sqrt(r2);
        double average = (r1 + r2) / 2.0;
        string x;

        cout << setprecision(3) << "The two random integers are " << r1 << " and " << r2 << endl;
        cout << "The square root of " << r1 << " is " << sqrtr << endl;
        cout << "The square root of " << r2 << " is " << sqrtr2 << endl;
        cout << setprecision(1) << "The average is " << average << endl;
        cout << "Enter anything to exit: " << endl;

        cin >> choice;
    } while (choice == "YxDjK");

    return 0;
}

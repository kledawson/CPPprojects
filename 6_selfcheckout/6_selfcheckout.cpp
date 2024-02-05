#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string name1;
    int amount1;
    double price1;
    char tax1;
    double finalprice1{};
    string name2;
    int amount2;
    double price2;
    char tax2;
    double finalprice2{};
    const double taxRate = 0.0925;
    double taxPrice1 = 0;
    double taxPrice2 = 0;

    cout << "Enter the name of item 1: ";
    getline(cin, name1);
    cin.ignore();
    cout << "Enter the number of " << name1 << " and the price of each : ";
    cin >> amount1;
    cin >> price1;
    cout << "Is (are) " << name1 << " taxable? Y/N" << endl;
    cin >> tax1;
    if (tax1 == 'Y' || tax1 == 'y')
    {
        taxPrice1 = price1 * taxRate;
        finalprice1 = price1 * taxPrice1;
    }
    else if (tax1 == 'N' || tax1 == 'n')
    {
        finalprice1 = price1;
    }

    cout << "Enter the name of item 2: ";
    cin.ignore();
    getline(cin, name2);
    cout << "Enter the number of " << name2 << " and the price of each : ";
    cin >> amount2;
    cin >> price2;
    cout << "Is (are) " << name2 << " taxable? Y/N" << endl;
    cin >> tax2;
    if (tax2 == 'Y' || tax2 == 'y')
    {
        taxPrice2 = price2 * taxRate;
        finalprice2 = price2 * taxPrice2;
    }
    else if (tax2 == 'N' || tax2 == 'n')
    {
        finalprice2 = price2;
    }
    cout << setprecision(3) << "Item               Count   Price   Ext.Price   Tax" << endl;
    cout << "===================================================" << endl;
    cout << name1 << "               " << amount1 << "       " << price1 << "      " << finalprice1 << "       " << setprecision(2) << taxPrice1 << endl;
    cout << name2 << "               " << amount2 << "       " << price2 << "      " << finalprice2 << "       " << setprecision(2) << taxPrice2 << endl;
    return 0;
}
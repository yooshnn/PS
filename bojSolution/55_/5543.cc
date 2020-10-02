#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int burger[3];
    int beverage[2];
    int cheapestBurger = 2000, cheapestBeverage = 2000;
    int cheapestSet;

    cin >> burger[0] >> burger[1] >> burger[2] >> beverage[0] >> beverage[1];

    for (int i : burger) {
        if (i < cheapestBurger) cheapestBurger = i;
    }
    for (int i : beverage) {
        if (i < cheapestBeverage) cheapestBeverage = i;
    }
    cheapestSet = cheapestBurger + cheapestBeverage - 50;

    cout << cheapestSet;

    return 0;
}
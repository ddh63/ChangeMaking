// David Highsmith

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> coins;
    coins.push_back(1);
    int getCoin;
    int amtChange;

    std::cout << "1 cent coin has already been added" << std::endl;
    std::cout << "Enter coins: (or -1 if out of coins): ";
    std::cin >> getCoin;
    while (getCoin != -1) {
        bool check = true;

        for (int i : coins)
            if (getCoin == i)
                check = false;

        if (check)
            coins.push_back(getCoin);
        else
            std::cout << "Coin already entered" << std::endl;

        std::cout << "Next coin: ";
        std::cin >> getCoin;
    }

    std::cout << "Enter amount of change: ";
    std::cin >> amtChange;

    std::vector<int> coinUsed(amtChange + 1);
    std::vector<int> coinCount(amtChange + 1);

    for (int cents = 1; cents <= amtChange; ++cents) {
        int minimum = INT_MAX;
        int last = 0;
        for (int coin : coins) {
            if (coin > amtChange) continue;
            // Stops coin from being added if result comes out less than 0
            // Not sure why this was needed but it fixed the error
            if (cents - coin < 0) continue;
            int x = 1 + coinCount[cents - coin];
            if (x < minimum) {
                minimum = x;
                last = coin;
            }
        }
        coinCount[cents] = minimum;
        coinUsed[cents] = last;
    }

    std::cout << coinCount[amtChange] << " coins needed" << std::endl;

    int count = 1;
    while (amtChange) {
        std::cout << count << ": " << coinUsed[amtChange] << std::endl;
        amtChange -= coinUsed[amtChange];
        count++;
    }

    return 0;
}

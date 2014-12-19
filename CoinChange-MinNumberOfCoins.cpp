#include <cstdio>
#include <iostream>
#include <vector>

int main(){

    //Input:
    //First line: amount to be exchanged, and number of available denominations
    //Subesquent lines: the available denominations
    
    long change, numCoins; std::cin >> change >> numCoins;

    std::vector<long> denom(numCoins, 0);

    for(long p = 0; p < numCoins; p++){long value; std::cin >> value; denom[p] = value;}

    std::vector<std::pair<long, long> > optimal(1 + change, std::pair<long, long>(0,0));

    for(long rest = 1; rest <= change; rest++){
        for(long d = 0; d < numCoins; d++){
            long currentValue = denom[d];
            if(rest < currentValue){continue;}
            if(optimal[rest].first == 0 || 1 + optimal[rest - currentValue].first < optimal[rest].first){
                optimal[rest].first = 1 + optimal[rest - currentValue].first;
                optimal[rest].second = currentValue;
            }
        }
    }

    std::cout << "\nMinimum number of coins: " << optimal[change].first << std::endl;

    std::cout << "\n\nUsed Coins:\n";
    long rem = change;
    while(rem > 0){
        std::cout << optimal[rem].second << "\t";
        rem -= optimal[rem].second;
    }
    std::cout << std::endl;

    return 0;
}

#include <iostream>
#include <vector>

long numCoins(long amount, std::vector<long> denom){

    std::vector<long> numCoins(amount + 1);
    for(long p = 0; p <= amount; p++){numCoins[p] = p;}

    for(long p = 1; p <= amount; p++){
        for(long c = 0; c < denom.size(); c++){
            long currentDen = denom[c];
            if(currentDen > p){break;}
            numCoins[p] = std::min(numCoins[p], 1 + numCoins[p - currentDen]);
        }
    }

    //for(long p = 1; p <= amount; p++){std::cout << p << "   ---> " << numCoins[p] << std::endl;};

    return numCoins[amount];
}


int main(){

    const long N(7);
    std::vector<long> coinValues(N);
    coinValues[0] = 1; coinValues[1] = 2; coinValues[2] = 5; coinValues[3] = 10; coinValues[4] = 20; coinValues[5] = 50; coinValues[6] = 100;

    int test;
    test = 100; std::cout << test << "   --->   " << numCoins(test, coinValues) << std::endl;
    test = 97; std::cout << test << "   --->   " << numCoins(test, coinValues) << std::endl;
    test = 23; std::cout << test << "   --->   " << numCoins(test, coinValues) << std::endl;
    test = 17; std::cout << test << "   --->   " << numCoins(test, coinValues) << std::endl;


    return 0;
}

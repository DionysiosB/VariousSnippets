#include <iostream>
#include <vector>

int main(){

    int n; std::cin >> n;
    std::vector<int> price(n + 1);
    for(int p = 1; p <= n; p++){std::cin >> price[p];}

    std::vector<int> optimal(n + 1);
    for(int p = 1; p <= n; p++){
        int currentMax(0);
        for(int q = 0; q <= p / 2; q++){
            int current = price[q] + price[p - q];
            if(current > currentMax){currentMax = current;}
        }
        optimal[p] = currentMax;
    }

    for(int p = 0; p <= n; p++){std::cout << price[p] << "\t";}
    std::cout << std::endl;
    for(int p = 0; p <= n; p++){std::cout << optimal[p] << "\t";}
    std::cout << std::endl;

    std::cout << optimal[n] << std::endl;

    return 0;
}



//Given a rod that can be cut into individual pieces of integer length,
//find how to cut it in order to achieve maximum profit
//http://tech-queries.blogspot.com/2014/04/max-price-by-selling-pieces-of-rod.html

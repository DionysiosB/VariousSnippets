#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        std::string s; getline(std::cin, s);
        std::istringstream iss(s);
        long x; std::vector<long> candies;
        while(iss >> x){candies.push_back(x);}
        size_t n = candies.size();
        std::vector<long> sums(n);
        sums[0] = candies[0]; sums[1] = 0; sums[2] = candies[0] + candies[2];
        for(int p = 3; p < n; p++){sums[p] = candies[p] + ((sums[p - 3] > sums[p - 2]) ? sums[p - 3] : sums[p - 2]);}
        long ans = (sums[n - 2] > sums[n - 1]) ? sums[n - 2] : sums[n - 1];
        std::cout << ans << " ";
    }
    std::cout << std::endl;

    return 0;
}

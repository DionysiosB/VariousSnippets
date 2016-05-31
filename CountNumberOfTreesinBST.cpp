#include <iostream>
#include <vector>

int main(){

    int n; std::cin >> n;
    std::vector<long> count(n + 1, 0);
    count[0] = 1;

    for(int p = 1; p <= n; p++){
        for(int q = 0; q < p; q++){
            count[p] += count[q] * count[p - 1 - q];
        }
    }

    for(int p = 0; p <= n; p++){std::cout << p << " " << count[p] << std::endl;}

    return 0;
}

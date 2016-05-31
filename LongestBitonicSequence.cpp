#include <iostream>
#include <vector>

int main(){

    long n; std::cin >> n;
    std::vector<long> v(n);
    for(long p = 0; p < n; p++){std::cin >> v[p];}


    std::vector<long> lis(n, 1);
    std::vector<long> lds(n, 1);
    for(int p = 1; p < n; p++){
        for(int q = 0; q < p; q++){
            if(v[q] < v[p] && lis[p] < lis[q] + 1){lis[p] = lis[q] + 1;}
            if(v[q] > v[p] && lds[p] < lds[q] + 1){lds[p] = lds[q] + 1;}
        }
    }

    int maxLen(0);
    for(int p = 1; p < n; p++){
        long candidate = lis[p] + lds[p] - 1;
        maxLen = (maxLen < candidate) ? candidate : maxLen;
    }

    std::cout << maxLen << std::endl;

    return 0;
}

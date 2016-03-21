#include <iostream>
#include <vector>

int lis(std::vector<long> v){

    std::vector<long> length(v.size(), 1);
    long res(0);

    for(long p = 1; p < v.size(); p++){
        for(long q = 0; q < p; q++){
            if(v[q] >= v[p]){continue;}
            length[p] = std::max(length[p], length[q] + 1);
        }

        res = std::max(res, length[p]);
    }

    return res;
    
}

int main(){

    long n(100);
    std::vector<long> array(n);
    for(int p = 0; p < n; p++){array[p] = p;}; std::cout << lis(array) << std::endl;
    for(int p = 0; p < n; p++){array[p] = n - p;}; std::cout << lis(array) << std::endl;
    for(int p = 0; p < n; p++){array[p] = p % 5;}; std::cout << lis(array) << std::endl;

    return 0;
}

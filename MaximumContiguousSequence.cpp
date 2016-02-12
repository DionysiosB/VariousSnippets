#include <iostream>
#include <vector>

int maxValue(std::vector<int> v){

    int res(0);
    int ending(0);
    for(int p = 0; p < v.size(); p++){
        ending = std::max(ending + v[p], v[p]);
        res = std::max(res, ending);
    }

    return res;
}


int main(){

    int n = 23;
    std::vector<int> x(n);
    for(int p = 0; p < n; p++){x[p] = (3 * p + 5) % n - 10;}
    for(int p = 0; p < n; p++){std::cout << x[p] << " ";}; std::cout << std::endl;
    std::cout << maxValue(x) << std::endl;

    return 0;
}

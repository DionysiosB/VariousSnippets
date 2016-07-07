#include <iostream>
#include <vector>

int main(){

    int n; std::cin >> n;
    std::vector<int> a(n);
    for(int p = 0; p < n; p++){std::cin >> a[p];}

    int nextZero(n - 1);
    while(a[nextZero] == 0){--nextZero;}
    for(int p = 0; p < n && p < nextZero; p++){
        if(a[p] != 0){continue;}
        int temp = a[nextZero]; a[nextZero] = 0; a[p] = temp;
        --nextZero;
    }

    for(int p = 0; p < n; p++){std::cout << a[p] << " ";}; std::cout << std::endl;

    return 0;
}

#include <iostream>
#include <vector>

int main(){

    int D, S, m; std::cin >> D >> S >> m;
    std::vector<std::vector<long> > ways(D + 1, std::vector<long>(S + 1));


    for(int p = 1; p <= m && p <= S; p++){ways[1][p] = 1;}


    for(int dice = 2; dice <= D; dice++){
        for(int sum = 1; sum <= S; sum++){
            for(int res = 1; res <= m && res < sum; res++){ways[dice][sum] += ways[dice - 1][sum - res];}
        }
    }

    for(int dice = 0; dice <= D; dice++){
        for(int sum = 0; sum <= S; sum++){std::cout << ways[dice][sum] << "\t";}
        std::cout << std::endl;
    }

    return 0;
}

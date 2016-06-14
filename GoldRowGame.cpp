#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int n; std::cin >> n;
    std::vector<int> v(n, 0);
    std::ios_base::sync_with_stdio(false);
    for(int p = 0; p < n; p++){std::cin >> v[p];}

    std::vector<std::vector<int> > dp(n, std::vector<int>(n, 0));
    for(int p = 0; p < n; p++){dp[p][p] = v[p];}
    for(int p = 0; p < n - 1; p++){dp[p][p + 1] = std::max(v[p], v[p + 1]);}

    for(int len = 3; len <= n; len++){
        for(int s = 0; s + len <= n; s++){
            int f = s + len - 1;
            dp[s][f] = std::max(v[s] + std::min(dp[s + 2][f], dp[s + 1][f - 1]), std::min(dp[s + 1][f - 1], dp[s][f - 2]) + v[f]);
        }
    }

    for(int p = 0; p < n; p++){
        for(int q = 0; q < n; q++){std::cout << dp[p][q] << "\t";};
        std::cout << std::endl;
    }

    std::cout << dp[0][n - 1] << std::endl;

    return 0;
}

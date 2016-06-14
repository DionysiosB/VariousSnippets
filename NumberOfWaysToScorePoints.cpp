#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int s, n; std::cin >> s >> n;
    std::vector<int> steps;
    for(int p = 0; p < n; p++){
        int x; std::cin >> x;
        if(x > 0){steps.push_back(x);}
    }

    sort(steps.begin(), steps.end());

    std::vector<long> dp(s + 1, 0);
    dp[0] = 1;
    for(int p = 1; p <= s; p++){
        for(int k = 0; k < n && steps[k] <= p; k++){dp[p] += dp[p - steps[k]];}
    }
    
    for(int p = 0; p <= s; p++){std::cout << dp[p] << " ";}; std::cout << std::endl;
    std::cout << dp[s] << std::endl;

    return 0;
}

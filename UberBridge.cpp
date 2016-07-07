#include <iostream>

int main(){

    std::string s; getline(std::cin, s);
    int k; std::cin >> k;

    int left(0), right(0);
    int l(0), maxLen(0), rem(k);
    for(int r = 0; r < s.size(); r++){
        if(s[r] == 'W'){--rem;}
        while(l <= r && rem < 0){if(s[l] == 'W'){++rem;}; ++l;}
        if(maxLen < r - l + 1){left = l; right = r; maxLen = right - left + 1;}
    }

    std::cout << maxLen << std::endl;
    for(int p = left; p <= right; p++){if(s[p] == 'W'){std::cout << (p + 1) << " ";}}

    return 0;
}

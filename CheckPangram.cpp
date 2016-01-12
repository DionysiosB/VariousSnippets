#include <cstdio>
#include <iostream>
#include <vector>

int main(){

    const int N = 26;

    std::string s; getline(std::cin, s);

    std::vector<bool> check(N, 0);
    for(size_t p = 0; p < s.size(); p++){check[s[p] - 'a'] = 1;}
    bool flag(true);
    for(size_t p = 0; p < N; p++){if(check[p] == 0){flag = 0; break;}}
    puts(flag ? "YES" : "NO");

    bool nostruct(1);
    for(int p = 0; p < N; p++){
        bool hasLetter(0);
        for(size_t q = 0; q < s.size(); q++){if(s[q] == 'a' + p){hasLetter = 1; break;}}
        if(!hasLetter){nostruct = 0; break;}
    }
    puts(nostruct ? "YES" : "NO");

    return 0;
}

#include <iostream>

int main(){

    std::string s; getline(std::cin, s);
    long x(1);
    for(int p = 0; p < s.size(); p++){
        if(s[p] != s[p - 1]){s[x++] = s[p];}
    }
    s = s.substr(0, x);
    std::cout << s << std::endl;

    return 0;
}

#include <iostream>

int main(){

    std::string s; getline(std::cin, s);
    std::string r("");
    for(size_t p = 0; p < s.size(); p++){
        if(s[p] != ' '){r += s[p];}
        else{r += "%20";}
    }

    std::cout << r << std::endl;


    return 0;
}

#include <cstdio>
#include <iostream>
#include <vector>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        std::string s; getline(std::cin, s);
        int correct = 1;
        std::vector<char> brackets;
        for(int p = 0; p < s.size(); p++){
            if(s[p] == '(' || s[p] == '[' || s[p] == '{' || s[p] == '<'){brackets.push_back(s[p]);}
            else if(s[p] == ')'){if(brackets.back() == '('){brackets.pop_back();} else{correct = 0; break;}}
            else if(s[p] == ']'){if(brackets.back() == '['){brackets.pop_back();} else{correct = 0; break;}}
            else if(s[p] == '}'){if(brackets.back() == '{'){brackets.pop_back();} else{correct = 0; break;}}
            else if(s[p] == '>'){if(brackets.back() == '<'){brackets.pop_back();} else{correct = 0; break;}}
        }

        if(brackets.size() > 0){correct = 0;}
        std::cout << correct << " ";
    }
    std::cout << std::endl;

    return 0;
}

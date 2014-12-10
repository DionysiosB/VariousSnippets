#include <cstdio>
#include <iostream>


int matchStrings(std::string glob, std::string test) {

  int cp(0),mp(0);
  int first(0), second(0);

  while (glob[first] != '*' && second < test.size()) {
    if ((glob[first] != test[second]) && (glob[first] != '?')){return 0;}
    ++first; ++second;
  }

  while(second < test.size()) {
    if (glob[first] == '*') {
      if (first == glob.size() - 1){return 1;}
      mp = first; cp = second + 1;
    } 
    else if ((glob[first] == test[second]) || (glob[first] == '?')){++first; ++second;}
    else{first = mp; second = cp++;}
  }

  while (glob[first] == '*') {++first;}
  if(first == glob.size()){return 1;}
  else{return 0;}


}

int main(){

    std::string test(""), glob("");
    getline(std::cin, test);
    getline(std::cin, glob);

    printf("%d\n", matchStrings(glob,test));


    return 0;
}

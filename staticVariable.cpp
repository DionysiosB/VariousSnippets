#include <cstdio>
#include <vector>
#include <iostream>
#include <string>


class user{
  private:
  int id;
  static int next_id;

  public:
  user(){id = user::next_id++;}
  void printId(){std::cout << this->id << std::endl;}

};

int user::next_id = 0;


int main(){

    user first, second, third;
    first.printId();
    second.printId();
    third.printId();

    return 0;
}



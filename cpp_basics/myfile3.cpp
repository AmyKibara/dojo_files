#include "my_include/myfile3.hpp"
#include <iostream>

using namespace std;

//function defined in main file, class and all its functions declared in header file

void Greeter::greet_me(){
    cout<<"Sup chica"<<endl;
}

int main(){
    Greeter my_greeter;
    my_greeter.greet_me();
    return 0;
}



#include <iostream>
using namespace std;

class MyClassA{
    private:
    double range;
    public:
    //constructor
    MyClassA(double max_range) : range(max_range){}
    void printOut(){
        cout<<"My maximum limit: "<<range<<endl;
    }
}; //SEMICOLON after class definition

//can have main within this file or within another file i think
int main(){
    MyClassA class_a = MyClassA(45.78);
    class_a.printOut();
    return 0;
}
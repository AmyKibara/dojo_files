#include <iostream>

using namespace std;
class myClassB{
    private:
    int age_;//include underscore to show its privTE
    protected:
    float height_;
    public:
    myClassB(int age, float height){
        age_ = age;
        height_ = height;
    }
    void printer(){
        static int counter = 0;
        counter++;
        cout<<"age: "<<age_<<endl;
        cout<<"height: "<<height_<<endl;
        cout<<"count: "<<counter<<endl;
    }
};

int main(){
    myClassB my_b_class(89,89.9);
    for(int i=0; i<5; i++){
        my_b_class.printer();
    }
    

}
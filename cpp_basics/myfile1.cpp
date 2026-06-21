#include <iostream> //basic input-output library
#include <eigen3/Eigen/Dense>
#include <string> //for strings
#include <iomanip> //for changing decimal precision using cout
#include <cstdio> //for printf -- not sure if necessary though -- it ran without this library]
#include <vector> //for dynamic arrays

using namespace std; //to simplify code without std prefix

//Global vars and constants declared outside of main
bool is_active = true;
const float MAX_SPEED = 8.9;
const char* robot_name = "Iskandar";

//Functions made outside of main
void my_toggler(){
    is_active = false;
}

int main(int argc, char *argv[]){
    //BASIC INPUT OUTPUT
    /* double speed = 0.5; //in m/s
    double time = 10.0; //in s
    double distance = speed * time;
    std::cout << "Hi! You've covered " << distance << " meters." << std::endl; */

    //USING EIGEN LIBRARY FOR MATRICES
    /* Eigen::Vector3d v(1,2,3);
    std::cout <<v.transpose()<<std::endl;//1x3
    std::cout <<v<<std::endl; // 3x1; 3 rows 1 col */

    //USING STD namespace
    /* string var1 = "yellow";
    cout << var1 << endl; //endl prints next item on new line */

    //USING ARGUMENTS WITH MAIN -- int main(int argc, char *argv[]) --hmm the args added at compilation?
    /* cout << "My args: "<<endl;
    for (int i=0; i<argc; ++i){
        cout<<i<<":"<<argv[i]<<endl;
    }
    //argc - count of command line arguments passed to the program inlcuding the program name; done through command line
    //argv - array of character strings representing those arguments
    return 0; */

    //VARIABLES
    //integers, floats, chars, bools
    int distance = 100;
    float speed = 4.89735621375;
    char direction = 'N';
    bool is_on = true;

    cout<<"Is toggled? "<<(is_active ? "Yes" : "No")<<endl;//if is_active==true; print yes; if false, print no
    my_toggler();
    cout<<"Part 2: Is toggled? "<<(is_active ? "Yes" : "No")<<endl;
    cout<< "max_speed: " << MAX_SPEED <<endl;

    //changing decimal precision 
    cout << fixed << setprecision(5);//5dp
    cout << speed <<endl;
    cout << fixed << setprecision(2);//2dp...convenient when all numbers in a file are to be rounded off; placed at top of file
    cout << speed <<endl;
    printf("Speed (%.2f) should be less than max speed (%.2f)\n", speed, MAX_SPEED);//rounds off

    //printf
    printf("name: %s, distance: %d\n", robot_name, distance);

    //auto keyword - allows compiler to automatically deduce the type of a variable from its initializer
    float days[5] = {1,2,3,4,5};//arrays are fixed in size, vectors are dynamic
    vector<int> new_days = {1,2,3,4,5};
    for (auto i = new_days.begin(); i != new_days.end(); ++i){
        cout << *i << endl;//gotta have that asterisk
    }
    //alternatively, for every i in new_days
    for (auto i : new_days){
        cout << i << endl;
    }

    //user input
    double chosen_speed;
    cout<<"Enter desired speed: "<<endl;
    cin>> chosen_speed;
    cout<<"Setting speed to: "<<chosen_speed<<"m/s"<<endl;
    return 0;
 
}
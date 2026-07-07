#include <iostream> //basic input-output library
#include <eigen3/Eigen/Dense>
#include <string> //for strings
#include <iomanip> //for changing decimal precision using cout
#include <cstdio> //for printf -- not sure if necessary though -- it ran without this library]
#include <vector> //for dynamic arrays
#include <cmath> //for math ops
#include <stdexcept> //for errors

using namespace std; //to simplify code without std prefix

//Global vars and constants declared outside of main
bool is_active = true;
const float MAX_SPEED = 8.9;
const char* robot_name = "Iskandar";

//Functions made outside of main
void my_toggler(){
    is_active = false;
}
double divider(double a, double b);

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
    /*//integers, floats, chars, bools
    int distance = 14;
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

    //type-casting
    double time = distance/speed;
    int time_a, time_b;
    cout<<"Implicit casting: "<<time<<endl;
    time_a = (int)time; //C-style casting
    time_b = static_cast<int>(time);//Cpp style casting

    //String stream-for formating and merging diverse data types
    stringstream ss;
    ss<<"time_a: "<<time_a;
    string log_entry = ss.str();
    cout<<"Streamin: "<<log_entry<<endl;

    //getline - reads entire line of input including spaces; unlike regular cin that just grabs the first work in a multi-word sentence
    string command;
    cout<<"Gimme command: ";
    getline(cin, command);
    cout<<"Executing "<<command<<endl;

    //user input
    string chosen_speed;
    cout<<"Enter desired speed: "<<endl;
    cin>> chosen_speed;
    cout<<"Setting speed to: "<<chosen_speed<<"m/s"<<endl;
    
    //Operators: +, -, /, *, %, 
    //Conditions: && (and), || (or); break exits loop immediately, continue skips current iteration and moves to next iteration
    //Ternary operator
    int A = 78;
    int B = 90;
    int C = (A > B) ? A:B;//if true, return the first, if false, return the second --for simple if-else statements
    printf("%d\n", C);*/

    //Arrays - have fixed size
    /* const int size = 5;
    int arr_1[size];
    for(int i=0; i<size; ++i){
        arr_1[i] = i*10;
        cout<<arr_1[i]<<endl;
    }
    //Vectors - resizeable
    vector <int> arr_2;
    arr_2.push_back(90);
    arr_2.push_back(40);
    arr_2.push_back(50);//to add elements
    arr_2.pop_back();//removes last element
    for (int i=0; i<arr_2.size(); i++){
        cout<<arr_2[i]<<endl;
    }
    //Strings
    string var_3 = "melki";
    cout<<var_3[0]<<endl;
    string var_4 = var_3 + "_";
    cout<<var_4<<endl;
    char var_6 = var_3[0];
    char var_7 = toupper(var_6);
    cout<<var_7<<endl; */

    //Math ops
    double angle = 4.0;
    double angle_rad = angle * M_PI / 180.0;
    double angle_tan = sin(angle_rad)/cos(angle_rad);//sin n cos to radian angles
    cout<<"TAN: "<<angle_tan<<endl;

    //Functions declared at top of file; defined after main
    //Pointers
    int my_id = 90;
    int* my_id_ptr = &my_id;
    cout<<"my_id: "<<my_id<<endl;
    cout<<"my_id_ptr: "<<my_id_ptr<<endl;
    cout<<"my_id_ptr_dereferenced:"<<*my_id_ptr<<endl;
    *my_id_ptr = 56;
    cout<<"new my_id:"<<my_id<<endl;

    //Error catching-good for risky code that might crash ur code
    try{
        double var_4 = divider(4.5, 0);
        cout<<var_4<<endl;
    }
    catch(const exception& e){
        cerr<<"Error! :"<<e.what()<<endl;
    } 
    cout<<"yay didnt break my code!"<<endl;
    return 0; 
}

double divider(double a, double b){
    if(b==0){
        throw runtime_error("Division kby zero");
    }
    return a/b;
}
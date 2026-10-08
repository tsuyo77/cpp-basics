#include <iostream>
#include <vector>

void square(int x) {
    std::cout << "int: " << x * x << "\n";
}

void square(double x) {
    std::cout << "double: " << x * x << "\n";
}

void print_vec(const std::vector<int>& v){
    std::cout << "vector: ";
    for (const auto& e : v) {  
        std::cout << e << " ";
    }
    std::cout << "\n";
}

void print_vec(const std::vector<double>& v){
    std::cout << "vector: ";
    for (const auto& e : v) {  
        std::cout << e << " ";
    }
    std::cout << "\n";
}

namespace planning{

    double cost( double length ){
        return length;
    }

}

namespace control{

    double cost( double error ){
        return error*error;
        }

}

int main() 
{
    square(3);        // int版
    square(1.5);      // double版 
    
    print_vec(std::vector<int>{1, 2, 3});          // int版
    print_vec(std::vector<double>{0.5 , 1.5});      // double版

    std::cout << "Planning cost: " << planning::cost(2.0) << "\n";
    std::cout << "Control cost: " << control::cost(2.0) << "\n";    
    return 0;
 }

 //戻り値は違うが引数が一緒のため。オーバーロードは引数で最適な関数を判断しているため。
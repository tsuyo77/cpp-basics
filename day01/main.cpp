#include <iostream>
#include <vector>

int main(){
    std::vector<int> v = {1,2,3};
    for (const auto& x:v){
        std::cout << "value: " << x << "\n";
    }
    return 0;
}
#include "array.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    mArray arr{1,2,3,4,5};
    for(int i = 0; i < 10; ++i){
        arr.push_back(rand() % 100);
    }
    arr.print();
    arr.insert(10, 20);
    arr.insert(4,6);
    arr.print();
    std::cout << arr[arr.find(20)] << '\n';
    arr.erase(2);
    arr.print();
    arr.pop_back();
    arr.print();
}
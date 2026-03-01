#include<iostream>
#include<vector>

int main()
{
    std::vector<int> v1 = {1,2,3,4,5};
    std::cout << "v1 size before move: " << v1.size() << "\n";
    
    std::vector<int> v2 = std::move(v1);
    std::cout << "v1 size after move: " << v1.size() << "\n";
    std::cout << "v2 size after move: " << v2.size() << "\n";
}

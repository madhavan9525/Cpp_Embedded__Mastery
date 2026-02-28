#include<iostream>
#include<memory>
#include<string>


class Device{
    public:
    std::string name;
    Device(std::string n): name(n){
        std::cout<<"Device "<<name<<" is created"<<std::endl;
    }
    ~Device(){
        std::cout<<"Device "<<name<<" is destroyed"<<std::endl;
    }
};

struct Node {
    std::string name;
    std::shared_ptr<Node> next; // change this to weak_ptr later
    //std::weak_ptr<Node> next;

    Node(std::string n): name(n){ std::cout << name << " created\n"; }
    ~Node(){ std::cout << name << " destroyed\n"; }
};


int main(){

//Unique pointers
    std::unique_ptr<Device> d =std::make_unique<Device>("samsung");
    auto d1 = std::make_unique<Device>("sensor");
    // auto d2 = d1;
    auto d2 = std::move(d1);
    std::cout<<(d1 == nullptr ? "d1 is empty":"d1 has values")<<std::endl;

//Shared pointers
    auto s1 = std::make_shared<Device>("shared sensor");
    {
        auto s2 = s1;
        std::cout<<"owners:"<<s1.use_count() << "\n";
    }
            std::cout<<"owners:"<<s1.use_count() << "\n";

            /*Why shared_ptr allows copying — it keeps a reference count. When count hits 0, it destroys. 
            unique_ptr has no counter, one owner only.*/

//weak pointer

 auto n1 = std::make_shared<Node>("n1");
    auto n2 = std::make_shared<Node>("n2");
    n1->next = n2;
    n2->next = n1; // circular!

    
}


    

#include<iostream>
#include<vector>
#include<string>

class SensorBuffer{
public:
    std::string name;
    std::vector<float> data;

    // Normal constructor
    SensorBuffer(std::string n, std::vector<float> d)
        : name(n), data(d){
        std::cout << name << " created\n";
    }

    // Move constructor
    SensorBuffer(SensorBuffer&& other) noexcept
        : name(std::move(other.name)), 
          data(std::move(other.data)){
        std::cout << name << " move constructed\n";
    }

    // Move assignment operator
    SensorBuffer& operator=(SensorBuffer&& other) noexcept {
    std::cout << "move assignment called\n";
    
    if(this != &other){  // prevent self assignment
        name = std::move(other.name);
        data = std::move(other.data);
    }
    return *this;
    }

    ~SensorBuffer(){
        std::cout << "destroyed, data size: " << data.size() << "\n";
    }
};

int main()
{
    SensorBuffer s1("TempSensor", {1.1, 2.2, 3.3, 4.4, 5.5});
    std::cout << "s1 data size: " << s1.data.size() << "\n";

    SensorBuffer s2 = std::move(s1);
    std::cout << "s1 data size after move: " << s1.data.size() << "\n";
    std::cout << "s2 data size after move: " << s2.data.size() << "\n";


    SensorBuffer s3("Temp", {1.1, 2.2, 3.3});
    SensorBuffer s4("Gyro", {4.4, 5.5});

    std::cout << "s4 data size before: " << s4.data.size() << "\n";
    s4 = std::move(s3);
    std::cout << "s4 data size after: " << s4.data.size() << "\n";
    std::cout << "s3 data size after: " << s3.data.size() << "\n";
}

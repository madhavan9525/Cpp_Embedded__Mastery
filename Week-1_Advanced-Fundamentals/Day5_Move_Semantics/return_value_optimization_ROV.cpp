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

    ~SensorBuffer(){
        std::cout << name << " destroyed, data size: " << data.size() << "\n";
    }
};

// Function that creates and returns SensorBuffer
SensorBuffer captureData(){
    SensorBuffer buf("TempSensor", {1.1, 2.2, 3.3}); // object created inside
    std::cout << "inside function, buf size: " << buf.data.size() << "\n";
    //return buf; // compiler moves this out via RVO
    return std::move(buf); // no ROV
}

int main()
{
    std::cout << "--- calling captureData ---\n";
    SensorBuffer result = captureData(); // result receives the object
    std::cout << "--- back in main ---\n";
    std::cout << "result name: " << result.name << "\n";
    std::cout << "result size: " << result.data.size() << "\n";
}



/*## Run it and observe

Expected flow:
```
--- calling captureData ---
TempSensor created          ← buf created inside function
inside function, buf size: 3
--- back in main ---        ← RVO kicks in, no move constructor printed!
result name: TempSensor
result size: 3
TempSensor destroyed        ← result destroyed at end of main */

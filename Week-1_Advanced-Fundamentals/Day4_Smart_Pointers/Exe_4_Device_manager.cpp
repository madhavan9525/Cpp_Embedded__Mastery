#include<iostream>
#include<memory>
#include<string>
#include<vector>


class Device{
public:
    std::string Device_Name;

    Device(std::string n):Device_Name(n){
        std::cout<<"Device:"<<Device_Name<<" is created"<<"\n";
    }
    void run()
    {
        std::cout<<"Device:"<<Device_Name<<" is running"<<"\n";
    }

    ~Device()
    {
        std::cout<<"Device:"<<Device_Name<<" is Destroyed"<<"\n";
    }
};

class Device_Manager{
    std::vector<std::unique_ptr<Device>> Devices;
 public:
 //std::vector<std::unique_ptr<Device>> Devices;
    void addDevice(std::string name);
    void runAll();   
};

void Device_Manager::addDevice(std::string name)
{
    auto d1 = std::make_unique<Device>(name);
    Devices.push_back(move(d1));
    // Devices.push_back(std::make_unique<Device>(name));
}

void Device_Manager::runAll(){
    for(size_t i=0;i<Devices.size();i++)
    {
        Devices.at(i)->run();
    }

}

int main()
{
    Device_Manager manager;
    manager.addDevice("Sensor");
    manager.addDevice("motor");
    manager.addDevice("camera");
    manager.runAll();
}

#include<iostream>
#include<memory>

int main()
{
    // Step 1: define custom deleter as lambda
    auto fileDeleter = [](FILE* f){
        std::cout << "File closing automatically\n";
        fclose(f);
    };

    // Step 2: open file with unique_ptr + custom deleter
    std::unique_ptr<FILE, decltype(fileDeleter)> 
        file(fopen("sensor_data.txt", "w"), fileDeleter);

    /*  Explanation 1
        
    std::unique_ptr<FILE, decltype(fileDeleter)>  // TYPE
    file(fopen("sensor_data.txt", "w"), fileDeleter);  // VARIABLE 
    
    TYPE:
    std::unique_ptr<FILE, decltype(fileDeleter)>
              ^         ^
         what it      what function
         holds        to call on destroy

         Normal unique_ptr takes one type: std::unique_ptr<Device>  // uses default delete
         With custom deleter takes two types:std::unique_ptr<FILE, decltype(fileDeleter)>  // uses our deleter
         "Above is the syntax for unique_ptr"
    
    VARIABLE:
    file(fopen("sensor_data.txt", "w"), fileDeleter)
       ^                               ^
       raw pointer to manage           deleter to call on destroy
    
    Normal unique_ptr construction: unique_ptr<Device> d(new Device());  // one argument

    With custom deleter:

    unique_ptr<FILE,...> file(fopen(...), fileDeleter);  // two arguments
                              ^           ^
                              the pointer    the deleter

---

## Full Picture
```
unique_ptr called "file"
    → holds FILE* from fopen()
    → when destroyed, calls fileDeleter(FILE*)
    → fileDeleter calls fclose()
    
    */

/*  Explanation 2 - hy we pass filedeleter two time inside unique_ptr type and file?

    1st time — inside <> (Template)
    std::unique_ptr<FILE, decltype(fileDeleter)>
                      ^
                 "I will use A DELETER OF THIS TYPE"
                 just telling the TYPE, not the actual function


    2nd time — inside () (Constructor)
    file(fopen("sensor_data.txt", "w"), fileDeleter)
                                    ^
                          "THIS is the actual function to call"
    ```
    This is passing the **actual function itself**

    ---

    ## Analogy
    ```
    1st time = telling compiler "I'll pay by credit card"  // type
    2nd time = actually handing over your credit card      // actual value
    
*/

    // Step 3: write to file
    if(file){
        fprintf(file.get(), "Temperature: 25.5C\n");
        fprintf(file.get(), "Humidity: 60%%\n");
        std::cout << "Data written to file\n";
    }

} // file automatically closed here!

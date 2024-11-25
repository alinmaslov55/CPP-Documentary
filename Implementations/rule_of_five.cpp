#include <iostream>

// Rule of 3 applies to older c++ versions 03 and earlier - without move semantic
// Rule of 0 encourages using standard containers instead or smart pointers std::unique_ptr, std::shared_ptr
class Human{
    std::string name;
    int *data_of_person;
    int size_of_data;
    int age;
    public:
    // constructor
    Human(const std::string& name = "", const int& age = 0, const int& size = 0) : name(name), age(age), size_of_data(size){
        if(size_of_data > 0) data_of_person = new int[size];
        else data_of_person = nullptr;
    }

    //destructor
    ~Human(){
        delete[] data_of_person;
    };

    //Copy destructor
    Human(const Human& otherHuman){
        name = otherHuman.name;
        age = otherHuman.age;
        if(this->data_of_person != nullptr) delete data_of_person;
        if(otherHuman.size_of_data > 0){
            data_of_person = new int[otherHuman.size_of_data];
            for(int i = 0; i < otherHuman.size_of_data; i++){
                data_of_person[i] = otherHuman.data_of_person[i];
            }
        }
        this->size_of_data = otherHuman.size_of_data;
    }

    //Copy assignment operator
    Human& operator=(const Human& otherHuman){
        if(this == &otherHuman) return *this;
        
        if(data_of_person!= nullptr) delete data_of_person;
        
        if(otherHuman.size_of_data > 0){
            data_of_person = new int[otherHuman.size_of_data];
            for(int i = 0; i < otherHuman.size_of_data; i++){
                data_of_person[i] = otherHuman.data_of_person[i];
            }
        }
        this->size_of_data = otherHuman.size_of_data;
        name = otherHuman.name;
        age = otherHuman.age;
        return *this;
    }

    //Move constructor
    Human(Human&& otherHuman) noexcept : name(""), age(0){
        this->name = otherHuman.name;
        this->age = otherHuman.age;

        otherHuman.name = "";
        otherHuman.age = 0;
    }

    //Move assignment operator
    Human& operator=(Human&& otherHuman) noexcept {
        if(this == &otherHuman) return *this;
        
        std::swap(name, otherHuman.name);
        std::swap(age, otherHuman.age);
        return *this;
    }
};

int main(){

    return 0;
}
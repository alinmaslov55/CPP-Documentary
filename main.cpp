#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

void ex1();
void ex2();
int main(){

    int option = 0;

    std::cin >> option;

    switch(option){
        case 1:
            ex1();
            break;
        case 2:
            ex2();
            break;

    }
    return 0;
}
void ex2(){
    auto compare1 = [](int &x, int &y){
        return x < y;
    };
    auto compare2 = [](int &x, int &y){
        return x > y;
    };
    //Use two std::priority_queues (one max-heap and one min-heap) to dynamically calculate the median of a stream of numbers.
    std::priority_queue<int, std::vector<int>, decltype(compare1)> first(compare1);
    std::priority_queue<int, std::vector<int>, decltype(compare2)> second(compare2);

    int n{10};
    int num;
    std::cout << "\nCitire numere:" << std::endl;

    while(n > 0){
        std::cin >> num;
        first.emplace(num);
        second.emplace(num);
        n--;
    }

    int num1, num2;
    do{
    
        num1 = first.top();
        num2 = second.top();
        first.pop();
        second.pop();
    
    }while(num1 < num2);

    std::cout << (num1 + num2)/(float)2 << std::endl;
}
void ex1(){
    //Given a std::vector of a custom class (e.g., Student{name, grade}), sort the students by grade using std::sort.
    typedef struct Student{
        std::string name{""};
        float grade{0.0f};
        Student(std::string name, float grade){
            this->name = name;
            this->grade = grade;
        }
    } Student;
    std::vector<Student> my_student;
    int n{5};
    float grade;
    std::string name;

    while(n > 0){
        std::cout << "Nume: ";
        std::cin>> name;
        std::cout << "Grade: ";
        std::cin >> grade;
        my_student.push_back(Student(name, grade));
        n--;
    }

    std::for_each(my_student.begin(), my_student.end(), [](const Student &x){
        std::cout << x.name << " : " << x.grade << std::endl;
    });
    std::cout << "---------------\n";

    std::sort(my_student.begin(), my_student.end(), [](Student& x, Student& y){
        return x.name < y.name;
    });

    std::for_each(my_student.begin(), my_student.end(), [](const Student &x){
        std::cout << x.name << " : " << x.grade << std::endl;
    });
    std::cout << "---------------\n";

}
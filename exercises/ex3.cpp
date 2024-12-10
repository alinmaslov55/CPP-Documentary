/*Implement a program to:

    Add tasks with a priority (e.g., high, medium, low).
    Retrieve the highest-priority task to execute.
    Display all tasks sorted by priority.*/

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <utility>

typedef std::pair<std::string, int> task;

void afisare(const std::vector<task>& schedule);
void introducere(std::vector<task>& schedule);
int main(){
    std::vector<task> schedule;

    int option{0};

    do{
        std::cout << "1 - introducere" << std::endl;
        std::cout << "2 - afisare" << std::endl;
        std::cout << "Alegeti Optiune: ";
        std::cin >> option;
        switch(option){
            case 0:
                break;
            case 1:
                introducere(schedule);
                break;
            case 2:
                afisare(schedule);
                break;
            default:
                std::cout << "Optiune gresita" << std::endl;
        }
    }while(option);

    return 0;
}
void afisare(const std::vector<task>& schedule){
    std::for_each(schedule.begin(), schedule.end(), [](const task& pair){
        std::cout << pair.second << " - " << pair.first; 
    });
}
void introducere(std::vector<task>& schedule){
    task new_task;
    int prioritate;
    std::string lucru;
    std::cin >> prioritate;
    std::cin >> lucru;
    new_task.first = lucru;
    new_task.second = prioritate;

    schedule.push_back(new_task);

    std::stable_sort(schedule.begin(), schedule.end(), [](const task& first, const task& second){
        return first.second < second.second;
    });
}
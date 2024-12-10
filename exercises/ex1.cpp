/* Write a program to store words and their multiple meanings. Provide functionality to:

    Add a new word with its meanings.
    Retrieve all meanings of a word.
    Display all words and their meanings in alphabetical order.*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>


void adaugare(std::map<std::string, std::vector<std::string>>& my_dictionary);
void afisare(const std::map<std::string, std::vector<std::string>>& my_dictionary);
int main(){
    std::map<std::string, std::vector<std::string>> my_dictionary;

    int optiune{0};

    do{
        std::cout << "1 - Adaugare Notiune" << std::endl;
        std::cout << "2 - Afisare Notiuni" << std::endl;
        std::cout << "Alegeti Optiune: ";
        std::cin >> optiune;
        switch(optiune){
            case 0:
                break;
            case 1:
                adaugare(my_dictionary);
                break;
            case 2:
                afisare(my_dictionary);
                break;
            default:
                std::cout << "Optiune Gresita" << std::endl;
        }
    }while(optiune);
    
    return 0;
}
void adaugare(std::map<std::string, std::vector<std::string>>& my_dictionary){
    std::string s_buffer1, s_buffer2;
    std::cout << "Dati cuvant de adaugat definitie: " << std::endl;
    std::cin >> s_buffer1;
    std::cin.ignore();
    std::cout << "Dati definitie: " << std::endl;
    std::getline(std::cin, s_buffer2);

    if(my_dictionary.contains(s_buffer1)){
        my_dictionary[s_buffer1].push_back(s_buffer2);
    } else {
        std::pair<std::string, std::vector<std::string>> new_pair;
        new_pair.first = std::move(s_buffer1);
        new_pair.second.push_back(s_buffer2);
        my_dictionary.insert(new_pair);
    }
}
void afisare(const std::map<std::string, std::vector<std::string>>& my_dictionary){
    std::for_each(my_dictionary.begin(), my_dictionary.end(), [](const std::pair<std::string, std::vector<std::string>>& pair){
        std::cout << pair.first << std::endl;
        int x{0};
        std::for_each(pair.second.begin(), pair.second.end(), [&x](const std::string& definition){
            std::cout << "\t\t" << ++x << ".\t" << definition << std::endl;
        });
    });
}
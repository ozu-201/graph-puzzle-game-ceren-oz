#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "graph.h"

int main(){
    std::vector<std::string> dictionary3;
    std::vector<std::string> dictionary4;
    std::vector<std::string> dictionary5;
    std::ifstream file("C:\\Users\\TEMP.OZUN\\Downloads\\wordtest.txt");
    std::string line;
    if(file.is_open()){
        while (getline(file,line)){
            if(line.length()==3){
                dictionary3.push_back(line);
            }
            else if(line.length()==4){
                dictionary4.push_back(line);
            }
            else if(line.length()==5){
                dictionary5.push_back(line);
            }
        }
    }
    file.close();



    /*Graph graph3= Graph( dictionary3.size());
    graph3.createGraph(dictionary3);*/

    Graph graph4=  Graph( dictionary4.size());
    graph4.createGraph(dictionary4);
    std::vector<std::string> words =graph4.breadthFirstSearch("polo","tall");

    for(const auto & word : words){
        std::cout << word;
    }

    /*Graph graph5= Graph(dictionary5.size());
    graph5.createGraph(dictionary5);

    std::cout << "enter number of letters: ";
    int numLetters;
    std::cin >> numLetters;

    std::cout << "enter the first word: ";
    std::string firstWord;
    std::cin >> firstWord;

    std::cout << "enter the last word: ";
    std::string lastWord;
    std::cin >> lastWord;*/

    return 0;
}

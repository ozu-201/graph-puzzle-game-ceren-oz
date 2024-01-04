#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "graph.h"

int main(){
    std::vector<std::string> dictionary3;
    std::vector<std::string> dictionary4;
    std::vector<std::string> dictionary5;


    std::ifstream file("C:\\Users\\co033572\\Downloads\\turkishDictionary.txt");
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

/*
    dictionary3.push_back("cat");
    dictionary3.push_back("cot");
    dictionary3.push_back("cog");
    dictionary3.push_back("dog");

    dictionary4.push_back("dark");
    dictionary4.push_back("bark");
    dictionary4.push_back("barn");

    dictionary5.push_back("stone");
    dictionary5.push_back("store");
    dictionary5.push_back("score");
*/



    Graph graph3= Graph( dictionary3.size());
    graph3.createGraph(dictionary3);

    Graph graph4=  Graph( dictionary4.size());
    graph4.createGraph(dictionary4);

    Graph graph5= Graph(dictionary5.size());
    graph5.createGraph(dictionary5);

    std::cout << "enter number of letters: ";
    int numLetters;
    std::cin >> numLetters;

    std::cout << "enter the first word: ";
    std::string firstWord;
    std::cin >> firstWord;

    std::cout << "enter the last word: ";
    std::string lastWord;
    std::cin >> lastWord;


    //for dijkstra
    std::vector<std::string> words1;

    //for Breadth First Search
    std::vector<std::string> words2;

   if(numLetters==3){
        words1=graph3.dijkstra(firstWord,lastWord);
       // words2=graph3.breadthFirstSearch(firstWord,lastWord);
   }
    else if(numLetters==4){
        words1=graph4.dijkstra(firstWord,lastWord);
       //words2=graph4.breadthFirstSearch(firstWord,lastWord);
    }
    else if(numLetters==5){
        words1=graph5.dijkstra(firstWord,lastWord);
       //words2=graph5.breadthFirstSearch(firstWord,lastWord);
    }

    std::cout << "Dijkstra: ";
    for(const auto & word : words1){
        std::cout << word <<" ";
    }

    /*std::cout << "/ Breadth First Search: ";
    for(const auto & word : words2){
        std::cout << word <<" ";
    }*/



    return 0;
}

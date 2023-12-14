#include <string>

class Edge{
public:
    std::string from;
    std::string to;
    int weight;
    Edge* next;

public:
    Edge(std::string from, std::string to){
        this->from=from;
        this-> to=to;
        next=nullptr;
        this->weight=1;
    }


};
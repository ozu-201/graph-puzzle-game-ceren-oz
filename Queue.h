#include <iostream>
#include <string>

class Node{
public:
    std::string data;
    Node* next;

    Node(std::string data){
        this->data=data;
        this->next= nullptr;
    }
};

class Queue{
public:
    Node* first;
    Node* last;
public:
    Queue(){
        first= nullptr;
        last= nullptr;
    }

    bool isEmpty(){
        return first==nullptr;
    }
    void enqueue(Node* newNode){
        if(isEmpty()){
            first=newNode;
        }else{
            last->next=newNode;
        }
        last=newNode;
    }
    Node* dequeue(){
        Node* result =first;
        if(!isEmpty()){
            first=first->next;
            if (isEmpty()){
                last= nullptr;
            }
        }
        return result;
    }
};
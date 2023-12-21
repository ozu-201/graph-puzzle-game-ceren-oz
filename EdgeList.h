
#include "Edge.h"

class EdgeList {
public:
        Edge* head;
        Edge* tail;
     public:
        EdgeList(){
        head = nullptr;
        tail = nullptr;
    }
        void insert (Edge* newEdge){
            if (head == nullptr) {
                head = newEdge;
            }
            else {
                tail->next = newEdge;
            }
            tail = newEdge;
        }
};


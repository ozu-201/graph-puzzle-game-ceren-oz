#include <string>
#include <vector>
#include "EdgeList.h"
#include "Queue.h"



class Graph{
    int vertexCount;
    std::vector<EdgeList> edges;

public:
    Graph(int vertexCount) : vertexCount(vertexCount){
        edges.resize(vertexCount);
    }

    void createGraph(std::vector<std::string> words){

        for(int i=0; i<words.size(); i++){
            std::string word1=words[i];
            if(words.size()==1){
                Edge *edge1=new Edge(word1,"");
                edges[i].insert(edge1);
                break;
            }
            for(int j=i+1; j<words.size(); j++){
                std::string word2=words[i];
                if(isOneLetterApart(word1,word2)){
                    Edge *edge1=new Edge(word1,word2);
                    edges[i].insert(edge1);
                    Edge *edge2=new Edge(word2,word1);
                    edges[j].insert(edge2);
                }
            }
        }

    }
    bool isOneLetterApart(std::string word1, std::string word2){
        if(word1.length()!=word2.length()){
            return false;
        }
        int diffNum=0;
        for(int i=0; i<word1.length(); i++){
            if(word1[i]!=word2[i]){
                diffNum++;
            }
            if(diffNum>1){
                return false;
            }
        }
        return diffNum==1;
    }

    std::vector<std::string> breadthFirstSearch(std::string startNode, std::string endNode){
        std::vector<bool> visited;
        visited.resize(vertexCount);

        std::vector<std::string> words;
        bool toFound = false;

        Queue* queue = new Queue();
        queue->enqueue(new Node(startNode));

        while(!queue->isEmpty()){
            std::string fromNode=queue->dequeue()->data;
            Edge* edge= nullptr;
            for(int i=0; i<edges.size();i++){
                if(edges[i].head->from == fromNode){
                    if(!visited[i]){
                        visited[i]= true;
                        words.push_back(edges[i].head->from);
                        edge=edges[i].head;
                    }
                    break;
                }
            }
            while(edge != nullptr){
                std::string toNode=edge->to;
                int i;
                for(i=0; i<edges.size();i++){
                    if(edges[i].head->from==toNode){
                        edge=edges[i].head;
                        break;
                    }
                }
                if(!visited[i]){
                    visited[i]= true;
                    words.push_back(edges[i].head->from);
                    queue->enqueue(new Node(toNode));
                }

                if(edges[i].head->from==endNode){
                    toFound = true;
                    break;
                }
                edge = edge->next;
            }
            if(edge == nullptr){
                std::cout << "end node not found.";
                words.clear();
                break;
            }
            if(toFound){
                break;
            }
        }
        return words;
    }
};

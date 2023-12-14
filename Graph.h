#include <string>
#include <vector>
#include "EdgeList.h"


class Graph{
    int vertexCount;
    std::vector<EdgeList> edges;

public:
    Graph(int vertexCount) : vertexCount(vertexCount){
        edges.resize(vertexCount);
    }

    Graph createGraph(std::vector<std::string> words){
        Graph graph(words.size());
        for(int i=0; i<words.size(); i++){
            std::string word1=words[i];
            if(words.size()==1){
                Edge *edge1=new Edge(word1,"");
                graph.edges[i].insert(edge1);
                break;
            }
            for(int j=i+1; j<words.size(); j++){
                std::string word2=words[i];
                if(isOneLetterApart(word1,word2)){
                    Edge *edge1=new Edge(word1,word2);
                    graph.edges[i].insert(edge1);
                    Edge *edge2=new Edge(word2,word1);
                    graph.edges[j].insert(edge2);
                }
            }
        }
        return graph;
    }
    bool isOneLetterApart(std::string word1, std::string word2){
        if(word1.length()!=word2.length()){
            return false;
        }
        int diffNum;
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
};

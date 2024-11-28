#ifndef Graph_h
#define Graph_h

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <typeinfo>
#include <algorithm>

class Graph
{
private:
    int edgesList;
    int edgesMat;
    int nodes;
    std::vector<int> *adjList;
    int *adjMatrix;

public:
    Graph();
    void loadGraphList(std::string, int);
    void addToList(int, int);
    void sortAdjList();
    void loadGraphMat(std::string, int, int);
    void addToMat(int, int, bool);
    std::string printAdjList();
    std::string printAdjMat();
    std::string DFS(int x, int y){return "0";}
    std::string BFS(int x, int y) {return "0";}
};

Graph::Graph()
{
    edgesList = 0;
    edgesMat = 0;
    nodes = 0;
    adjList = 0;
    adjMatrix = 0;
}

void Graph::addToList(int n1, int n2)
{
    adjList[n1].push_back(n2);
    adjList[n2].push_back(n1);
    edgesList++;
    sortAdjList();
}

void Graph::loadGraphList(std::string inputList, int nodos)
{
    nodes = nodos;
    adjList = new std::vector<int>[nodes];
    
    for (int j = 0; j < inputList.size(); j++){
        char temp = inputList[j];
        if (temp == '('){    
            int num1 = inputList[j + 1] - '0';
            int num2 = inputList[j + 3] - '0';
            addToList(num1, num2);
        }
    }

}

void Graph::sortAdjList()
{
    for (int i = 0; i < nodes; i++){
        sort(adjList[i].begin(), adjList[i].end());
    }
}

void Graph::addToMat(int n1, int n2, bool binario)
{
    if (binario == false)
    {
        adjMatrix[n1 * n2] = 0;
        std::cout << "[" << n1 << "][" << n2 << "]: " << adjMatrix[n1 * n2] << std::endl;
        adjMatrix[n2 * n1] = 0;
        std::cout << "[" << n2 << "][" << n1 << "]: " << adjMatrix[n2 * n1] << std::endl;
        edgesMat++;
    }
    else if (binario == true)
    {
        adjMatrix[n1 * n2] = 1;
        std::cout << "[" << n1 << "][" << n2 << "]: " << adjMatrix[n1 * n2] << std::endl;
        adjMatrix[n2 * n1] = 1;
        std::cout << "[" << n2 << "][" << n1 << "]: " << adjMatrix[n2 * n1] << std::endl;
        edgesMat++;
    }
}

void Graph::loadGraphMat(std::string inputMat, int n1, int n2)
{
    adjMatrix = new int[n1 * n2];
    nodes = n1;
    for (int i = 0;i < inputMat.size();i++){
        char temp = inputMat[i];
        if (temp == '('){
            int num1 = inputMat[i + 1] - '0';
            int num2 = inputMat[i + 3] - '0';
            addToMat(num1, num2, true);
            //Escribir la matriz en papel pa ver cómo hacerla aquí
        }
    }
    for (int j = 0;j < nodes;j++){
        addToMat(j, j, false);
    }
}

std::string Graph::printAdjList()
{
    std::stringstream aux;
    for (int i = 0; i < nodes; i++)
    {
        aux << "vertex " << i << " :";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            aux << " " << adjList[i][j];
        }
        aux << " ";
    }
    return aux.str();
}

std::string Graph::printAdjMat(){
    std::stringstream aux;
    for (int i = 0;i < nodes;i++){
        for (int j = 0;j < nodes;j++){
            aux << " " << adjMatrix[i * j];
        }
        //aux << " ";
    }
    return aux.str();
}

#endif

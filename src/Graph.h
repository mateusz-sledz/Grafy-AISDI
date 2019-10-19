//
// Created by Mateusz on 03.01.2019.
//

#ifndef GRAFY_GRAPH_H
#define GRAFY_GRAPH_H

#include <iostream>
#include <fstream>
#include <random>


class Graph {
public:

    Graph(const std::string &file_name)
    {
        create(file_name);
        visited = new bool[amount]{false};
    }

    ~Graph()
    {
        clear();
        delete[] arr;
        delete[] arr2;
        delete[] visited;
    }


    void create (const std::string &file_name);
    void show ();
    void find();
    void markVisit(size_t one, size_t two, size_t three);
    void clear();

private:

    class Node{
    public:
        size_t apex;
        Node* pointer;

        Node(size_t one=0, Node* two=nullptr) : apex(one), pointer(two)
        {}
    };

    size_t amount;
    Node **arr;
    Node **arr2;
    bool* visited;



};


#endif //GRAFY_GRAPH_H

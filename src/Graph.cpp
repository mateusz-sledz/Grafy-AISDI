//
// Created by Mateusz on 03.01.2019.
//

#include "Graph.h"

void Graph::show ()
{
    int i = 0;
    Node* current;
    while(i < amount)
    {
        current = arr2[i];
        while(current != nullptr)
        {
            std::cout << i << "  " << current->apex << "  "<<std::endl;
            current = current->pointer;
        }
        i++;
    }
}

void Graph::markVisit(size_t one, size_t two, size_t three)
{
    visited[one] = true;

    auto current = arr[one];

    while(current != nullptr)
    {
        if(visited[current->apex] == true || one == two || one == three )
        {
            current = current->pointer;
            continue;
        }

        markVisit(current->apex, two, three);
        current = current->pointer;
    }
}


void Graph::find()
{
    size_t i =0;
    size_t x,y;

    while(i < amount)
    {
        auto current = arr2[i];
        x = i;
        while(current != nullptr)
        {
            y = current->apex;
            visited[x] = true;
            visited[y] = true;

            std::mt19937 mt(1729453);    //random number
            std::uniform_int_distribution<size_t> dist(0,amount-1);
            auto temp = dist(mt);

            while(arr2[temp] == nullptr || temp == x || temp== y)
            {
                temp = dist(mt);
            }

            markVisit(temp, x, y);

            int p=0;
            while(p < amount)
            {
                if(!visited[p])
                {
                    std::cout << "Most miedzy "<<x <<" a "<<y<<std::endl;
                    break;
                }
                p++;
            }

            p = 0;

            while(p < amount)
            {
                visited[p] = false;
                p++;
            }

            current = current->pointer;
        }
        i++;
    }
}

void Graph::create (const std::string &file_name)
{
    std::fstream plik;
    plik.open( file_name, std::ios::in);
    if( plik.good() )
    {
        plik >> amount;
        arr = new Node*[amount]{nullptr};
        arr2 = new Node*[amount]{nullptr};
        size_t x, y;

        while(! plik.eof())
        {
            plik >> x;
            plik >> y;

            auto newnode = new Node(y);
            if(arr[x] == nullptr)
                arr[x] = newnode;
            else
            {
                newnode->pointer = arr[x];
                arr[x] = newnode;
            }

            auto newnode1 = new Node(y);
            if(arr2[x] == nullptr)
                arr2[x] = newnode1;
            else
            {
                newnode1->pointer = arr2[x];
                arr2[x] = newnode1;
            }

            auto newnode2 = new Node(x);
            if(arr[y] == nullptr)
                arr[y] = newnode2;
            else
            {
                newnode2->pointer = arr[y];
                arr[y] = newnode2;
            }

        }
        plik.close();
    }
    else{
        std::cout<<"cant read file"<<std::endl;
    }
}

void Graph::clear()
{
    Node* curr;
    Node* temp;
    for(size_t i=0 ; i < amount ; i++)
    {
        curr = arr[i];
        while(curr != nullptr)
        {
            temp = curr;
            curr = curr->pointer;
            delete temp;
        }
        arr[i] = nullptr;
    }

    if (arr2 == nullptr)
        return;
    for(size_t i=0 ; i < amount ; i++)
    {
        curr = arr2[i];
        if(curr == nullptr)
            continue;
        while(curr != nullptr)
        {
            temp = curr;
            curr = curr->pointer;
            delete temp;
        }
        arr2[i] = nullptr;
    }
    amount = 0;
}
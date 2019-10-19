#include <iostream>
#include "Graph.h"

int main()
{

    Graph sample("sampleData.txt");
    sample.show();
    sample.find();

    return 0;
}
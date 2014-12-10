
#include "node.h"

Node::Node (int nodeVal, Node *nextPtr)
 : value (nodeVal), next (nextPtr)
{
    //std::cout << "Constructor Node" << std::endl;
}


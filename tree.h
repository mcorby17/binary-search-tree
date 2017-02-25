#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <cstddef>

template <class T>
class Tree {

  private:
    int   numOfNodes;
    int   numOfLeaves;
    Node<T>* startPtr;
    
    char nodeCompare(Node<T>* a, Node<T>* b);
    //Compares data in 2 nodes
    //Input: 2 Nodes
    //Output: 'g' if a.data > b.data, 'l' id a.data < b.data, 'e' if a.data == b.data

	void printContents(Node<T>*);
	//Prints data and if there is a node or not attached to the node's pointers
	//Input: 1 Node Pointer
	//Output: Printed data

  public:

  //Constructors
    Tree();			  //Default constructor
    Tree(const Tree&);		  //Copy Constructor
    Tree& operator=(const Tree&); //Assignment operator

  //Destructor
    ~Tree();

  //Methods
    void addNode(const T);		
    //Adds a node to the Tree.
    // Input: Value of templated type T

    Node<T>* search(const T);	//Note: What happens if there's 2 or more nodes holding the same data?
    //Searches for a node holding data T.
    //Input: Data of type T
    //Output: The address of the node holding the data

    void deleteNode(const T); //Note: Must account for nodes pointing to 0,1, or 2 nodes
    //Deletes a node from the tree
    //Input: Data of type T
     
    void deleteNode(Node<T>* const*);
    //Deletes a node from the tree
    //Input: Address of node to be deleted

    void returnAscOrDesc(const char);
    //Outputs the Data from all nodes of the tree in ascending or descending fashion
    //Input: The letter 'a' or 'A' to print in ascending (a-z or -inf to inf) fashion
    //	     The letter 'd' or 'D' to print in descending (z-a or inf to -inf) fashion

    int getNumOfNodes();
    //Returns the total number of nodes in the tree, kept track by the int property numOfNodes
    //Input: none
    //Output: int value stored in numOfNodes

    int getNumOfLeaves();
    //Returns the number of leaves (nodes with NULL stored in  both left and right ptrs) in the Tree
    //Input: none
    //Output: int value stored in numOfLeaves

    Node<T>* getStartPtr();
    //Returns the address of the first node in the tree
    //Input: none
    //Output: Node* address
   
	void visualTraverse();
	//Returns nothing
	//Input: none
	//Output: The contents of the root node. A prompt will ask which node you would like to go to next. The chosen node's contents is dasplayed

    //TEMP FUNCTIONS 
    void printData();
    //Temporary function to validate data stored in the tree class

    void setNodes(T);
    void setLeaves(T);
    
};

#endif

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

	Node<T>* makeNode(const T, Node<T>* const up = NULL, Node<T>* const left = NULL, Node<T>* const right = NULL);
	//Creates a node
	//Input: Data, optionally pass addresses of nodes to attatch to left and right pointers of the created node
	//Output: Address to a new node containing passed data and optional pointers

	void parseTree(Node<T>*);
	//Searches through the tree to and appends the passed node to it
	//Input: Address of a node object
	//Output: None

	bool isInTree(const T data, int &level, Node<T>* &addrOfFoundNode);
	//Searches through the tree for a node with the same data that was passed to the function
	//Input: Data of templated type T, optionally pass a reference to variables to hold the level the found node is at, along with it's address
	//Output: true if a node holding the same data is found, false if not

	int howManyNodesAttached(Node<T>*);
	//Input: A pointer holding the address of a Node
	//Output: An integer referring to how many pointers hold node addreses. This can only be 0,1, or 2.

	void deleteNodeWithSinglePtr(Node<T>*);
	//Input: pointer holding address of a node
	//Output: none

	void deleteNodeWithBothPtrs(Node<T>*);
	//Sets the pointers around a node-to-be-deleted so that the Tree maintains correct form once the node is deleted
	//Input: pointer holding the address of a node that will be deleted
	//Output: None
  
	void setParentPtrToNull(Node<T>*);
	//Used to set a parent's pointer to the passed child to NULL to avoid dangling pointers
	//Input: A child node that will be deleted
	//Output: none

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

    Node<T>* search(const T, bool=true);	//Note: What happens if there's 2 or more nodes holding the same data?
    //Searches for a node holding data T.
    //Input: Data of type T
    //Output: The address of the node holding the data

    void deleteNode(const T);
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

#include <iostream>
#include "tree.h"

using namespace std;

// Constructors/Destructor ---------------------------
template <class T>
Tree<T>::Tree() : numOfNodes(0), numOfLeaves(0), startPtr(NULL){}

template <class T>
Tree<T>::Tree(const Tree<T>& other){
  numOfNodes = other.numOfNodes;
  numOfLeaves = other.numOfLeaves;
  startPtr = other.startPtr;
}

template <class T>
Tree<T>& Tree<T>::operator=(const Tree<T>& other){
  numOfNodes = other.numOfNodes;
  numOfLeaves = other.numOfLeaves;
  startPtr = other.startPtr;
}

template <class T>
Tree<T>::~Tree(){}
// ----------------------------------------------------

// Private Functions ----------------------------------
 
template <class T>
char Tree<T>::nodeCompare(Node<T> *a, Node<T> *b){
	
	T aData = a->getData();
	T bData = b->getData();

	if (aData > bData)
		return 'g';
	else if (aData < bData)
		return 'l';
	else
		return 'e';

}

template <class T>
void Tree<T>::printContents(Node<T>* nodePtr) {

	Node<T>* left = nodePtr->getLeftPtr();
	Node<T>* right = nodePtr->getRightPtr();
	Node<T>* up = nodePtr->getUpPtr();

	cout << "Data: " << nodePtr->getData() << endl;

	if (left != NULL)
		cout << "Left Node holds: " << left->getData() << endl;
	else
		cout << "No left node.\n";

	if (right != NULL)
		cout << "Right node holds: " << right->getData() << endl;
	else
		cout << "No right node.\n";

	if (up != NULL)
		cout << "Previous node holds: " << up->getData() << endl;
	else
		cout << "This is the root node.\n";

}

template<class T>
Node<T>* Tree<T>::makeNode(const T data, Node<T>* const up, Node<T>* const left, Node<T>* const right)
{
	Node<T>* newNode = new Node<T>;
	
	newNode->setData(data);
	newNode->setUpPtr(up);
	newNode->setLeftPtr(left);
	newNode->setRightPtr(right);

	return newNode;
}

template<class T>
void Tree<T>::parseTree(Node<T>* newNode)
{
	Node<T> *tempPtr = startPtr;							// Make tempPtr to keep track of where we are in the Tree

	while (true) {											// Endlessly loop until a break occurs

		if (nodeCompare(newNode, tempPtr) == 'g') {			// If newNode->getData() > tempPtr->getData()

			if (tempPtr->getRightPtr() == NULL) {			// Append newNode to current node's right ptr if there's no node
															// attached to right ptr, which holds greater-than data
				tempPtr->setRightPtr(newNode);
				tempPtr->getRightPtr()->setUpPtr(tempPtr);	// Set the newNode's 'up' pointer to point to it's parent node, which tempPtr is pointing at
				break;										// Break from the endless loop since we successfully added the new node

			}
			else											// If tempPtr->getRightPtr() != NULL, there is already a node here
				tempPtr = tempPtr->getRightPtr();			// Set tempPtr to hold the address of the node at the current node's right ptr

		}

		else if (nodeCompare(newNode, tempPtr) == 'l') {	// Else if newNode->getData() is less than tempPtr->getData()

			if (tempPtr->getLeftPtr() == NULL) {			// If tempPtr->getLeftPtr() returns NULL, there is no node attached to node tempPtr is pointing at

				tempPtr->setLeftPtr(newNode);				// Attach the new node via the current node's left pointer
				tempPtr->getLeftPtr()->setUpPtr(tempPtr);
				break;										// Break from the endless loop since we successfully attrached 

			}
			else											// If tempPtr->getLeftPtr() != NULL, there is already a node here
				tempPtr = tempPtr->getLeftPtr();            // Set tempPtr to hold the address of the node at the current node's left ptr

		}

		else {												// Else, datas of each comapred node using nodeCompare() must be equal
			cout << newNode->getData() << " is already in the tree.\n";    // Give a prompt to notify that the node is in the tree
			break;
		}

	}
}

template<class T>
bool Tree<T>::isInTree(const T data, int &level, Node<T>* &addrOfFoundNode)
{
	Node<T>* searchPtr = startPtr;

	while (true) {

		T searchPtrData = searchPtr->getData();

		if (searchPtrData == data) {
			addrOfFoundNode = searchPtr;
			return true;
		}
		else if ((searchPtr->getLeftPtr() == NULL) && (searchPtr->getRightPtr() == NULL))
			return false;
		else {

			if (data > searchPtrData) {
				searchPtr = searchPtr->getRightPtr();
				level++;
			}
			else if (data < searchPtrData) {
				searchPtr = searchPtr->getLeftPtr();
				level++;
			}
			else
				return true;

		}

	}

	return false;
}

template <class T>
int Tree<T>::howManyNodesAttached(Node<T>* node){

  int numOfNodes = 0;

  if(node->getLeftPtr() != NULL)
    numOfNodes++;
  
  if(node->getRightPtr() != NULL)
    numOfNodes++;

  return numOfNodes; 

}

template <class T>
void Tree<T>::deleteNodeWithSinglePtr(Node<T>* node){

  bool nodeIsLeftPtr = (node->getUpPtr()->getLeftPtr() == node); 
  bool childIsLeftPtr = (node->getLeftPtr() != NULL);

  if(nodeIsLeftPtr){ 

    if(childIsLeftPtr){

      node->getUpPtr()->setLeftPtr(node->getLeftPtr());
      // Makes parent node point to the node-to-be-deleted's
      // child node. Always want to append to parent's left node
      // if node-to-be-deleted is the left child

      node->getLeftPtr()->setUpPtr(node->getUpPtr());
      // Makes node-to-be-deleted's child node point to the
      // node-to-be-deleted's parent node 

    }
    else {
 
      node->getUpPtr()->setLeftPtr(node->getRightPtr());
      // Makes parent node point to the node-to-be-deleted's
      // child node. Always want to append to parent's left node
      // if node-to-be-deleted is the right child

      node->getRightPtr()->setUpPtr(node->getUpPtr());
      // Makes node-to-be-deleted's child node point to the
      // node-to-be-deleted's parent node  

    }        

  }
  else {

    if (childIsLeftPtr) {

      node->getUpPtr()->setRightPtr(node->getLeftPtr());
      // Makes parent node point to the node-to-be-deleted's
      // child node. Always want to append to parent's left node
      // if node-to-be-deleted is the left child

      node->getLeftPtr()->setUpPtr(node->getUpPtr());
      // Makes node-to-be-deleted's child node point to the
      // node-to-be-deleted's parent node 

    } 
    else {

      node->getUpPtr()->setRightPtr(node->getRightPtr());
      // Makes parent node point to the node-to-be-deleted's
      // child node. Always want to append to parent's left node
      // if node-to-be-deleted is the right child

      node->getRightPtr()->setUpPtr(node->getUpPtr());
      // Makes node-to-be-deleted's child node point to the
      // node-to-be-deleted's parent node 

    }

  }
  
  delete node;

}

template <class T>
void Tree<T>::deleteNodeWithBothPtrs(Node<T>* node){

  //Will go down left branch by default since it doesn't matter if you parse down the left or right of the node-to-be-deleted

  Node<T>* movingPtr = node->getLeftPtr();

  while (movingPtr->getRightPtr() != NULL) {

    movingPtr = movingPtr->getRightPtr(); 

  } 

  node->setData(movingPtr->getData());

  setParentPtrToNull(movingPtr); 

  if (movingPtr->getLeftPtr() != NULL)
    deleteNodeWithSinglePtr(movingPtr);
  else
    delete movingPtr; 

}

template <class T>
void Tree<T>::setParentPtrToNull(Node<T>* node){

  Node<T>* parent = node->getUpPtr();
  bool nodeIsLeftChild = (parent->getLeftPtr() == node);

  if (nodeIsLeftChild)
    parent->setLeftPtr(NULL);
  else
    parent->setRightPtr(NULL);

}

// Accessors -------------------------------------------
template <class T>
int Tree<T>::getNumOfNodes(){
  return numOfNodes;
}

template <class T>
int Tree<T>::getNumOfLeaves(){
  return numOfLeaves;
}

template <class T>
Node<T>* Tree<T>::getStartPtr(){
  return startPtr;
}

template <class T>
void Tree<T>::printData(){
  cout << "numOfNodes: " << numOfNodes << endl;
  cout << "numOfLeaves: " << numOfLeaves << endl;
  cout << "startPtr: " << startPtr << endl;
}

template <class T>
void Tree<T>::setNodes(T num){
  numOfNodes = num;
}

template <class T>
void Tree<T>::setLeaves(T num){
  numOfLeaves = num;
}
// ------------------------------------------------------

// Tree Methods -----------------------------------------

template <class T>
void Tree<T>::addNode(const T dat) {
  
	Node<T>* newNode = makeNode(dat);					// Make a new node and insert the data
  
														// 2 scenarios:
	if (startPtr == NULL)								// 1) The Tree instance has no nodes
		startPtr = newNode;												
    else 											    // 2) The Tree instance has nodes already
		parseTree(newNode);
  
  numOfNodes++;

}

template <class T>
Node<T>* Tree<T>::search(const T data, bool printDesc) {

	int level = 0;
	Node<T>* foundNodeAddr = NULL;
	
	if (isInTree(data, level, foundNodeAddr)) {
	  if (printDesc) {
		cout << data << " was found in the Tree.\n";
		cout << "Located at level " << level << endl;
		cout << "Memory Address: " << foundNodeAddr << endl;
	  }
	}
	else {
	  if (printDesc) {
		cout << data << " is not in the Tree.\n";
	  }		
	}
	
	return foundNodeAddr;
}

template <class T>
void Tree<T>::deleteNode(const T data) {
  
  Node<T>* nodeToDelete = search(data, false);

  if (nodeToDelete != NULL) {
    int numOfNodesAttached = howManyNodesAttached(nodeToDelete);

    switch(numOfNodesAttached) {
    
      case 0:
	setParentPtrToNull(nodeToDelete);
	delete nodeToDelete;
	break;
      case 1:
	deleteNodeWithSinglePtr(nodeToDelete);
	//connect single node to nodeToDelete->getUpPtr()
	break;
      case 2:
	deleteNodeWithBothPtrs(nodeToDelete);
	break;
      default:
	cout << "Some weird ass error\n";
    } 
  }
}

template <class T>
void Tree<T>::returnAscOrDesc(const char aOrD) {

}

template <class T>
void Tree<T>::visualTraverse() {

	char choice;
	bool quit = false;
	Node<T>* movingPtr = startPtr;

	while (true) {

		printContents(movingPtr);	// 1) Output root node's contents

		do {

			cout << "How would you like to traverse the tree? (l - left, r - right, u - up, q - quit): ";   // 2) Ask if the user would like to move left or right down the tree
			cin >> choice;

			choice = tolower(choice);

			if (choice == 'l') {	// 3) Move down tree

				if (movingPtr->getLeftPtr() != NULL) {

					movingPtr = movingPtr->getLeftPtr();
					break;

				}
				else {
					cout << "There is no node there. Enter another command.\n";
					continue;
				}

			}
			else if (choice == 'r') {

				if (movingPtr->getRightPtr() != NULL) {

					movingPtr = movingPtr->getRightPtr();
					break;

				}
				else {
					cout << "There is no node there. Enter another command.\n";
					continue;
				}

			}
			else if (choice == 'u') {

				if (movingPtr->getUpPtr() != NULL) {

					movingPtr = movingPtr->getUpPtr();
					break;

				}
				else {
					cout << "You are at the root node, there's no parent node!\nEnter another command.\n";
					continue;
				}

			}
			else if (choice == 'q') {

				quit = true;
				break;

			}
			else if (choice != 'l' && choice != 'r') {

				cout << "Please enter a valid selection (l, r, or q).\n";
				continue;

			}


		} while (true);

		if (quit)
			break;

	}
		// 4) Output next node's contents

		// 5) repeat steps 2, 3, and 4 until either the user quits or the user reaches a leaf node  

}

// ------------------------------------------------------


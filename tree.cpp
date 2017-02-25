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

	cout << "Data: " << nodePtr->getData() << endl;

	if (left != NULL)
		cout << "Left Node holds: " << left->getData() << endl;
	else
		cout << "No left node.\n";

	if (right != NULL)
		cout << "Right node holds: " << right->getData() << endl;
	else
		cout << "No right node.\n";

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
  
  // Make a new node and insert the data
  Node<T>* newNode = new Node<T>;
  newNode->setData(dat);
  
  // 2 scenarios:

  // 1) The Tree instance has no nodes
  if(startPtr == NULL)
    startPtr = newNode;

  // 2) The Tree instance has nodes already
  else {

    // Make tempPtr to keep track of where we are in the Tree
    Node<T> *tempPtr = startPtr;
    
    // Endlessly loop until a break occurs
    while(true){
      
      // If newNode->data > tempPtr->data
      if(nodeCompare(newNode, tempPtr) == 'g'){
	
	// Append newNode to tree if there's no node
	// attached to right ptr, which holds greater-than data
		if(tempPtr->getRightPtr() == NULL){

		  tempPtr->setRightPtr(newNode);
		  //numOfLeaves++; See below comment
		  break;

		}
		else
		  tempPtr = tempPtr->getRightPtr();	
	  
      }
	  // Else if newNode->data is less than tempPtr->data
      else if(nodeCompare(newNode, tempPtr) == 'l'){
	
		if(tempPtr->getLeftPtr() == NULL){
	  
		  tempPtr->setLeftPtr(newNode);
		  //numOfLeaves++; Need a seperate function to calculate leaves. This would just also count nodes
		  break;

		}
		else
		  tempPtr = tempPtr->getLeftPtr();

      }
	  // Else, datas must be equal
	  else {
		  cout << dat << " is already in the tree.\n";
		  break;
	  }

    }  
  }  
  
  numOfNodes++;

}

template <class T>
Node<T>* Tree<T>::search(const T data) {
	return NULL;
}

template <class T>
void Tree<T>::deleteNode(const T data) {

}

template <class T>
void Tree<T>::deleteNode(Node<T>* const* nodeAddress) {

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

			cout << "How would you like to traverse the tree? (l - left, r - right, q - quit): ";   // 2) Ask if the user would like to move left or right down the tree
			cin >> choice;

			choice = tolower(choice);

			if (choice == 'l') {	// 3) Move down tree

				if (movingPtr->getLeftPtr() != NULL) {

					movingPtr = movingPtr->getLeftPtr();
					break;

				}
				else {
					cout << "Please enter a valid selection (l, r, or q).\n";
					continue;
				}

			}
			else if (choice == 'r') {

				if (movingPtr->getRightPtr() != NULL) {

					movingPtr = movingPtr->getRightPtr();
					break;

				}
				else {
					cout << "Please enter a valid selection (l, r, or q).\n";
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

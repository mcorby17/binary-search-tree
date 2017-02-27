#include "node.h"
#include <cstddef>
#include <iostream>
using namespace std;

template <class T>
Node<T>::Node(){
  data = 0;
  left = NULL;
  right = NULL;
  up = NULL;
}

template <class T>
Node<T>::Node(T data){
  this->data = data;
  left = NULL;
  right = NULL;
  up = NULL;
}

template <class T>
void Node<T>::setData(const T data){
  this->data = data;
}

template <class T>
T Node<T>::getData(){
  return data;
}

template <class T>
void Node<T>::setLeftPtr(Node<T>* ptr){
  left = ptr;
}

template <class T>
Node<T>* Node<T>::getLeftPtr(){
  return left;
}

template <class T>
void Node<T>::setRightPtr(Node<T>* ptr){
  right = ptr;
}

template<class T>
Node<T>* Node<T>::getUpPtr()
{
	return up;
}

template<class T>
void Node<T>::setUpPtr(Node<T>* ptr)
{
	up = ptr;
}

template <class T>
Node<T>* Node<T>::getRightPtr(){
  return right;
}

template <class T>
void Node<T>::printInfo(){
  cout << "Data: " << data << endl;
  cout << "Left Ptr: " << left << endl;
  cout << "Right Ptr: " << right << endl;
  cout << "Previous Node: " << up << endl;
  cout << endl;
}

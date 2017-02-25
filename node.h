#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
  
  private:
    T         data;
    Node<T>*  left;
    Node<T>*  right;

  public:
    Node();	    //Default Constructor, sets all private properties to NULL
    Node(T);	//Overloaded constructor, allows a node to be created with a specified data
    
    T getData();
    void setData(const T);

    Node<T> *getLeftPtr();
    void setLeftPtr(Node<T>*);	

    Node<T> *getRightPtr();
    void setRightPtr(Node<T>*);

    void printInfo();
};

#endif 

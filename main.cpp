#include <iostream>
#include "node.cpp"
#include "tree.cpp"
using namespace std;

int main(){

	Tree<int> t1;

	t1.addNode(3);
	t1.addNode(5);
	t1.addNode(1);
	t1.addNode(2);
	t1.addNode(8);
	t1.addNode(4);
	
	t1.returnAscOrDesc('d');

  return 0;
}

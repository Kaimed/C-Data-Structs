#include "intNode.h"
#include <iostream>


using namespace std;


void buildTreeR(node& r);
void buildTreeL(node& r);
int curDepth = 0;
int const MAXDEPTH = 5;
int main() {
	node root(0);
	buildTreeR(root);
	buildTreeL(root);
	cout << "Break works as expected...\n";
	node* ptr = &root;
	while (ptr) {
		cout << *ptr;
		ptr = ptr->left;
	}
	ptr = &root;
	while (ptr) {
		cout << *ptr;
		ptr = ptr->left;
	}
}




void buildTreeR(node& r) {
	if (curDepth >= MAXDEPTH) {
		curDepth = 0;
		return;
	}
	if (r.left == nullptr) {
		r.newNode(curDepth + 1, 'l');
		//return buildTree(*r.left);
	}
	if (r.right == nullptr) {
		r.newNode(curDepth + 1, 'r');
		//return buildTree(*r.right);
	}
	curDepth += 1;
	if (r.right->right == nullptr) { return buildTreeR(*r.right); }
	//curDepth += 1;
	//if (r.left->left == nullptr) { return buildTree(*r.left); }


}



void buildTreeL(node& r) {
	if (curDepth >= MAXDEPTH) {
		curDepth = 0;
		return;
	}
	if (r.left == nullptr) {
		r.newNode(curDepth+1, 'l');
		//return buildTree(*r.left);
	}
	if (r.right == nullptr) {
		r.newNode(curDepth+1, 'r');
		//return buildTree(*r.right);
	}
	curDepth += 1;
	if (r.left->left == nullptr) { return buildTreeL(*r.left); }
	//curDepth += 1;
	//if (r.right->right == nullptr) { return buildTreeL(*r.right); }

}
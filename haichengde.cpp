#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
struct Node {
	char data;
	struct Node *lc, *rc;
}tree;
Node *creat(){
	char ch;
	Node *tree;
	cin >> ch;
	if(ch == '#') tree = NULL;
	else{
		tree = (struct Node*)malloc(sizeof(struct Node));
		tree->data = ch;
		tree->lc = creat();
		tree->rc = creat();
	}
	return tree;
} 

void cxbl(Node *tree){
	queue<Node*> q;
	q.push(tree);
	Node *p;
	while(!q.empty()){
		cout << q.front()->data ;
	    p = q.front();
	    q.pop();
	    if(p->lc != NULL) q.push(p->lc);
		if(p->rc != NULL) q.push(p->rc); 
	}
}
int main()
{
    Node *tree;
	tree = creat();
	cxbl(tree);
	return 0;
}

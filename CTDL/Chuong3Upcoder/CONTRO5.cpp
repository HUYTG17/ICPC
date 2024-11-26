#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* pNext;
};
struct List{
	Node* first;
	Node* last;
};
void init(List& l){
	l.first = l.last = NULL;
}
Node* getNode(int x){
	Node* p = new Node;
	p->data = x;
	p->pNext = NULL;
	return p;
}
void addFirst(List& l, int x){
	Node* new_ele = getNode(x);
	if (l.first == NULL){
		l.first = l.last = new_ele;
	}
	else{
		new_ele->pNext = l.first;
		l.first = new_ele;
	}
}
void printList(List l){
	Node* p = l.first;
	while (p != NULL){
		cout << p->data << " ";
		p = p->pNext;
	}
}
bool kt(List&l){
    for(Node*i=l.first;i!=NULL;i=i->pNext){
        for(Node*j=l.first;j!=NULL;j=j->pNext){
            for(Node*k=l.first;k!=NULL;k=k->pNext){
                int a,b,c;
                a=i->data;
                b=j->data;
                c=k->data;
                if(a!=b && a!=c && b!=c){
                    if(a==b+c) return true;
                }
            }
        }    
    }
    return false;
}
int main(){
	List l;
	init(l);
	int x,n,k;
	cin >>n;
	for(int i =0;i<n;i++){
	    cin>> x;
	    addFirst(l,x);
	}
    if(kt(l)==true)
    cout << "YES";
    else cout << "NO";
	return 0;
    
}
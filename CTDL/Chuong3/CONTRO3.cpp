#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

typedef struct Node* node;

node makeNode(int x) {
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

bool empty(node a) {
	return a == NULL;
}

int Size(node a) {
	int cnt = 0;
	while (a != NULL) {
		++cnt;
		a = a->next;
	}
	return cnt;
}

void insertFirst(node& a, int x) {
	node tmp = makeNode(x);
	if (a == NULL) {
		a = tmp;
	}
	else {
		tmp->next = a;
		a = tmp;
	}
} 

void insertLast(node& a, int x) {
	node tmp = makeNode(x);
	if (a == NULL) {
		a = tmp;
	}
	else {
		node p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = tmp;
	}
}

void insertMiddle(node& a, int x, int pos) {
	int n = Size(a);
	node p = a;
	for (int i = 1; i < pos - 1; i++) {
		p = p->next;
	}
	node tmp = makeNode(x);
	tmp->next = p->next;
	p->next = tmp;
}

void deleteFirst(node &a) {
	if (a == NULL) return;
	a = a->next;
}

void deleteLast(node& a) {
	if (a == NULL) return;
	node truoc = NULL, sau = a;
	while (sau->next != NULL) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL) {
		a = NULL;
	}
	else {
		truoc->next = NULL;
	}
}

void deleteMiddle(node &a, int pos) {
	if (pos <= 0 || pos > Size(a)) return;
	node truoc = NULL, sau = a;
	for (int i = 1; i < pos; i++) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL) {
		a = a->next;
	}
	else {
		truoc->next = sau->next;
	}
}

void in(node a) {
	while (a != NULL) {
		cout << a->data << " ";
		a = a->next;
   }
}

int main()
{
	node head = NULL;
	int n, a, k;
	cin >> n >> a >> k;
	for (int i = 1; i <= n; i++) {
		int tmp; cin >> tmp;
		insertLast(head, tmp);
	}
    
    if (k == 1) insertFirst(head, a);
    else if(k == (Size(head) + 1)) insertLast(head,a);
    else insertMiddle(head, a, k);
	
	cout << Size(head) << endl;
	in(head);

	return 0;
}
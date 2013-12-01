// RingOneLinked.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Node{
	int ITEM;
	Node *NEXT;
};

int emptyIdentificator,emptySignal;
int retrivingValue;
int countNumberOfElements;

Node* addN(Node *t, int it){ //добавлении(включение) элемента в голову списка 
	if(t==0){
		Node *temp = t;
		t = new Node;
		t->ITEM = it;
		t->NEXT = temp;
		return t;
	}
	else{
		Node *temp = t;
		t = new Node;
		t->ITEM = it;
		t->NEXT = temp;
		temp->NEXT=t;
		return t;
	}
}

Node* delN(Node *t){ //удаление(исключение) элемента из головы списка 
	if (t){
		Node *temp = t;
		t = temp->NEXT;
		delete(temp);
	}
	return t;
}

void prN(Node *t){ // вывод содержания кольцевого списка 
	Node *temp = t;
	while (temp){
		if(temp->NEXT != t){
			cout << temp->ITEM << " ";
			temp = temp->NEXT;
		}
	}
}

Node* finPN(Node *t, int p){ //поиск указателя узла по позиции 
	Node *temp = t;
	p--;
	while (temp && p > 0){
		temp = temp->NEXT;
		p--;
	}
	return temp;
}

Node* insert(Node *t, int k, int p){ //вставка узла в указанную позицию связанного списка 
	Node *temp = finPN(t,p-1);
	if (!temp){
		t = addN(t,k);
		return t;
	}
	Node *temp1 = new Node;
	temp1->ITEM = k;
	temp1->NEXT = temp->NEXT;
	temp->NEXT  = temp1;
	return t;
}

Node* addToEnd(Node *t, int k){
	Node *temp = t;
	while(temp->NEXT!=NULL){
		temp = temp->NEXT;
	}
	Node* newOne = new Node;
	newOne->ITEM = k;
	newOne->NEXT = NULL;
	temp->NEXT = newOne;
	newOne->NEXT = t;
	return t;
}

int numberOfElements(Node *t){
	Node *temp = t;
	while(temp->NEXT!=NULL){
		temp = temp->NEXT;
		countNumberOfElements++;
	}
	return countNumberOfElements;
}

Node* remove(Node *t, int p){
	Node *temp = finPN(t,p);
	if (!temp){
		t = delN(t);
		return t;
	}
	else{
		Node *temp1 = finPN(t, p-1);
		temp1->NEXT=temp->NEXT;
		return t;
	}
}

Node* removeAll(Node *t){
	while(t){
		t = delN(t);
	}
	return t;
}

int isEmpty(Node *t){
	if(t=NULL){
		emptyIdentificator = 0;
	}
	else{
		emptyIdentificator = 1;
	}
	return emptyIdentificator;
}

void retrieve(Node *t, int p){
	Node *temp = finPN(t,p);
}



int _tmain(int argc, _TCHAR* argv[])
{
	
	Node* head = NULL;
	

	head=addN(head, 5);
	head=addN(head, 10);
	head=addN(head, 15);
	prN(head);
	
	return 0;
}
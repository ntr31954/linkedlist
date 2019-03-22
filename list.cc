#include "list.h"
#include <iostream>

using namespace std;

ListPtr listCreate(){
	ListPtr AuxPtr = nullptr;
	AuxPtr = new List;
	listInit(AuxPtr);
	return AuxPtr;
}

static std::string listToString (ListPtr l, char c) {
  std::string s;

  for (ListNodePtr n = l->head; n != nullptr; n = n->next)
    s += c + listNodeToString (n);

  return s;
}
ListNodePtr listNodeCreate(Element e){
	ListNodePtr AuxPtr = nullptr;
	AuxPtr = new ListNode;
	AuxPtr->key = e;
	return AuxPtr;
}

void listInit(ListPtr l){
	l->head = nullptr;
}

bool listInsert(ListPtr l, Element x, Position i){

	Position counter = 1;
	if(i<1)
		return false;

	ListNodePtr AuxPtr2 = l->head, AuxPtr = nullptr;

	if(counter == i){
		AuxPtr = listNodeCreate(x);
		AuxPtr->next = l->head;
		l->head = AuxPtr;
		return true;
	}
	while(AuxPtr2 != nullptr){
		counter++;
		if(counter==i){
			AuxPtr = listNodeCreate(x);
			AuxPtr->next = AuxPtr2->next;
			AuxPtr2->next = AuxPtr;
			return true;
		}
		if(AuxPtr2->next == nullptr && counter == i-1){
			AuxPtr = listNodeCreate(x);
			AuxPtr = AuxPtr2->next;
			return true;
		}
		AuxPtr2 = AuxPtr2->next;
	}
	return false;
}

Position listLocate(ListPtr l, Element x){
	ListNodePtr AuxPtr2 = l->head;
	Position counter = 1;
	while(AuxPtr2 != nullptr){
		if(AuxPtr2->key == x)
			return counter;
		else{
			AuxPtr2 = AuxPtr2->next;
			counter++;
		}
	}
	return NOPOS;
}

ListNodePtr listRetrieve(ListPtr l, Position i){
	ListNodePtr AuxPtr2 = l->head;
	Position counter = 1;
	while(AuxPtr2 != nullptr){
		if(counter == i){
			cout<<AuxPtr2->key<<endl;
			return AuxPtr2;
		}else{
			AuxPtr2 = AuxPtr2->next;
			counter++;
		}
	}
	return nullptr;
}

bool listRemove(ListPtr l, Position p){

	if(p < 1)
		return false;

	ListNodePtr AuxPtr21 = l->head;
	Position counter = 1;

	if(counter == p){
		l->head = l->head->next;
		return true;
	}
	while(AuxPtr21->next != nullptr){
		if(counter==p){
			AuxPtr21->next = AuxPtr21->next->next;
			delete AuxPtr21;
			return true;
		}
		if(counter > 1)
			AuxPtr21 = AuxPtr21->next;

		counter++;
	}
	return false;
}

ulong listSize(ListPtr l){
	ListNodePtr AuxPtr2 = l->head;
	Position counter = 1;
	if(AuxPtr2==nullptr)
		return counter = 0;
	while(AuxPtr2->next != nullptr){
		AuxPtr2 = AuxPtr2->next;
		counter++;
	}
	return counter;
}

ListNodePtr listFirst(ListPtr l){
	ListNodePtr AuxPtr2 = l->head;
	return AuxPtr2;
}

void listMakeNull(ListPtr l){
	ulong max = listSize(l);
	for(Position i = max; i >= 1; i--){
		listRemove(l,i);
	}
	listInit(l);
}

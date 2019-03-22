#include "list.h"
#include <iostream>

using namespace std;

int main(){ 

	ListPtr l = listCreate();

	bool q=false, w=false, t=false;

	for (char c='g'; c >= 'a'; c--)
		listInsert (l, c, 1);
	cout<<endl;


	q=listInsert (l, 'z', 1);
	if(q){
		cout<<"-------------------------------"<<endl;
		cout<<"New node in head correct"<<endl;
		cout<<"-------------------------------"<<endl;
	}
	w=listInsert (l, 't', 3);
	if(w){
		cout<<"New node in middle correct"<<endl;
		cout<<"-------------------------------"<<endl;
	}
	t=listInsert (l, 'w', 10);
	if(t)
		cout<<"New node in end correct"<<endl;
	auto s = listToString (l,':');
	auto p = listLocate (l, 'd');
	cout<<"-------------------------------"<<endl;
	cout<<s<<"\tNode 'd' in position: "<<p<<" "<<endl;
	cout<<"-------------------------------"<<endl;
	listRemove(l,1);
	cout<<"-------------------------------"<<endl;
	s = listToString (l,':');
	cout<<s<<endl;
	cout<<"-------------------------------"<<endl;
	s = listToString (l,':');
	cout<<"-------------------------------"<<endl;
	cout<<"After makeNull: "<<s<<endl;

	uint NodeNumber = listSize(l);
	cout<<"-------------------------------"<<endl;
	cout<<"Node number: "<<NodeNumber<<endl;
	cout<<"-------------------------------"<<endl;
	listMakeNull(l);
	listInsert (l, '1', 1);
	s = listToString (l,':');
	cout<<s<<endl;
	NodeNumber = listSize(l);
	cout<<"-------------------------------"<<endl;
	cout<<"Node Number: "<<NodeNumber<<endl;
	cout<<"-------------------------------"<<endl;

	listMakeNull(l);
	delete l;

  return 0;
}

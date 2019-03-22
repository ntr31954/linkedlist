#ifndef LIST
#define LIST

#include <string>


typedef char Element;
typedef int Position;
const Position NOPOS = -1;

struct ListNode;
typedef ListNode* ListNodePtr;


struct ListNode {
  Element key;
  ListNodePtr next;
};

ListNodePtr listNodeCreate (Element e);
static std::string listNodeToString (ListNodePtr p) {
  std::string s;
  return s + p->key;
}

struct List;
typedef List* ListPtr;

struct List {
  ListNodePtr head;
};


ListPtr listCreate            ();

void listInit                 (ListPtr l);

bool listInsert               (ListPtr l, Element x, Position i);

Position listLocate           (ListPtr l, Element x);

ListNodePtr listRetrieve          (ListPtr l, Position i);

bool listRemove               (ListPtr l, Position p);

void listMakeNull             (ListPtr l);

ListNodePtr listFirst             (ListPtr l);

static std::string listToString (ListPtr l, char c) {
  std::string s;

  for (ListNodePtr n = l->head; n != nullptr; n = n->next)
    s += c + listNodeToString (n);

  return s;
}

ulong listSize                (ListPtr l);


#endif

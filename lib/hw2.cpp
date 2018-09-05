
#include <stdio.h>

class Item {
	
	public:
	const char * str;
	Item(const char *as = "") 
	{ 
		str = as; 
	}
};

class List {
	private:
		// add head and tail pointer
		ListNode *head;
		ListNode *tail;
	public:
		List();
		void append(Item a);    
		bool remove(Item &a);    
		bool empty(); 
};

class ListNode {
	private:
		Item item; // data in the list
		ListNode *next;	
	public:
		ListNode(Item a) 
		{ item = a; next=NULL; }
		ListNode* getNext() { return next; }
		void setNext(ListNode *n) { next = n; }
		Item getItem() { return item; }
		void push_back(Item a) 
		{
			ListNode *node = new ListNode(a);
			if (head==NULL) { 
				// list is empty, so set head and 
				// tail to be node
				head = node;
				tail = node;
			} 
			else {
				// put new node at end of list
				tail->setNext(node);
				tail = node;
			}
		}


		Item get(int n)
		{
			int i;
			Item ans;
			for (i=0; i < n; i++) {
				node = node->getNext();
				if (node == NULL) {
					return NULL;
				}
			}
			ans = node->getItem();
			return ans;
		}

		int length()
		{
			if (head==NULL) {
				return 0;
			}
			int i = 1;
			while (next != NULL) {
				i = i + 1;
				next = node->next;
			}
			return i;
		}

		Item remove_front() 
		{
			if (!empty()) // if list is not empty
			{
			copy = head->getItem(); // return copy
			ListNode *tmp = head->getNext();
			delete head; // delete the node
			head = tmp;  // update the head
			if (tmp==NULL) // removed last element 
				tail = NULL;
			return true;
			}
			return copy; // nothing in list
		}

		//a destructor
		~List()
		{
			// Free all of the ListNodes in the list
			Item t;
			while(!empty()){ // while not empty
				remove(t);	// remove the next node
			}	 
		}

		//a constructor
		List() 
		{
			// there’s nothing in the list
			head = NULL;
			tail = NULL;
		}
};


void List::append(Item a)
{
  ListNode *node = new ListNode(a);
  if (head == NULL)
    {
      // list is empty
      head = node;
      tail = node;
    }
  else 
    {
      tail->setNext(node);
      tail = node;
    }
}

bool List::remove(Item &copy) 
{
  if (!empty()) // if list is not empty
    {
      copy = head->getItem(); // return copy
      ListNode *tmp = head->getNext();
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==NULL) // removed last element 
	tail = NULL;
      return true;
    }
  return false; // nothing in list
}

bool List::empty()
{
  return head==NULL;
}



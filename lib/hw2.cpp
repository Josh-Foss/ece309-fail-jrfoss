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
	public:

// ListNode represents each 
// node of the list
	class ListNode {
		
		private:
		Item item; // data in the list
		ListNode *next;	
		
		public:
		ListNode(Item a) 
		{ 
			item = a; 
			next=NULL; // automatically serves as a list tail
		}
		
		ListNode* getNext() //returns the pointer for the next node.
		{ 
			return next; 
		}
		
		void setNext(ListNode *n) //sets pointer to next node. Helpful when inserting or deleteing items.
		{ 
			next = n; 
		}
		
		Item getItem() //retrieves the item in a certain node
		{ 
			return item; 
		}
	};
	
	// add head and tail pointer
	ListNode *head;
	ListNode *tail;
	
	void push_back(char *a) 
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

	
	List () {
		head = NULL;
		tail = NULL;
	};
	//a destructor
	~List();
	

	
	

  
	public:
	List();
	void append(Item a);    
	bool remove(Item &a);    
	bool empty(); 
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


int main()
{
	List a;

	a.append(Item("Fraser"));
	a.append(Item("Lucas"));
	a.append(Item("Silva"));
	a.append(Item("Mkhi"));
	a.append(Item("Townsend"));
	a.push_back(Item("Sessegnon"));

	while(!a.empty())
    {
		Item copy;
		a.remove(copy);

		printf("Next thing removed: %s\n",copy.str);
    }

	return 0;
}

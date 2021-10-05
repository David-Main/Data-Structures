#include <iostream>
#include <iomanip>

using namespace std;


class list {

	private:
		struct node {
			int data;
			node* next = nullptr;
		};


	public:	//variables
		node* head = nullptr;
		size_t listCount = 0;


	public: //functions
		list()
		{
			listCount = 0;
		}

		list(int value)
		{
			this->head = new(node);
			this->head->data = value;
			listCount++;
		}

		void add(int value)
		{
			auto temp = head;				// get head of list
			if(nullptr == temp)
			{
				temp = new node{value};
				return;
			}
			while(temp->next != nullptr)	// go to last node of list
			{
				temp = temp->next;
			}
			temp->next = new node;			// append new node to last node
			temp = temp->next;				// move to new node
			
			temp->data = value;				// add value.
			listCount++;
		}

		void print()
		{
			node* temp = head;
			while(temp != nullptr)
			{	
				cout << setw(3) << setfill(' ') << temp->data;
				temp = temp->next;
			}
			cout << endl;
		}

		bool insert(int value, size_t position)
		{
			if(position > listCount) 
				return false;						//position not in range

			node* currentNode = head;
			node* prev;
			size_t currentPosition = 1;

			while(currentPosition != position)		//go to node in question
			{
				prev = currentNode;
				currentNode = currentNode->next;
				currentPosition++;
			}
			
			if(currentNode == head)
			{
				//create new node with given value,
				//set newNode.next = head
			    //set head to newNode;
				head = new node{value, head};
			}
			else
			{
				// Create new node with given value as data and currentNode as next;
				// Set prev->next to new Node;
				prev->next = new node{value, currentNode};

			}
			listCount++;
			return true; 							//insert complete
		}

		size_t search(int value)
		{
			node* currentNode = head;
			size_t currentPosition = 1;

			while(currentNode->data != value && currentNode != nullptr)		//go to node in question
			{
				if(currentNode->next == nullptr)
				{
					currentPosition = 0;
					return currentPosition;
				}
				currentNode = currentNode->next;
				currentPosition++;
			}
			return currentPosition;
		}
};

int main()
{
	list items(2);
	items.add(4);
	items.add(5);

	items.insert(8, 2);
	items.insert(19, 1);

	items.print();
	cout << "List Count: " << items.listCount << endl;
	cout << "Found at position: " << items.search(23) << endl;

	list materials;
	cout << materials.listCount;
	// // // materials.add(2);
	
	return 0;
}
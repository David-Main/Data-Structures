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


	public: //functions
		list()
		{
			this->head = nullptr;	//empty list;			
		}

		list(int value)
		{
			this->head = new(node);
			this->head->data = value;
		}

		void add(int value)
		{
			auto temp = head;

			while(temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new node;
			temp = temp->next;
			
			temp->data = value;
			cout << temp->data << endl;
			cout << "from temp" << endl;
		}

		void print()
		{
			node* temp = head;
			while(temp != nullptr)
			{	
				cout << setw(3) << setfill(' ') << temp->data;
				temp = temp->next;
			}
		}

};

int main()
{
	list items(2);
	items.add(4);
	items.add(5);

	items.print();
	
	return 0;
}
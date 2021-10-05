list();

	// list(int value){
	// 	list temp;
	// 	temp.data = value;
	// 	temp.next = nullptr;
	// 	listCount++;
	// }

	// list * searchList (int value)
	// {
	// 	list *temp = this;
	// 	while(temp->data != value)
	// 	{
	// 		if(temp == nullptr) return nullptr;		//return nullptr if item is not found.
	// 		temp = temp->next;
	// 	}
	// 	return temp;
	// }

	// void add(int value)
	// {
	// 	list *temp = this->next;
	// 	while(temp->next != nullptr)
	// 	{
	// 		temp = temp->next;
	// 	}
	// 	temp->next = new(list);
	// 	temp->data = value;
	// 	listCount += 1;
	// }

	// bool empty(){
	// 	return (0 == listCount ? true : false);		//return true if empty or false otherwise.
	// }

	// int getCount(){
	// 	return listCount;
	// }
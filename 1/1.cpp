#include <iostream>

//indexes start from 1, 0 is a root

struct person
{
	std::string name = "root";
	int age = 0;
	std::string gender;

	person* next = NULL;
	person* previous = NULL;
};

person* findIndex(person* root, int index);//finds object's pointer
void showIndex(person* root);///shows info about object
void showAll(person* root);//shows info about all objects
person* createNew(person* root);//creates a new object, returns its pointer
void addNew(person* root);//"adds" new object at the end of a "list"
void insertNew(person* insertHere);//pushes back object and inserts a new one

int main()
{
	///creates root
	person* root;
	root = new person;
	///

	while (true)
	{
		system("cls");
		std::cout << "1-ADD NEW\n2-INSERT NEW\n3-SHOW INDEX\n4-SHOW ALL\n";
		int choice;
		std::cin >> choice;

		int tempIndex = 0;

		switch (choice)
		{
		case 1:
			system("cls");
			addNew(root);
			break;
		case 2:
			system("cls");
			std::cout << "Index: ";
			std::cin >> tempIndex;
			insertNew(findIndex(root, tempIndex));
			break;
		case 3:
			system("cls");
			std::cout << "Index: ";
			std::cin >> tempIndex;
			showIndex(findIndex(root, tempIndex));
			system("pause");
			break;
		case 4:
			system("cls");
			showAll(root);
			system("pause");
			break;
		}
	}
}

void showIndex(person* root)
{
	if (root == NULL)
	{
		return;
	}

	std::cout << "///Debug previous name: " << root->previous->name << "\n";

	std::cout << "Name: " << root->name << "\n";
	std::cout << "Age: " << root->age << "\n";
	std::cout << "Gender: " << root->gender << "\n";

	if (root->next != NULL)
	{
		std::cout << "///Debug next name: " << root->next->name << "\n\n\n";
	}
}

void showAll(person* root)
{
	if (root->next != NULL)
	{
		showIndex(root->next);

		showAll(root->next);
	}
}

person* createNew(person* root)
{
	person* temp;
	temp = new person;

	std::cout << "Name:";
	std::cin >> temp->name;
	std::cout << "Age:";
	std::cin >> temp->age;
	std::cout << "Gender:";
	std::cin >> temp->gender;

	return temp;
}

void addNew(person* root)
{
	if (root->next == NULL)
	{
		person* temp = createNew(root);

		temp->previous = root;

		root->next = temp;
	}
	else
	{
		addNew(root->next);
	}
}

void insertNew(person* insertHere)
{
	person* temp = createNew(insertHere);

	temp->next = insertHere;
	temp->previous = insertHere->previous;

	insertHere->previous->next = temp;
	insertHere->previous = temp;
}

person* findIndex(person* root, int index)
{
	if (index == 0)
	{
		return root;
	}
	else
	{
		if (root->next != NULL)
		{
			index--;
			return findIndex(root->next, index);
		}
		else
		{
			std::cout << "Index is empty.\n";
			return NULL;
		}
	}
}
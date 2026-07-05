#include <iostream>
#include <windows.h>
using namespace std;

struct Tree {
	int data;
	Tree* left;
	Tree* right;
};

Tree* create(int value)            //создание узла
{
	Tree* newptr = new Tree();
	newptr->data = value;
	newptr->left = newptr->right = NULL;
	return newptr;
}

Tree* add(Tree* root, int value)     //добавление элемента в дерево
{
	if (root == NULL)
		return create(value);

	if (value < root->data) {
		root->left = add(root->left, value);
	}
	else if (value > root->data) {
		root->right = add(root->right, value);
	}

	return root;
}

Tree* minvalue(Tree* node)     //минимальное значение 
{
	while (node->left != NULL) {
		node = node->left;
	}
	return node;
}


Tree* del(Tree* root, int value)     //удаление элемента дерева
{
	if (root == NULL)
		return NULL;

	if (value < root->data) {
		root->left = del(root->left, value);
	}
	else if (value > root->data) {
		root->right = del(root->right, value);
	}
	else {
		if (root->left == NULL) {
			Tree* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			Tree* temp = root->left;
			delete root;
			return temp;
		}
		Tree* temp = minvalue(root->right);
		root->data = temp->data;
		root->right = del(root->right, temp->data);
	}
	return root;
}

bool search(Tree* root, int value)     //поиск значения в дереве
{
	if (root == NULL) {
		return false;
	}
	if (value == root->data) {
		return true;
	}
	else if (value < root->data) {
		return search(root->left, value);
	}
	else if (value > root->data) {
		return search(root->right, value);
	}
}

void print(Tree* root)       //вывод дерева левый-вершина-правый  
{
	if (root != NULL) {
		print(root->left);
		cout << root->data << " ";
		print(root->right);
	}
}

int leaves(Tree* root) {    //количество листьев
	if (root == NULL) {
		return 0;  
	}

	if (root->left == NULL && root->right == NULL) {
		return 1;  
	}

	return leaves(root->left) + leaves(root->right);
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);

	Tree* root = NULL;     //создание дерева

	int choice, value;
	do
	{
		cout << "1. Добавление элемента" << endl;
		cout << "2. Удаление элемента" << endl;
		cout << "3. Поиск элемента" << endl;
		cout << "4. Вывод дерева" << endl;
		cout << "5. Подсчет листьев в дереве" << endl;
		cout << "6. Выход" << endl;
		cout << "Выберите вариант: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Введите значение для добавления: ";
			cin >> value;
			if (root == NULL)
				root = create(value);
			else
				root = add(root, value);
			break;
		case 2:
			cout << "Введите значение для удаления: ";
			cin >> value;
			root = del(root, value);
			break;
		case 3:
			cout << "Какое значение искать: ";
			cin >> value;
			if (search(root, value))
				cout << "Найдено " << value << endl;
			else
				cout << "Не найдено" << endl;
			break;
		case 4:
			print(root);
			cout << endl;
			break;
		case 5:
		{
			int l = leaves(root);
			cout << "Количество листьев в дереве: " << l << endl;
			break;
		}
		case 6:
			break;
		}

	} while (choice != 6);

	return 0;
}
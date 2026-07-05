#include "Heap.h"

Heap* create(int value)     //создание кучи
{
	Heap* ptr = new Heap;
	ptr->data = value;
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->parent = NULL;
	return ptr;
}

Heap* findplace(Heap* root)     //поиск места
{       
	if (root == NULL) 
		return NULL;
	if (root->left == NULL) 
		return root;
	if (root->right == NULL) 
		return root;

	Heap* leftres = findplace(root->left);
	if (leftres != NULL) 
		return leftres;

	return findplace(root->right);
}
void situp(Heap* ptr)                //просеивание вверх 
{
	if (ptr->parent == NULL)
		return;

	if (ptr->data > ptr->parent->data) {
		int temp = ptr->data;
		ptr->data = ptr->parent->data;
		ptr->parent->data = temp;
		situp(ptr->parent);
	}
}

void sitdown(Heap* ptr)                 //просеивание вниз нужно при удалении максимального элемента
{
	if (ptr->left == NULL && ptr->right == NULL)
		return;

	if (ptr->left != NULL && ptr->left->data > ptr->data) {
		int temp = ptr->data;
		ptr->data = ptr->left->data;
		ptr->left->data = temp;
		sitdown(ptr->left);
	}
	else if (ptr->right != NULL && ptr->right->data > ptr->data) {
		int temp = ptr->data;
		ptr->data = ptr->right->data;
		ptr->right->data = temp;
		sitdown(ptr->right);
	}
}

Heap* findlast(Heap* root)    //нахождение последнего
{
	if (root == NULL) 
		return NULL;

	while (root->right != NULL) {
		root = root->right;
	}
	return root;
}


void add(Heap*& root, int value)    //добавление в кучу
{
	Heap* ptr = create(value);

	if (root == NULL) {
		root = ptr;
		return;
	}

	Heap* parent = findplace(root);
	ptr->parent = parent;

	if (parent->left == NULL) {
		parent->left = ptr;
	}
	else {
		parent->right = ptr;
	}

	situp(ptr);
}

int del(Heap*& root)    //удаление
{
	if (root == NULL) {
		cout << "Пустая куча" << endl;
		return 1;
	}

	int result = root->data;

	if (root->left == NULL && root->right == NULL) {
		delete root;
		root = NULL;
		return result;
	}

	Heap* last = findlast(root);
	root->data = last->data;

	if (last->parent != NULL) {
		if (last->parent->left == last) {
			last->parent->left = NULL;
		}
		else {
			last->parent->right = NULL;
		}
	}
	delete last;

	sitdown(root); 

	return result;
}

void print(Heap* root)    //вывод
{
	if (root == NULL) 
		return;
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}

bool find(Heap* root, int value)    //поиск
{
	if (root == NULL) 
		return false;
	if (root->data == value) 
		return true;

	return find(root->left, value) || find(root->right, value);
}

Heap* findmin(Heap* root)    //нахождение минимального для функции удаления минималного
{
	if (root == NULL) 
		return NULL;

	Heap* min = root;

	Heap* lmin = findmin(root->left);
	if (lmin != NULL && lmin->data < min->data) {
		min = lmin;
	}

	Heap* rmin = findmin(root->right);
	if (rmin != NULL && rmin->data < min->data) {
		min = rmin;
	}

	return min;
}

int deletemin(Heap*& root)     //удаление минимального
{
	if (root == NULL) {
		cout << "Пустая куча" << endl;
		return 1;
	}

	Heap* min = findmin(root);
	int minval = min->data;

	if (root->left == NULL && root->right == NULL) {
		delete root;
		root = NULL;
		return minval;
	}

	Heap* last = findlast(root);

	min->data = last->data;

	if (last->parent != NULL) {
		if (last->parent->left == last) {
			last->parent->left = NULL;
		}
		else {
			last->parent->right = NULL;
		}
	}
	delete last;

	sitdown(min);

	return minval;
}

Heap* findindex(Heap* root, int& index, int current)    //нахождение по индексу
{
	if (root == NULL) 
		return NULL;

	if (index == current) 
		return root;
	index++;

	Heap* leftres = findindex(root->left, index, current);
	if (leftres != NULL) 
		return leftres;

	return findindex(root->right, index, current);
}

void deleteindex(Heap*& root, int i)    // Удаление i-го элемента
{
	if (root == NULL) {
		cout << "Пустая куча" << endl;
		return;
	}

	int current = 1;
	Heap* res = findindex(root, current, i);

	if (res == NULL) 
		return;

	Heap* last = root;
	Heap* lastpar = NULL;
	while (last->right != NULL) {
		lastpar = last;
		last = last->right;
	}

	res->data = last->data;

	if (lastpar != NULL) {
		if (lastpar->left == last) {
			lastpar->left = NULL;
		}
		else {
			lastpar->right = NULL;
		}
	}
	delete last;

	sitdown(res);
	situp(res);
}

void copy(Heap*& to, Heap* from)    //копирование
{
	if (from == NULL) 
		return;
	
	add(to, from->data);

	copy(to, from->left);
	copy(to, from->right);
}

void clear(Heap*& root)     //очистка
{
	if (root == NULL) 
		return;

	clear(root->left);
	clear(root->right);

	delete root;
	root = NULL;
}

void unionheap(Heap*& root, Heap*& heap2)    //объединение 2х куч в одну
{
	if (heap2 == NULL) 
		return;

	copy(root, heap2);
	clear(heap2);
}

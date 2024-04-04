#include <iostream>
#include "set.h"

using namespace std;

Tree* Set::_Insert(Tree* root, int key)
{
	if (root == nullptr)
		root = new Tree(key);
	else if (key < root->key)
	{
		root->left = _Insert(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = _Insert(root->right, key);
	}
	else if (key == root->key)
		throw "The element is already exist";
	return _Balance(root);
}

Tree* Set::_Erase_elem(Tree* root, int key)
{
	if (!root)
		return nullptr;
	if (key < root->key)
	{
		root->left = _Erase_elem(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = _Erase_elem(root->right, key);
	}
	else
	{
		Tree* temp_l = root->left;
		Tree* temp_r = root->right;
		delete root;
		if (!temp_r) return temp_l;
		if (!temp_l) return temp_r;
		Tree* min = _Find_min(temp_r);
		min->right = _Erase_min(temp_r);
		min->left = temp_l;
		return _Balance(min);
	}
	return _Balance(root);
}

void Set::_Delete_tree(Tree* root)
{
	if (root)
	{
		_Delete_tree(root->right);
		_Delete_tree(root->left);
		delete root;
	}
}

void Set::_Print(Tree* root, int step) const
{
	if (root)
	{
		_Print(root->right, step + 1);
		for (int i = 0; i < step; i++)
			cout << "--- ";
		cout << root->key << std::endl;
		_Print(root->left, step + 1);
	}
}

unsigned Set::_Height(Tree* root)
{
	if (root)
	{
		return root->height;
	}
	else
	{
		return 0;
	}
}

void Set::_Fix_height(Tree* root)
{
	unsigned  hl = _Height(root->left);
	unsigned hr = _Height(root->right);
	if (hl > hr)
	{
		root->height = hl + 1;	
	}
	else
	{
		root->height = hr + 1;
	}
	//root->height = (hl > hr ? hl : hr) + 1;
}

int Set::_Balance_factor(Tree* root)
{
	return _Height(root->right) - _Height(root->left);
}

Tree* Set::_Balance(Tree* root)
{
	_Fix_height(root);
	if (_Balance_factor(root) == -2)
	{
		if (_Balance_factor(root->left) > 0)
			root->left = _Rotate_left(root->left);
		return _Rotate_right(root);
	}
	if (_Balance_factor(root) == 2)
	{
		if (_Balance_factor(root->right) < 0)
			root->right = _Rotate_right(root->right);
		return _Rotate_left(root);
	}
	return root;
}


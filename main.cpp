#include <iostream> 
#include <chrono> 
#include <exception> 
#include "set.h" 

using namespace std;

struct steady_clock;

static void m_union(Set& result, Tree* tree)
{
	if (tree != nullptr) {
		m_union(result, tree->left);
		result.Insert(tree->key);
		m_union(result, tree->right);
	}
}

static void logic_or(Set& result, Set& set1, Set& set2) {
	m_union(result, set1.Getroot());
	m_union(result, set2.Getroot());
}

static void m_xor(Set& result, Set& set1, Set& set2, Tree* node)
{
	if (node != nullptr) {
		m_xor(result, set1, set2, node->left);
		if (!(set1.Find(node->key) && set2.Find(node->key)))
			result.Insert(node->key);
		m_xor(result, set1, set2, node->right);
	}
}

static void logic_xor(Set& result, Set& set1, Set& set2) {
	m_xor(result, set1, set2, set2.Getroot());
	m_xor(result, set1, set2, set1.Getroot());
}



int main()
{
	Set r;
	Set a;
	Set b;

	a.Insert(7);
	a.Insert(5);
	a.Insert(9);
	a.Insert(8);

	a.Print();
	a.Erase(9);
	a.Insert(1);
	a.Insert(6);
	a.Insert(11);
	a.Print();


	/*b.Insert(5);
	b.Insert(6);
	b.Insert(7);
	b.Insert(8);*/

	/*logic_xor(r, a, b);*/

	//try { 
	//  logic_or(r, a, b); 
	//} 
	//catch (const char* err) { 
	//  cout << err << endl; 
	//} 

	/*r.Print();
	Set r;  Set a;
	Set b;
	a.Insert(1);  a.Insert(2);
	b.Insert(3);  b.Insert(4);
	logic_or(r, a, b);
	r.Print();*/
	//r.Insert(1); 
	//r.Insert(6); 
	//r.Insert(7); 
	//r.Insert(5); 
	//r.Insert(-6); 
	////r.Insert(10); 
	////r.Insert(20); 
	////r.Insert(3); 
	//r.Print(); 
	//cout << endl << "==================" << endl; 
	//cout << r.Find(1000) << endl; 
	//cout << r.Find(6) << endl; 
	//cout << "==================" << endl; 
	//r.Erase(7); 
	//r.Erase(15); 
	//r.Print(); 

	//Set r; 
	//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); 
	//std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now(); 
	//for (int i = 0; i < 10; i++) 
	//{ 
	// /*begin = std::chrono::steady_clock::now();*/ 
	// for (int j = 1; j < 100000; j++) 
	// { 
	//  r.Insert(i * 100000 + j); 
	// } 
	// //end = std::chrono::steady_clock::now(); 
	// //std::cout << "Diff(ms) = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl; 
	//} 
	//end = std::chrono::steady_clock::now(); 
	//std::cout << "Diff(s) = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << std::endl; 
	////std::cout << "Diff(ns) = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << std::endl; 
	return 0;
}
//*****************************************************************************************************
//
//		File:					node.h
//
//		Student:				Cadence Seim
//
//		Assignment:				Assignmnt #8
//
//		Due:					11/10/2025		
//			
//*****************************************************************************************************
#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************
template <typename T>
struct Node
{
	public:
	T info;
	Node <T>* left; 
	Node <T>* right;
	double frequency;
	Node();
	Node(const T& in, double freq, Node<T>* l = nullptr, Node<T>* r = nullptr);
};

//*****************************************************************************************************
template <typename T>
Node<T>::Node()
{
	info = T();
	frequency = 0;
	left = nullptr; 
	right = nullptr; 
}

//*****************************************************************************************************
template <typename T>
Node<T>::Node(const T& in, double freq, Node<T>* l, Node<T>* r)
{
	info = in; 
	frequency = freq;
	left = l; 
	right = r; 
}

#endif
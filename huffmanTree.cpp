//*****************************************************************************************************
//
//		File:					huffmanTree.cpp
//
//		Student:				Cadence Seim
//
//		Assignment:				Assignmnt #8
//
//		Due:					11/10/2025	
//			
//*****************************************************************************************************

#include "stock.h"
#include "node.h"

#include <fstream>
#include <string>
#include <new>
#include <limits>

//*****************************************************************************************************
int readStocks(const std::string& fileName, Stock*& stocks, double*& freqs)
{
	int size;

	std::ifstream infile("HuffmanStocks.txt");
	
	if (!infile) 
	{
		std::cout << "could not open file";
	}

	infile >> size;
	infile.ignore();

	stocks = new Stock[size];
	freqs = new double[size];

	for (int i = 0; i < size; i++)
	{
		infile >> stocks[i];
		infile >> freqs[i];
		infile.ignore();
	}

	return size;
}

//*****************************************************************************************************
Node<Stock>* createHuffmanTree(Stock stocks[], double freqs[], int size)
{

	Node<Stock>** elements = new Node<Stock>*[size];

	for (int i = 0; i < size; ++i) 
	{
		elements[i] = new Node<Stock>;
		elements[i]->info = stocks[i];
		elements[i]->frequency = freqs[i];
		elements[i]->left = nullptr;
		elements[i]->right = nullptr;
	}

	int index1;
	int index2;
	double freq1;
	double freq2;

	while (size > 1) 
	{
		index1 = index2 = 0;
		freq1 = freq2 = std::numeric_limits<double>::max();

		for (int i = 0; i < size; ++i)
		{
			if (elements[i]->frequency < freq1) 
			{
				freq2 = freq1;
				index2 = index1;
				freq1 = elements[i]->frequency;
				index1 = i;
			}
			else if ((elements[i]->frequency < freq2) && (i != index1)) 
			{
				freq2 = elements[i]->frequency;
				index2 = i;
			}
		}

		Node<Stock>* newNode;
		newNode = new Node<Stock>;
		newNode->left = elements[index1];
		newNode->right = elements[index2];
		newNode->frequency = freq1 + freq2;

		elements[index1] = newNode;

		for (int i = index2; i < size - 1; ++i) 
		{
			elements[i] = elements[i + 1];
		}

		--size;
	}

	return elements[0];
}

//*****************************************************************************************************
void printArray(int path[], int pathLen, Node<Stock>* leaf)
{
	std::cout << leaf->info << " ";

	for (int i = 0; i < pathLen; i++) 
	{
		std::cout << path[i] << " ";
	}
	std::cout << std::endl;

}

//*****************************************************************************************************
void printPaths(Node<Stock>* node, int path[], int pathLen, int lr)
{
	if (node != nullptr) 
	{
		if (lr != -1) {
			path[pathLen] = lr;
			++pathLen;
		}
		if ((node->left == nullptr) && (node->right == nullptr)) 
		{
			printArray(path, pathLen, node);
		}
		else 
		{
			printPaths(node->left, path, pathLen, 0);
			printPaths(node->right, path, pathLen, 1);
		}
	}
}

//*****************************************************************************************************
void displayStockList(Node<Stock>* rootPtr, const std::string& sentence)
{
	if (rootPtr == nullptr)
	{
		std::cout << "Empty Huffman tree.\n";
		return;
	}

	std::cout << "Decoding stock list from sentence:\n";

	Node<Stock>* current = rootPtr;

	for (char c : sentence)
	{
		if (c == '0')
			current = current->left;
		else if (c == '1')
			current = current->right;
		else
		{
			std::cout << "\nError: sentence contains invalid character " << c << "\n";
		}

		if (current->left == nullptr && current->right == nullptr)
		{
			std::cout << current->info.getSymbol() << " ";
			current = rootPtr;
		}
	}

	std::cout << "\n";
}

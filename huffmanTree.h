//*****************************************************************************************************
//
//		File:					huffmanTree.h
//
//		Student:				Cadence Seim
//
//		Assignment:				Assignmnt #8
//
//		Due:					11/10/2025		
//			
//*****************************************************************************************************

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "node.h"
#include "stock.h"

//*****************************************************************************************************

int readStocks(const std::string& fileName, Stock*& stocks, double*& freqs);
Node<Stock>* createHuffmanTree(Stock stocks[], double freqs[],int size);
void printArray(int path[], int pathLen, Node<Stock>* leaf);
void printPaths(Node<Stock>* node, int path[], int pathLen, int lr);
void displayStockList(Node<Stock>* rootPtr, const std::string& sentence);

//*****************************************************************************************************

#endif
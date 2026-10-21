//*****************************************************************************************************
//
//		File:					Driver.cpp
//
//		Student:				Cadence Seim
//
//		Assignment:				Assignmnt #8
//
//		Due:					11/10/2025	
//			
//*****************************************************************************************************

#include "huffmanTree.h"
#include "stock.h"

#include <iostream>
using namespace std;

//*****************************************************************************************************
void collectCodes(Node<Stock>* node, string code, string symbols[], string codes[], int& count);
//*****************************************************************************************************

int main()
{
    Stock* stocks = nullptr;
    double* freqs = nullptr;

    int size = readStocks("HuffmanStocks.txt", stocks, freqs);

    Node<Stock>* root = createHuffmanTree(stocks, freqs, size);

    string symbols[50];
    string codes[50];
    int codeCount = 0;

    collectCodes(root, "", symbols, codes, codeCount);

    cout << "Huffman Codes:\n";
    for (int i = 0; i < codeCount; i++)
    {
        cout << symbols[i] << ": " << codes[i] << endl;
    }


    string sentence = "";
    string wanted[] = { "AAPL", "GS", "KO", "AAPL" };

    for (int w = 0; w < 4; w++)
    {
        for (int i = 0; i < codeCount; i++)
        {
            if (symbols[i] == wanted[w])
            {
                sentence += codes[i];
                break;
            }
        }
    }

    cout << "\nEncoded Sentence:\n" << sentence << endl << endl;

    displayStockList(root, sentence);

    return 0;
}

//*****************************************************************************************************
void collectCodes(Node<Stock>* node, string code, string symbols[], string codes[], int& count)
{
    if (node == nullptr)
        return;

    if (node->left == nullptr && node->right == nullptr)
    {
        symbols[count] = node->info.getSymbol();
        codes[count] = code;
        count++;
        return;
    }

    collectCodes(node->left, code + "0", symbols, codes, count);
    collectCodes(node->right, code + "1", symbols, codes, count);
}
#include <iostream>
#include <cstring>
#include <conio.h>
#include <fstream>
using namespace std;

struct Element
{
	string str;
	Element* next;

	Element(string val) :
		str(val), next(NULL)
	{}

	Element(Element* ptr) :
		str(ptr->str), next(NULL)
	{}
};

Element* findline(Element*, int);
Element* opentext(string);
Element* entertext();
void copyline(Element* first, int i, int j);
Element* cutline(Element* first, int i, int j);
void maxC(Element* first);
void writetext(Element* first);
#pragma once

#include "element.h"

Element* first, * it = NULL;


Element* findline(Element* top, int i)
{
	Element* it;
	int curr = 0;
	it = top;
	while (curr < i - 1)
	{
		if (it == NULL)
		{
			return NULL;
		}

		curr++;
		it = it->next;
	}

	return it;
}


Element* entertext()
{
	Element* ptr;
	string answer, str;
	cout << "input the first string:" << endl;
	cin >> str;
	ptr = new Element(str);

	first = ptr;
	it = ptr;

	cout << "Do you want continue? (’n’ if no)";
	cin >> answer;
	while (answer != "n")
	{
		cout << "input a string:" << endl;
		cin >> str;
		ptr = new Element(str);
		it->next = ptr;
		it = ptr;
		cout << "Do you want continue? (’n’ if no)";
		cin >> answer;
	}
	it = first;
	while (it != NULL)
	{
		cout << it->str << endl;
		it = it->next;
	}
	return first;
}



Element* opentext(string a)
{
	Element* first, * it = NULL, * ptr;
	string str;
	ifstream inf(a);
	if (!inf)
	{
		cout << "error!";
	}
	while (!inf.eof())
	{
		getline(inf, str);
		ptr = new Element(str);


		if (it == NULL)
		{
			first = ptr;
			it = ptr;
		}

		else
		{
			it->next = ptr;
			it = ptr;
		}

	}
	it = first;
	while (it != NULL)
	{
		cout << it->str << endl;
		it = it->next;
	}
	cout << endl;
	inf.close();
	return first;
}




void writetext(Element* first)
{
	ofstream outf("../out.txt");
	if (!outf)
	{
		cout << "error!";
	}
	it = first;
	while (it != NULL)
	{
		outf << it->str << endl;
		it = it->next;
	}

	cout << "file writed!";
	outf.close();
}




void copyline(Element* first, int i, int j)
{
	Element* nexttoi, * newnext;
	it = findline(first, i);
	nexttoi = it->next;
	newnext = it->next = new Element(findline(first, j));
	newnext->next = nexttoi;

	it = first;

	while (it != NULL)
	{
		cout << it->str << endl;
		it = it->next;
	}
	cout << endl;

}



Element* cutline(Element* first, int i, int j)
{
	if (i < j)
	{
		findline(first, j)->next = findline(first, j + 1)->next;
	}
	else if (j == 1)
		first = first->next;
	else
	{
		findline(first, j - 1)->next = findline(first, j + 1);
	}
	it = first;

	while (it != NULL)
	{
		cout << it->str << endl;
		it = it->next;
	}
	cout << endl;
	return first;

}



void maxC(Element* first)
{
	int k = 0, i = 1, j, max = 0, pos;
	string line;
	it = first;

	while (it != NULL)
	{
		line = it->str;
		j = line.find("c");
		if (line.find('c') != std::string::npos)
		{
			break;
		}

		it = it->next;
		i++;
	}
	cout << "first C in:" << i << " line, " << j + 1 << " posision" << endl;

	it = first;
	i = 1;
	while (it != NULL)
	{
		line = it->str;
		for (j = 0; j < line.size(); j++)
		{
			if (line[j] == 'c')
			{
				k++;
			}
		}
		if (max < k)
		{
			max = k;
			pos = i;
		}
		k = 0;
		i++;
		it = it->next;
	}
	cout << "max C in line:" << pos << endl;

}

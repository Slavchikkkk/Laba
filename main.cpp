#include "list.h"
#include <fstream>
MyStruct* fillList(int &i)  //�������, ��� �������� ������ ����������.
{
    MyStruct* head = new MyStruct;
    char answer;
    cout << "Will you fill the list? (press y if yes) \n";
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {
        cout << "Please, fill your " << i << " list: \n";
        cin >> head->element;
        MyStruct * temp = head;
        while (true) {
            char var;
            cout << "Do you want to add some new elements? Please, type ""y"":" << endl;
            cin >> var;
            if (var == 'y' || var == 'Y') {
                temp->next = new MyStruct;
                temp = temp->next;
                cout << "Enter your elements: ";
                cin >> temp->element;
            }
            else {
                break;
            }
        }
        temp->next = NULL;
        cout << "End of " << i << " list" << endl;
        cout << endl;
        i++;
        return head;
    }else {//���� ���������� �� ������ ������� ������
        head = NULL;
        cout << "End of " << i << " list" << endl;
        cout << endl;
        i++;
        return head;
    }
}

void Empty(MyStruct* list)  //�������, ��� ������� ������� �������� ������, ���
//����������� ��� ��, �� ������ �������.
{
    int result = 0;
    if (list == NULL) {
        cout << "List is empty";
    }
    while (list != 0) {
        result++;
        list = list->next;
    }
    cout << "List is not empty, amount of elements: " << result << "\n";
}

void average(MyStruct* list)  //�������, ��� ������� ������ ����������� ��� �������� ������.
{//Mystruct* list ������� ������� ����� ���� �� �������� ������� �� ������ ������� ������
    double sum = 0;//���� ���������
    int k = 1;//������� ���������
    double mean;

    if (list == NULL) {
        cout << "List is empty";
    }
    else {
        for (MyStruct * temp = list ; temp != NULL; temp = temp->next) {
            k++;
            sum += temp->element;
        }
    }
    mean = sum / (k-1);//������� ��.���.
    cout << "sr: " << mean << "\n";
}


void write(MyStruct*list) {      //�������, ��� �������� ������ � ��������� ����.
    MyStruct * temp = list;//�������� ��'���
    ofstream output("output.txt");

    while (temp != NULL) {
        output << temp->element << " ";//�������� ���� ��'����
        temp = temp->next;//�������
    }

    cout << "Your information is in this file! " << endl;

    output.close();
}
void change(MyStruct* list)  //�������, ��� ����� ������ �������� �� ���.
{
    int var1;//���� �� ��������
    int var2;//���� �� �� ���������
    cout << "enter var1, then var2:";
    cin >> var1 >> var2;
    MyStruct* temp = list;//�������� ��'���
    for (list; temp != NULL; temp = temp->next) {
        if (temp->element == var1) {
            temp->element = var2;
        }
    }
    temp = list;//���������, ��� �� ���������� ����� ���
    while (temp != NULL) {
        cout << temp->element << " ";
        temp = temp->next;
    }
}

void showList(MyStruct* list)  //�������, ��� �������� ������ � �������.
{
    MyStruct* temp = list;
    while (temp != NULL) {
        cout << temp->element << " ";
        temp = temp->next;
    }
}

void replace(MyStruct* list)  //�������, ��� ����������� 1-� ������� ������ � ����
//�����, � ������� ������� �� �������.

{
    MyStruct * temp = list;
    MyStruct * temp1 = list->next;
    MyStruct *newHead = list->next;
    while (temp1->next != NULL)//���� ��� ������ ����� ������� �������
    {
        temp1 = temp1->next;
        temp = temp->next;
    }
    list->next = NULL;
    temp1->next = newHead;
    temp->next = list;//������� �� ������ ���������, �� ���� �������
    list = temp1;
}


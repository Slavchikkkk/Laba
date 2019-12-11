#include "list.h"
#include <fstream>
MyStruct* fillList(int &i)  //функція, яка заповнює список значеннями.
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
    }else {//Якщо користувач не захоче вводити список
        head = NULL;
        cout << "End of " << i << " list" << endl;
        cout << endl;
        i++;
        return head;
    }
}

void Empty(MyStruct* list)  //функція, яка повертає кількість елементів списку, або
//повідомлення про те, що список порожній.
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

void average(MyStruct* list)  //функція, яка повертає середнє арифметичне усіх елементів списка.
{//Mystruct* list парметр функції через який ми передаємо адрессу на перший елемент списку
    double sum = 0;//сума елемментів
    int k = 1;//кількість елемментів
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
    mean = sum / (k-1);//формула ср.арф.
    cout << "sr: " << mean << "\n";
}


void write(MyStruct*list) {      //функція, яка виводить список в текстовий файл.
    MyStruct * temp = list;//поточний об'єкт
    ofstream output("output.txt");

    while (temp != NULL) {
        output << temp->element << " ";//записуємо данні об'єкту
        temp = temp->next;//перехід
    }

    cout << "Your information is in this file! " << endl;

    output.close();
}
void change(MyStruct* list)  //функція, яка змінює вказані елементи на нові.
{
    int var1;//данні які замінюємо
    int var2;//данні на які заміниться
    cout << "enter var1, then var2:";
    cin >> var1 >> var2;
    MyStruct* temp = list;//поточний об'єкт
    for (list; temp != NULL; temp = temp->next) {
        if (temp->element == var1) {
            temp->element = var2;
        }
    }
    temp = list;//обнуляємо, щоб не створювати новий тємп
    while (temp != NULL) {
        cout << temp->element << " ";
        temp = temp->next;
    }
}

void showList(MyStruct* list)  //функція, яка виводить список у консоль.
{
    MyStruct* temp = list;
    while (temp != NULL) {
        cout << temp->element << " ";
        temp = temp->next;
    }
}

void replace(MyStruct* list)  //функція, яка переставляє 1-й елемент списку в його
//кінець, а останній елемент на початок.

{
    MyStruct * temp = list;
    MyStruct * temp1 = list->next;
    MyStruct *newHead = list->next;
    while (temp1->next != NULL)//цикл щоб знайти перед останній елемент
    {
        temp1 = temp1->next;
        temp = temp->next;
    }
    list->next = NULL;
    temp1->next = newHead;
    temp->next = list;//звєязуємо із першим елементом, що став останнім
    list = temp1;
}


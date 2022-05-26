#include <iostream>
using namespace std;
#define SIZE 20
class Node
{
    string name;
    string telno;
    Node *next;

public:
    Node()
    {
        name = "";
        telno = "";
        next = NULL;
    }
    friend class SeparateChaining;
};
class SeparateChaining
{
    Node *head[SIZE];
    int tsize;

public:
    SeparateChaining(int size)
    {
        tsize = size;
        for (int i = 0; i < tsize; i++)
            head[i] = NULL;
    }
    // declaration
    void insert(string name, string tel);
    void display();
    void search(string name);
    int hashf(string name);
};
/*drfinition*/
void SeparateChaining::insert(string name, string tel)
{
    int index = hashf(name);
    cout << "\nIndex:" << index << endl;
    Node *p = new Node(); // p-> name="", telno="", next=NULL;
    p->name = name;
    p->telno = tel;
    if (head[index] == NULL)
    {
        head[index] = p;
        cout << "Record inserted" << endl;
    }
    else
    {
        p->next = head[index];
        head[index] = p;
        cout << "\n Record inserted";
    }
}

void SeparateChaining::display()
{
    for (int i = 0; i < tsize; i++)
    {
        if (head[i] == NULL)

            cout << "\n"
                 << i << "\tNULL";
        else
        {
            Node *temp;
            temp = head[i];
            cout << "\n"
                 << i;
            while (temp != NULL)
            {
                cout << "\t" << temp->name << "," << temp->telno;
                temp = temp->next;
            }
        }
    }
}
void SeparateChaining::search(string name)
{
    int index = hashf(name);

    Node *temp = head[index];
    // traverse the link list
    while (temp != NULL)
    {
        if (temp->name == name)
        {
            cout << temp->name << "," << temp->telno << "found.";
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) // 1 when the list is empty
                      // 2 element is not present in the list
    {
        cout << name << " does not exist ";
    }
}
int SeparateChaining::hashf(string name)
{
    int index, asciisum = 0;
    for (int i = 0; i < name.length(); i++)
        asciisum += name[i];
    // hash function->key%tsize
    index = asciisum % tsize;
    return index;
}
int main()
{
    int size;
    string name;
    string tel;
    int ch;
    cout << "Enter Hash Table Size:" << endl;
    cin >> size;
    SeparateChaining obj(size);
    do
    {
        cout << "\n1. Insert\n2. Display\n3. Search\n4. Exit";
        cout << "\n Enter choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter Client's Nmae:" << endl;
            cin >> name;
            cout << "Enter Telephone no.:" << endl;
            cin >> tel;
            obj.insert(name, tel);
            break;
        case 2:
            obj.display();
            break;
        case 3:
            cout << "\nEnter Client's name to be searched:";
            cin >> name;
            obj.search(name);
            break;
        case 4:
            exit(0);
        default:
            cout << "\n Invalid choice";
        }
    } while (ch != 4);

    return 0;
}
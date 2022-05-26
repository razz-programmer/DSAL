#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class student
{
    int rollno;
    char name[20], div, address[20];

public:
    student()
    {
        rollno = 0;
        div = ' ';
        strcpy(name, "");
        strcpy(address, "");
    }
    void input();
    void display();
    int getrollno()
    {
        return rollno;
    }
};

void student::input()

{
    cout << "\n---------------------Enter Student Details-------------------";
    cout << "\n| Enter Student Roll No :";
    cin >> rollno;

    cout << "\n| Enter Student Name :";
    cin >> name;

    cout << "\n| Enter Student Division :";
    cin >> div;

    cout << "\n| Enter student address :";
    cin >> address;
}

void student::display()
{
    cout << "\n"
         << rollno << "\t" << name << "\t" << div << "\t" << address;
}

class sequential_file
{
    fstream file;
    student obj;

public:
    void create(); // Creates new file
    void add();
    void search();
    void del();
    void print();
};

void sequential_file::create()
{
    char ch = 'y';
    file.open("student_data.txt", ios::out | ios::binary);
    while (ch == 'y' || ch == 'Y')
    {
        obj.input();
        file.write((char *)&obj, sizeof(obj));
        cout << "\nWant to enter more entries!!!! :";
        cin >> ch;
    }
    file.close();
}

void sequential_file::add()
{
    char ch = 'y';
    file.open("student_data.txt", ios::app | ios::out | ios::binary);
    while (ch == 'y' || ch == 'Y')
    {
        obj.input();
        file.write((char *)&obj, sizeof(obj));
        cout << "\nWant to enter more entries!!!! :";
        cin >> ch;
    }
    file.close();
}

void sequential_file::print()
{
    file.open("student_data.txt", ios::in | ios::binary);
    if (!file)
    {
        cout << "File Not Found!!!!!!!!!!! ";
    }
    else
    {
        file.read((char *)&obj, sizeof(obj));
        while (!file.eof())
        {
            obj.display();
            file.read((char *)&obj, sizeof(obj));
        }
    }
    file.close();
}

void sequential_file::search()
{
    int n, fl = 0;
    cout << "Enter roll no . to be searched :";
    cin >> n;
    file.open("student_data.txt", ios::in | ios::binary);
    if (!file)
    {
        cout << "File Not Found!!!!!!!!!!! ";
        exit(0);
    }
    else
    {
        file.read((char *)&obj, sizeof(obj));
        while (!file.eof())
        {
            if (n == obj.getrollno())
            {
                obj.display();
                fl = 1;
                break;
            }
            else
                file.read((char *)&obj, sizeof(obj));

            if (fl == 0)
            {
                cout << "Record Not Found!!!!!!!!!!";
            }
        }
    }
}

int main()
{
    student obj;
    sequential_file sobj;
    // obj.input();
    // obj.display();
    sobj.create();
    // cout<<"appending data";
    // sobj.add();
    // sobj.print();
    sobj.search();

    return 0;
}
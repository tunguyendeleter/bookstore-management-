#include "datastructure.h"
#include <fstream>
using namespace std;
staff *newNode();
void addNode(tree &p, staff *q);
void textHandling(string &a);
//=============================READ WRITE FILE ==============================
void ReadWriteFile(bookList &dsbook)
{
    ifstream filein;
    filein.open("book.txt", ios::in);
    while (filein.eof() != true)
    {
        dsbook.list[dsbook.len] = new book;
        getline(filein, dsbook.list[dsbook.len]->bookName, ',');
        getline(filein, dsbook.list[dsbook.len]->author, ',');
        getline(filein, dsbook.list[dsbook.len]->bookID, ',');
        getline(filein, dsbook.list[dsbook.len]->bookCategory, ',');
        filein >> dsbook.list[dsbook.len]->prices;
        filein.ignore();
        filein >> dsbook.list[dsbook.len]->status;
        filein.ignore();
        textHandling(dsbook.list[dsbook.len]->bookName);
        textHandling(dsbook.list[dsbook.len]->author);
        textHandling(dsbook.list[dsbook.len]->bookID);
        textHandling(dsbook.list[dsbook.len]->bookCategory);
        dsbook.len++;
    }
    filein.close();
}
void ReadWriteFile_Staff(staff_tree &dsstaff)
{
    ifstream filein;
    filein.open("staff.txt", ios::in);
    while (filein.eof() != true)
    {
        staff *x = new staff;
        filein >> x->staffID;
        filein.ignore();
        getline(filein, x->firstName, ',');
        getline(filein, x->lastName, ',');
        getline(filein, x->occupation, '\n');
        addNode(dsstaff.TREE, x);
        dsstaff.len++;
    }
    filein.close();
}
staff *newNode()
{
    staff *newstaff = new staff;
    newstaff->pleft = NULL;
    newstaff->pright = NULL;
    return newstaff;
}
void addNode(tree &p, staff *q)
{
    if (p == NULL)
        p = q;
    else
    {
        if (p->staffID < q->staffID)
        {
            addNode(p->pright, q);
        }
        else if (p->staffID > q->staffID)
        {
            addNode(p->pleft, q);
        }
    }
}
void logo()
{
    string line;
    ifstream file("ascii-art.txt");
    while (!file.eof())
    {
        getline(file, line);
        cout << line << endl;
    }
}

void textHandling(string &a)
{
    while (a[0] == ' ')
    {
        a.erase(a.begin() + 0);
    }
    while (a[a.size() - 1] == ' ')
    {
        a.erase(a.begin() + a.size() - 1);
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == ' ' && a[i + 1] == ' ')
        {
            a.erase(a.begin() + i + 1);
            i--;
        }
    }
    // normalize characters - characters compare in decimal
    if (a[0] >= 97 && a[0] <= 122) // lower case from 97 - 122
    {
        a[0] -= 32; // substract 32 to get
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == ' ')
        {
            if (a[i + 1] >= 97 && a[i + 1] <= 122)
            {
                a[i + 1] -= 32;
            }
        }
        else
        {
            if (a[i + 1] >= 65 && a[i + 1] <= 90)
            {
                a[i + 1] += 32;
            }
        }
    }
}
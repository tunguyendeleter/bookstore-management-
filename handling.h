#include "datastructure.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include "read_write_file.h"
#include <ctime>
#include <map>

void menu();
//======================= BOOK handling =========================
string createBookID(bookList dsbook);
void addBook(bookList &dsbook);
int checkSame_bookID(bookList dsbook, string a);
void printAllBook(bookList dsbook);
void searchBookByName(bookList dsbook, string name);
void printBook(bookList dsbook);
void bookDelete(bookList &dsbook);
int checkBookStatus(bookList dsbook, string a);
void editBook(bookList dsbook);
//======================= STAFF handling =========================
// void textHandling(string &a);
// staff *newNode();
void createStaffTree(staff_tree &dsstaff);
// void addNode(tree &p, staff *q);
int createStaffID(tree temp);
bool checkSame_staffID(tree tem, int id);
void mostLeftValue(tree &temp, staff *&swap);
void inOrder(staff *tree);
void SearchStaff(staff *&curr, staff *&father, int id);
void TreeToArray(staff *tree, staff *list[], int &listlen);
void swapList(staff *&first, staff *&second);
void printList(staff *list[], int &listlen);
void sortList(staff *list[], int &listlen);
void printAscendingID(staff_tree dsstaff);
void printStaff(staff_tree dsstaff);
void release_One_Staff(staff *&tree, int id);
void releaseStaff(staff_tree &dsstaff);
void edit_One_Staff(tree t, int id);
void editStaff(staff_tree &dsstaff);
//========================== BILL handling ==================
void add_One_Bill(bill *&phead, bill *&p);
void makeBill(staff_tree &dsstaff, bookList dsbook);
bool checkSame_billID(bill *phead, string id);
string createBillID(billList dsbill);
bill *newBill();
staff *findStaffID(tree t, int id);
void addProductBill(bill *&b, bookList dsbook);
void print_All_Bill(bill *list, staff *s);
int countBill(billList dsbill, string name, int &count);
void printBill_preOrder(staff *tree);
void printBill(staff_tree &dsstaff);
void print_All_DateBill(staff *s, bill *list, int date, int month, int year);
void printDateBill_preOrder(staff *tree, int date, int month, int year);
void printDateBill(staff_tree dsstaff);
void deleteBill(staff_tree dsstaff);
void deleteBill1(staff *s, string id);
void deleteOneBill(bill *&b, string id);
void checkSame_billID_AllStaff(staff *s, string id);
//============================= FUN ================
void printDict();
void search(bill *list);
void find(bill *list);
void findBest(staff *tree);
//=======================menu=========================
map<string, int> myDictionary;
void menu()
{
    bool kt = true;
    int staffid;
    bookList dsbook;
    staff_tree dsstaff;
    staff *staf = NULL;
    ReadWriteFile(dsbook);
    ReadWriteFile_Staff(dsstaff);
    while (kt == true)
    {
        logo();
        cout << "//////////////// MENU ////////////////" << endl;
        cout << "(1) Add a Book." << endl;
        cout << "(2) Search Book" << endl;
        cout << "(3) Delete a Product" << endl;
        cout << "(4) Edit a Product" << endl;
        cout << "(5) Add a Staff" << endl;
        cout << "(6) Print Staff" << endl;
        cout << "(7) Delete a staff" << endl;
        cout << "(8) Edit a staff" << endl;
        cout << "(9) Make a Bill" << endl;      // print book
        cout << "(10) Print Bill list" << endl; // print nv
        cout << "(11) Print Statistical Bill by Date, Week, and Month " << endl;
        cout << "(12) Delete a Bill " << endl;
        cout << "(13) Print Best Sellers " << endl;
        cout << "(0) Save and Exit" << endl;
        cout << "Choose an option: ";
        int option;
        cin >> option;
        if (option == 1)
        {
            if (dsbook.len == MAX)
            {
                cout << "Full of stock!, cannot be added more Books" << endl;
                system("pause");
            }
            else
            {
                addBook(dsbook);
            }
        }
        else if (option == 2)
        {
            printBook(dsbook);
        }
        else if (option == 3)
        {
            if (dsbook.len == 0)
            {
                cout << "Out of stock!, cannot be deleted more Books" << endl;
                system("pause");
            }
            else
            {
                bookDelete(dsbook);
            }
        }
        else if (option == 4)
        {
            editBook(dsbook);
        }
        else if (option == 5)
        {
            createStaffTree(dsstaff);
        }
        else if (option == 6)
        {
            printStaff(dsstaff);
        }
        else if (option == 7)
        {
            releaseStaff(dsstaff);
        }
        else if (option == 8)
        {
            editStaff(dsstaff);
        }
        else if (option == 9)
        {
            system("cls");
            printAscendingID(dsstaff);
            makeBill(dsstaff, dsbook);
        }
        else if (option == 10)
        {
            printBill(dsstaff);
        }
        else if (option == 11)
        {
            printDateBill(dsstaff);
        }
        else if (option == 12)
        {
            deleteBill(dsstaff);
        }
        else if (option == 0)
        {
            kt == false;
        }
        else if (option == 13)
        {
            findBest(dsstaff.TREE);
            printDict();
            system("pause");
            system("cls");
        }
        else
        {
            system("cls");
        }
        // switch (option)
        // {
        // case 1:
        //     if (dsbook.len == MAX)
        //     {
        //         cout << "Full of stock!, cannot be added more Books" << endl;
        //         system("pause");
        //     }
        //     else
        //     {
        //         addBook(dsbook);
        //     }
        //     break;
        // case 2:
        //     printAllBook(dsbook);
        //     break;
        // case 3:
        //     if (dsbook.len == 0)
        //     {
        //         cout << "Out of stock!, cannot be deleted more Books" << endl;
        //         system("pause");
        //     }
        //     else
        //     {
        //         bookDelete(dsbook);
        //     }
        //     break;
        // case 4:
        //     editBook(dsbook);
        //     break;
        // case 5:
        //     createStaffTree(dsstaff);
        //     break;
        // case 6:
        //     staff *list[100];
        //     int listlen = 0;
        //     TreeToArray(dsstaff.TREE, list, listlen);
        //     sortList(list, listlen);
        //     printList(list, listlen);
        //     releaseList(list, listlen);
        //     system("pause");
        //     break;
        // case 7:
        //     releaseStaff(dsstaff);
        //     system("pause");
        //     break;
        // case 8:
        //     editStaff(dsstaff);
        //     break;
        // case 0:
        //     kt == false;
        //     break;
        // }
    }
}
//======================= ADD BOOK =========================
void addBook(bookList &dsbook)
{
    int prices;
    book *temp = new book;
    cin.ignore();
    cout << "Enter Book Name: ";
    getline(cin, temp->bookName);
    cout << "Enter Book Author: ";
    getline(cin, temp->author);
    cout << "Enter Book Category: ";
    getline(cin, temp->bookCategory);
    cout << "Enter Book Price: ";
    cin >> temp->prices;
    temp->bookID = createBookID(dsbook);
    textHandling(temp->bookName);
    textHandling(temp->author);
    textHandling(temp->bookCategory);
    dsbook.list[dsbook.len] = temp;
    dsbook.len++;
    system("pause");
    system("cls");
}
string createBookID(bookList dsbook)
{
    int count = 0;
    string a = "B0000";
    do
    {
        for (int i = 1; i < a.size(); i++)
        {
            a[i] = rand() % (57 - 48 + 1) + 48; // acsii '9' = 57, '0' = 48
        }
        return a;
    } while (checkSame_bookID(dsbook, a) >= 0);
}
int checkSame_bookID(bookList dsbook, string a)
{
    for (int i = 0; i < dsbook.len; i++)
    {
        if (dsbook.list[i]->bookID == a)
        {
            return i;
        }
    }
    return -1;
}
//=================================== DELETE BOOK ==============================
void bookDelete(bookList &dsbook)
{
    cout << "If the book is ordered, the product cannot be Deleted" << endl;
    string a;
    cout << "Enter the book" << endl;
    cin >> a;
    int index = checkBookStatus(dsbook, a);
    if (index < 0)
    {
        cout << "The book is already ordered" << endl;
        system("pause");
    }
    else
    {
        for (int i = index; i < dsbook.len; i++)
        {
            dsbook.list[i] = dsbook.list[i + 1];
        }
        dsbook.len--;
        cout << "Delete successfully!" << endl;
        system("pause");
    }
    system("pause");
    system("cls");
}
int checkBookStatus(bookList dsbook, string a)
{
    for (int i = 0; i < dsbook.len; i++)
    {
        if (dsbook.list[i]->bookName == a)
        {
            if (dsbook.list[i]->status == false)
            {
                return i;
            }
        }
    }
    return -1;
}
//=================================== TRAVESAL BOOK =========================================
void printAllBook(bookList dsbook)
{
    cout << "==================================Print out all Books================================\n";
    printf("|%-10s|%-25s|%-20s|%-12s|%-12s|%\n", "ID", "Book Name", "Author's Name", "Price", "Available");
    for (int i = 0; i < dsbook.len; i++)
    {
        int count = 0;
        int same = 0;
        for (int j = 0; j < dsbook.len; j++)
        {
            if (dsbook.list[i]->bookName == dsbook.list[j]->bookName)
            {
                count++;
            }
        }
        for (int j = 0; j < dsbook.len; j++)
        {
            if (dsbook.list[i]->bookName == dsbook.list[j]->bookName)
            {
                same++;
                if (i == j && same == 1)
                {
                    cout << "-------------------------------------------------------------------------------------\n";
                    printf("|%-10s|%-25s|%-20s|%-12d|%-12d|%\n", dsbook.list[i]->bookID.c_str(), dsbook.list[i]->bookName.c_str(), dsbook.list[i]->author.c_str(), dsbook.list[i]->prices, count);
                }
            }
        }
    }
    cout << "=====================================================================================\n";
}
void searchBookByName(bookList dsbook, string name)
{
    for (int i = 0; i < dsbook.len; i++)
    {
        int count = 0;
        for (int j = 0; j < dsbook.len; j++)
        {
            if (dsbook.list[i]->bookName == dsbook.list[j]->bookName)
            {
                count++;
            }
        }
        if (dsbook.list[i]->bookName == name)
        {
            cout << "=====================================================================================\n";
            printf("|%-26s%-57s|%\n", "Search for Book named >>>", name.c_str());
            printf("|%-10s|%-25s|%-20s|%-12s|%-12s|%\n", "ID", "Book Name", "Author's Name", "Price", "Available");
            cout << "-------------------------------------------------------------------------------------\n";
            printf("|%-10s|%-25s|%-20s|%-12d|%-12d|%\n", dsbook.list[i]->bookID.c_str(), dsbook.list[i]->bookName.c_str(), dsbook.list[i]->author.c_str(), dsbook.list[i]->prices, count);
            cout << "=====================================================================================\n";
            return;
        }
    }
    cout << "Book named " << name << " cannot be Found!" << endl;
    return;
}
void searchBookByAuthor(bookList dsbook, string name)
{
    for (int i = 0; i < dsbook.len; i++)
    {
        int count = 0;
        int same = 0;
        for (int j = 0; j < dsbook.len; j++)
        {
            if (dsbook.list[i]->bookName == dsbook.list[j]->bookName && dsbook.list[i]->author == name)
            {
                count++;
            }
        }
        for (int k = 0; k < dsbook.len; k++)
        {
            if (dsbook.list[i]->bookName == dsbook.list[k]->bookName)
            {
                if (dsbook.list[i]->author == name)
                {
                    same++;
                    if (same == 1 && k == i)
                    {
                        cout << "=====================================================================================\n";
                        printf("|%-26s%-57s|%\n", "Search for Book by >>>", name.c_str());
                        printf("|%-10s|%-25s|%-20s|%-12s|%-12s|%\n", "ID", "Book Name", "Author's Name", "Price", "Available");
                        cout << "-------------------------------------------------------------------------------------\n";
                        printf("|%-10s|%-25s|%-20s|%-12d|%-12d|%\n", dsbook.list[i]->bookID.c_str(), dsbook.list[i]->bookName.c_str(), dsbook.list[i]->author.c_str(), dsbook.list[i]->prices, count);
                        cout << "=====================================================================================\n";
                    }
                }
            }
        }
    }
    return;
}
void printBook(bookList dsbook)
{
    bool key = true;
    system("cls");
    while (key == true)
    {
        cout << "(1) Print all Books available in Stock" << endl;
        cout << "(2) Search Book by Name" << endl;
        cout << "(3) Search Book by Author" << endl;
        cout << "(0) Exit" << endl;
        int in;
        string name;
        cout << "Enter option: ";
        cin >> in;
        switch (in)
        {
        case 1:
            printAllBook(dsbook);
            system("pause");
            system("cls");
            break;
        case 2:
            cin.ignore();
            cout << "Enter Name to search: ";
            getline(cin, name);
            textHandling(name);
            searchBookByName(dsbook, name);
            system("pause");
            system("cls");
            break;
        case 3:
            cin.ignore();
            cout << "Enter Author's Name to search: ";
            getline(cin, name);
            textHandling(name);
            searchBookByAuthor(dsbook, name);
            system("pause");
            system("cls");
            break;
        case 0:
            key = false;
            system("cls");
            break;
        default:
            break;
        }
    }
}
//=================================== EDITIING BOOK ==============================
void editBook(bookList dsbook)
{
    string a;
    cout << "Enter Book ID for Editing: ";
    cin >> a;
    int item = checkSame_bookID(dsbook, a);
    if (item < 0)
    {
        cout "The Book with ID " << a << " does not exist";
        system("pause");
    }
    else
    {
        cin.ignore();
        cout << "Enter Book Name: ";
        getline(cin, dsbook.list[item]->bookName);
        cout << "Enter Author's Name: ";
        getline(cin, dsbook.list[item]->author);
        cout << "Enter Category: ";
        getline(cin, dsbook.list[item]->bookCategory);
        textHandling(dsbook.list[item]->bookName);
        textHandling(dsbook.list[item]->author);
        textHandling(dsbook.list[item]->bookCategory);
        cout << "Editing is successful!" << endl;
    }
    system("pause");
    system("cls");
}
//=================================== ADD STAFF ===========================================

void createStaffTree(staff_tree &dsstaff)
{
    staff *newstaff = newNode();
    cin.ignore();
    cout << "Enter First Name: ";
    getline(cin, newstaff->firstName);
    cout << "Enter Last Name: ";
    getline(cin, newstaff->lastName);
    cout << "Enter Occupation: ";
    getline(cin, newstaff->occupation);
    newstaff->staffID = createStaffID(dsstaff.TREE);
    addNode(dsstaff.TREE, newstaff);
    dsstaff.len++;
    system("pause");
    system("cls");
}
void mostLeftValue(tree &temp, staff *&swap)
{
    if (temp->pleft != NULL)
    {
        mostLeftValue(temp->pleft, swap);
    }
    else
    {
        swapList(temp, swap);
        swap = temp;
        temp = temp->pright;
    }
}
void SearchStaff(staff *&curr, staff *&father, int id)
{
    if (curr == NULL)
    {
        return;
    }
    while (curr->staffID != id)
    {
        father = curr;
        cout << father->staffID;
        if (curr->staffID > id)
            curr = curr->pleft;
        else
            curr = curr->pright;
    }
}
void inOrder(tree tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        inOrder(tree->pleft);
        cout << "------------------------------------------" << endl;
        printf("|%-10d|%-8s%-10s|%-10s|%\n", tree->staffID, tree->firstName.c_str(), tree->lastName.c_str(), tree->occupation.c_str());
        inOrder(tree->pright);
    }
}
void printAscendingID(staff_tree dsstaff)
{
    cout << "=============== STAFF LIST ===============" << endl;
    printf("|%-10s|%-18s|%-10s|%\n", "Staff ID", "Full name", "Position");
    inOrder(dsstaff.TREE);
    cout << "==========================================" << endl;
}
int createStaffID(tree temp)
{
    int a;
    do
    {
        a = rand() % (999 - 100 + 1) + 100;
        return a;
    } while (checkSame_staffID(temp, a) == true);
    return a;
}
bool checkSame_staffID(tree temp, int id)
{
    if (temp == NULL)
    {
        return false;
    }
    else
    {
        if (temp->staffID == id)
        {
            return true;
        }
        else if (temp->staffID < id)
        {
            return checkSame_staffID(temp->pright, id);
        }
        else
        {
            return checkSame_staffID(temp->pleft, id);
        }
    }
}
//=================================== PRINT STAFF ===========================================
void TreeToArray(staff *tree, staff *list[], int &listlen)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        list[listlen] = new staff;
        list[listlen]->firstName = tree->firstName;
        list[listlen]->lastName = tree->lastName;
        list[listlen]->occupation = tree->occupation;
        list[listlen]->staffID = tree->staffID;
        listlen++;
        TreeToArray(tree->pleft, list, listlen);
        TreeToArray(tree->pright, list, listlen);
    }
}
void printList(staff *list[], int &listlen)
{
    cout << "=============== STAFF LIST ===============" << endl;
    printf("|%-10s|%-18s|%-10s|%\n", "Staff ID", "Full name", "Position");
    for (int i = 0; i < listlen; i++)
    {
        cout << "------------------------------------------" << endl;
        printf("|%-10d|%-8s%-10s|%-10s|%\n", list[i]->staffID, list[i]->firstName.c_str(), list[i]->lastName.c_str(), list[i]->occupation.c_str());
    }
    cout << "==========================================" << endl;
}
void swapList(staff *&first, staff *&second)
{
    staff *temp = new staff;
    temp->firstName = second->firstName;
    temp->lastName = second->lastName;
    temp->occupation = second->occupation;
    temp->staffID = second->staffID;

    second->firstName = first->firstName;
    second->lastName = first->lastName;
    second->occupation = first->occupation;
    second->staffID = first->staffID;

    first->firstName = temp->firstName;
    first->lastName = temp->lastName;
    first->occupation = temp->occupation;
    first->staffID = temp->staffID;
    delete temp;
}
void sortList(staff *list[], int &listlen)
{
    for (int i = 0; i < listlen; i++)
    {
        for (int j = i + 1; j < listlen; j++)
        {
            if (list[j]->lastName < list[i]->lastName)
            {
                swapList(list[i], list[j]);
            }
            else if (list[j]->lastName == list[i]->lastName)
            {
                if (list[j]->firstName < list[i]->firstName)
                    swapList(list[i], list[j]);
            }
        }
    }
}
void printStaff(staff_tree dsstaff)
{
    bool key = true;
    while (key == true)
    {
        system("cls");
        cout << "(1) Print Staffs by ascending ID" << endl;
        cout << "(2) Print Staffs by ascending Full Name" << endl;
        cout << "(3) Exit" << endl;
        int listlen = 0;
        int in;
        cout << "Enter option: ";
        cin >> in;
        if (in != 3)
        {
            switch (in)
            {
            case 1:
                printAscendingID(dsstaff);
                system("pause");
                break;
            case 2:
                staff *list[100];
                listlen = 0;
                TreeToArray(dsstaff.TREE, list, listlen);
                sortList(list, listlen);
                printList(list, listlen);
                releaseList(list, listlen);
                system("pause");
                break;
            default:
                break;
            }
        }
        else
        {
            key = false;
            system("cls");
        }
    }
}
void releaseStaff(staff_tree &dsstaff)
{
    int a;
    cout << "Enter staff ID: ";
    cin >> a;
    bool kt = checkSame_staffID(dsstaff.TREE, a);
    if (kt == true)
    {
        release_One_Staff(dsstaff.TREE, a);
        dsstaff.len--;
        cout << "Delete successfully!" << endl;
    }
    else
    {
        cout << "Staff ID does not exist" << endl;
    }
    system("pause");
    system("cls");
}
void release_One_Staff(staff *&tree, int id)
{
    if (tree != NULL)
    {
        if (tree->staffID == id)
        {
            staff *temp = tree; // store node to be released
            if (tree->pleft == NULL)
            {
                tree = tree->pright;
            }
            else if (tree->pright == NULL)
            {
                tree = tree->pleft;
            }
            else if (tree->pleft != NULL && tree->pright != NULL)
            {
                mostLeftValue(tree->pright, temp);
            }
            delete temp;
        }
        if (tree->staffID > id)
        {
            release_One_Staff(tree->pleft, id);
        }
        else
        {
            release_One_Staff(tree->pright, id);
        }
    }
}
void editStaff(staff_tree &dsstaff)
{
    int a;
    cout << "Enter Staff ID to be edited" << endl;
    cin >> a;
    bool kt = checkSame_staffID(dsstaff.TREE, a);
    if (kt == true)
    {
        edit_One_Staff(dsstaff.TREE, a);
    }
    else
    {
        cout << "Staff ID does not exist" << endl;
    }
    system("pause");
    system("cls");
}
void edit_One_Staff(tree t, int id)
{
    if (t != NULL)
    {
        if (t->staffID == id)
        {
            cin.ignore();
            cout << "Enter first name: ";
            getline(cin, t->firstName);
            cout << "Enter last name: ";
            getline(cin, t->lastName);
            cout << "Enter occupation: ";
            getline(cin, t->occupation);
            textHandling(t->firstName);
            textHandling(t->lastName);
            textHandling(t->occupation);
            cout << "Staff information edited successfully" << endl;
        }
        else if (t->staffID > id)
        {
            edit_One_Staff(t->pleft, id);
        }
        else if (t->staffID < id)
        {
            edit_One_Staff(t->pright, id);
        }
    }
}
//================================== MAKE A BILL========================================

void add_One_Bill(bill *&phead, bill *&p)
{
    bill *last = phead;
    if (phead == NULL)
    {
        phead = p;
        return;
    }
    if (last->pnext == NULL)
    {
        last->pnext = p;
        return;
    }
    while (last->pnext != NULL)
    {
        last = last->pnext;
    }
    last->pnext = p;
    return;
}
void makeBill(staff_tree &dsstaff, bookList dsbook)
{
    int a;
    cout << "Enter Staff ID: ";
    cin >> a;
    staff *s = findStaffID(dsstaff.TREE, a);
    if (s == NULL)
    {
        cout << "Staff ID does not exist" << endl;
    }
    else
    {
        bill *b = newBill();
        bool input;
        bool kt = true;
        bool buy = true;
        string bookName;
        while (kt == true)
        {
            system("cls");
            cout << "(1) Import Bill" << endl;
            cout << "(2) Export Bill" << endl;
            cout << "Enter Bill Category: ";
            int x;
            cin >> x;
            switch (x)
            {
            case 1:
                input = true;
                b->category = 'I';
                cout << "Bill Category: Import" << endl;
                kt = false;
                break;
            case 2:
                input = false;
                b->category = 'E';
                cout << "Bill Category: Export" << endl;
                kt = false;
                break;
            default:
                break;
            }
        }
        //===============
        b->billID = createBillID(s->dsbill);
        cout << "Bill ID: " << b->billID << endl;
        cout << "Enter date to create Bill" << endl;
        cout << "Date: ";
        cin >> b->date;
        cout << "Month: ";
        cin >> b->month;
        b->year = 1900 + ltm->tm_year;
        addProductBill(b, dsbook);
        add_One_Bill(s->dsbill.phead, b);
        s->dsbill.len++;
        cout << "Create Bill successfully! Enter any key to proceed!" << endl;
        system("pause");
        cout << "Bill: " << b->category << " || Bill ID: " << b->billID << " || Invoice Date: " << b->date << "/" << b->month << "/" << b->year << endl;
        system("pause");
        system("cls");
    }
}
void addProductBill(bill *&b, bookList dsbook)
{
    bool buy = true;
    while (buy == true)
    {
        int yn;
        bool out;
        string bookName;
        cout << "Enter product Name: ";
        cin.ignore();
        getline(cin, bookName);
        for (int it = 0; it < dsbook.len; it++)
        {
            if (dsbook.list[it]->bookName == bookName)
            {
                bool check = true;
                while (check == true)
                {
                    cout << "Do you want to choose: " << dsbook.list[it]->bookName << " [1/0]: ";
                    cin >> yn;
                    switch (yn)
                    {
                    case 1:
                        b->product_list.list[b->product_list.len] = dsbook.list[it];
                        b->product_list.len++;
                        cout << "Add a Product Completely!!!" << endl;
                        check = false;
                        break;
                    case 0:
                        cout << "Fail to Add a Product!!!" << endl;
                        check = false;
                        break;
                    default:
                        break;
                    }
                }
                break;
            }
        }
        bool check = true;
        while (check == true)
        {
            cout << "Do you want to buy more [1/0]: ";
            cin >> yn;
            switch (yn)
            {
            case 1:
                check = false;
                break;
            case 0:
                buy = false;
                check = false;
                break;
            default:
                break;
            }
        }
    }
}
bool checkSame_billID(bill *phead, string id)
{
    for (bill *k = phead; k != NULL; k = k->pnext)
    {
        if (k->billID == id)
        {
            return true;
        }
    }
    return false;
}
string createBillID(billList dsbill)
{
    int count = 0;
    string a = "HD0000";
    do
    {
        for (int i = 2; i < a.size(); i++)
        {
            a[i] = rand() % (57 - 48 + 1) + 48; // acsii '9' = 57, '0' = 48
        }
    } while (checkSame_billID(dsbill.phead, a) == true);
    return a;
}
bill *newBill()
{
    bill *p = new bill;
    p->pnext = NULL;
}
staff *findStaffID(tree t, int id)
{
    if (t != NULL)
    {
        if (t->staffID == id)
        {
            return t;
        }
        else if (t->staffID > id)
        {
            findStaffID(t->pleft, id);
        }
        else if (t->staffID < id)
        {
            findStaffID(t->pright, id);
        }
    }
    else
    {
        return NULL;
    }
}
//================================= PRINT BILL ===========================================
void printBill(staff_tree &dsstaff)
{
    system("cls");
    bool key = true;
    while (key == true)
    {
        int id;
        staff *temp = new staff;
        bill *b = newBill();
        cout << "(1) Print all Bills from all staffs" << endl;
        cout << "(2) Print Bills from staff ID" << endl;
        cout << "(0) Exit" << endl;
        int option;
        cout << "Choose option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            printBill_preOrder(dsstaff.TREE);
            break;
        case 2:
            cout << "Enter Staff ID: ";
            cin >> id;
            temp = findStaffID(dsstaff.TREE, id);
            cout << temp->firstName << temp->lastName << endl;
            if (temp == NULL)
            {
                cout << "Staff ID does not exist!" << endl;
            }
            else
            {
                print_All_Bill(temp->dsbill.phead, temp);
            }
            break;
        case 0:
            key = false;
            system("cls");
            break;
        default:
            break;
        }
    }
}
void print_All_Bill(bill *list, staff *s)
{
    cout << "?????";
    bill *b = list;
    int count = 0;
    while (b != NULL)
    {
        int sum = 0;
        int VAT = 0;
        cout << "====================== BILL LIST " << count++ << " =======================" << endl;
        printf("|%-56s|\n", "113 VO VAN NGAN - TP.THU DUC - TP.HCM");
        printf("|%-15s%-41s|\n", "Receipt No:", b->billID.c_str());
        printf("|%-15s%-7s%-34s|\n", "Staff Name:", s->firstName.c_str(), s->lastName.c_str());
        printf("|%-56s|\n", "Description:");
        cout << "==========================================================" << endl;
        for (int i = 0; i < b->product_list.len; i++)
        {
            printf("|%-35s%-21d|\n", b->product_list.list[i]->bookName.c_str(), b->product_list.list[i]->prices);
            sum += b->product_list.list[i]->prices;
            VAT = sum * (5 %);
        }
        cout << "----------------------------------------------------------" << endl;
        printf("|%-35s%-21d|\n", "Total Sum:", sum);
        printf("|%-35s%-21d|\n", "VAT:", VAT);
        printf("|%-35s%-21d|\n", "Final Sum:", sum - VAT);
        printf("|%-56s|\n", "Receipt printed by day");
        cout << "|                        (" << b->date << "/" << b->month << "/" << b->year << ")                     |" << endl;
        cout << "==========================================================" << endl;
        b = b->pnext;
        cout << endl;
    }
    return;
}
int countBill(billList dsbill, string name, int &count)
{
    if (dsbill.phead != NULL)
    {
        for (bill *b = dsbill.phead; b != NULL; b = b->pnext)
        {
            if (name == b->billID)
            {
                count++;
            }
        }
    }
    return count;
}
void printBill_preOrder(staff *tree)
{
    if (tree != NULL)
    {
        print_All_Bill(tree->dsbill.phead, tree);
        printBill_preOrder(tree->pleft);
        printBill_preOrder(tree->pright);
    }
    return;
}
void print_All_DateBill(staff *s, bill *list, int date, int month, int year, bool mode)
{
    bill *b = list;
    int count = 0;
    while (b != NULL)
    {
        int VAT = 0;
        int sum = 0;
        if (b->year == year)
        {
            if (b->month == month)
            {
                if (b->date == date || mode == true)
                {
                    cout << "====================== BILL LIST " << count++ << " =======================" << endl;
                    printf("|%-56s|\n", "113 VO VAN NGAN - TP.THU DUC - TP.HCM");
                    printf("|%-15s%-41s|\n", "Receipt No:", b->billID.c_str());
                    printf("|%-15s%-7s%-34s|\n", "Receipt No:", s->firstName.c_str(), s->lastName.c_str());
                    printf("|%-56s|\n", "Description:");
                    cout << "==========================================================" << endl;
                    for (int i = 0; i < list->product_list.len; i++)
                    {
                        printf("|%-35s%-21d|\n", list->product_list.list[i]->bookName.c_str(), list->product_list.list[i]->prices);
                        sum += list->product_list.list[i]->prices;
                        VAT = sum * (5 %);
                    }
                    cout << "----------------------------------------------------------" << endl;
                    printf("|%-35s%-21d|\n", "Total Sum:", sum);
                    printf("|%-35s%-21d|\n", "VAT:", VAT);
                    printf("|%-35s%-21d|\n", "Final Sum:", sum - VAT);
                    printf("|%-56s|\n", "Receipt printed by day");
                    cout << "|                        (" << b->date << "/" << b->month << "/" << b->year << ")                     |" << endl;
                    cout << "==========================================================" << endl;
                    cout << endl;
                }
            }
        }
        b = b->pnext;
    }
    return;
}
void printDateBill_preOrder(staff *tree, int date, int month, int year, bool mode)
{
    if (tree != NULL)
    {
        print_All_DateBill(tree, tree->dsbill.phead, date, month, year, mode);
        printDateBill_preOrder(tree->pleft, date, month, year, mode);
        printDateBill_preOrder(tree->pright, date, month, year, mode);
    }
    return;
}
void printDateBill(staff_tree dsstaff)
{
    system("cls");
    bool key = true;
    while (key == true)
    {
        int date = 0;
        int month = 0;
        int year = 0;
        int in;
        cout << "(1) Print all Bills by Date" << endl;
        cout << "(2) Print all Bills by Week" << endl;
        cout << "(3) Print all Bills by Month" << endl;
        cout << "(0) Exit" << endl;
        cout << "Enter option: ";
        cin >> in;
        switch (in)
        {
        case 1:
            cout << "Enter Date: ";
            cin >> date;
            cout << "Enter Month: ";
            cin >> month;
            cout << "Enter Year: ";
            cin >> year;
            printDateBill_preOrder(dsstaff.TREE, date, month, year, false);
            system("pause");
            break;
        case 2:
            for (int i = 0; i < 7; i++)
            {
                ltm->tm_mday = ltm->tm_mday - 1;
                mktime(ltm);
                year = 1900 + ltm->tm_year;
                month = 1 + ltm->tm_mon;
                date = ltm->tm_mday;
                printDateBill_preOrder(dsstaff.TREE, date, month, year, false);
            }
            ltm->tm_mday = ltm->tm_mday + 7;
            mktime(ltm);
            system("pause");
            break;
        case 3:
            cout << "Enter Month: ";
            cin >> month;
            cout << "Enter Year: ";
            cin >> year;
            printDateBill_preOrder(dsstaff.TREE, date, month, year, true);
            system("pause");
            break;
        case 0:
            key = false;
            break;

        default:
            break;
        }
        system("cls");
    }
}
void deleteBill(staff_tree dsstaff)
{
    string id;
    cout << "Enter Bill ID: ";
    cin >> id;
    deleteBill1(dsstaff.TREE, id);
}
void deleteBill1(staff *s, string id)
{
    if (s == NULL)
    {
        return;
    }
    deleteOneBill(s->dsbill.phead, id);
    deleteBill1(s->pleft, id);
    deleteBill1(s->pright, id);
}
void deleteOneBill(bill *&b, string id)
{
    bill *temp = b;
    if (temp == NULL)
    {
        return;
    }
    if (b->billID == id)
    {
        b = b->pnext;
        return;
    }
    if (temp->billID == id)
    {
        temp = temp->pnext;
        return;
    }
    while (temp->pnext->billID != id && temp != NULL)
    {
        temp = temp->pnext;
        cout << temp->billID << "-";
    }
    temp->pnext = temp->pnext->pnext;
    return;
}

void printDict()
{
    int one = 0;
    int two = 0;
    int three = 0;
    string best = "Unknown";
    string second = "Unknown";
    string third = "Unknown";
    for (auto it : myDictionary)
    {
        if (it.second > one)
        {
            one = it.second;
            best = it.first;
        }
    }
    myDictionary.erase(best);
    for (auto it : myDictionary)
    {
        if (it.second > two)
        {
            two = it.second;
            second = it.first;
        }
    }
    myDictionary.erase(second);
    for (auto it : myDictionary)
    {
        if (it.second > three)
        {
            three = it.second;
            third = it.first;
        }       
    }
    cout << "======================= BEST SELLER ==========================" << endl;
    printf("|%-30s%-22s%-5s%-3d|\n", "<<<[TOP 1]>>>", best.c_str(), "Sold:", one);
    cout << "--------------------------------------------------------------" << endl;
    printf("|%-30s%-22s%-5s%-3d|\n", "<<<[TOP 2]>>>", second.c_str(), "Sold:", two);
    cout << "--------------------------------------------------------------" << endl;
    printf("|%-30s%-22s%-5s%-3d|\n", "<<<[TOP 3]>>>", third.c_str(), "Sold:", three);
    cout << "==============================================================" << endl;
}
void findBest(staff *tree)
{
    if (tree == NULL)
    {
        return;
    }
    find(tree->dsbill.phead);
    findBest(tree->pleft);
    findBest(tree->pright);
}
void find(bill *list)
{
    bill *temp = list;
    while (temp != NULL)
    {
        search(temp);
        temp = temp->pnext;
    }
}
void search(bill *list)
{

    for (int i = 0; i < list->product_list.len; i++)
    {
        int count = 0;
        int same = 0;
        for (int j = 0; j < list->product_list.len; j++)
        {
            if (list->product_list.list[i]->bookName == list->product_list.list[j]->bookName)
            {
                count++;
            }
        }
        for (int j = 0; j < list->product_list.len; j++)
        {
            if (list->product_list.list[i]->bookName == list->product_list.list[j]->bookName)
            {
                same++;
                if (i == j && same == 1)
                {
                    // myDictionary.insert(pair<string, int>(list->product_list.list[i]->bookName, count));
                    myDictionary[list->product_list.list[i]->bookName] = count;
                }
            }
        }
    }
}
void printBestSeller()
{
    for (auto pair : myDictionary)
    {
        cout << pair.second << "-" << pair.first << endl;
    }
}
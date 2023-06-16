#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#define MAX 9999
//=================DANHSACH SANPHAM=========================
struct book
{
    string bookID;
    string bookName;
    string bookCategory;
    string author;
    int prices;
    bool status = false;
};
struct bookList // array of book
{
    struct book *list[MAX];
    int len = 0;
};

//=================DANHSACH HOADON=========================
struct bill // linked list
{
    string billID;
    int date;
    int month;
    int year;
    char category;
    int price;
    int VAT;
    struct bookList product_list;
    // pointer
    bill *pnext = NULL;
};
typedef struct bill BILL;
struct billList
{
    bill *phead = NULL;
    int len = 0;
};
typedef struct billList BILL_LIST;

//=================DANHSACH NHANVIEN=========================
struct staff // staff
{
    int staffID;
    string firstName;
    string lastName;
    string occupation;
    // pointer
    struct staff *pright = NULL;
    struct staff *pleft = NULL;
    BILL_LIST dsbill;
};
typedef struct staff *tree;
struct staff_tree // tree of staff
{
    tree TREE = NULL;
    int len = 0;
};
//======================== TIME HANDLE ========================
time_t now = time(0);
tm *ltm = localtime(&now);

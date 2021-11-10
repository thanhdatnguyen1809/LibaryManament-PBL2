#include "qlsv.h"
qlsv::qlsv()
{
    this->head = nullptr;
    this->tail = nullptr;
}
qlsv::~qlsv()
{
}
nodesv *create(const sv &s)
{
    nodesv *p = new nodesv;
    if (p == nullptr)
        exit(1);
    p->data = s;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}
bool qlsv::isEmpty()
{
    return this->head == nullptr;
}
void qlsv::addhead(const sv &s)
{
    nodesv *p = create(s);
    if (isEmpty())
        this->head = this->tail = p;
    else
    {
        p->next = this->head;
        this->head->prev = p;
        this->head = p;
    }
}
void qlsv::addtail(const sv &s)
{
    nodesv *p = create(s);
    if (isEmpty())
        addhead(s);
    else
    {
        this->tail->next = p;
        p->prev = this->tail;
        this->tail = p;
    }
}
void qlsv::show()
{
    nodesv *p = this->head;
    while (p != nullptr)
    {
        cout << "MSSV: " << p->data.getmssv() << endl;
        cout << "Ho va ten: " << p->data.getname() << endl;
        cout << "Lop: " << p->data.getclasss() << endl;
        cout << "Khoa: " << p->data.getfaculty() << endl;
        cout << "So dien thoai: " << p->data.getphonenumber() << endl;
        cout << "_______________________________________" << endl;
        p = p->next;
    }
}
void qlsv::searchid(const string &t)
{
    nodesv *p = this->head;
    int k = 0;
    while (p != nullptr)
    {
        if (p->data.getmssv() == t)
        {
            cout << "MSSV: " << p->data.getmssv() << endl;
            cout << "Ho va ten: " << p->data.getname() << endl;
            cout << "Lop: " << p->data.getclasss() << endl;
            cout << "Khoa: " << p->data.getfaculty() << endl;
            cout << "So dien thoai: " << p->data.getphonenumber() << endl;
            k++;
        }
        p = p->next;
    }
    if (k == 0)
    {
        cout << "Khong tim thay MSSV can tim! " << endl;
    }
}
void qlsv::searchname(const string &t)
{
    nodesv *p = this->head;
    int k = 0;
    while (p != nullptr)
    {
        if (t.compare(p->data.getfaculty()) == 0)
        {
            cout << "MSSV: " << p->data.getmssv() << endl;
            cout << "Ho va ten: " << p->data.getname() << endl;
            cout << "Lop: " << p->data.getclasss() << endl;
            cout << "Khoa: " << p->data.getfaculty() << endl;
            cout << "So dien thoai: " << p->data.getphonenumber() << endl;
            k++;
        }
        p = p->next;
    }
    if (k == 0)
    {
        cout << "Khong tim thay ten sinh vien can tim! " << endl;
    }
}
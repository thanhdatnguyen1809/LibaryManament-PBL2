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

    ofstream ofs("filexuatdanhsachsinhvien.txt");
    int k = 0;
    nodesv *p;
    for (p = this->head; p != nullptr; p = p->next)
    {
        if (p == head)
        {
            p->data.show();
            ofs << "***********************************************************************************************************" << endl;
            ofs << "*                                         DANH SACH SINH VIEN                                             *" << endl;
            ofs << "*                                                                                                         *" << endl;
            ofs << "***********************************************************************************************************" << endl;
            ofs << "MSSV: " << p->data.getmssv() << endl;
            ofs << "Ho Va Ten: " << p->data.getname() << endl;
        }
        else
        {
            cout << "_______________________________________" << endl;
            cout << "MSSV: " << p->data.getmssv() << endl;
            cout << "Ho va ten: " << p->data.getname() << endl;

            ofs << "_______________________________________" << endl;
            ofs << "MSSV: " << p->data.getmssv() << endl;
            ofs << "Ho va ten: " << p->data.getname() << endl;
        }
        k++;
    }
    delete p;
    cout << "*********************************************";
    cout << "*      Tong so sinh vien la :" << k << "     *";
    cout << "*********************************************" << endl;

    ofs << "*********************************************";
    ofs << "*      Tong so sinh vien la :" << k << "     *";
    ofs << "*********************************************" << endl;
    ofs.close();
}
void qlsv::Delete(const int &s)
{
    nodesv *p = this->head;
    int k = 0;
    while (p != nullptr)
    {
        if (this->head->data.getmssv() == s)
        {
            this->head = this->head->next;
            k++;
            break;
        }
        else if ((this->tail->data.getmssv() == s) && (p->data.getmssv() == s))
        {
            this->tail = p->prev;
            p->prev->next = nullptr;
            k++;
            break;
        }
        else if (p->data.getmssv() == s)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            k++;
            break;
        }
        p = p->next;
    }
    if (k == 1)
    {
        cout << "Xoa thanh cong sinh vien: " << endl;
        cout << "_______________________________________" << endl;
        cout << "MSSV: " << p->data.getmssv() << endl;
        cout << "Ho va ten: " << p->data.getname() << endl;
        cout << "Lop: " << p->data.getclasss() << endl;
        cout << "Khoa: " << p->data.getfaculty() << endl;
        cout << "So dien thoai: " << p->data.getphonenumber() << endl;
        cout << "_______________________________________" << endl;
    }
    else if (k == 0)
    {
        cout << "Khong tim thay ma so sinh vien can xoa" << endl;
    }
}
void qlsv::searchid(const int &t)
{
    nodesv *p = this->head;
    int k = 0;
    while (p != nullptr)
    {
        if (p->data.getmssv() == t)
        {
            cout << "_______________________________________" << endl;
            cout << "MSSV: " << p->data.getmssv() << endl;
            cout << "Ho va ten: " << p->data.getname() << endl;
            cout << "Lop: " << p->data.getclasss() << endl;
            cout << "Khoa: " << p->data.getfaculty() << endl;
            cout << "So dien thoai: " << p->data.getphonenumber() << endl;
            cout << "_______________________________________" << endl;
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
        if (p->data.getname() == t)
        {
            cout << "_______________________________________" << endl;
            cout << "MSSV: " << p->data.getmssv() << endl;
            cout << "Ho va ten: " << p->data.getname() << endl;
            cout << "Lop: " << p->data.getclasss() << endl;
            cout << "Khoa: " << p->data.getfaculty() << endl;
            cout << "So dien thoai: " << p->data.getphonenumber() << endl;
            cout << "_______________________________________" << endl;
            k++;
        }
        p = p->next;
    }
    if (k == 0)
    {
        cout << "Khong tim thay ten sinh vien can tim! " << endl;
    }
}

nodesv *qlsv::searchName(const string &k)
{
    nodesv *p = this->head;
    while (p != NULL)
    {
        if (p->data.getname() == k)
            return p;
        else
            p = p->next;
    }
    return NULL;
}
nodesv *qlsv::searchID(const int &id)
{
    nodesv *p = this->head;
    while (p != NULL)
    {
        if (p->data.getmssv() == id)
            return p;
        else
            p = p->next;
    }
    return NULL;
}

bool qlsv::checkMssv(const int &id)
{
    if (this->searchID(id) != NULL)
        return true;
    return false;
}

bool qlsv::checkNamesv(const string &name)
{
    if (this->searchName(name) != NULL)
        return true;
    return false;
}

bool qlsv::checkNameAndMssv(const int &id, const string &name)
{
    nodesv *check = this->searchID(id);
    if (check != NULL)
    {
        if (check->data.getname() == name)
            return true;
    }

    return false;
}
int qlsv::tongsosach(const int &id)
{
    nodesv *p = this->searchID(id);
    p->data.settongsachmuon(p->data.gettongsachmuon() + 1);
    return p->data.gettongsachmuon();
}
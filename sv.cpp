#include "sv.h"
sv::sv()
{
this->tongsachmuon=0;
}
sv::sv(const int &mssv, const string &name, const string &classs, const string &faculty, const string &phonenumber) : tongsachmuon(-2)
{
    this->mssv = mssv;
    this->name = name;
    this->classs = classs;
    this->faculty = faculty;
    this->phonenumber;
}
sv::~sv()
{
}
void sv::show()
{
 
    cout << "***********************************************************************************************************" << endl;
    cout << "*                                         DANH SACH SINH VIEN                                             *" << endl;
    cout << "*                                                                                                         *" << endl;
    cout << "***********************************************************************************************************" << endl;
    cout << "MSSV: " << this->mssv << endl;
    cout << "Ho Va Ten: " << this->name << endl;
}
int sv::getmssv()
{
    return this->mssv;
}
void sv::setmssv(const int &mssv)
{
    this->mssv = mssv;
}
string sv::getname()
{
    return this->name;
}
void sv::setname(const string &name)
{
    this->name = name;
}
string sv::getclasss()
{
    return this->classs;
}
void sv::setclasss(const string &classs)
{
    this->classs = classs;
}
string sv::getfaculty()
{
    return this->faculty;
}
void sv::setfaculty(const string &faculty)
{
    this->faculty = faculty;
}
string sv::getphonenumber()
{
    return this->phonenumber;
}
void sv::setphonenumber(const string &phonenumber)
{
    this->phonenumber = phonenumber;
}
int sv::gettongsachmuon()
{
    return this->tongsachmuon;
}
void sv::settongsachmuon(const int &s)
{
    this->tongsachmuon = s;
}
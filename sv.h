#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class sv
{
private:
    int mssv;
    string name;
    string classs;
    string faculty;
    string phonenumber;
    int tongsachmuon;

public:
    sv();
    sv(const int &, const string &, const string &, const string &, const string &);
    ~sv();
    void show();
    int getmssv();
    void setmssv(const int &);
    string getname();
    void setname(const string &);
    string getclasss();
    void setclasss(const string &);
    string getfaculty();
    void setfaculty(const string &);
    string getphonenumber();
    void setphonenumber(const string &);
    int gettongsachmuon();
    void settongsachmuon(const int &);
};

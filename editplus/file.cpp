//
// Created by bozhi on 2024/1/7.
//

#include "file.h"

//string_1类
string_1::string_1():string(){};
string_1::string_1(const char* a):string(a)
    {
    };
string_1::string_1(const string& a): string(a)
    {
    };
string_1::string_1(const string_1& a):string(a)
    {
    };
string_1::string_1(const char& a):string(1,a)
    {
    };

void string_1::operator=(const string_1& str)
{
    this->string::operator=(str);
};
void string_1::operator=(const char& str)
{
    char a[2];
    a[0]=str;
    char* d=a;
    this->operator=(d);
};
bool string_1::operator==(const char& a)
{
    if(this->size()==1)
    {
        if(this->find(a)==0)
        {
            return true;
        }else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
};
bool string_1::operator==(const char* a)
{
    int a_size=0;
    for(int i=0;a[i]!='\0';++i)
    {
        ++a_size;
    }
    if(this->size()!=a_size)
    {
        return false;
    }
    for(int i=0;i<this->size();++i)
    {
        if(this->operator[](i)!=a[i])
        {
            return false;
        }
    }
    return true;
};
bool string_1::operator==(const string& a)
{
    if(this->size()!=a.size())
    {
        return false;
    }
    for(int i=0;i<this->size();++i)
    {
        if(this->operator[](i)!=a[i])
        {
            return false;
        }
    }
    return true;
};
bool string_1::operator!=(const char& a)
{
    return !(this->operator==(a));
};
bool string_1::operator!=(const char* a)
{
    return !(this->operator==(a));
};
bool string_1::operator!=(const string& a)
{
    return !(this->operator==(a));
};


//file类
file::file(const string& address1, const string& mode1):address(address1),mode(mode1)
{
    if(mode=='w'||mode=="w")
    {
        f.open(address, ios::out);
    }
    else if(mode=='a'||mode=="a")
    {
        f.open(address,ios::app);
    }
    else if(mode=='r'||mode=="r")
    {
        f.open(address,ios::in);
    }
    else if(mode=="br")
    {
        f.open(address,ios::binary|ios::in);
    }
    else if(mode=="bw")
    {
        f.open(address,ios::binary|ios::out);
    }
    else if(mode=="ba")
    {
        f.open(address,ios::binary|ios::app);
    }
    else if(mode=="ar")
    {
        f.open(address,ios::in|ios::out);
    }
    else
    {
        cout<<"输入模式不正确"<<endl;
        abort();
    }

    if(f.is_open()== false)
    {
        cout << "打开文件" << address << "失败。\n";
        abort();
    }

};
file::file(const string& address1, const char& mode1):address(address1),mode(mode1)
{
    if(mode=='w'||mode=="w")
    {
        f.open(address, ios::out);
    }
    else if(mode=='a'||mode=="a")
    {
        f.open(address,ios::app);
    }
    else if(mode=='r'||mode=="r")
    {
        f.open(address,ios::in);
    }
    else if(mode=="br")
    {
        f.open(address,ios::binary|ios::in);
    }
    else if(mode=="bw")
    {
        f.open(address,ios::binary|ios::out);
    }
    else if(mode=="ba")
    {
        f.open(address,ios::binary|ios::app);
    }
    else if(mode=="ar")
    {
        f.open(address,ios::in|ios::out);
    }
    else
    {
        cout<<"输入模式不正确"<<endl;
        abort();
    }

    if(f.is_open()== false)
    {
        cout << "打开文件" << address << "失败。\n";
        abort();
    }

};
file::~file()
{
    f.close();
    cout<<"guanbi";
};

void file::write(const string& content)
{
    if(mode!="w"&&mode!="a"&&mode!='a'&&mode!='w'&&mode!="bw"&&mode!="ba"&&mode!="ar")
    {
        cout<<"文件对象没有设置可写属性"<<endl;
        abort();
    }
    f<<content.c_str();
};
string file::read()
{
    if(mode!="r"&&mode!='r'&&mode!="br"&&mode!="ar")
    {
        cout<<"文件对象没有设置可读属性"<<endl;
        abort();
    }

    string buffer;
    string content;
    while(f>>buffer)
    {
        content+=buffer;
    }
    return content;
};
string file::getline()
{
    if(mode!="r"&&mode!='r'&&mode!="br"&&mode!="ar")
    {
        cout<<"文件对象没有设置可读属性"<<endl;
        abort();
    }
    string buffer;
    f>>buffer;
    return buffer;
};



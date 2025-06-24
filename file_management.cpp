#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<conio.h>
using namespace std;
fstream file1,file2;
class Book
{
    protected:
    int bid,price;
    string name;
    public:
    void menu();
};
class Bookinfo: public Book{
    public:  
void getinfo();
void putinfo();
void writedata();
void readdata();
void appenddata();
};
Bookinfo bk;
void Bookinfo::getinfo()
{
    cout<<"\n\t\tEnter Book ID: ";
    cin>>bid;
    cout<<"\n\t\tEnter Book Name: ";
    cin>>name;
    cout<<"\n\t\tEnter Book price: ";
    cin>>price;
}
void Bookinfo::putinfo()
{
  cout<<setw(28)<<bid;
  cout<<setw(28)<<name;
  cout<<setw(28)<<price<<endl;
}
void Bookinfo::writedata()
{
    
    file1.open("Book.txt",ios::out|ios::binary);
        bk.getinfo();
        file1.write((char *)&bk,sizeof(bk));
        file1.close();
        menu();
}
void Bookinfo::readdata()
{
    file1.open("Book.txt",ios::in | ios::binary);
    if(!file1)
    {
        cout<<"\n\tFile not exist";
        exit(0);

    }
    else{
        file1.read((char *)&bk,sizeof(bk));
        while(!file1.eof())
    {
           bk.putinfo();
           file1.read((char *)&bk,sizeof(bk));

    }
    }
    file1.close();
    menu();
}
void Bookinfo::appenddata()
{

    char ch='y';
    file1.open("Book.txt",ios::app | ios::binary);
    while(ch=='y' || ch=='Y')
    {
        bk.getinfo();
        file1.write((char*)&bk,sizeof(bk));
        cout<<"\n\t\t\t\t If you Want to add another Book information press...(Y/N)";
        cin>>ch;
    }
    file1.close();
    menu();
}
void Book::menu()
{
    Bookinfo E3;
    int choice;
    cout<<"\n\t\t\tTask 1";
    cout<<"\n\t\t----:File Operation Menu:----";
    cout<<"\n\t\tEnter your operation which you want to perform";
    cout<<"\n\t\t1.Write data into the file";
    cout<<"\n\t\t2.Append data to the file";
    cout<<"\n\t\t3.Read data  from the file";
    cout<<"\n\t\tEnter Your choice ";
    cin>>choice;
    switch(choice)
    {
        system("cls");
        case 1:E3.writedata();
               break;
        case 2:E3.appenddata();
               break;
        case 3:
        cout<<"\n\t\t\t--------------------------------------------------------------"<<endl;
        cout<<setw(30)<<"BookId"<<setw(28)<<"BookName"<<setw(28)<<"BookPice"<<endl;
        cout<<"\n\t\t\t-------------------------------------------------------------"<<endl;
        E3.readdata();
               break;
        default:cout<<"\n Enter only 1,2,3 and if u want to exit enter 4";                     
    }
}
int main()
{
    Book E1;
    E1.menu();
    return 0;
}

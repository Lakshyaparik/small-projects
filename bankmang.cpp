#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<time.h>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;

class bank
{
    int account;
    string name;
    int age;
    char address[50];
    long int amount=0;
    public:
    void createaccount();
    void accountinfo();
    void deposit();
    void withdraw();
    void deleteacc();
    void menu();
};
void bank::menu()
{   int choice;
    while(choice!=6)
    {
    cout<<"\n\t\t\t\t-------BANK MANANGEMENT SYSTEM--------";
    cout<<"\n\t\t\t\t1 : CREATE NEW ACCOUNT               *";
    cout<<"\n\t\t\t\t2 : ACCOUNT INFORMATION              *";
    cout<<"\n\t\t\t\t3 : DEPOSIT MONEY                    *";
    cout<<"\n\t\t\t\t4 : WITHDRAW MONEY                   *";
    cout<<"\n\t\t\t\t5 : DELETE ACCOUNT                   *";
    cout<<"\n\t\t\t\t6 : EXIT                             *";
    cout<<"\n\t\t\t\t--------------------------------------";
    cout<<"\n ENTER YOUR CHOICE :";
    cin>>choice;
    if(choice==1 || choice==2 || choice==3 || choice==4 || choice==5 || choice==6)
    {
    switch (choice)
    {
        case 1: createaccount();
                break;
        case 2: accountinfo();
                break;
        case 3: deposit();
                break;
        case 4: withdraw();
                break;
        case 5: deleteacc();
                break;
        case 6: exit(0);
        
        default: cout<<"\n INVALID CHOICE";
    }
    }
    else
    cout<<"CHOOSE ONLY 1 TO 6 CHOICE";
    }
}
void bank::createaccount()
{   system("cls");
    srand(time(0));
    account=rand()*rand()+rand();
    cin.ignore(256, '\n');
    cout<<"\n\t\tEnter your name    : ";
    getline(cin, name);
    cout<<"\n\t\tYOUR ACCOUNT NUMBER IS READY :"<<account;
    cout<<"\n\t\tEnter your age     : ";
    cin>>age;
    cout<<"\n\t\tEnter your address : ";
    cin>>address;
    fstream file;
    file.open("c://studentdata//bank.txt",ios::out|ios::app);
    file<<account<<"\t"<<name<<"\t"<<age<<"\t"<<address<<"\t"<<amount<<endl;
    file.close();
}
void bank::accountinfo()
{  
    fstream file;
    int search;
    cout<<"\nENTER YOUR ACCOUNT NUMBER : ";
    cin>>search;
    file.open("c://studentdata//bank.txt",ios::in);
    if(!file)
    cout<<"\nfile openening error";
    file>>account>>name>>age>>address>>amount;
    while (!file.eof())
    {
        if(search==account)
        {
        cout<<"\nACCOUNT NO :"<<account<<"\nNAME :"<<name<<"\nAGE :"<<age<<"\nADDRESS :"<<address<<"\nAMOUNT"<<amount<<"\n\n";
        break;
        }
        else
        file>>account>>name>>age>>address>>amount;
    }
    file.close();
}
void bank::deposit()
{  
   int tempacc,newamount;
   cout<<"\n\t\tENTER YOUR ACCOUNT NUMBER : ";
   cin>>tempacc;
   abc :cout<<"\n\t\tENTER THE AMOUNT OF DEPOSIT : ";
   cin>>newamount;
   if(newamount<1)
   {
    cout<<"\n\t\tINVALID AMOUNT";
    goto abc;
   }
   fstream file("c://studentdata//bank.txt",ios::in);
   fstream file1("c://studentdata//bank1.txt",ios::out);
   if(file.is_open())
   {
    file>>account>>name>>age>>address>>amount;
      while (!file.eof())
            { 
              if(tempacc==account)  
              {
                cout<<"\n\t\tPREVIOUS AMOUNT : "<<amount;
                amount=amount+newamount;
                cout<<"\n\t\tCURRENT AMOUNT : "<<amount;
                file1<<account<<"\t"<<name<<"\t"<<age<<"\t"<<address<<"\t"<<amount<<endl;
              }
              else
              {
              file1<<account<<"\t"<<name<<"\t"<<age<<"\t"<<address<<"\t"<<amount<<endl;
              }
              file>>account>>name>>age>>address>>amount;
            }
    file.close();
    file1.close();
    remove("c://studentdata//bank.txt");
    int x=rename("c://studentdata//bank1.txt","c://studentdata//bank.txt");
    if(x==0)
    cout<<"\n\t\tPROCESS DONE";
    else
    cout<<"\n\t\tSOME ISSUE";
   }
   else
   cout<<"\n\t\tFILE ERROR";
   
}
void bank::withdraw()
{
    int wid=0,tempacc=0;
    cout<<"\n\t\tENTER YOUR ACCOUNT NUMBER : ";
    cin>>tempacc;
    fstream file("c://studentdata//bank.txt",ios::in);
    fstream file1("c://studentdata//bank1.txt",ios::out);
    if(file.is_open())
    {
       file>>account>>name>>age>>address>>amount;
       while (!file1.eof())
       {
          if(tempacc==account)
          {
            cout<<"\n\t\tYOUR CURRENT AMOUNT : "<<amount;
    abc :   cout<<"\n\t\tENTER AMOUNT FOR WITHDRAW : ";
            cin>>wid;
            if(wid<1 || wid>amount)
            {   cout<<"\n\t\tINVALID AMOUNT";
                goto abc;
            }
            amount=amount-wid;
            cout<<"\n\t\tYOUR UPDATED AMOUNT : "<<amount;
            file1<<account<<"\t"<<name<<"\t"<<age<<"\t"<<address<<"\t"<<amount<<endl;
            break;
          }
          else
          {
            file1<<account<<"\t"<<name<<"\t"<<age<<"\t"<<address<<"\t"<<amount<<endl;
          }
          file>>account>>name>>age>>address>>amount;
       }
       
       file.close();
       file1.close();
       remove("c://studentdata//bank.txt");
       int x=rename("c://studentdata//bank1.txt","c://studentdata//bank.txt");
       if(x==0)
       cout<<"\n\t\tPROCESS DONE!";
       else
       cout<<"\n\t\tSOME ISSUE";
    }
    else
    {
        cout<<"\n\t\tFILE OPENING ERROR";
    }
}
void bank::deleteacc()
{  
   int tempacc;
   char c;
   cout<<"\n\t\tARE YOU SURE WANNA DELETE ACCOUNT : ";
   cout<<"\n\t\tPRESS Y/yTO CONFIRM AND CANCEL FOR ANY KEY : ";
   cin>>c;
   if(c=='Y' or c=='y')
   {
    cout<<"\n\t\tENTER YOUR ACCOUNT NUMBER : ";
    cin>>tempacc;
    fstream file("c://studentdata//bank.txt",ios::in);
    fstream file1("c://studentdata//bank1.txt",ios::out);
    if(file.is_open())
      {
        file>>account>>name>>age>>address>>amount;
        while (!file.eof())
        {
            if(tempacc==account)
            {
                cout<<"\n\t\tYOUR ACCOUNT HAS BEED DELETED : ";
                break;
            }
            else
            {
                file1<<account<<"\t"<<name<<"\t"<<age<<"\t"<<address<<"\t"<<amount<<endl;
            }
                file>>account>>name>>age>>address>>amount;
        }
           file.close();
           file1.close();
           remove("c://studentdata//bank.txt");
           int x=rename("c://studentdata//bank1.txt","c://studentdata//bank.txt");
           if(x==0)
           cout<<"\n\t\tPROCESS DONE";
           else
           cout<<"\n\t\tSOME ISSUE";
        }
    }
   else
   return;
}
int main()
{   bank s;
    s.menu();  
}


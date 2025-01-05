//student data managment
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
#define max 5
class student
{   fstream file;
    int rollno;
    char name[20];
    char course[20];
    int totalstudent=0;
    public:

    void addstudent();//method
    void display();   //display
    void update();  //update
    void clear();//clear
};
student s[max];
int main()
{ 
    int choice;
    system("cls");
    do
    {
    cout<<"\n-------STUDENT DATA MANANGEMENT-------";
    cout<<"\n1 : ADD STUDENT";
    cout<<"\n2 : UPDATE DETAIL";
    cout<<"\n3 : DISPLAY DATA";
    cout<<"\n4 : DELETE DATA";
    cout<<"\n5 : EXIT";
    cout<<"\n--------------------------------------";
    cout<<"\n ENTER YOUR CHOICE :";
    cin>>choice;
    switch (choice)
    {
        case 1: s->addstudent();
                break;
        case 2: s->update();
                break;
        case 3: s->display();
                break;
        case 4: s->clear();
                break;
        case 5: exit(0);
        default: cout<<"\n INVALID CHOICE";
    }
    }while(choice!=5);
}
 void student::addstudent()
{   if(totalstudent>max)
     {
        cout<<"\n SEAT IS FULL";
     }
    else
    cout<<"\n ENTER ROLL NO :";
    cin>>s[totalstudent].rollno;
    cout<<" ENTER STUDENT NAME :";
    cin>>s[totalstudent].name;
    cout<<" ENTER COURSE NAME :";
    cin>>s[totalstudent].course;
    file.open("c://studentdata//student.txt",ios::app);
    if(file.is_open())
    {   file<<s->totalstudent<<" ";
        file<<s[totalstudent].rollno<<" ";
        file<<s[totalstudent].name<<" ";
        file<<s[totalstudent].course<<" ";
        totalstudent++;
        file.close();
    }
    else
    cout<<"\nFILE ERROR";
}
 void student::display() //display
 {   
       student temp[max];
       file.open("c://studentdata//student.txt",ios::in);
       if(file.is_open())

       {  
        while (!file.eof())
        {
           file>>temp[totalstudent].totalstudent;
           file>>temp[totalstudent].rollno;
           file>>temp[totalstudent].name;
           file>>temp[totalstudent].course;
           totalstudent++;
        }
        file.close();
       for(int i=0;i<totalstudent--;i++)
       {
       cout<<"\nROLL NO :"<<temp[i].rollno;
       cout<<"\tNAME :"<<temp[i].name;
       cout<<"\tCOURSE :"<<temp[i].course<<"\n";
       }
       } 
       else
       cout<<"\nFILE ERROR";
       

}
void student::update()  //update
{   int roll;
    cout<<"\ns[i].rollno :"<<s[1].rollno;
    cout<<"\nENTER ROLL NUMBER OF STUDENT YOU WANT UPDATE :";
    cin>>roll;
    int flag=-1;
    for(int i=0;i<totalstudent--;i++)
    {   
        if(s[i].rollno== roll)
        {
            flag++;
            break;
        }
        else
        {
        cout<<"\nROLL NUMBER IS INVALID";
        return;
        }
    }
    cout<<"\nENTER NEW DETAILS";
            cout<<"\nENTER ROLL NUMBER :";
            cin>>s[flag].rollno;
            cout<<"ENTER STUDENT NAME :";
            cin>>s[flag].name;
            cout<<"ENTER COURSE NAME :";
            cin>>s[flag].course;
}
void student::clear()
{
   char c;
   cout<<"\n ARE YOU SURE TO DELETE ALL DATA";
   cout<<"\nIF YES PRESS Y else other key :";
   cin>>c;
   if(c=='y' || c=='Y')
   totalstudent=0;
   else
   return;
}

//Students data project with file stream
#include<iostream>
#include<fstream>
#include<conio.h>
#include<process.h>
#include<stdio.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////-----Class-----\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class Student
{
 int rollno;
 char name[80];
 int Class;
 int marks;
 char grade;
 char project[80];
 public:2
 void getdata();
 void display();
 int getmarks() {return marks;}
 int getno() {return rollno;}
 int getClass() {return Class;}
}s;

void Student::getdata()
{
 cout<<"Enter Roll No.       : ";
 cin>>rollno;
 cout<<"Enter Name           : "<<endl;
 fflush(stdin);
 cin.getline(name,80);
 cout<<"Enter Class          : ";
 cin>>Class;
 cout<<"Enter the Project    : "<<endl;
 fflush(stdin);
 cin.getline(project,80);
 cout<<"Enter Marks          : ";
 cin>>marks;
      if(marks>=75) grade='A';
 else if(marks>=60) grade='B';
 else if(marks>=50) grade='C';
 else if(marks>=35) grade='D';
 else grade='F';
}
void Student::display()
{
 cout<<"=================================================\n";
 cout<<"Roll No. : "<<rollno<<"\n";
 cout<<"Name     : "<<name<<"\n";
 cout<<"Class    : "<<Class<<"\n";
 cout<<"Marks    : "<<marks<<"\n";
 cout<<"Grade    : "<<grade<<"\n";
 cout<<"Project  : "<<project<<"\n";
// cout<<"=================================================\n";
}

//Prototyping of functions for menu

void menu();
void search();
void add();
void displayall();
void Classwise();
void Modify();
void Delete();

///////////////////////////////////////////////////////////////////////////////////-----Main-----\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

int main()
{
 int n,rno,i;
 fstream fio("Student.txt",ios::in|ios::out);
 cout<<"Enter the ID  :";
 long long int ID;
 string password;
 long long int id = 20210020319;
 cin>>ID;
 if(ID != id ){
  cout<<"incorrect";
 }
 else{
  cout<< "Password   :";
  cin>>password;
  if(password == "123456"){
    menu();
  }
  else{
    cout<<"incorrect";
  }
  
 }
 
// fio.close();
 getch();
 return 0;
}

///////////////////////////////////////////////////////////////////////////////////-----Option-----\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void options()
{
 cout<<"\n\t...MENU OF PROGRAM...\n";
 cout<<"\t0. EXIT....\n";
 cout<<"\t1. Add the record...\n";
 cout<<"\t2. Search the record...\n";
 cout<<"\t3. Display all records...\n";
 cout<<"\t4. Class wise records...\n";
 cout<<"\t5. Modify the Record...\n";
 cout<<"\nEnter Your Choice     : ";
}

///////////////////////////////////////////////////////////////////////////////////-----Menu-----\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void menu()
{
 int ch;
 options();
 cin>>ch;
 while(ch)
 {
   switch(ch)
   {
  case 1: add(); break;
  case 2: search(); break;
  case 3: displayall(); break;
  case 4: Classwise(); break;
  case 5: Modify(); break;
  default: cout<<"Wrong Input please enter the correct value....";
   }
   system("pause");
   options();
   cin>>ch;
 }
}

///////////////////////////////////////////////////////////////////////////////////-----Search-----\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void search()
{
 ifstream fin("Student.txt",ios::in);
 int rno,i=0;
 char found='n';
 cout<<"\nEnter Roll No. to be searched : ";
 cin>>rno;

 while(fin.read((char*)&s,sizeof(s)))
 {
  if(s.getno()==rno)
  {
   s.display();
   found='y';
  }
  i++;
 }
 if(found=='n') cout<<"\nThe Roll No. "<<rno<<" is not in the file...\n";
 fin.close();
}

///////////////////////////////////////////////////////////////////////////////////-----Display-----\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

//For Displaying the all data of the students.

void displayall()
{
 ifstream fin("Student.txt",ios::in);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.display();
 }
 fin.close();
}

///////////////////////////////////////////////////////////////////////////////////-----Add-----\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

//For adding the data into the file.

void add()
{
 char ch='y';
 ofstream fout("Student.txt",ios::out|ios::app);
 while(ch=='y'||ch=='Y')
 {
  s.getdata();
  fout.write((char*)&s,sizeof(s));
  cout<<"\nDo you want to add more(Y/N) : ";
  cin>>ch;
 }
 cout<<"\nData Appended and Transferred to file...\n";
 fout.close();
}

///////////////////////////////////////////////////////////////////////////////////-----Class Wise-----\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void Classwise()
{
 ifstream fin("Student.txt",ios::in);
 int std;
 char found='n';
 cout<<"\nEnter the class to be searched : ";
 cin>>std;

 while(fin.read((char*)&s,sizeof(s)))
 {
  if(s.getClass()==std)
  {
   s.display();
   found='y';
  }
 }
 if(found=='n') cout<<"\nThe Class "<<std<<" is not in the file...\n";
 fin.close();
}

///////////////////////////////////////////////////////////////////////////////////-----Modify-----\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void Modify()
{
 fstream fio("Student.txt",ios::in|ios::out);
 int rno;
 char found='n';
 fio.seekg(0);
 cout<<"\nEnter the Roll No. whose record is to be modified: ";
 cin>>rno;

 while(fio)
 {
   int loc=fio.tellg();
   fio.read((char*)&s,sizeof(s));
//   fio.read((char*)&s,sizeof(s));
   if(s.getno()==rno)
   {
  s.getdata();
  found='y';
  fio.seekg(loc);
  fio.write((char*)&s,sizeof(s));
  cout<<"\nYour record of Roll No. "<<rno
      <<" has been updated....";
   }
 }
 if(found=='n') cout<<"\nThe Class "<<rno<<" is not in the file...\n";
 fio.close();
}
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Decimal.h"
#include "Convert.h"
using namespace std;

enum Bases{binary=2,octal=8,hexadecimal=16,decimal=10}base1,base2,base3;
Bases check();
int main()
{
	int i;
	Decimal *d1=new Decimal();
	Decimal *d2=new Decimal();
	ofstream file1;
	ifstream file;
	string frst,scnd,res,a,b,line;
	do
	{
		cout<<"\n"<<"Enter the operation you want to perform:"<<"\n";
		cout<<"Press 1 for addition"<<"\n";
		cout<<"Press 2 for subtraction"<<"\n";
		cout<<"Press 3 for multiplication"<<"\n";
		cout<<"Press 4 for division"<<"\n";
		cout<<"Press 5 for checking history"<<"\n";
		cout<<"Press 6 for clearing history\n";
		cout<<"Press 7 for exit"<<"\n";
		cout<<"ENTER YOUR CHOICE:\n";
		cin>>i;
		switch(i)
		{
			case 1:
			case 2:
			case 3:
			case 4: cout<<"\nFOR FIRST NUMBER\n";
				base1=check();
				cout<<"\nEnter your first number\n";
				cin>>frst;
				cout<<"\nFOR SECOND NUMBER\n";
				base2=check();
				cout<<"\nEnter your second number\n";
				cin>>scnd;
				cout<<"\nFOR GETTING RESULT\n";
				base3=check();
				a=frst;
				b=scnd;
				file1.open("History.txt",ios::app);
				if(base1!=10)
				{
					Systm *c=new Convert(frst,base1);
					frst=c->ConverttoDecimal();
				}
				if(base2!=10)
				{
					Systm *c=new Convert(scnd,base2);
					scnd=c->ConverttoDecimal();
				}
				d1->accept(frst);
				d2->accept(scnd);
				if(i==1)
				{
					res=*d1+*d2;
					file1<<a<<"("<<base1<<")+"<<b<<"("<<base2<<")=";
				}
				else if(i==2)
				{
					res=*d1-*d2;
					file1<<a<<"("<<base1<<")-"<<b<<"("<<base2<<")=";
				}
				else if(i==3)
				{
					res=(*d1)*(*d2);
					file1<<a<<"("<<base1<<")*"<<b<<"("<<base2<<")=";
				}
				else
				{
					res=(*d1)/(*d2);
					file1<<a<<"("<<base1<<")/"<<b<<"("<<base2<<")=";
				}
				if(base3!=10)
				{
					Systm *c=new Convert(res,base3);
					res=c->ConvertfromDecimal();
				}
				file1<<res<<"("<<base3<<")"<<endl;
				cout<<res<<"("<<base3<<")\n";
				file1.close();
				break;

			case 5: file.open("History.txt");
				cout<<"\nHISTORY OF OPERATIONS:\n";
    				while(getline(file, line))
       					cout << line << endl;
    				file.close();
				break;

			case 6: file1.open("History.txt");
				file1.close();
				cout<<"\nDELETED HISTORY\n";
				break;

			case 7:break;

			default:cout<<"Wrong input entered.Enter between 1 to 6.";
		}
	}while(i!=7);
	cout<<"TERMINATED\n";
	return 0;
}
	
Bases check()
{
	int a;
	cout<<"\nPress 1 for entering in binary\n";
	cout<<"Press 2 for entering in octal\n";
	cout<<"Press 3 for entering in hexadecimal\n";
	cout<<"Press 4 for entering in decimal\n";
	cout<<"ENTER YOUR CHOICE:\n";
	cin>>a;
	if(a==1)
		return binary;
	if(a==2)
		return octal;
	if(a==3)
		return hexadecimal;
	if(a==4)
		return decimal;
	cout<<"Wrong input..Terminating";
	exit(1);
}

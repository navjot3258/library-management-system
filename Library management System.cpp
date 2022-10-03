//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>
#include<graphics.h>
#include<dos.h>

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************



class book
{
	char bno[6];
	char bname[50];
	char aname[20];
  public:
	void create_book()
	{      setbkcolor(BLUE);
	     //	clrscr();
//	int gdriver=DETECT,gmode,i;
//	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");


		outtextxy(10,10,"NEW BOOK ENTRY...");
		cout<<"\n\nEnter The book no.";
		cin>>bno;
		cout<<"\n\nEnter The Name of The Book ";
		gets(bname);
		cout<<"\n\nEnter The Author's Name ";
		gets(aname);
		cout<<"\n\n\nBook Created..";

	}

	void show_book()
	{

  //	int gdriver=DETECT,gmode,i;
//	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(YELLOW);
		cout<<"\nBook no. : "<<bno;
		cout<<"\nBook Name : ";
		puts(bname);
		cout<<"Author Name : ";
		puts(aname);
	}

	void modify_book()
	{
    //		clrscr();
  //	int gdriver=DETECT,gmode,i;
  //	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);
		cout<<"\nBook no. : "<<bno;
		cout<<"\nModify Book Name : ";
		gets(bname);
		cout<<"\nModify Author's Name of Book : ";
		gets(aname);
	}

	char* retbno()
	{
		return bno;
	}

	void report()
	{cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;}


};         //class ends here




class student
{
	char admno[6];
	char name[20];
	char stbno[6];
	int token;
public:
	void create_student()
	{


  //	int gdriver=DETECT,gmode,i;
 //	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);
		cout<<"\nNEW STUDENT ENTRY...\n";
		cout<<"\nEnter The admission no. ";
		cin>>admno;
		cout<<"\n\nEnter The Name of The Student ";
		gets(name);
		token=0;
		stbno[0]='/0';
		cout<<"\n\nStudent Record Created..";
	}

	void show_student()
	{

   //	int gdriver=DETECT,gmode,i;
   //	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);
		cout<<"\nAdmission no. : "<<admno;
		cout<<"\nStudent Name : ";
		puts(name);
		cout<<"\nNo of Book issued : "<<token;
		if(token==1)
			cout<<"\nBook No "<<stbno;
	}

	void modify_student()
	{
    //		clrscr();
   //	int gdriver=DETECT,gmode,i;
   //	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);
		cout<<"\nAdmission no. : "<<admno;
		cout<<"\nModify Student Name : ";
		gets(name);
	}

	char* retadmno()
	{
		return admno;
	}

	char* retstbno()
	{
		return stbno;
	}

	int rettoken()
	{
		return token;
	}

	void addtoken()
	{token=1;}

	void resettoken()
	{token=0;}

	void getstbno(char t[])
	{
		strcpy(stbno,t);
	}

	void report()
	{

    //	int gdriver=DETECT,gmode,i;
   //	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<token<<endl;}

};         //class ends here




//***************************************************************
//    	global declaration for stream object, object
//****************************************************************

fstream fp,fp1;
book bk;
student st;

//***************************************************************
//    	function to write in file
//****************************************************************

void write_book()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app);
	do
	{
			clrscr();
	int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);

		bk.create_book();
		fp.write((char*)&bk,sizeof(book));
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}

void write_student()
{

	char ch;
	fp.open("student.dat",ios::out|ios::app);
	do
	{
		clrscr();
	int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);
		st.create_student();
		fp.write((char*)&st,sizeof(student));
		cout<<"\n\ndo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}


//***************************************************************
//    	function to read specific record from file
//****************************************************************


void display_spb(char n[])
{
	clrscr();
	int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);
	cout<<"\nBOOK DETAILS\n";
	int flag=0;
	fp.open("book.dat",ios::in);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book();
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
		cout<<"\n\nBook does not exist";
	getch();
}

void display_sps(char n[])
{

     //	clrscr();
    //	int gdriver=DETECT,gmode,i;
   //	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);
	cout<<"\nSTUDENT DETAILS\n";
	int flag=0;
	fp.open("student.dat",ios::in);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if((strcmpi(st.retadmno(),n)==0))
		{
			st.show_student();
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
		cout<<"\n\nStudent does not exist";
	getch();
}


//***************************************************************
//    	function to modify record of file
//****************************************************************


void modify_book()
{
	clrscr();
	char n[6];
	int found=0;
	clrscr();
	int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);
	cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
	cout<<"\n\n\tEnter The book no. of The book ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(book)) && found==0)
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book();
			cout<<"\nEnter The New Details of book"<<endl;
			bk.modify_book();
			int pos=-1*sizeof(bk);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&bk,sizeof(book));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}


void modify_student()
{
	clrscr();
	char n[6];
	int found=0;
	clrscr();
	int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);
	cout<<"\n\n\tMODIFY STUDENT RECORD... ";
	cout<<"\n\n\tEnter The admission no. of The student ";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmno(),n)==0)
		{
			st.show_student();
			cout<<"\nEnter The New Details of student"<<endl;
			st.modify_student();
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}

//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_student()
{
	clrscr();

	char n[6];
	int flag=0;
	clrscr();
	int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);
	cout<<"\n\n\n\tDELETE STUDENT...";
	cout<<"\n\nEnter The admission no. of the Student You Want To Delete : ";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(strcmpi(st.retadmno(),n)!=0)
			fp2.write((char*)&st,sizeof(student));
		else
			flag=1;
	}

	fp2.close();
	fp.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	if(flag==1)
		cout<<"\n\n\tRecord Deleted ..";
	else
		cout<<"\n\nRecord not found";
	getch();
}


void delete_book()
{
	clrscr();
	char n[6];
	int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);
	cout<<"\n\n\n\tDELETE BOOK ...";
	cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)!=0)
		{
			fp2.write((char*)&bk,sizeof(book));
		}
	}

	fp2.close();
	fp.close();
	remove("book.dat");
	rename("Temp.dat","book.dat");
	cout<<"\n\n\tRecord Deleted ..";
	getch();
}



//***************************************************************
//    	function to display all students list
//****************************************************************

void display_alls()
{

	clrscr();
		int gdriver=DETECT,gmode,i;
		initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
		setbkcolor(GREEN);
	fp.open("student.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}

	cout<<"\n\n\t\tSTUDENT LIST\n\n";
	cout<<"==================================================================\n";
	cout<<"\tAdmission No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
	cout<<"==================================================================\n";

	while(fp.read((char*)&st,sizeof(student)))
	{
		st.report();
	}

	fp.close();
	getch();
}


//***************************************************************
//    	function to display Books list
//****************************************************************

void display_allb()
{
     clrscr();
    //	int gdriver=DETECT,gmode,i;
   //	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
  //	setbkcolor(GREEN);
	fp.open("book.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}

	cout<<"\n\n\t\tBook LIST\n\n";
	cout<<"=========================================================================\n";
	cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
	cout<<"=========================================================================\n";

	while(fp.read((char*)&bk,sizeof(book)))
	{
		bk.report();
	}
	fp.close();
	getch();
}



//***************************************************************
//    	function to issue book
//****************************************************************

void book_issue()
{
	clrscr();
	int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);
	char sn[6],bn[6];
	int found=0,flag=0;

	cout<<"\n\nBOOK ISSUE ...";
	cout<<"\n\n\tEnter The student's admission no.";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmno(),sn)==0)
		{
			found=1;
			if(st.rettoken()==0)
			{
				cout<<"\n\n\tEnter the book no. ";
				cin>>bn;
				while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
				{
					if(strcmpi(bk.retbno(),bn)==0)
					{
						bk.show_book();
						flag=1;
						st.addtoken();
						st.getstbno(bk.retbno());
						int pos=-1*sizeof(st);
						fp.seekp(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						cout<<"\n\n\t Book issued successfully\n\nPlease Note: Write the current date 						in backside of your book and submit within 15 days fine Rs. 1 for each day 							after 15 days period";
					}
				}
				if(flag==0)
					cout<<"Book no does not exist";
			}
			else
				cout<<"You have not returned the last book ";

		}
	}
	if(found==0)
		cout<<"Student record not exist...";
	getch();
	fp.close();
	fp1.close();
}

//***************************************************************
//    	function to deposit book
//****************************************************************

void book_deposit()
{

	int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);

    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
	cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter The students admission no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
       {
	    if(strcmpi(st.retadmno(),sn)==0)
	    {
		    found=1;
		    if(st.rettoken()==1)
		    {
			while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
			{
			   if(strcmpi(bk.retbno(),st.retstbno())==0)
			{
				bk.show_book();
				flag=1;
				cout<<"\n\nBook deposited in no. of days";
				cin>>day;
				if(day>15)
				{
				   fine=(day-15)*1;
				   cout<<"\n\nFine has to deposited Rs. "<<fine;
				}
					st.resettoken();
					int pos=-1*sizeof(st);
					fp.seekp(pos,ios::cur);
					fp.write((char*)&st,sizeof(student));
					cout<<"\n\n\t Book deposited successfully";
			}
		    }
		  if(flag==0)
		    cout<<"Book no does not exist";
		      }
		 else
			cout<<"No book is issued..please check!!";
		}
	   }
      if(found==0)
	cout<<"Student record not exist...";
	getch();
  fp.close();
  fp1.close();
  }




//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{       clrscr();
	int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);

	delay(1000);
	settextstyle(7,0,4);
	outtextxy(40,80,"LIBRARY MANAGEMENT SYSTEM");
	delay(1000);
	settextstyle(8,0,1);
	outtextxy(70,250,"MADE BY : GAURAV,KHUSHAL,NAVJOT,PRANAV");
	delay(1000);
	settextstyle(8,0,1);
	outtextxy(80,425,"GOVERMENT POLYTECHNIC COLLEGE,JODHPUR");
	getch();
}



//***************************************************************
//    	ADMINISTRATOR MENU FUNCTION
//****************************************************************

void admin_menu()
{
	clrscr();
	int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(RED);
	int ch2;
	settextstyle(8,0,4);
	outtextxy(150,0,"ADMINISTRATOR MENU");
	settextstyle(8,0,1);
	outtextxy(10,50,"1. CREATE STUDENT RECORD");
	settextstyle(8,0,1);
	outtextxy(10,75,"2. DISPLAY ALL STUDENTS RECORD");
	settextstyle(8,0,1);
	outtextxy(10,100,"3. DISPLAY SPECIFIC STUDENT RECORD");
	settextstyle(8,0,1);
	outtextxy(10,125,"4. MODIFY STUDENT RECORD");
	settextstyle(8,0,1);
	outtextxy(10,150,"5. DELETE STUDENT RECORD");
	settextstyle(8,0,1);
	outtextxy(10,175,"6. CREATE BOOK");
	settextstyle(8,0,1);
	outtextxy(10,200,"7. DISPLAY ALL BOOKS");
	settextstyle(8,0,1);
	outtextxy(10,225,"8. DISPLAY SEPCIFIC BOOKS");
	settextstyle(8,0,1);
	outtextxy(10,250,"9. MODIFY BOOK");
       settextstyle(8,0,1);
	outtextxy(10,275,"10. DELETE BOOK");
       settextstyle(8,0,1);
	outtextxy(10,300,"11. BACK TO MAIN MENU");
	settextstyle(8,0,1);
	outtextxy(10,350,"PLEASE ENTER YOUR CHOICE (1-11)");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cin>>ch2;
	switch(ch2)
	{
		case 1: clrscr();
			write_student();break;
		case 2: display_alls();break;
		case 3:
			char num[6];
			clrscr();
			clrscr();
    //	int gdriver=DETECT,gmode,i;
    //	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
    //	setbkcolor(GREEN);
			cout<<"\n\n\tPlease Enter The Admission No. ";
			cin>>num;
			display_sps(num);
			break;
		case 4: modify_student();break;
		case 5: delete_student();break;
		case 6: clrscr();
			write_book();break;
		case 7: display_allb();break;
		case 8: {
			char num[6];
			clrscr();

   //	int gdriver=DETECT,gmode,i;
  //	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
  //	setbkcolor(GREEN);
			cout<<"\n\n\tPlease Enter The book No. ";
			cin>>num;
			display_spb(num);
			break;
			}
		case 9: modify_book();break;
		case 10: delete_book();break;
		case 11: return;
		default:cout<<"\a";
	}
	admin_menu();
}


//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


void main()
{
	char ch;
	intro();
	do
	{      clrscr();
	int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(GREEN);
		settextstyle(8,0,4);
	outtextxy(250,0,"MAIN MENU");
	//delay(1000);
	      setcolor(BLUE);
	       settextstyle(8,0,1);
	outtextxy(10,100,"01. BOOK ISSUE");
	//delay(1000);
		settextstyle(8,0,1);
	outtextxy(10,150, "02. BOOK DEPOSIT");
	//delay(1000);
		settextstyle(8,0,1);
	outtextxy(10,200,"03. ADMIN MENU");
	//delay(1000);
	settextstyle(8,0,1);
	outtextxy(10,250,"04. EXIT");
	settextstyle(8,0,1);
	//delay(1000);
	outtextxy(10,300,"PLEASE SELECT YOUR OPTION (1-4)");
	setcolor(WHITE);
		ch=getche();
		switch(ch)
		{
			case '1':clrscr();
				 book_issue();
				 break;
			case '2':book_deposit();
				 break;
			case '3':admin_menu();
				 break;
			case '4':exit(0);
			default :cout<<"\a";
		}
	}while(ch!='4');
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************

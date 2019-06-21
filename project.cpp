//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class STUDENT
{ char sname[70];
  long admno;
  int no;
  int f;
  char iss[90];
  public:
  STUDENT()
  { strcpy(sname,"NULL");
	 admno=0;
	 strcpy(iss,"NULL");
	 no=0,f=0;
  }
  void stu_enter()
  { cout<<"\n Enter student name:";
	 gets(sname);
	 cout<<"\n Enter student admission number:";
	 cin>>admno;
  }
  void stu_disp()
  { cout<<"\n Name is:";
	 puts(sname);
	 cout<<"\n Admission number is:";
	 cout<<admno;
	 cout<<"\n Book issued is ";
	 puts(iss);
	 if(f>0)
	 { cout<<"\n Fine to be paid is ";
		cout<<f<<" bucks";
	 }
  }
  void stu_mod()
  { cout<<"\n Enter student name:";
	 gets(sname);
	 cout<<"\n Enter student admission number:";
	 cin>>admno;
  }
  long admno_chk()
  { return admno;
  }
  int no_chk()
  { return no;
  }
  int stu_done()
  { no=1;
  }
  int stu_redone()
  { no=0;
  }
  int stu_fine(int g)
  { f=g;
  }
  char stu_cop(char t[])
  { strcpy(iss,t);
  }
  char stu_recop()
  { strcpy(iss,"NULL");
  }
  void fine_show()
  { cout<<f;
  }
  int fine_chk()
  { if(f>0)
	 return 0;
	 else
	  return 1;
  }
  void fine_done()
  { f=0;
  }
};
class BOOK
{ char bname[70];
  long bno;
  char lang[90];
  char auth[70];
  int stock;
	public:
  BOOK()
  { strcpy(bname,"NULL");
	 bno=0;
	 strcpy(auth,"NULL");
	 stock=0;
	 strcpy(lang,"NULL");
  }
  void book_enter()
  { cout<<"\n Enter book title:";
	 gets(bname);
	 cout<<"\n Enter book id number:";
	 cin>>bno;
	 cout<<"\n Enter author name:";
	 gets(auth);
	 cout<<"\n Enter language(english/hindi/other):";
	 gets(lang);
	 cout<<"\n Enter stock:";
	 cin>>stock;
  }
  void book_disp()
  { cout<<"\n Book title is:";
	 puts(bname);
	 cout<<"\n Book id is:";
	 cout<<bno;
	 cout<<"\n Author of book is:";
	 puts(auth);
	 cout<<"\n Language is:";
	 puts(lang);
	 cout<<"\n Stock is:";
	 cout<<stock;
  }
  void book_disp1()
  { cout<<"\n Book title is:";
	 puts(bname);
	 cout<<"\n Book id is:";
	 cout<<bno;
	 cout<<"\n Author of book is:";
	 puts(auth);
	 cout<<"\n Stock is:";
	 cout<<stock;
  }
  void book_mod()
  { cout<<"\n Enter book title:";
	 gets(bname);
	 cout<<"\n Enter book id number:";
	 cin>>bno;
	 cout<<"\n Enter author name:";
	 gets(auth);
	 cout<<"\n Enter language(english/hindi/other):";
	 gets(lang);
	 cout<<"\n Enter stock:";
	 cin>>stock;
  }
  char bname_chk(char l[])
  { return strcmp(bname,l);
  }
  char blang_chk(char p[])
  { return strcmp(lang,p);
  }
  int bnos_chk()
  { if(stock>1)
	 return 0;
	 else
	 return 1;
  }
  int bno_chk()
  { return bno;
  }
  int book_done()
  { stock=stock-1;
  }
  int book_redone()
  { stock=stock+1;
  }
};
class PASSWORD
{ char password[100];
  public:
  PASSWORD()
  { strcpy(password,"NULL");
  }
	void ent_pass()
	{ cout<<"\n Enter new password:";
	  gets(password);
	}
	char chk_pass(char g[])
	{ return strcmp(password,g);
	}
	void pass()
	{ strcpy(password,"NULL");
	}
};     //class ends here

//***************************************************************
//    	global declaration for stream object, object
//****************************************************************

BOOK bk;
STUDENT sdt;
PASSWORD p;

//***************************************************************
//    	function to write in file
//****************************************************************

void add_stu()
{  clrscr();
	ofstream fout("student.dat",ios::app|ios::out);
	sdt.stu_enter();
	fout.write((char*)&sdt,sizeof(sdt));
	fout.close();
}

void add_book()
{ clrscr();
  ofstream fout5("book.dat",ios::app|ios::out);
  bk.book_enter();
  fout5.write((char*)&bk,sizeof(bk));
  fout5.close();
}

//***************************************************************
//    	function to modify in file
//****************************************************************

void mod_stu()
{      clrscr();
		 long num;
		 ofstream fout1("student1.dat",ios::binary|ios::out);
		 ifstream fin1("student.dat",ios::binary|ios::in);
		 cout<<"\n Enter student's admission number you want to modify:";
		 cin>>num;
		 while(fin1.read((char*)&sdt,sizeof(sdt)))
		 { if(sdt.admno_chk()==num)
				{ sdt.stu_mod();
				  fout1.write((char*)&sdt,sizeof(sdt));
				}
			else
			  fout1.write((char*)&sdt,sizeof(sdt));
		 }
		remove("student.dat");
		rename("student1.dat","student.dat");
		fout1.close();
		fin1.close();
}

void mod_book()
{ clrscr();
  ofstream fout6("book1.dat",ios::binary|ios::out);
  ifstream fin6("book.dat",ios::binary|ios::in);
  long num;
	 cout<<"\n Enter book id you want to modify:";
	 cin>>num;
	 while(fin6.read((char*)&bk,sizeof(bk)))
		{ if(num==bk.bno_chk())
			 { bk.book_mod();
				fout6.write((char*)&bk,sizeof(bk));
			 }
		  else
			 fout6.write((char*)&bk,sizeof(bk));
		}
	 remove("book.dat");
	 rename("book1.dat","book.dat");
  fout6.close();
  fin6.close();
}

//***************************************************************
//    	function to display all records
//****************************************************************

void disa_stu()
{
  ifstream fin3("student.dat",ios::binary|ios::in);
  cout<<"\n Data is:";
  while(fin3.read((char*)&sdt,sizeof(sdt)))
  { sdt.stu_disp();
  }
  fin3.close();
}

void mini_eng()
{ ifstream fino("book.dat",ios::binary|ios::out);
  int i=0;
  while(fino.read((char*)&bk,sizeof(bk)))
  { if(bk.blang_chk("english")==0)
	 bk.book_disp1(); i=1;
  }
  if(i==0)
  cout<<"\n NULL";
  fino.close();
}

void mini_hindi()
{ ifstream finp("book.dat",ios::binary|ios::out);
  int j=0;
  while(finp.read((char*)&bk,sizeof(bk)))
  { if(bk.blang_chk("hindi")==0)
	 bk.book_disp1();  j=1;
  }
  if(j==0)
  cout<<"\n NULL";
  finp.close();
}

void mini_other()
{ ifstream finq("book.dat",ios::binary|ios::out);
  int k=0;
  while(finq.read((char*)&bk,sizeof(bk)))
  { if(bk.blang_chk("other")==0)
	 bk.book_disp1(); k=1;
  }
  if(k==0)
  cout<<"\n NULL";
  finq.close();
}

void disa_book()
{ clrscr();
  cout<<"\n The data is:";
  cout<<"\n English Titles";
  mini_eng();
  cout<<"\n Hindi Titles";
  mini_hindi();
  cout<<"\n Other Titles";
  mini_other();
}


//***************************************************************
//    	function to display specific record
//****************************************************************

void diss_stu()
{ clrscr();
  ifstream fin4("student.dat",ios::binary|ios::in);
	  long num;
		cout<<"\n Enter student's admission number whose details you want to display:";
		cin>>num;
		while(fin4.read((char*)&sdt,sizeof(sdt)))
		{ if(num==sdt.admno_chk())
			sdt.stu_disp();
		}
  fin4.close();
}

void diss_book()
{ clrscr();
  ifstream fout9("book.dat",ios::binary|ios::out);
  long num;
	  cout<<"\n Enter book id of the book which you want to display:";
	  cin>>num;
	  while(fout9.read((char*)&bk,sizeof(bk)))
	  { if(num==bk.bno_chk())
		  bk.book_disp();
	  }
	fout9.close();
}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void del_stu()
{ clrscr();
  ofstream fout2("student2.dat",ios::binary|ios::out);
  ifstream fin2("student.dat",ios::binary|ios::in);
	 long num;
		 cout<<"\n Enter student's admission number you want to delete:";
		 cin>>num;
		 while(fin2.read((char*)&sdt,sizeof(sdt)))
		 { if(num!=sdt.admno_chk())
			 fout2.write((char*)&sdt,sizeof(sdt));
			else
			{ cout<<"\n Record deleted successfully";
			  cout<<"\n Deleted record is:";
			  sdt.stu_disp();
			}
		 }
		 remove("student.dat");
		 rename("student2.dat","student.dat");
  fout2.close();
  fin2.close();
}

void del_book()
{ clrscr();
  ofstream fout7("book2.dat",ios::binary|ios::out);
  ifstream fin7("book.dat",ios::binary|ios::in);
  long num;
	  cout<<"\n Enter the book id which you want to delete:";
	  cin>>num;
	  while(fin7.read((char*)&bk,sizeof(bk)))
	  { if(num!=bk.bno_chk())
		  fout7.write((char*)&bk,sizeof(bk));
		 else
		 { cout<<"\n Record deleted";
			cout<<"\n Deleted record is:";
			bk.book_disp();
		 }
	  }
	  remove("book.dat");
	  rename("book2.dat","book.dat");
  fout7.close();
  fin7.close();
}

//***************************************************************
//    	function to delete file
//****************************************************************


void del_sys()
{ ifstream fin20("book.dat",ios::binary|ios::in);
  ifstream fin21("student.dat",ios::binary|ios::in);
  ifstream fin22("pass.dat",ios::binary|ios::in);
  char ch[60];
  clrscr();
  cout<<"\n Warning! This will delete all the records which exist in database.";
  cout<<"\n Enter password to confirm: ";
  gets(ch);
  if(p.chk_pass(ch)==0)
  { remove("pass.dat");
	 remove("student.dat");
	 remove("book.dat");
	 p.pass();
	 cout<<"\n All files have been deleted successfully.";
  }
  else
	cout<<"\n Wrong password.";
  fin20.close();
  fin21.close();
  fin22.close();
}

void del_sys1()
{ ifstream fin22("book.dat",ios::binary|ios::in);
  ifstream fin23("student.dat",ios::binary|ios::in);
  ifstream fin24("pass.dat",ios::binary|ios::in);
	 remove("pass.dat");
	 remove("student.dat");
	 remove("book.dat");
	 p.pass();
  fin22.close();
  fin23.close();
  fin24.close();
}

//***************************************************************
//    	password related functions
//****************************************************************

void pass_admin()
{ ofstream fout12("pass.dat",ios::binary|ios::out);
  p.ent_pass();
  fout12.write((char*)&p,sizeof(p));
  fout12.close();
}

void change_admin()
{ clrscr();
  ofstream fout13("pass1.dat",ios::binary|ios::out);
  ifstream fin13("pass.dat",ios::binary|ios::in);
  while(fin13.read((char*)&p,sizeof(p)))
  { p.ent_pass();
	 fout13.write((char*)&p,sizeof(p));
  }
  remove("pass.dat");
  rename("pass1.dat","pass.dat");
  fout13.close();
  fin13.close();
}

void wrong()
{ static int j=0;int c;
  j++;
  if(j>3)
  { cout<<"\n Replace password?(Press 1 for yes and 0 for no):";
	 cin>>c;
	 if(c==1)
	{ change_admin();
	  j=0;
	}
  }
}

int wrong(int p)
{ p++;
  return p;
}

//***************************************************************
//    	function to pay fine
//****************************************************************

void pay()
{ clrscr();
  ifstream finy("student.dat",ios::binary|ios::in);
  ofstream fouty("student1.dat",ios::binary|ios::out);
  long adm;char ch;int flag=0,flag1=0;
  cout<<"\n Enter student admission number";
  cin>>adm;
  while(finy.read((char*)&sdt,sizeof(sdt)))
  { if(adm==sdt.admno_chk())
	{ flag=1;
	  if(sdt.fine_chk()==0)
		{ flag1=1;
		  cout<<"\n Fine to be paid is: ";
		  sdt.fine_show();
		  cout<<"\n Press 'y' to make payment";
		  cin>>ch;
		  if(ch=='y')
		  {  sdt.fine_done();
			  cout<<"\n Fine paid";
			  fouty.write((char*)&sdt,sizeof(sdt));
		  }
		  else
		  {  fouty.write((char*)&sdt,sizeof(sdt));
			  return;
		  }
		}
	  else
		fouty.write((char*)&sdt,sizeof(sdt));
	 }
	else
	 fouty.write((char*)&sdt,sizeof(sdt));
  }
  if(flag==0)
  cout<<"\n Wrong admission number entered";
  if(flag1==0)
  cout<<"\n No fine has been issued yet.";
  remove("student.dat");
  rename("student1.dat","student.dat");
  finy.close();
  fouty.close();
}

//***************************************************************
//    	function to issue book in file
//****************************************************************

void issue_book()
{ clrscr();
  ifstream fin10("book.dat",ios::binary|ios::in);
  ifstream fin110("student.dat",ios::binary|ios::in);
  ofstream fout10("book3.dat",ios::binary|ios::out);
  ofstream fout110("student3.dat",ios::binary|ios::out);
  long num;
  cout<<"\n Enter student admission number:";
  cin>>num;
  cout<<"\n Enter the name of the book which you want to issue:";
  char h[80];
  gets(h);
  int fs=0,fb=0;
  while(fin110.read((char*)&sdt,sizeof(sdt)))
  {  	if(num==sdt.admno_chk())
			{  fs=1;
					if(sdt.no_chk()==0)
						{ while(fin10.read((char*)&bk,sizeof(bk)))
									{ if(bk.bname_chk(h)==0)
										{   fb=1;
												if(bk.bnos_chk()==0)
													{ bk.book_done();
													  sdt.stu_done();
													  sdt.stu_cop(h);
													  fout10.write((char*)&bk,sizeof(bk));
													  fout110.write((char*)&sdt,sizeof(sdt));
													  cout<<"\n Book issued.Fine of Rs. 10 per day if failed to Return/Renew after 15 days.";

													}
												else
													{ cout<<"\n Sorry book has been issued by another student or it is out of stock";
														fout10.write((char*)&bk,sizeof(bk));
														fout110.write((char*)&sdt,sizeof(sdt));
													}
										}
										else
											 { fb=0;
													fout10.write((char*)&bk,sizeof(bk));
													fout110.write((char*)&sdt,sizeof(sdt));
											 }
									}
							}
						else
							{	cout<<"\n Return the issued book first in order to issue another one";
								fout110.write((char*)&sdt,sizeof(sdt));
							}
				}
			else
			  fout110.write((char*)&sdt,sizeof(sdt));
	 }
	 if(fs==0)
	  { cout<<"\n Admission no. does not exist";
	  }
	 remove("book.dat");
	 remove("student.dat");
	 rename("book3.dat","book.dat");
	 rename("student3.dat","student.dat");
	 fout10.close();
	 fout110.close();
	 fin10.close();
	 fin110.close();
}

//***************************************************************
//    	function to deposit book in file
//****************************************************************

void deposit_book()
{ clrscr();
  ofstream fout14("book1.dat",ios::binary|ios::out);
  ofstream fout15("student1.dat",ios::binary|ios::out);
  ifstream fin14("book.dat",ios::binary|ios::in);
  ifstream fin15("student.dat",ios::binary|ios::in);
  cout<<"\n Enter student admission number:";
  long k;
  int flag=0,x=0,y=0,a=0,c=0,flag2=0;
  cin>>k;
  cout<<"\n Enter name of book which you want to deposit:";
  char l[90];
  gets(l);
  cout<<"\n Enter no. of days which have passed since the issue of book:";
  int t,fine;
  cin>>t;
	  while(fin15.read((char*)&sdt,sizeof(sdt)))
		 {  if(k==sdt.admno_chk())
			 { flag=1;y++;
				 if(sdt.no_chk()!=0)
					 { flag2=1;a++;
						while(fin14.read((char*)&bk,sizeof(bk)))
						 { if(bk.bname_chk(l)==0)
							 {  x=1;c++;
								 bk.book_redone();
								 sdt.stu_redone();
								 sdt.stu_recop();
								 cout<<"\n Book deposited successfully";
								 if(t>15)
									{	fine=(t-15)*10;
										sdt.stu_fine(fine);
									}
								 fout14.write((char*)&bk,sizeof(bk));
								 fout15.write((char*)&sdt,sizeof(sdt));
							 }
							else
							{  x=0;
							  fout14.write((char*)&bk,sizeof(bk));
							  fout15.write((char*)&sdt,sizeof(sdt));
							}
						 }
					 }
				 else
						{ flag2=0;
						  fout15.write((char*)&sdt,sizeof(sdt));
						}
			  }
				 else
				  {  flag=0;
					  fout15.write((char*)&sdt,sizeof(sdt));
				  }
		 }
	  if((flag==0)&&(y==0))
	  {  if((flag2==0)&&(a==0))
			 {  if((x==0)&&(c==0))
				 {	cout<<"\n Invalid book name entered";
					cout<<"\n Wrong admission number entered";
					cout<<"\n Issue a book first in order to deposit it";
				 }
			 }
	  }
	 remove("student.dat");
	 remove("book.dat");
	 rename("book1.dat","book.dat");
	 rename("student1.dat","student.dat");
	 fout14.close();
	 fin14.close();
	 fout15.close();
	 fin15.close();
}

//***************************************************************
//    	function for administrator menu
//****************************************************************

void admin()
{ clrscr(); int r=0;
	if(p.chk_pass("NULL")==0)
	 pass_admin();
	 else
	 { cout<<"\n Enter password:";
		char ch[78];
		gets(ch);
		int i=1;
		do
				{ if(p.chk_pass(ch)==0)
				  {  i=0;
					 cout<<"\n ADMINISTRATOR MENU";
					 cout<<"\n 1. To add student record";
					 cout<<"\n 2. To modify student record";
					 cout<<"\n 3. To delete student record";
					 cout<<"\n 4. To display all student records";
					 cout<<"\n 5. To display specific student record";
					 cout<<"\n 6. To add book record";
					 cout<<"\n 7. To modify book record";
					 cout<<"\n 8. To delete book record";
					 cout<<"\n 9. To display all book records";
					 cout<<"\n 10. To display a specific book record";
					 cout<<"\n 11. To change password";
					 cout<<"\n 12. To delete the database system";
					 cout<<"\n 13. To pay fine";
					 cout<<"\n 14. To return";
					 cout<<"\n Enter your choice:";
					 int a;
					 cin>>a;
					 if(a==1)
						add_stu();
					 else if(a==2)
						mod_stu();
					 else if(a==3)
						del_stu();
					 else if(a==4)
						disa_stu();
					 else if(a==5)
						diss_stu();
					 else if(a==6)
						add_book();
					 else if(a==7)
						mod_book();
					 else if(a==8)
						del_book();
					 else if(a==9)
						disa_book();
					 else if(a==10)
						diss_book();
					 else if(a==11)
						change_admin();
					 else if(a==12)
					 {	 r=1;i=1;  }
					 else if(a==13)
					  pay();
					 else
						return;
				  }
				  else
				  i=1;
				} while(i==0);
			  if(i==1)
			  wrong();
			  if(r==1)
			  del_sys();
		}
}



//***************************************************************
//    	the main function of program
//****************************************************************

void start()
{ clrscr();
  cout<<"\n********************LIBRARY MANAGEMENT SYSTEM********************";
  char ch='y'; int choi;
	  while(ch=='y')
	  { cout<<"\n Main menu";
		cout<<"\n 1. To issue a book";
		cout<<"\n 2. To deposit a book";
		cout<<"\n 3. To open administrator menu";
		cout<<"\n 4. To exit";
		cout<<"\n Enter your choice:";
		cin>>choi;
		if(choi==1)
		 issue_book();
		else if(choi==2)
		 deposit_book();
		else if(choi==3)
		 admin();
		else
		{ exit(0);
		  del_sys1();
		}
		cout<<"\n Do you want to continue?(y/n) ";
		cin>>ch;
	 } del_sys1();
}
void main()
{  cout<<"\n PROJECT SUBMITTED BY";
  cout<<"\n Dhruv Sethi";
  cout<<"\n Type 'ent' to continue:";
  char ch[5];
  gets(ch);
  if(strcmp(ch,"ent")==0)
	start();
  else
	exit(0);
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************









 
 
 
 
 
 
 
 
 
 
 
   
 


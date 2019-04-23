//ALL REQUIRED HEADER FILES
#include <iostream>
#include <vector>
#include <cstdio>
#include <windows.h>
#include <mysql.h>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

/*
    Project is Built by students of Chandigarh University
    Akash Kumar Singhal
    UID - 18BCS3762
    Contact Number - 9868238010
    Email - akashksinghalnewdelhi@gmail.com

    Project is Built using IDE CODEBLOCKS AND LOCALHOST SERVER (WAMP)
    Project has all the front end in C++.
    Database is stored using WAMP SERVER in MySQL server.

    Date of Completion of Project : 10th April 2019
    Time Taken : 2 Weeks
*/

// this is global variable
//center of axis is set to the top left cornor of the screen
COORD coord={0,0};

//ALL THE USED FUNCTIONS
void About(int);
void Booking(MYSQL* conn,char username[20],char name[20],string B_ID,string D_ID);
void cover(int ,int ,int ,int );
void DisplayBlood(int Flag,MYSQL* conn,char username[20],char name[20],string D_ID);
void DisplayDC(int Flag,MYSQL* conn,char username[20],char name[20]);
void gotoxy(int x,int y);
void insertPatients(MYSQL* conn);
void Login(MYSQL* conn);
void MENU1(MYSQL *conn);
void MENU2(MYSQL* conn,char username[20],char name[20]);
void wait();
void welcome(MYSQL* conn);

//CLASS PATIENTS TO RETRIEVE DATA
class Patients
{
    public:
    string username;
    string name;
    string email;
    string contact_number;
    char DOB[9];
    char password[9];
};

//FUNCTION TO SET CURSOR POINTER
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//FUNCTION TO MAKE BORDERS
void cover(int x1=10,int y1=3,int x2=70,int y2=24)
{
    system("cls");
	char ch=205,hc=186,o=187,p=200,g=201,h=188;
	int a=x1,b=y1,c=x2,d=y2;
	for(int k=x1;k<x2;k++)
	{
		if(a==21&&b==7&&c==55&&d==22)
			Sleep(10);
		gotoxy(k,b);
		if(k==x1)
            cout<<g;
		else
            cout<<ch;
	}
	gotoxy(x2,y1);cout<<o;
	for(int j=y1+1;j<=y2;j++)
	{
		if(x1==21&&y1==7&&x2==55&&y2==22)
			Sleep(10);
		gotoxy(c,j);
		cout<<hc;
	}
	gotoxy(x2,y2);
	cout<<h;
	for(--c;c>x1;c--)
	{
		if(x1==21&&y1==7&&x2==55&&y2==22)
			Sleep(10);
		gotoxy(c,y2);
		cout<<ch;
	}
	gotoxy(x1,y2);
	cout<<p;
	for(--d;d>y1;d--)
	{
		if(x1==21&&y1==7&&x2==55&&y2==22)
			Sleep(10);
		gotoxy(a,d);
		cout<<hc;
	}

}

//WELCOME SCREEN ANIMATION
void welcome(MYSQL* conn)
{
    system("color ED");
    cover(7,2,112,27);
    gotoxy(44,4);
    Sleep(60);
    gotoxy(14, 4);Sleep(60);  cout<<"||      ||   ||======   ||        ||=====   |=====|   ||      ||   ||======";
    gotoxy(14, 5);Sleep(60);  cout<<"||      ||   ||         ||        ||        ||   ||   ||\\\\  //||   ||      ";
    gotoxy(14, 6);Sleep(60);  cout<<"||  ==  ||   ||======   ||        ||        ||   ||   ||  ==  ||   ||======";
    gotoxy(14, 7);Sleep(60);  cout<<"||//  \\\\||   ||         ||        ||        ||   ||   ||      ||   ||      ";
    gotoxy(14, 8);Sleep(60);  cout<<"||      ||   ||======   ||||||||  ||=====   |=====|   ||      ||   ||======";
    gotoxy(29,10);Sleep(60);  cout<<"\t.....TO......\t";
    gotoxy(14,12);Sleep(60);  cout<<" ||==\\\\    ||======||  ========   ||      ||     ====     " ;
    gotoxy(14,13);Sleep(60);  cout<<" ||   ||   ||      ||     ||      ||      ||   //    \\\\   " ;
    gotoxy(14,14);Sleep(60);  cout<<" ||==//    ||======||     ||      ||======||  ||      ||     " ;
    gotoxy(14,15);Sleep(60);  cout<<" ||        ||      ||     ||      ||      ||   \\\\    //  |   |~~| |~~| _  \\\\ // " ;
    gotoxy(14,16);Sleep(60);  cout<<" ||        ||      ||     ||      ||      ||     ====    |__ |__| |___| |  // " ;
    gotoxy(14,18);Sleep(60);  cout<<" ||======    ====     ||       ||       || ||======   ||======   ======" ;
    gotoxy(14,19);Sleep(60);  cout<<" ||        //    \\\\   || \\\\    || \\\\    || ||         ||           ||  " ;
    gotoxy(14,20);Sleep(60);  cout<<" ||       ||      ||  ||   \\\\  ||   \\\\  || ||===      ||           ||  " ;
    gotoxy(14,21);Sleep(60);  cout<<" ||        \\\\    //   ||     \\\\||     \\\\|| ||         ||           ||  " ;
    gotoxy(14,22);Sleep(60);  cout<<" ||======    ====     ||       ||       || ||======   ||======     ||  \n\n";
    gotoxy(14,24);Sleep(60);  cout<<"                                            --- Premium Solution For Blood Diagnosis & Testing";
    getch();
    wait();
    MENU1(conn);
}

//WAITING ANIMATION
void wait()
{
    system("cls");
    system("color 5F");
	cover(41,7,75,22);
	gotoxy(52,11) ;
	cout << " Please Wait " ;
	gotoxy(44,14) ;
	char D[]={"....PathoConnect Loading...."};
	for ( int y = 0 ; y < 28 ; ++y )
	{
		Sleep(20);
		cout<<D[y];
	}
	gotoxy(44,18);
	Sleep(100);
	cout<<" PRESS ANY KEY TO CONTINUE";
	getch();
}

//INSERTING Dignostic Centre Details
//NOT IN USE AS OF NOW
/*
void insertDC(MYSQL* conn)
{
    DC ob;  //CLASS DC (USED EARLIER)
    cout<<"Enter ID : ";cin>>ob.id;
    cout<<"Enter Name : ";cin>>ob.name;
    cout<<"Enter Address : ";cin>>ob.address;
    cout<<"Enter Major Locality : ";cin>>ob.major_locality;
    cout<<"Enter City : ";cin>>ob.city;
    cout<<"Enter State : ";cin>>ob.state;
    cout<<"Enter Ratings : ";cin>>ob.rating;
    cout<<"Enter Timings : ";cin>>ob.timings;
    cout<<"Enter Contact Number : ";cin>>ob.contact_number;
    cout<<"Enter HCFacililty : ";cin>>ob.hcfacility;
    string query = "INSERT INTO `dc`(`ID`, `Name`, `Address`, `Major Locality`, `City`, `State`, `Ratings`, `Timings`, `Contact Numer`, `HCFacility`) VALUES ('";//"insert into dc values(";
    query+= ob.id ;
    query+= "','"  ;
    query+= ob.name;
    query+= "','" ;
    query+= ob.address ;
    query+= "','" ;
    query+= ob.major_locality ;
    query+= "','" ;
    query+= ob.city ;
    query+= "','" ;
    query+= ob.state ;
    query+= "','" ;
    query+= ob.rating ;
    query+= "','" ;
    query+= ob.timings ;
    query+= "','" ;
    query+= ob.contact_number ;
    query+= "','" ;
    query+= ob.hcfacility ;
    query+= "')";
    const char* q = query.c_str();
    //cout<<"query is: "<<q<<endl;
    int qstate = mysql_query(conn,q);
    if(!qstate)
        cout<<"record inserted successfully..."<<endl;
    else
        cout<<"query problem: "<<mysql_error(conn)<<endl;
}*/

//MAIN MENU (USER DIRECTLY REACHES HERE)
void MENU1(MYSQL *conn)
{
	char ch;
    cover(41,7,75,22);
	gotoxy(48,9) ;
	cout << " MAIN MENU " ;
	gotoxy(45,12) ;
	cout << " 1. Login" ;
	gotoxy(45,13) ;
	cout << " 2. Register" ;
	gotoxy(45,14);
	cout << " 3. Exit " ;
	gotoxy(45,15) ;
	cout << " 4. Credits " ;
	gotoxy(45,17);
	cout << " Enter your choice ( 1-4 ) " ;
	H:gotoxy(45,19) ;
	cin >> ch ;
	switch( ch )
	{
		case '1':
            Login(conn);
            getch();
			break;
		case '2':
            insertPatients(conn);
			break;
		case '3':
			exit(0);
			break;
		case '4':
			About(2);
			getch();
			break;
		default : goto H;
	}
	MENU1(conn);
	getch() ;
}

//LOGIN MENU (username and password verification)
void Login(MYSQL* conn)
{
	char hk[20],ps[9];
	cover(35,6,85,17);
	gotoxy(45,8);
	cout << " LOGIN MENU";
	gotoxy(45,10) ;
	cout << " Enter Username :  ";
	cin>>hk;
	gotoxy(45,12);
	cout << " Enter Password :  " ;
	for ( int j = 0 ; j < 8 ; ++j )
	{
		ps[j] = getch() ;
		cout << "*" ;
	}
	ps[8] = '\0' ;
    string query = "SELECT `username`, `password`,`name` FROM `patients` WHERE username = '";
	query+=hk;
	query+="' AND  password = '";
	query+=ps;
	query+="'";
	const char* q = query.c_str();
    int qstate = mysql_query(conn,q);
    MYSQL_RES* res;
    MYSQL_ROW row;
    if(!qstate)
    {
        res = mysql_store_result(conn);
        while(row=(mysql_fetch_row(res)))
        {
            //cout<<row[0]<<row[1];
            if(strcmp(hk,row[0])==0 && strcmp(ps,row[1])==0)
            {
                gotoxy(45,14);
                Sleep(50);
                cout<<"PRESS ANY KEY TO CONTINUE";
                getch();
                MENU2(conn,hk,row[2]);
            }
        }
    }
    gotoxy(45,14);
    cout << " Invalid Username or Password ";
    getch();
    MENU1(conn);
}

//FUNCTION TO REGISTER NEW PATIENT DETAILS
void insertPatients(MYSQL* conn)
{
    Patients ob;
    string a;
    cover(35,5,85,22);
    gotoxy(50, 7);
    cout<<"SIGN UP MENU";
    gotoxy(40,10);
    cout<<"First Name       : ";
    cin>>a;
    gotoxy(40,11);
    cout<<"Username         : ";
    cin>>ob.username;
    gotoxy(40,12);
    cout<<"Contact Number   : ";
    cin>>ob.contact_number;
    gotoxy(40,13);
    cout<<"Email            : ";
    cin>>ob.email;
    gotoxy(40,14);
    cout<<"DOB (DD:MM:YYYY) : ";
    for (int j = 0 ; j < 8 ; ++j )
	{
        if(j==2 || j==4 )
            cout<<":";
        ob.DOB[j] = getch() ;
        cout<< ob.DOB[j];
	}
	ob.DOB[8]='\0';
    gotoxy(40,15);
    cout<<"Password (8 Letters): ";
    for ( int j = 0 ; j < 8 ; ++j )
	{
	    ob.password[j] = getch() ;
        cout << "*" ;
	}
	ob.password[8]='\0';
    string query = "INSERT INTO `patients`(`username`, `name`, `contact`, `DOB`, `password`,`email`) VALUES ('";
    query+= ob.username ;
    query+= "','" ;
    query+= a;
    query+= "','" ;
    query+= ob.contact_number ;
    query+= "','" ;
    query+= ob.DOB ;
    query+= "','" ;
    query+= ob.password ;
    query+= "','" ;
    query+= ob.email;
    query+= "')";
    const char* q = query.c_str();
    int qstate = mysql_query(conn,q);
    if(!qstate)
    {
        gotoxy(44,17);
        cout<<"Registered Successfully"<<endl;
        gotoxy(40,19);
        cout<<"....Press Any key to Continue...."<<endl;
        getch();
        MENU1(conn);
    }
    else
    {
        gotoxy(49,24);
        cout<<"Error : "<<mysql_error(conn)<<endl;
        getch();
    }
}

//MAIN MENU-2 (FOR DC,BLOOD & BOOKING MENU CALLS)
void MENU2(MYSQL* conn,char username[20],char name[20])
{
    cover(35,6,85,22);
    gotoxy(45,8);
	cout << " Welcome "<<name;
	gotoxy(40,10);
	cout << " 1. View Diagnostic Centers";
	gotoxy(40,12) ;
	cout << " 2. Details of Blood Tests";
	gotoxy(40,14) ;
	cout << " 3. Book Blood Tests";
	gotoxy(40,16) ;
	cout << " 4. Logout";
    gotoxy(40,18) ;
    cout << " Enter Choice : ";
	int a;
    I:
    gotoxy(55,18);
    cin>>a;
	switch(a)
	{
        case 1: DisplayDC(1,conn,username,name);
                break;
        case 2: DisplayBlood(1,conn,username,name,"");
                break;
        case 3: DisplayDC(2,conn,username,name);
                break;
        case 4: MENU1(conn);
                break;
        default:goto I;
                break;
	}
	getch();
	exit(0);
}

//Dignostic Centre Function (Performing Selection & Booking call)
void DisplayDC(int Flag,MYSQL* conn,char username[20],char name[20])
{
    M1:
    int a;
    if(Flag==2)
    {
        cover(35,6,85,10);
        gotoxy(40,8);
        cout<<"Centre Test Selection ->->->->";
        getch();
    }
    cover(35,6,85,25);
    gotoxy(45,8);
	cout << " Select the State ";
	string query = "SELECT distinct `state` FROM `dc` limit 10";
	const char* q = query.c_str();
	int qstate = mysql_query(conn,q);
    MYSQL_RES* res;
    MYSQL_ROW row;
    vector<string> names;
    int i;
    if(!qstate)
    {
        i=1;
        res = mysql_store_result(conn);
        while(row=(mysql_fetch_row(res)))
        {
            gotoxy(40,9+i);
            cout<<i<<". "<<row[0];
            names.push_back(row[0]);
            i++;
        }
    }
    gotoxy(40,9+i+1);
    cout<<i<<". "<<"Back";
    gotoxy(40,9+i+2);
    cout<<"Enter Your Choice : ";
    do
    {
        gotoxy(60,9+i+2);
        cin>>a;
    }while(a<0&&a>i+1);
    if(a==i)
        MENU2(conn,username,name);
    string state=names[a-1];
    names.clear();
    M2:
    cover(35,6,85,25);
    gotoxy(45,8);
	cout << " Select the City ";
    query = "SELECT distinct `city` FROM `dc` WHERE state = '";
	query+=state;
	query+="' limit 10";
	q = query.c_str();
    qstate = mysql_query(conn,q);
    if(!qstate)
    {
        i=1;
        res = mysql_store_result(conn);
        while(row=(mysql_fetch_row(res)))
        {
            gotoxy(40,9+i);
            cout<<i<<". "<<row[0];
            names.push_back(row[0]);
            i++;
        }
    }
    gotoxy(40,9+i+1);
    cout<<i<<". "<<"Back";
    gotoxy(40,9+i+2);
    cout<<"Enter Your Choice : ";
    do
    {
        cin>>a;

    }while(a<0&&a>i+1);
    if(a==i)
        goto M1;
    string city=names[a-1];
    names.clear();
    cover(35,6,85,25);
    gotoxy(45,8);
	cout << " Select the Locality ";
    query = "SELECT distinct `locality` FROM `dc` WHERE state = '";
	query+=state;
	query+="' and city = '";
	query+=city;
	query+="' limit 10";
    q = query.c_str();
    qstate = mysql_query(conn,q);
    if(!qstate)
    {
        i=1;
        res = mysql_store_result(conn);
        while(row=mysql_fetch_row(res))
        {
            gotoxy(40,9+i);
            cout<<i<<". "<<row[0];
            names.push_back(row[0]);
            i++;
        }
    }
    gotoxy(40,9+i+1);
    cout<<i<<". "<<"Back";
    gotoxy(40,9+i+2);
    cout<<"Enter Your Choice : ";
    do
    {
        cin>>a;
    }while(a<0&&a>i+1);
    if(a==i)
        goto M2;
    string locality = names[a-1];
    names.clear();
    cover(35,6,85,25);
    gotoxy(45,8);
    M3:
	cout << " Select the Centre ";
    query = "SELECT distinct `Name` FROM `dc` WHERE state = '";
	query+=state;
	query+="' and city = '";
	query+=city;
	query+="' and locality = '";
	query+=locality;
	query+="' order by ratings limit 10";
    q = query.c_str();
    qstate = mysql_query(conn,q);
    if(!qstate)
    {
        i=1;
        res = mysql_store_result(conn);
        while(row=(mysql_fetch_row(res)))
        {
            gotoxy(40,9+i);
            cout<<i<<". "<<row[0];
            names.push_back(row[0]);
            i++;
        }
    }
    gotoxy(40,9+i+1);
    cout<<i<<". "<<"Back";
    gotoxy(40,9+i+2);
    cout<<"Enter Your Choice : ";
    do
    {
        cin>>a;
    }while(a<0&&a>i+1);
    if(a==i)
        goto M3;
    string centre = names[a-1];
    names.clear();
    cover(25,6,95,25);
    gotoxy(35,8);
    cout << "CENTRE DETAILS";
    query = "SELECT `Name`, `Address`, `Locality`, `City`, `State`, `Ratings`, `Timings`, `Contact Numer`, `HCFacility`,`ID` FROM `dc` WHERE state = '";
	query+=state;
	query+="' and city = '";
	query+=city;
	query+="' and locality = '";
	query+=locality;
	query+="'and name = '";
	query+=centre;
	query+="' order by ratings limit 10";
    q = query.c_str();
    names.clear();
    qstate = mysql_query(conn,q);
    if(!qstate)
    {
        res = mysql_store_result(conn);
        while(row=(mysql_fetch_row(res)))
        {
            for(int j=0;j<10;j++)
                names.push_back(row[j]);
        }
    }
    gotoxy(30,10);
    cout << " NAME           : ";
    for (int h = 0 ; names[0][h] != '\0' ; ++h )
	{
	    cout << names[0][h] ;
		Sleep(50) ;
	}
    gotoxy(30,11);
    cout << " Address        : ";
    for (int h = 0 ; names[1][h] != '\0' ; ++h )
	{
	    cout << names[1][h] ;
		Sleep(50) ;
	}
    gotoxy(30,12);
    cout << " Locality       : ";
    for (int h = 0 ; names[2][h] != '\0' ; ++h )
	{
	    cout << names[2][h] ;
		Sleep(50) ;
	}
    gotoxy(30,13);
    cout << " City           : ";
    for (int h = 0 ; names[3][h] != '\0' ; ++h )
	{
	    cout << names[3][h] ;
		Sleep(50) ;
	}
    gotoxy(30,14);
    cout << " State          : ";
    for (int h = 0 ; names[4][h] != '\0' ; ++h )
	{
	    cout << names[4][h] ;
		Sleep(50) ;
	}
    gotoxy(30,15);
    cout << " Ratings        : "<<names[5];
    gotoxy(30,16);
    cout << " Timings        : ";
    for (int h = 0 ; names[6][h] != '\0' ; ++h )
	{
	    cout << names[6][h] ;
		Sleep(50) ;
	}
    gotoxy(30,17);
    cout << " Contact Number : ";
    for (int h = 0 ; names[7][h] != '\0' ; ++h )
	{
	    cout << names[7][h] ;
		Sleep(50) ;
	}
    gotoxy(30,18);
    cout << " Home Facility  : ";
    for (int h = 0 ; names[8][h] != '\0' ; ++h )
	{
	    cout << names[8][h] ;
		Sleep(50) ;
	}
	if(Flag==1)
    {
        gotoxy(35,23);
        cout<<"Press Any Key for Main Menu";
        getch();
        MENU2(conn,username,name);
    }
	else if(Flag==2)
    {
        gotoxy(35,20);
        cout<<"Press 1 to Continue";
        gotoxy(35,21);
        cout<<"Press 2 to Select Other Centre";
        int choice;
        choi:
        gotoxy(40,22);
        cout<<": ";
        cin>>choice;
        if(choice==1)
            DisplayBlood(2,conn,username,name,names[9]);//names[9] stands for Diagnostic Centres ID
        else if (choice ==2)
            goto M3;
        else
            goto choi;
    }
    getch();
}

//Blood Tests Function (Performing Selection & Booking call)
void DisplayBlood(int Flag,MYSQL* conn,char username[20],char name[20],string D_ID="")
{
    K1:
    int a;
    if(Flag==2)
    {
        cover(35,6,85,10);
        gotoxy(40,8);
        cout<<"Blood Test Selection ->";
        getch();
    }
    cover(35,6,85,25);
    gotoxy(45,8);
	cout << " Select the Category ";
	string query = "SELECT distinct `Category` FROM `blood` limit 10";
	const char* q = query.c_str();
	int qstate = mysql_query(conn,q);
    MYSQL_RES* res;
    MYSQL_ROW row;
    vector<string> names;
    int i;
    if(!qstate)
    {
        i=1;
        res = mysql_store_result(conn);
        while(row=(mysql_fetch_row(res)))
        {
            gotoxy(40,9+i);
            cout<<i<<". "<<row[0];
            names.push_back(row[0]);
            i++;
        }
    }
    gotoxy(40,9+i+1);
    cout<<i<<". "<<"Back";
    gotoxy(40,9+i+2);
    cout<<"Enter Your Choice : ";
    do{
        cin>>a;
    }while(a<0&&a>i+1);
    if(a==i)
        DisplayDC(Flag,conn,username,name);
    string category=names[a-1];
    names.clear();
    K2:
    cover(35,6,85,25);
    gotoxy(45,8);
	cout << " Select the Test ";
    query = "SELECT `Scientific_Name` FROM `blood` WHERE `Category` = '";
	query+=category;
	query+="' limit 10";
	q = query.c_str();
    qstate = mysql_query(conn,q);
    if(!qstate)
    {
        i=1;
        res = mysql_store_result(conn);
        while(row=(mysql_fetch_row(res)))
        {
            gotoxy(40,9+i);
            cout<<i<<". "<<row[0];
            names.push_back(row[0]);
            i++;
        }
    }
    gotoxy(40,9+i+1);
    cout<<i<<". "<<"Back";
    gotoxy(40,9+i+2);
    cout<<"Enter Your Choice : ";
    do{
        cin>>a;
    }while(a<0&&a>i+1);
    if(a==i)
        goto K1;
    string test=names[a-1];
    cover(25,6,85,23);
    gotoxy(40,8);
    cout << "TEST DETAILS";
    query = "SELECT `Scientific_Name`, `Category`, `Reports`, `Symptoms`, `Prerrequisites`, `cost`, `ID` FROM `blood` WHERE `Category` = '";
	query+=category;
	query+="' and `Scientific_Name` = '";
	query+=test;
	query+="' limit 10";
    q = query.c_str();
    names.clear();
    qstate = mysql_query(conn,q);
    if(!qstate)
    {
        res = mysql_store_result(conn);
        while(row=(mysql_fetch_row(res)))
        {
            for(int j=0;j<7;j++)
                names.push_back(row[j]);
        }
    }
    gotoxy(30,10);
    cout << " Scientific Name : ";
    for (int h = 0 ; names[0][h] != '\0' ; ++h )
	{
	    cout << names[0][h] ;
		Sleep(50) ;
	}
    gotoxy(30,11);
    cout << " Category        : ";
    for (int h = 0 ; names[1][h] != '\0' ; ++h )
	{
	    cout << names[1][h] ;
		Sleep(50) ;
	}
    gotoxy(30,12);
    cout << " Availability    : ";
    for (int h = 0 ; names[2][h] != '\0' ; ++h )
	{
	    cout << names[2][h] ;
		Sleep(50) ;
	}
    gotoxy(30,13);
    cout << " Symptoms        : ";
    for (int h = 0 ; names[3][h] != '\0' ; ++h )
	{
	    cout << names[3][h] ;
		Sleep(50) ;
	}
    gotoxy(30,14);
    cout << " Prerequisites   : ";
    for (int h = 0 ; names[4][h] != '\0' ; ++h )
	{
	    cout << names[4][h] ;
		Sleep(50) ;
	}
    gotoxy(30,15);
    cout << " Cost            : "<<names[5];
    if(Flag==1)
    {
        gotoxy(35,16);
        cout<<"Press Any Key for Main Menu";
        getch();
        MENU2(conn,username,name);
    }
	else if(Flag==2)
    {
        gotoxy(35,17);
        cout<<"Press 1 to take Appointment ";
        gotoxy(35,18);
        cout<<"Press 2 to Select Other test";
        int choice;
        choi:
        gotoxy(50,19);
        cout<<": ";
        cin>>choice;
        if(choice==1)
            Booking(conn,username,name,names[6],D_ID);
        else if (choice ==2)
            goto K1;
        else
            goto choi;
    }
    getch();
}

//BOOKING MENU FOR BOOKING APPOINTMENT WITH DC
void Booking(MYSQL* conn,char username[20],char name[20],string B_ID,string D_ID)
{
    int a;
    cover(25,6,85,25);
    gotoxy(35,8);
	cout << " Confirm Details ";
	string query = "SELECT patients.name,patients.contact,patients.email,dc.Name,dc.`Contact Numer` ,dc.Address,blood.Scientific_Name,blood.Category,blood.cost from patients,blood,dc WHERE patients.name = '";
	query+=name;
	query+="' and patients.username = '";
	query+=username;
	query+="' and dc.ID = '";
	query+=D_ID;
	query+="' and blood.ID = '";
	query+=B_ID; query+="'";
	const char* q = query.c_str();
	int qstate = mysql_query(conn,q);
    MYSQL_RES* res;
    MYSQL_ROW row;
    //cout<<query<<endl;
    vector<string> names;
    if(!qstate)
    {
        res = mysql_store_result(conn);
        while(row=(mysql_fetch_row(res)))
        {
            for(int j=0;j<9;j++)
            {
                names.push_back(row[j]);
            }
        }
    }
    gotoxy(30,10);
    cout << " NAME OF PATIENT: ";
    for (int h = 0 ; names[0][h] != '\0' ; ++h )
	{
	    cout << names[0][h] ;
		Sleep(50) ;
	}
    gotoxy(30,11);
    cout << " MOBILE NO.     : ";
    for (int h = 0 ; names[1][h] != '\0' ; ++h )
	{
	    cout << names[1][h] ;
		Sleep(50) ;
	}
    gotoxy(30,12);
    cout << " EMAIL ID       : ";
    for (int h = 0 ; names[2][h] != '\0' ; ++h )
	{
	    cout << names[2][h] ;
		Sleep(50) ;
	}
    gotoxy(30,13);
    cout << " DIGNOSTIC CENTRE : ";
    for (int h = 0 ; names[3][h] != '\0' ; ++h )
	{
	    cout << names[3][h] ;
		Sleep(50) ;
	}
    gotoxy(30,14);
    cout << " CONTACT NO.      : ";
    for (int h = 0 ; names[4][h] != '\0' ; ++h )
	{
	    cout << names[4][h] ;
		Sleep(50) ;
	}
    gotoxy(30,15);
    cout << " ADDRESS          : "<<names[5];
    gotoxy(30,16);
    cout << " TEST NAME      : ";
    for (int h = 0 ; names[6][h] != '\0' ; ++h )
	{
	    cout << names[6][h] ;
		Sleep(50) ;
	}
    gotoxy(30,17);
    cout << " TEST CATEGORY  : ";
    for (int h = 0 ; names[7][h] != '\0' ; ++h )
	{
	    cout << names[7][h] ;
		Sleep(50) ;
	}
    gotoxy(30,18);
    cout << " COST           : Rs.";
    for (int h = 0 ; names[8][h] != '\0' ; ++h )
	{
	    cout << names[8][h] ;
		Sleep(50) ;
	}
	gotoxy(35,20);
    cout<<"Press 1 to CONFIRM ";
    gotoxy(35,21);
    cout<<"Press 2 to RESET";
    int choice;
    choi:
    gotoxy(40,22);
    cout<<": ";
    cin>>choice;
    if(choice==1)
    {
        cover(35,6,85,25);
        gotoxy(50,9);
        cout<<"THANK YOU";
        gotoxy(45,11);
        cout<<names[0];
        gotoxy(45,13);
        cout<<"Hope You Get Well Soon";
        gotoxy(45,15);
        cout<<"Timing : 10:00 onwards";
        gotoxy(45,17);
        cout<<"Press Any Key to EXIT";
        getch();
        About(1);
        exit(0);
    }
    else if (choice ==2)
        MENU1(conn);
    else
        goto choi;
    getch();
}

//CREDITS MENU
void About(int i=2)
{
	system("cls");
	cover(30,3,90,24);
	gotoxy(46,4) ;
	Sleep(70);
	cout << " PATHOLOGY CONNECT "   ;
	gotoxy(35,6) ;
	Sleep(70);
	cout << " A project by - " ;
	gotoxy(35,7) ;
	Sleep(70);
	cout << " Akash Kumar Singhal \t CSE-IBM-BD1 " ;
	gotoxy(40,8);
	cout << " Contact : 9868238010; UID :18BCS3762";
	gotoxy(35,10) ;
	Sleep(70);
	cout << " Based on the Diagnostic Centres & Blood Tests" ;
	gotoxy(35,14) ;
	Sleep(70);
	cout << " Information Source - " ;
	gotoxy(35,16) ;
	Sleep(70);
	cout << " www.medifee.com " ;
	gotoxy(35,17) ;
	Sleep(70);
	cout << " www.lalpathlabs.com " ;
	gotoxy(35,19) ;
	Sleep(70);
	cout << " Technical Resources - " ;
	gotoxy(35,20) ;
	Sleep(70);
	cout << " Google and GeeksForGeeks.com " ;
	gotoxy(35,22) ;
	Sleep(70);
	cout << " THANK YOU !! " ;
	getch() ;
	if(i==1)
        exit(0);
}

//MAIN MENU
int main()
{
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","root","","pathoconnect",0,NULL,0);
    if(conn)
        cout<<"Connection to PATHOCONNECT Database successful "<<endl;
    else
        cout<<"Connection Problem: "<<mysql_error(conn)<<endl;
    welcome(conn);
    return 0;
}

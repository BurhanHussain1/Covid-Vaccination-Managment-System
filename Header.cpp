#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include<string>
#include<fstream>
#include<stdio.h>
#include "Header.h"
using namespace std;
void Files::setNumberofCitizen(int n)
{
	fstream out;
	out.open("numberofcitizens.txt", ios::out);
	out << n;
	out.close();
}

void Citizen::inputCitizenData(int idd)
{
	Methods mobj;
	string y;
	id = idd;
	cout << endl;
	cout << "Enter First Name :     ";
	cin.ignore();
	getline(cin, firstName);
	cout << "Enter Last Name  :     ";
	getline(cin, lastName);
	cout << "Enter ContactNo  :     ";
	getline(cin, contactNo);
	cout << "Enter Email      :     ";
	getline(cin, email);
	cout << "Enter Password   :     ";
	getline(cin, passWord);
	while (mobj.uniqueLogin(email, passWord))
	{
	cout << "Already taken : " << endl;
	cout << "enter new email and pass : " << endl;
	cout << "Enter email : ";
	cin >> email;
	cout << "Enter password : ";
	cin >> passWord;
	}
	cout << "Enter Cnic       :     ";
	getline(cin, cnic);
	cout << "Enter BloodType  :     ";
	getline(cin, bloodType);
	cout << "Enter State Name :     ";
	getline(cin, state);
	cout << "Enter Address    :     ";
	getline(cin, address);
	cout << "Enter City       :     ";
	getline(cin, city);
	cout << "\t\t\t\tEnter DATE OF BIRTH : " << endl;
	cout << "Enter Day        : ";
	cin >> day;
	cout << "Enter month      : ";
	cin >> month;
	cout << "Enter year       : ";
	cin >> year;
	age = mobj.calculateAge(day,month,year);
	cout << "Do you have allergic reaction to any of vaccines(Y or y) : ";
	cin >> y;
	if (y == "Y"|| y=="y")
	{
	flag = false;
	}

	else 
	{
	flag = true;
	}

	if (age < 5) 
	{
	flag = false;
	}
	else 
	{
	flag = true;
	}
	check_conformation(flag,cnic);
	outputCitizendata();
	
}

void Citizen::outputCitizendata()
{
	fstream out;
	fstream out1;
	out.open("Getcitizendata.txt", ios::app);
	out1.open("registeredpublic.txt", ios::app);
	out << getCnic() << endl;
	out << getfirstName() << endl;
	out << getLastName() << endl;
	out << getContactNo() << endl;
	out << getbloodType() << endl;
	out << getState() << endl;
	out << getAddress() << endl;
	out << getCity() << endl;
	out << getDay() << "-" << getMonth() << "-" << getYear() << endl;
	out << getId() << endl;
	out << getAge() << endl;
	out1 << getEmail() << endl;
	out1 << getPassword() << endl;
	cout << endl;
	out.close();
	out1.close();
}

string Citizen:: getfirstName()
{
	return firstName;
}
string Citizen::getLastName()
{
	return lastName;
}
string Citizen::getEmail()
{
	return email;
}
string Citizen::getContactNo()
{
	return contactNo;
}
int Citizen::getId()
{
	return id;
}
string Citizen :: getCnic() {
	return cnic;
}
string Citizen::getbloodType()
{
	return bloodType;
}
string Citizen::getState()
{
	return state;
}
string Citizen::getAddress()
{
	return address;
}
string Citizen::getCity()
{
	return city;
}
int Citizen::getDay()
{
	return day;
}
int Citizen::getMonth()
{
	return month;
}
int Citizen::getYear()
{
	return year;
}
string Citizen::getPassword()
{
	return passWord;
}
int Citizen::getAge()
{
	return age;
}

int Methods::uniqueId()
{
	fstream in;
	in.open("id.txt", ios::in);
	in >> id;
	in.close();
	id = id + 1;
	getUniqueid();	
	return id;
	
}

void Methods :: getUniqueid()
{
	fstream out;
	out.open("id.txt", ios::out);
	out << id << endl;
	out.close();
}

bool Citizen :: citizenLoginCheck(string userEmail, string userPass)
{
	fstream in;
	in.open("registeredpublic.txt", ios::in);
	string email, pass;
	while (!in.eof())
	{
	getline(in, email);
	getline(in, pass);
	if (userEmail == email && userPass == pass)
	{
		return true;
		break;
	}
	}
}

bool Methods::LoginCheck(string userEmail, string userPass)
{
	fstream in;
	in.open("registeredpublic.txt", ios::in);
	string email, pass;
	while (!in.eof())
	{
		in >> email;
		in >> pass;
		if (userEmail == email && userPass == pass)
		{
			return true;
			break;
		}
	}
	in.close();
}

void Citizen::check_conformation(bool y,string cnic)
{
	int x = 0;
	if (y == true) 
	{
	cout << "you have been registered and eligible for vaccination:" << endl;
	fstream out,out1;
	out.open("eligiblecitizens.txt",ios::app);
	out1.open("doses.txt", ios::app);
	out << cnic << endl;
	out1 << cnic << endl;
	out1 << x << endl;
	out.close();
	out1.close();
	}
	else 
	{
	cout << "Your are not eligible for vaccination:" << endl;
	}
}

int Methods :: calculateAge(int day,int month,int year)
{
	time_t ti = time(NULL);

	tm* datePtr = localtime(&ti);
	int age, d, m, y;
	d = (datePtr->tm_mday);
	m = (datePtr->tm_mon) + 1;
	y=(datePtr->tm_year) + 1900;
	if (m < month)
	{
		age = y - year;
		age = age - 1;
	}
	else
	age = y - year;
	return age;
}

int Files::getNumberofCitizen()
{
	fstream in;
	int c;
	in.open("numberofcitizens.txt", ios::in);
	in >> c;
	in.close();
	return c;
}

void Doctor :: setDoctor(int idd)
{
	Methods mobj;
	id = idd;
	cout << "\t\t\t\t\tDOCTOR DETAILS " << endl;
	cout << "Enter Cnic : ";
	cin.ignore();
	getline(cin, cnic);
	cout << "Enter First name : ";
	getline(cin, firstName);
	cout << "Enter Last name : ";
	getline(cin, lastName);
	cout << "Enter contact no : ";
	getline(cin, contactNo);
	cout << "Enter email : ";
	getline(cin,email);
	cout << "Enter password : ";
	getline(cin, passWord);
	while (mobj.uniqueLogin(email, passWord))
	{
	cout << "Already taken : " << endl;
	cout << "enter new email and pass : " << endl;
	cout << "Enter email : ";
	cin >> email;
	cout << "Enter password : ";
	cin >> passWord;
	}
	cout << "Enter Dutydays : ";
	cin >> dutydays;
	getDoctor();
}

void Doctor::getDoctor()
{
	fstream out,out1;
	out.open("doctorsdata.txt", ios::app);
	out1.open("registeredpublic.txt", ios::app);
	out << cnic<<endl;
	out << id << endl;
	out << firstName << endl;
	out << lastName << endl;
	out << contactNo << endl;
	out << dutydays << endl;
	out << email << endl;
	out << passWord << endl;
	out1 << email << endl;
	out1 << passWord << endl;
	out.close();
	out1.close();
}

void Admin::setAdmin(int idd)
{
	Methods mobj;
	id = idd;
	cout << "\t\t\t\t\tADMIN DETAILS " << endl;
	cout << "Enter Cnic : ";
	cin.ignore();
	getline(cin, cnic);
	cout << "Enter First name : ";
	getline(cin, firstName);
	cout << "Enter Last name : ";
	getline(cin, lastName);
	cout << "Enter contact no : ";
	getline(cin, contactNo);
	cout << "Enter email : ";
	getline(cin, email);
	cout << "Enter password : ";
	getline(cin, passWord);
	while (mobj.uniqueLogin(email, passWord))
	{
	cout << "Already taken : " << endl;
	cout << "enter new email and pass : " << endl;
	cout << "Enter email : ";
	cin >> email;
	cout << "Enter password : ";
	cin >> passWord;
	}
	getAdmin();
}

void Admin::getAdmin()
{
	fstream out,out1;
	out.open("admindata.txt", ios::app);
	out1.open("registeredpublic.txt", ios::app);
	out << cnic << endl;
	out << id << endl;
	out << firstName << endl;
	out << lastName << endl;
	out << contactNo << endl;
	out << email << endl;
	out << passWord << endl;
	out1 << email << endl;
	out1 << passWord << endl;
	out.close();
	out1.close();
}

void Fdo::setFdo(int idd)
{
	Methods mobj;
	id = idd;
	cout << "\t\t\t\t\tFdo DETAILS " << endl;
	cout << "Enter Cnic : ";
	cin.ignore();
	getline(cin, cnic);
	cout << "Enter First name : ";
	getline(cin, firstName);
	cout << "Enter Last name : ";
	getline(cin, lastName);
	cout << "Enter contact no : ";
	getline(cin, contactNo);
	cout << "Enter email : ";
	getline(cin, email);
	cout << "Enter password : ";
	getline(cin, passWord);
	while (mobj.uniqueLogin(email, passWord))
	{
	cout << "Already taken : " << endl;
	cout << "enter new email and pass : " << endl;
	cout << "Enter email : ";
	cin >> email;
	cout << "Enter password : ";
	cin >> passWord;
	}
	getFdo();
}

void Fdo::getFdo()
{
	fstream out,out1;
	out.open("fdodata.txt", ios::app);
	out1.open("registeredpublic.txt", ios::app);
	out << cnic << endl;
	out << id << endl;
	out << firstName << endl;
	out << lastName << endl;
	out << contactNo << endl;
	out1 << email << endl;
	out1 << passWord << endl;
	out.close();
	out1.close();
}

bool Methods :: checkEligiblePatient(string cnic) 
{
	string c;
	fstream in;
	bool y = false;
	in.open("eligiblecitizens.txt", ios::in);
	while (!in.eof())
	{
	in>>c;
	if (c == cnic)
	{
	y = true;
	break;
	}
	}
	return y;

}

void Citizen::viewHistory(string c)
{
	fstream read;
	string fn, ln, email, pass, contact, cnic, bt, state, address, city, dob;
	int id, age;
	read.open("Getcitizendata.txt", ios::in);
	while(!read.eof())
	{
	//cin.ignore();
	read>>cnic;
	read >> fn;
	read >> ln;
	read >> contact;
	read >> bt;
	read >> state;
	read >>address;
	read >> city;
	read >> dob;
	/*getline(read, ln);
	getline(read, contact);
	getline(read, bt);
	getline(read, state);
	getline(read, address);
	getline(read, city);
	getline(read, dob);*/
	read >> id;
	read >> age;
	if (cnic == c)
	{
		cout << "Cnic           : " << cnic << endl;
		cout << "First name     :  " << fn << endl;
		cout << "Last name      : " << ln << endl;
		cout << "Contact No     : " << contact << endl;
		cout << "Blood Type     : " << bt << endl;
		cout << "State          : " << state << endl;
		cout << "Address        : " << address << endl;
		cout << "City           : " << city << endl;
		cout << "Date Of Birth  : " << dob << endl;
		cout << "Id             : " << id << endl;
		cout << "Age            : " << age << endl;
		break;
	}
	}

}

void Vaccines :: setVaccine(int vacId,string vacType, string vacName, int no_Of_Doses, int price, int batch_Id,string expiry,int supplierId)
{
	this->vacId = vacId;
	this->vacType = vacType;
	this->vacName = vacName;
	this->no_Of_Doses = no_Of_Doses;
	this->price = price;
	this->batch_Id = batch_Id;
	this->expiry = expiry;
	this->supplierId = supplierId;
	getVaccine();
}

void Vaccines :: getVaccine()
{
	fstream out;
	out.open("vaccinesdata.txt", ios::app);
	out << vacName << endl;
	out << no_Of_Doses << endl;
	out << expiry << endl;
	out << vacType << endl;
	out << vacId << endl;
	out << price << endl;
	out << batch_Id << endl;
	out << supplierId << endl;
	out.close();
}

void Companies :: buyVaccines() 
	{
		int c;
		Methods mobj;
		cout << "Which Vaccine you want to buy : " << endl;
		cout << "1) for international vaccines : " << endl;
		cout << "2) for Local vaccines : " << endl;
		cout << "Enter choice : ";
		cin >> c;
		mobj.intcrashCheck(c);
		if(c==1)
		{
		string name, type,expiry;
		int id, dose, price,batchid,doses,supid;
		int x, y;
		companyName = "INTERNATIONAL COMPANY ";
		cout << "\nCOMPANY NAME : " << companyName << endl;
		cout << endl;
		cout << "Types available are :  (WHOLE VIRUS, PROTEIN SUBUNIT, VIRAL VECTOR and NUCLEIC ACID)" << endl;
		cout << "Vaccines available are :  (Sinopharm, Phizer)" << endl;
		cout << "Enter type of vaccines you want : " << endl;
		cout << "1).For(WHOLE VIRUS)" << endl;
		cout << "2).For(PROTEIN SUBUNIT)" << endl;
		cout << "3).For(VIRAL VECTOR)" << endl;
		cout << "4).For(NUCLEIC ACID)" << endl;
		cin >> x;
		if (x == 1)
		type = "WHOLEVIRUS";
		else if (x == 2)
		type = "PROTEINSUBUNIT";
		else if (x == 3)
		type = "VIRALVECTOR";
		else if (x == 4)
		type = "NUCLEIC ACID"; 
		else
		cout<<"invalid choice"<<endl;
		cout << endl;
		cout << "Enter vaccine name you want to buy : "<<endl;
		cout << "1).For(Sinopharm)" << endl;
		cout << "2).For(Phizer)" << endl;
		cin >> x;
		if (x == 1)
		name = "Sinopharm";
		else if (x == 2)
		name = "Phizer";
		else
		cout<<"Invalid input"<<endl;
		id = mobj.uniqueId();
		batchid = mobj.uniqueId();
		supid = mobj.uniqueId();
		cout << "Enter non of doses of vaccines : ";
		cin >> doses;
		cout << "Enter price of vaccine : " ;
		cin >> price;
		mobj.tprice(price);
		cout << "Enter Vaccine expiry date (format 12-10-2005) : ";
		cin.ignore();
		getline(cin, expiry);
		mobj.checkcount();
		vac.setVaccine(id, type, name,doses, price, batchid,expiry,supid);
		}

		else if (c == 2)
		{
		string name, type,expiry;
		int id,dose, price,batchid,doses,supid;
		int x, y;
		companyName = "LOCAL COMPANY ";
		cout << "\nCOMPANY NAME : " << companyName << endl;
		cout << endl;
		cout << "Types available are    :  (WHOLE VIRUS, PROTEIN SUBUNIT, VIRAL VECTOR and NUCLEIC ACID)" << endl;
		cout << "Vaccines available are :  (Sinopharm, Phizer)" << endl;
		cout << "Enter type of vaccines you want : " << endl;
		cout << "1).For(WHOLE VIRUS)" << endl;
		cout << "2).For(PROTEIN SUBUNIT)" << endl;
		cout << "3).For(VIRAL VECTOR)" << endl;
		cout << "4).For(NUCLEIC ACID)" << endl;
		cin >> x;
		if (x == 1)
		type = "WHOLEVIRUS";
		else if (x == 2)
		type = "PROTEINSUBUNIT";
		else if (x == 3)
		type = "VIRALVECTOR";
		else if (x == 4)
		type = "NUCLEICACID"; 
		else
		cout<<"invalid choice"<<endl;
		cout << endl;
		cout << "Enter vaccine name you want to buy : "<<endl;
		cout << "1).For(Sinopharm)" << endl;
		cout << "2).For(Phizer)" << endl;
		cin >> x;
		if (x == 1)
		name = "Sinopharm";
		else if (x == 2)
		name = "Phizer";
		else
		cout<<"Invalid input"<<endl;
		id = mobj.uniqueId();
		batchid = mobj.uniqueId();
		supid = mobj.uniqueId();
		cout << "Enter price of vaccine : " ;
		cin >> price;
		mobj.tprice(price);
		cout << "Enter no of doses of vaccine : " ;
		cin >> doses;
		cout << "Enter Vaccine expiry date (format 12-10-2005) : ";
		cin.ignore();
		getline(cin, expiry);
		mobj.checkcount();
		vac1.setVaccine(id,type, name,doses, price, batchid,expiry,supid);
		}

	}

	void Admin :: procureVaccines()
	{
		Companies cobj;
		cobj.buyVaccines();
	}

	void Warehouse :: creatWarehouse()
	{
		Methods mobj;
		cout << "Enter Ware house name  : ";
		cin >> warehouseName;
		cout << "Enter Ware house Location  : ";
		cin >> warehouselocation;
		cout << "Enter Ware house Capacity : ";
		cin >> warehouseCapacity;
		warID = mobj.uniqueId();
		getWarehouse();
	}

	void Warehouse::getWarehouse()
	{
		fstream out;
		out.open("warehousedata.txt", ios::app);
		out << warehouseName<<endl;
		out << warehouselocation<<endl;
		out << warehouseCapacity<<endl;
		out << warID<<endl;
		out.close();
	}

	void Admin::warehouse_creation()
	{
		Warehouse wobj;
		Methods mobj;
		wobj.creatWarehouse();
		fstream in, out;
		string choice, name, expiry, type;
		int id, price, bid, sid, doses, q;
		int checkid=0;
		out.open("warehousedata.txt", ios::app);
		in.open("vaccinesdata.txt", ios::in);
		cout << "\nWAREhouse created successfully\n" << endl;
		cout << "Which vaccine you want to store in warehouse : " << endl;
		cout << "S).For(Sinopharm)" << endl;
		cout << "P).For(Phizer)" << endl;
		cout << "Choice : ";
		cin >> choice;
		if (choice == "S" || choice == "s")
		choice = "Sinopharm";
		else if (choice == "P" || choice == "p")
		choice = "Phizer";
		int count = 0, count1 = 0;
		int capacity;
		while (!in.eof())
		{
			in >> name >> doses >> expiry >> type >> id >> price >> bid >> sid;
			if (name == choice)
			{
				cout << "Enter number of vaccines you want to store in warehouse : ";
				cin >> q;
				if (doses == 0)
				{
					cout << "sorry no vaccines available at the moment please come again : " << endl;
					break;
				}
				while (q > doses)
				{
					cout << "Not enough vaccines : " << endl;
					cout << "Only " << doses << " available" << endl;
					cout << "Input again : ";
					cin >> q;
				}
				capacity = stoi(wobj.warehouseCapacity);
				while (q > capacity)
				{
					cout << "Sorry you cant store too much vaccine : " << endl;
					cout << "the ware house capacity is only " << capacity << endl;
					cout << "Input again : ";
					cin >> q;
				}

				checkid = id;
				out << name << endl;
				out << q << endl;
				out << expiry << endl;
				cout << "Vaccines loaded successfully to " << wobj.warehouselocation << " warehouse : " << endl;
				count++;
				break;
			}

			else if (in.eof())
			{
				int u;
				cout << "Sorry Your desired vaccine is not available  : " << endl;
				cout << "This vaccine " << name << " available : " << endl;
				cout << "If you want press 1 : ";
				cin >> u;
				if (u == 1)
				{
					cout << "Enter number of vaccines you want to store in warehouse : ";
					cin >> q;
					while (q > doses)
					{
						cout << "Not enough vaccines : " << endl;
						cout << "Only " << doses << " available" << endl;
						cout << "Input again : ";
						cin >> q;
					}

					capacity = stoi(wobj.warehouseCapacity);
					while (q > capacity)
					{
						cout << "Sorry you cant store too much vaccine : " << endl;
						cout << "the ware house capacity is only " << capacity << endl;
						cout << "Input again : ";
						cin >> q;
					}

					if (doses == 0)
					{
						cout << "sorry no vaccines available at the moment please come again : " << endl;
					}

					checkid = id;
					out << name << endl;
					out << q << endl;
					out << expiry << endl;
					cout << "Vaccines loaded successfully to " << wobj.warehouselocation << " warehouse : " << endl;
					count++;
					break;
				}
				else
				{
					cout << "Thanks you have a nice day : " << endl;
				}

			}
		}

			in.close();
			out.close();

			if (count != 0)
			{
			mobj.checkdoses(q, checkid);
			}

	}

	void VaccinationCenter::creatVaccinationcenter()
	{
		Methods mobj;
		cout << "Enter city for vaccination centre : ";
		cin >> city;
		vID = mobj.uniqueId();
		getVaccinationcenter();
	}

	void VaccinationCenter::getVaccinationcenter()
	{
		fstream out;
		out.open("vaccinationcenter.txt", ios::app);
		out << city << endl;
		out << vID << endl;
		out.close();
	}

	void Admin::vaccinationCenter_creation()
	{
		VaccinationCenter vobj;
		Methods mobj;
		vobj.creatVaccinationcenter();
		fstream in,in1,out;
		string choice,wname,location,vname,expiry,name,capacity;
		int doses,x,wid,vccid;
		string dname, cname,vcc;
		Warehouse wobj;
		in.open("warehousedata.txt", ios::in);
		in1.open("districts.txt", ios::in);
		out.open("vaccinationcenter.txt", ios::app);
		cout << "\nVACCINATION CENTER created successfully\n" << endl;
		int j, count = 0, checkid = 0;;
		while (!in.eof())
		{
			in >> wname >> location >> capacity>> wid >> vname >> doses >> expiry;
			while (!in1.eof())
			{
			in1 >> dname;
			
			if(dname==location)
			{
			while (true)
			{
				in1 >> cname;
				if (cname == "z")
				{
				break;
				}

				
				if (vobj.city == cname)
				{
				cout << "Enter vaccines amount to send to vaccination center " << endl;
			    cin >> x;
			    while(x > doses)
			    {
			    cout << "Only " << doses << " available" << endl;
			    cout << "Enter again : ";
			    cin >> x;
			    }

			    if (doses == 0)
			    {
			    cout << "Sorry No doses Available in the warehouse : " << endl;
				break;
			    }
                checkid = wid;
			    out << vname <<endl;
			    out << x << endl;
			    out << expiry << endl;
			    cout << vname << " Vaccines loaded successfully to " << vobj.city << " vaccination Centre " << endl;
			    count++;
			    break;
				}

			}

			if (cname == "z")
			{
			break;
			}

			}
			}
			
		}

		in.close(); 
		in1.close();
		out.close();

		if (count == 0)
		{
		cout << "Sorry no warehouse found in your District " << endl;
		}
		if (count != 0)
		{
		mobj.decrementdoses(x, checkid);
		}
		
	}

	void Doctor::doctorAssign(string Cnic)
	{
		cout << "\nDoctor Counter" << endl;
		fstream in, in1, out;
		int num = 0;
		Methods mobj;
		string c;
		int n,n1,x=0;
		
		while (x==0)
		{
			cout << "\nEnter Doctor Login Details : " << endl;
			cout << "1)Login : " << endl;
			cout << "2)exit : " << endl;
			cin >> n;
			string doMail, doPass;
			if (n == 1)
			{
			cout << "Enter Email : ";
			cin.ignore();
			getline(cin, doMail);
			cout << "Enter Password : ";
			getline(cin, doPass);
			bool z = false;
			z = mobj.LoginCheck(doMail, doPass);
			if (z == true)
			{
			cout << "Access granted : " << endl;
			checkPatient(Cnic);
			x = 1;
			break;
			}
			else
			{
			cout << "Wrong input : " << endl;
			cout << "1) input again : " << endl;
			cout << "2) Exit : " << endl;
			cin >> n1;
			if (n1 == 1)
			{
			x = 0;
			}
			else if (n1 == 2)
			{
			x = 1;
			}
			}
			}

			else if (n == 2)
			{
			break;
			}
		}

		
	}
   
	bool Methods :: uniqueLogin(string email, string password)
	{
		fstream in;
		in.open("registeredpublic.txt", ios::in);
		bool y = false;;
		string e, p;
		while (!in.eof())
		{
			in >> e;
			in >> p;
			if (e == email && p == password)
			{
				y = true;
				break;
			}
			y = false;
		}
		return y;
		in.close();
	}

	void SuperAdmin::Add()
	{
		int x,n,id;
		Methods mobj;
		cout << "(1).Add Admin()" << endl;
		cout << "(2).Add doctor()" << endl;
		cin >> x;
		if (x == 1)
		{
			cout << "Enter no of admins to creat : " << endl;
			cin >> n;
			mobj.intcrashCheck(n);
			aptr = new Admin[n];
			for (int i = 0; i < n; i++)
			{
			id = mobj.uniqueId();
			aptr[i].setAdmin(id);
			}
		}

		if (x == 2)
		{
			cout << "Enter no of doctors to create : " << endl;
			cin >> n;
			dptr = new Doctor[n];
			for (int i = 0; i < n; i++)
			{
			id = mobj.uniqueId();
			dptr[i].setDoctor(id);
			}
		}

		else
		cout << "Invalid Input" << endl;
	}

	void SuperAdmin :: Delete()
	{
	int i;
	cout << "(1).Delete Admin()" << endl;
	cout << "(2).Delete doctor()" << endl;
	cin >> i;
	if (i == 1)
	{
	DeleteAdmin();
	}
	else if (i == 2)
	{
	DeleteDoctor();
	}
	else
	cout << "Invalid Input" << endl;
	}

	void SuperAdmin::DeleteAdmin()
	{
		string cnic;
		cout << "Enter cnic to delete Admin : ";
		cin >> cnic;
		string cn, fn, ln, contact, email, pass;
		int id;
		fstream in, out;

		in.open("admindata.txt", ios::in);
		out.open("dummy.txt", ios::out);
		while (!in.eof())
		{
			in >> cn >> id >> fn >> ln >> contact >> email >> pass;
			if (cnic != cn)
			{
				out << cn << endl;
				out << id << endl;
				out << fn << endl;
				out << ln << endl;
				out << contact << endl;
				out << email << endl;
				out << pass << endl;
			}
		}

		in.close();
		out.close();
	    remove("admindata.txt");
		rename("dummy.txt","admindata.txt");
	}
	     
	void SuperAdmin::DeleteDoctor()
	{
     string cnic;
		cout << "Enter cnic to delete doctor : ";
		cin >> cnic;
		string cn, fn, ln, contact, email, pass;
		int id,ddays;
		fstream in, out;

		in.open("doctorsdata.txt", ios::in);
		out.open("dummy.txt", ios::out);
		while (!in.eof())
		{
			in >> cn >> id >> fn >> ln >> contact >> ddays>> email >> pass;
			if (cnic != cn)
			{
				out << cn << endl;
				out << id << endl;
				out << fn << endl;
				out << ln << endl;
				out << contact << endl;
				out << ddays << endl;
				out << email << endl;
				out << pass << endl;
			}
		}

		in.close();
		out.close();
		remove("doctorsdata.txt");
		rename("dummy.txt","doctorsdata.txt");
	}

	void SuperAdmin::updateDoctor()
	{
	string cnic;
	cout << "Enter cnic to update doctor : ";
	cin >> cnic;
	}

	void SuperAdmin::updateAdmin()
	{

	}

	void Methods::checkdoses(int q,int id)
	{
		fstream in,in1, out;
		string vn,ex, vtype;
		int doses, vid,price, bId, sId,count;
		in1.open("count.txt", ios::in);
		in1 >> count;
		in1.close();
		in.open("vaccinesdata.txt", ios::in);
		out.open("dum.txt", ios::out);
		for (int i=0;i<count;i++)
		{
			in >> vn >> doses >> ex >> vtype >> vid >> price >> bId >> sId;
			if (doses == 0)
			{
				break;
			}
			if (id == vid)
			{
				out << vn << endl;
				doses = doses - q;
				out << doses << endl;
				out << ex << endl;
				out << vtype << endl;
				out << vid << endl;
				out << price << endl;
				out << bId << endl;
				out << sId << endl;
			}
			else
			{
				out << vn << endl;
				out << doses<< endl;
				out << ex << endl;
				out << vtype << endl;
				out << vid << endl;
				out << price << endl;
				out << bId << endl;
				out << sId << endl;
			}
		}

		in.close();
		out.close();
		remove("vaccinesdata.txt");
		rename("dum.txt", "vaccinesdata.txt");
	}

	void Methods :: checkcount()
	{
		fstream in,out;
		int count;
		in.open("count.txt", ios::in);
		in >> count;
		in.close();
		out.open("count.txt", ios::out);
		count = count + 1;
		out << count << endl;;
		out.close();
	}

	void Methods::intcrashCheck(int n)
	{
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid Input  : " << endl;
		cout << "Enter input again : ";
		cin >> n;
	}
	}

	void Methods :: decrementdoses(int x, int cid)
	{
    fstream in,out;
	string wn, loc,vn,exp;
	int cap,wid,doses;
	in.open("warehousedata.txt", ios::in);
	out.open("dum1.txt", ios::out);
	for(int i=0;i<2;i++)
	{
    in >> wn >> loc >> cap >> wid >> vn >> doses >> exp;
	if (doses == 0)
	{
	break;
	}
	if (cid == wid)
	{
	out << wn << endl;
	out << loc << endl;
	out << cap << endl;
	out << wid << endl;
	out << vn << endl;
	doses = doses - x;
	out << doses << endl;
    out << exp << endl;
	}
	else
	{
	out << wn << endl;
	out << loc << endl;
	out << cap << endl;
	out << wid << endl;
	out << vn << endl;
	out << doses << endl;
	out << exp << endl;
	}
	}

	in.close();
	out.close();
	remove("warehousedata.txt");
	rename("dum1.txt", "warehousedata.txt");
	}

	void Methods::tprice(int p)
	{
		fstream out;
		out.open("prices.txt", ios::app);
		out << p << endl;
		out.close();
	}

	void Doctor :: checkPatient(string cnic)
	{
	fstream in,in1, out,in2,in3;
	string C;
	Methods mobj;
    in.open("eligiblecitizens.txt", ios::in);
    out.open("patientFile.txt", ios::app);	
	in1.open("vaccinationcenter.txt", ios::in);
	in2.open("Getcitizendata.txt", ios::in);
	string cn,city;
	string a, b, c, d, e, f, g;
	int h, i;
	string vcc,vn,expiry;
	int y,id,doses;
	while (!in.eof())
	{
		in >> C;
		if (cnic == C)
		{
		while (!in2.eof())
		{
		in2 >> cn>>a>>b>>c>>d>>e>>f>>city>>g>>h>>i;
		if (cnic == cn)
		{
		break;
		}
		}

		cout << city << endl;

		while (!in1.eof())
		{
		in1 >> vcc >>id >> vn >> doses >> expiry;
		if(vcc==city)
		{
		cout << vn << " vaccine is available" << endl;
		cout << "1)To be vaccinated " << endl;
		cout << "2)To exit " << endl;
		cin >> y;
		if (y == 1)
		{
		cout << "Enter patient blood pressure : ";
		cin >> bp;
		cout << "Enter patient oxygen level : ";
		cin >> oxygen_level;
		cout << "Enter patient glucose level : ";
		cin >> glucose;
		out << cnic << endl;
		out << bp << endl;
		out << oxygen_level << endl;
		out << glucose << endl;
		in3.open("doses.txt", ios::in);
		string dcnic;
		int ad;
		while (!in3.eof())
		{
		in3 >> dcnic;
		in3 >> ad;
		if (dcnic == cnic)
		{
		if (ad == 0)
		{
		//mobj.dosecheck(vcc);
	    mobj.increaseDoses(dcnic);
		cout << "Thank you Your first vaccinated dose done : " << endl<<endl;
		}
		else if (ad == 1)
		{
		cout << "Thank you Your 2nd vaccinated dose done : " << endl<<endl;
		}

		else if (ad == 2)
		{
		cout << "You are already completetly vaccinated " << endl<<endl;
		}
		break;
		}
		}
		}
		else if (y == 2)
		{
		break;
		}
		break;
		}
		}
		break;
		}
	}
	in.close();
	in.close();
	in.close();
	in.close();
	out.close();
	}

	void Methods :: dosecheck(string city)
	{
		fstream in;
		ofstream out;
		in.open("vaccinationcenter.txt",ios::in);
		out.open("dumm.txt");
		string vcc, vid, vn, exp;
		int doses;
		system("cls");
		for(int i=0;i<1;i++)
		{
		in >> vcc >> vid >> vn >> doses >> exp;

		if (vcc == city)
		{
			out << vcc << endl;
			out << vid << endl;
			out << vn << endl;
			doses = doses - 1;
			out << doses << endl;
			out << exp << endl;
		}

		else
		{
			out << vcc << endl;
			out << vid << endl;
			out << vn << endl;
			out << doses << endl;
			out << exp << endl;
		}
		}
		in.close();
		out.close();
		remove("vaccinationcenter.txt");
		rename("dumm.txt", "vaccinationcenter.txt");
	}

	void Methods :: increaseDoses(string dcnic)
	{
		fstream in, out;
		in.open("doses.txt", ios::in);
		out.open("dum2.txt", ios::out);
		string cnic;
		int doses,d;
		while (!in.eof())
		{
		in >> cnic >> doses;
		if (cnic == dcnic)
		{
			out << cnic << endl;
			d = doses + 1;
			out << d << endl;
			cout << d << endl;
		}
		else
		{
			out << cnic << endl;
			out << doses << endl;
		}
		}
		in.close();
		out.close();
		remove("doses.txt");
		rename("dum2.txt", "doses.txt");
	}



























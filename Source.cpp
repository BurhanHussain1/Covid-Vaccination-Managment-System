#include<iostream>
#include<string>
#include"Header.h"
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n =0;
	int n1,n2,n3,n4;
	int id;
	fstream in;
	Citizen ctz;
	Files fil;
	Methods mobj;
	SuperAdmin sobj;
	Doctor dobj;
	int count = fil.getNumberofCitizen();
	while (true)
	{
		label:
		cout << "\t\t\t\t\t\t(1) -> SuperAdmin Access " << endl;
		cout << "\n\t\t\t\t\t\t(2) -> Citizen Access " << endl;
		cout << "\n\t\t\t\t\t\t(3) -> FDO Access " << endl;
		cout << "\n\t\t\t\t\t\t(4) -> Admin Access " << endl;
		cout << "\n\t\t\t\t\t\t(5) -> Govt Officals Access " << endl;
		cin >> n1;
		mobj.intcrashCheck(n1);
		n2 = 0;
		if (n1 == 1)
		{
	    while(n2==0)
		{
		string Supername = "Burhan";
		string Superpass =  "123";
		string Superusername;
		string Superuserpass;
		cout << endl;
		cout << "Enter Username :";
		cin.ignore();
		getline(cin, Superusername);
		cout << "Enter Password :";
		getline(cin, Superuserpass);
		if (Supername == Superusername && Superpass == Superuserpass)
		{
		int j;
		cout << "Super Admin access granted "<<endl;
		cout << "1) Creat " << endl;
		cout << "2) UPDATE " << endl;
		cout << "3) DELETE " << endl;
		cout << "Choice : ";
		cin >> j;
		mobj.intcrashCheck(j);
		if (j == 1)
		{
		sobj.Add();
		}
		else if (j == 2)
		{
        
		}
		else if (j == 3)
		{
		sobj.Delete();
		}

		n2 = 1;
		}
		else
		{
		cout << endl;
		cout << "INVALID INPUT " << endl;
		cout << "(0) -> Input Again " << endl;
		cout << "(9) -> Main Menu " << endl;
		cout << "Input : ";
		cin >> n2;
		mobj.intcrashCheck(n2);
		}
		}
		}

		else if (n1 == 2)
		{
			n3 = 0;
			while(true)
			{ 
			cout << endl;
			cout << "(1) -> For Sign Up " << endl;
			cout << "(2) -> For Login " << endl;
			cout << "(3) -> To check eligibility criteria  : " << endl;
			cout << "(4) -> To view details " << endl;
			cout << "(5) -> To Exit " << endl;
			cout << "Enter Choice : ";
			cin >> n3;
			mobj.intcrashCheck(n3);
			if (n3 == 1)
			{
			cout << "\nFill the Form to Register  : " << endl;
			id = mobj.uniqueId();
			ctz.inputCitizenData(id);
			fil.setNumberofCitizen(count++);
			}

			else if (n3 == 2)
			{
			n4 = 0;
			while(n4==0)
			{ 
            cout<<"Enter Login Details : "<<endl;
			string citizenMail, citizenPass;
			cout << "Enter Email : ";
			cin.ignore();
			getline(cin, citizenMail);
			cout << "Enter Password : ";
			getline(cin, citizenPass);
			bool y = false;
			y=ctz.citizenLoginCheck(citizenMail, citizenPass);
			if (y == true)
			{
			cout << "Successfully Login " << endl;
			cout << "You are registered : " << endl;
			break;
			}

			else
			{
			cout << "Wrong Email and Password " << endl;
			cout << "(0) -> Input Again " << endl;
			cout << "(9) -> Main Menu " << endl;
			cout << "Input : ";
			cin >> n4;
			mobj.intcrashCheck(n4);
			}
			}

			}
			else if (n3 == 3)
			{
				string CNIC;
				cout << "Enter your Cnic number : ";
				cin.ignore();
				getline(cin,CNIC);
				if(mobj.checkEligiblePatient(CNIC)==true)
			    cout<<"YOU ARE ELIGIBLE FOR VACCINATION"<<endl;
				else
				cout << "YOU ARE NOT ELIGIBLE FOR VACCINATION" << endl;
			}
			else if (n3 == 4)
			{
				string cnicc;
				cout << "Enter person cnic to view history : ";
				cin.ignore();
				getline(cin, cnicc);
				ctz.viewHistory(cnicc);
			}
			else if (n3 == 5)
			{
			break;
			}
			}
		}

		else if (n1 == 3)
		{
			int x;
			Fdo fobj;
			cout << "FDO ACCESS : " << endl;
			while(true)
			{
			cout << "(1) -> For Sign Up " << endl;
			cout << "(2) -> For Login " << endl;
			cout << "(3) -> To Exit " << endl;
			cin >> x;
			mobj.intcrashCheck(x);
			if (x == 1)
			{
			Methods mobj;
			cout << "\nFill the Form to Register  : " << endl;
			id = mobj.uniqueId();
			fobj.setFdo(id);
			}

			else if (x == 2)
			{
            n4 = 0;
			while(n4==0)
			{ 
            cout<<"Enter Login Details : "<<endl;
			string fdoMail, fdoPass;
			cout << "Enter Email : ";
			cin.ignore();
			getline(cin, fdoMail);
			cout << "Enter Password : ";
			getline(cin, fdoPass);
			bool z = false;
			z=mobj.LoginCheck(fdoMail, fdoPass);
			if (z == true)
			{
			string cnic;
			bool k = false;
			cout << "Successfully Login" << endl;
			cout << "\nEnter patient Cnic for vaccination : ";
			getline(cin, cnic);
			k = mobj.checkEligiblePatient(cnic);
			if (k == true)
			{
			cout << "you are eligible and referred to doctor" << endl;
			dobj.doctorAssign(cnic);
			break;
			}
			else
			{
			cout << "you are not eligible : " << endl;
			goto label;
			}
			}

			else
			{
			cout << "Wrong Email and Password " << endl;
			cout << "(0) -> Input Again " << endl;
			cout << "(9) -> Main Menu " << endl;
			cout << "Input : ";
			cin >> n4;
			}
			}
			}

			else if (x == 3)
			{
			break;
			}

			}
		}

		else if (n1 == 4)
		{
		  int x,k;
			Admin aobj;
			cout << "Admin ACCESS : " << endl;
			while(true)
			{
			cout << "(1) -> For Sign Up " << endl;
			cout << "(2) -> For Login " << endl;
			cin >> x;
			if (x == 1)
			{
			Methods mobj;
			cout << "\nFill the Form to Register  : " << endl;
			id = mobj.uniqueId();
			aobj.setAdmin(id);
			}

			else if (x == 2)
			{
            n4 = 0;
			while(n4==0)
			{ 
            cout<<"Enter Login Details : "<<endl;
			string aMail, aPass;
			cout << "Enter Email : ";
			cin.ignore();
			getline(cin, aMail);
			cout << "Enter Password : ";
			getline(cin, aPass);
			bool z = false;
		    z=mobj.LoginCheck(aMail, aPass);
			if (z == true)
			{
			string cnic;
			cout << "Successfully Login" << endl;
			cout << "(1).To buy vaccines : " << endl;
			cout << "(2).To create warehouse : " << endl;
			cout << "(3).To send vaccines to vaccination centers : " << endl;
			cin >> k;
			if (k == 1)
			{
			aobj.procureVaccines();
			cout << "Vaccines bought successfully " << endl;
			}

			if (k == 2)
			{
			aobj.warehouse_creation();
			}

			if (k == 3)
			{
			aobj.vaccinationCenter_creation();
			}
			n4 = 1;
			}

			else
			{
			cout << "Wrong Email and Password " << endl;
			cout << "(0) -> Input Again " << endl;
			cout << "(9) -> Main Menu " << endl;
			cout << "Input : ";
			cin >> n4;
			}
			}
			}
			}
        }
	}
}



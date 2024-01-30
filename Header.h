#ifndef Classes_H
#define Classes_H
using namespace std;

class Person {
protected:
	string firstName;
	string lastName;
	string email;
	string passWord;
	string contactNo;
	int id;
};


//CITIZEN
class Citizen : public Person {
public:
	string cnic;
	string bloodType;
	string state;
	string address;
	string city;
	int day;
	int month;
	int year;
	int age;
	bool flag;
	
	string getfirstName();
	string getLastName();
	string getEmail();
	string getContactNo();
	int getId();
	string getCnic();
	string getbloodType();
	string getState();
	string getAddress();
	string getCity();
	int getDay();
	int getMonth();
	int getYear();
	string getPassword();
	int getAge();

	void inputCitizenData(int idd);
	void outputCitizendata(); 
	void check_conformation(bool,string);
	bool citizenLoginCheck(string userEmail, string userPass);
	void viewHistory(string);
	friend class SuperAdmin;
	
};

class Files {
public:
	int getNumberofCitizen();
	void setNumberofCitizen(int);
};



class Methods {
private:
	int id;
public:
	int uniqueId();
	void getUniqueid();
	int calculateAge(int ,int ,int);
	bool LoginCheck(string userEmail, string userPass);
	bool checkEligiblePatient(string);
	bool uniqueLogin(string,string);
	void checkdoses(int,int);
	void checkcount();
	void intcrashCheck(int);
	void decrementdoses(int,int);
	void tprice(int);
	void dosecheck(string);
	void increaseDoses(string);
};

class Admin : public Person {
	string cnic;
public:
	void setAdmin(int);
	void getAdmin();
	void procureVaccines();
	void warehouse_creation();
	void vaccinationCenter_creation();
     
};

class Vaccines {
public:
	    int vacId;
	    string vacType;              //(WHOLE VIRUS, PROTEIN SUBUNIT, VIRAL VECTOR and NUCLEIC ACID)
		string vacName;              //(sinopharm, pfizer)
		int no_Of_Doses;
		int price;
		int batch_Id;
		string expiry;
		int supplierId;
		void setVaccine(int,string, string, int, int, int,string,int);
		void getVaccine();
		friend class SuperAdmin;	 
};

class Companies {
private:
	string companyName;
	Vaccines vac;
	Vaccines vac1;
	void buyVaccines();
	friend class Admin;
	friend class SuperAdmin;
};

class Warehouse {
private:
	string warehouseName;
	string warehouselocation;
	string warehouseCapacity;
	int warID;
	friend class Admin;
	void creatWarehouse();
	void getWarehouse();
	friend class SuperAdmin;

};

class VaccinationCenter {
	string city;
	int vID;
	void creatVaccinationcenter();
	void getVaccinationcenter();
	friend class Admin;
	friend class SuperAdmin;
	   
};


//FDO
class Fdo : public Person
{
	string cnic;
public:
	void setFdo(int);
	void getFdo();
	friend class SuperAdmin;
};
//DOCTOR
class Doctor: public Person{
	string cnic;
	int dutydays;
	string bp;
	string oxygen_level;
	string glucose;
	friend class SuperAdmin;
public:
	void setDoctor(int );
	void getDoctor();
	void doctorAssign(string );
	void checkPatient(string);
	
};

class SuperAdmin {
private:
	Admin* aptr;
	Doctor* dptr;
public:
	void Add();
	void Delete();
	void DeleteDoctor();
	void DeleteAdmin();
	void updateDoctor();
	void updateAdmin();
};


#endif

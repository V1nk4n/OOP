#include <iostream>
using namespace std;

class Student {
private:
	char* Name;
	char* ID;
	char* Birth;
	double Marks[3];
	double Avr;
public:
	Student();
	Student(char* val_Name, char* val_ID, char* val_Birth, double val_Marks[]);
	~Student();
	Student& operator=(const Student&);

	//default constructor
	Student() {
		this->Name = nullptr;
		this->ID = nullptr;
		this->Birth = nullptr;
	}

	//parameter constructor
	Student(char* val_Name, char* val_ID, char* val_Birth, double val_Marks[]) {
		this->Name = new char[strlen(val_Name) + 1];
		this->ID = new char[strlen(val_ID) + 1];
		this->Birth = new char[strlen(val_Birth) + 1];

		strcpy(this->Name, val_Name);
		strcpy(this->ID, val_ID);
		strcpy(this->Birth, val_Birth);

		for (int i = 0; i < 3; i++) {
			this->Marks[i] = val_Marks[i];
		}
		this->Avr = Marks[0] * 0.25 + Marks[1] * 0.25 + Marks[2] * 0.5;
	}

	//copy constructor
	Student(const Student& val_Data) {
		this->Name = new char[strlen(val_Data.Name) + 1];
		this->ID = new char[strlen(val_Data.ID) + 1];
		this->Birth = new char[strlen(val_Data.Birth) + 1];

		strcpy(this->Name, val_Data.Name);
		strcpy(this->ID, val_Data.ID);
		strcpy(this->Birth, val_Data.Birth);

		for (int i = 0; i < 3; i++) {
			this->Marks[i] = val_Data.Marks[i];
		}
		this->Avr = this->Marks[0] * 0.25 + this->Marks[1] * 0.25 + this->Marks[2] * 0.5;
	}

	//assignment operator
	Student& operator=(const Student& val_Data) {
		if (this != &val_Data) {
			delete[] this->Name;
			delete[] this->ID;
			delete[] this->Birth;

			this->Name = new char[strlen(val_Data.Name) + 1];
			this->ID = new char[strlen(val_Data.ID) + 1];
			this->Birth = new char[strlen(val_Data.Birth) + 1];

			strcpy(this->Name, val_Data.Name);
			strcpy(this->ID, val_Data.ID);
			strcpy(this->Birth, val_Data.Birth);

			for (int i = 0; i < 3; i++) {
				this->Marks[i] = val_Data.Marks[i];
			}
			this->Avr = this->Marks[0] * 0.25 + this->Marks[1] * 0.25 + this->Marks[2] * 0.5;
		}
		return *this;
	}

	~Student() {
		delete[] this->Name;
		delete[] this->ID;
		delete[] this->Birth;

		this->Name = nullptr;
		this->ID = nullptr;
		this->Birth = nullptr;
	}
};
class Manager {
private:
	Student Data;
	Manager* Next;
	Manager* createStudent(Student val_Data);
public:
	void writeFile();
	Manager* readFile();
	void findLessAvr();
	void add();
	void classify();
	void out();
	void findSameBirth(); 
};
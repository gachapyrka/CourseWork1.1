#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <locale.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <Windows.h>
#include <string.h>
using namespace std;

int ID = -1;
int IDADMIN = -1;
struct Adress
{
	string city;       // �������� ������
	string street;     // �������� �����
	int house;         // ����� ����
};
struct FIO
{
	string name;      // ��� 
	string sName;     // �������
	string patron;    // ��������
};
struct Date
{
	int day;            // ����
	int month;          // �����
	int year;           // ���
};
struct Time
{
	int min;            // ������
	int hour;           // ����
};
struct Log
{
	string logIn;       // �����
	string password;    // ������
	long id;            // ���������� ����� ������������ ��� ��������������
};
struct User
{
	long id;            // ���������� �����
	FIO fio;            // ��� �������
	Adress adress;      // ����� �������
	long telephone;     // ���������� �����
};
struct Admin
{
	long id;            // ���������� �����
	FIO fio;            // ��� �������
};
struct TCredit
{
	string name;        // ������������
	double procent;     // ���������� ������
	double minSum;      // ����������� �����
	double maxSum;      // ������������ �����
	int period;         // ������������
};
struct TryCredit
{
	TCredit type;       // ��� �������
	long idUsr;         // ����� �������
	Date end;
};
struct Credit
{
	TCredit type;       // ��� �������
	Date start;         // ���� ������
	Time timeStart;     // ����� ������
	Date end;           // ���� �����
	long idAdm;         // ����� �������
	long idUsr;         // ����� �������
};
struct TDeposit
{
	string name;        // ������������
	double procent;     // ���������� ������
	double minSum;      // ����������� �����
	double maxSum;      // ������������ �����
	int period;         // ������������
};
struct TryDeposit
{
	TDeposit type;      //��� ��������
	long idUsr;         //����� �������
	Date end;
};
struct Deposit
{
	TDeposit type;      //��� ��������
	Date start;         //���� ������
	Time timeStart;     //����� ������
	Date end;           //���� �����
	long idAdm;         //����� �������
	long idUsr;         //����� �������
};

void Start();//									//������� ��� ������� ����� (������� ����� � ��������� ��������� ��������).
Adress CreateAdress();//						//������� ��� �������� ������.
FIO CreateFIO();//								//������� ��� �������� ���.
Date CreateDate();//							//������� ��� �������� ����.
Time CreateTime();//							//������� ��� �������� �������.
long CreateId();//								//������� ��� �������� ����������� ������.
int CreateInt();//								//������� ��� �������� ������ �����.
double CreateDouble();//						//������� ��� �������� ������������� �����.
string CreateString();//						//������� ��� �������� ������.
long CreateTelephone();//
int CompareDate(Date, Date);//					//������� ��� ��������� ���.
int CompareTime(Time, Time);//					//������� ��� ��������� �������.
bool LogIn(string);//							//������� ��� �����������.
void MenuLogIn();//								//���� �����������.
void MenuAdmin();//								//���� ��������������.
void MenuUser();//								//���� ������������.
void MenuView();								//���� ������ ����������.
void MenuAdd();//								//���� ���������� ����������.
void MenuDel();//								//���� �������� ����������.
void MenuEdit();//								//���� �������������� ����������.
void MenuSearch();//							//���� ������ ����������.
void MenuSort();//								//���� ���������� ����������.
void MenuFilter();//							//���� ���������� ����������.
void MenuTryOperation();//						//���� ������ � �������� �� ������� � ��������.
void MenuTryOperationForUser();//
void MenuEnd();//
void MenuViewForUser();//
void MenuSearchForUser();//
void MenuSortForUser();//
void EditUser(int);//
void MenuFilterForUser();//
void MenuUserControl();//						//���� ���������� ��������������.
int GetFileAdmin(Admin**);//					//������� ���������� �� ����� ������ �� ���������������.
int GetFileUser(User**);//						//������� ���������� �� ����� ������ � �������������.
int GetFileLog(Log**, string);//				//������� ���������� �� ����� ������ � ������� � �������.
int GetFileTCredit(TCredit**);//				//������� ���������� �� ����� ������ � ����� ��������.
int GetFileTryCredit(TryCredit**);//			//������� ���������� �� ����� ������ � ������� �� �������.
int GetFileCreditEnabled(Credit**);//			//������� ���������� �� ����� ������ � ������� ��������.
int GetFileCreditDisabled(Credit**);//			//������� ���������� �� ����� ������ �� �������� ��������.
int GetFileTDeposit(TDeposit**);//				//������� ���������� �� ����� ������ � ����� ���������.
int GetFileTryDeposit(TryDeposit**);//			//������� ���������� �� ����� ������ � ������� �� ��������.
int GetFileDepositEnabled(Deposit**);//			//������� ���������� �� ����� ������ � ������� ���������.
int GetFileDepositDisabled(Deposit**);//		//������� ���������� �� ����� ������ �� �������� ���������.
void SetFileAdmin(Admin*, int);//				//������� ������ � ���� ������ �� ���������������.
void SetFileUser(User*, int);//					//������� ������ � ���� ������ � �������������.
void SetFileLog(Log*, string, int);//			//������� ������ � ���� ������ � ������� � �������.
void SetFileTCredit(TCredit*, int);//			//������� ������ � ���� ������ � ����� ��������.
void SetFileTryCredit(TryCredit*, int);//		//������� ������ � ���� ������ � ������� �� �������.
void SetFileCreditEnabled(Credit*, int);//		//������� ������ � ���� ������ � ������� ��������.
void SetFileCreditDisabled(Credit*, int);//		//������� ������ � ���� ������ �� �������� ��������.
void SetFileTDeposit(TDeposit*, int);//			//������� ������ � ���� ������ � ����� ���������.
void SetFileTryDeposit(TryDeposit*, int);//		//������� ������ � ���� ������ � ������� �� ��������.
void SetFileDepositEnabled(Deposit*, int);//	//������� ������ � ���� ������ � ������� ���������.
void SetFileDepositDisabled(Deposit*, int);//	//������� ������ � ���� ������ �� �������� ���������.
void ViewTCredit(TCredit*, int);//				//������� ������ � ������� ������ � ����� ��������.
void ViewCredit(Credit*, int);//				//������� ������ � ������� ������ � ��������.
void ViewTryCredit(TryCredit*, int);//			//������� ������ � ������� ������ � ������� �� �������.
void ViewTDeposit(TDeposit*, int);//			//������� ������ � ������� ������ � ����� ���������.
void ViewDeposit(Deposit*, int);//				//������� ������ � ������� ������ � ���������.
void ViewTryDeposit(TryDeposit*, int);//		//������� ������ � ������� ������ � ������� �� ��������.
void ViewUser(User*, int);//					//������� ������ � ������� ������ � ��������.
void ViewAdmin(Admin*, int);//					//������� ������ � ������� ������ �� ���������������.
void AddTCredit();//							//������� ���������� ������ � ����� ��������.
void AddTDeposit();//							//������� ���������� ������ � ����� ���������.
void DelTCredit();//							//������� �������� ������ � ����� ��������.
void DelTDeposit();//							//������� �������� ������ � ����� ���������.
void EditTCredit();//							//������� �������������� ������ � ����� ��������.
void EditTDeposit();//							//������� �������������� ������ � ����� ���������.
void SearchUser();//							//������� ������ ������ � �������������.
void SearchTCredit();//							//������� ������ ������ � ����� ��������. 
void SearchCredit(int);//						//������� ������ ������ � ��������.
void SearchTDeposit();//						//������� ������ ������ � ����� ���������.
void SearchDeposit(int);//						//������� ������ ������ � ���������.
void SortUser();//								//������� ���������� ������ � �������������.
void SortTCredit();//							//������� ���������� ������ � ����� ��������.
void SortCredit(int);//							//������� ���������� ������ � ��������.
void SortTDeposit();//							//������� ���������� ������ � ����� ���������.
void SortDeposit(int);//						//������� ���������� ������ � ���������.
void FilterUser();//							//������� ���������� ������ � �������������.
void FilterTCredit();//							//������� ���������� ������ � ����� ��������.
void FilterCredit(int);//						//������� ���������� ������ � ��������.
void FilterTDeposit();//						//������� ���������� ������ � ����� ���������.
void FilterDeposit(int);//						//������� ���������� ������ � ���������.
bool CheckDouble(string);//						//������� �������� �� ������������ ����� ������������� �����.
bool CheckLetters(string);//				    //������� �������� �� ������������ ����� ������.
bool CheckNumbers(string);//					//������� �������� �� ������������ ����� ������ �����.
void MakeTryCredit();//							//������� �������� ������ �� ������.
void MakeTryDeposit();//						//������� �������� ������ �� �������.
void AcceptCredit();//							//������� �������� ������ �� ������.
void AcceptDeposit();//							//������� �������� ������ �� �������.
void EndCredit();//								//������� ��������� �������.
void EndDeposit();//							//������� �������� ��������.
string Encrypt(string);//						//������� ����������.
string Decrypt(string);//						//������� ������������.
void PrintDate(Date);//
void PrintTime(Time);//
void AddUser();//
void AddAdmin();//

void Start()
{
	ofstream f;
	f.open("user.txt", ios_base::trunc);
	f << 0 << endl;
	f.close();
	f.open("admin.txt", ios_base::trunc);
	f << 0 << endl;
	f.close();
	f.open("tcredit.txt", ios_base::trunc);
	f << 0 << endl;
	f.close();
	f.open("trycredit.txt", ios_base::trunc);
	f << 0 << endl;
	f.close();
	f.open("creditenabled.txt", ios_base::trunc);
	f << 0 << endl;
	f.close();
	f.open("creditdisabled.txt", ios_base::trunc);
	f << 0 << endl;
	f.close();
	f.open("tdeposit.txt", ios_base::trunc);
	f << 0 << endl;
	f.close();
	f.open("trydeposit.txt", ios_base::trunc);
	f << 0 << endl;
	f.close();
	f.open("depositenabled.txt", ios_base::trunc);
	f << 0 << endl;
	f.close();
	f.open("depositdisabled.txt", ios_base::trunc);
	f << 0 << endl;
	f.close();
}

Adress CreateAdress()
{
	Adress a;
	cout << "������� �����\n";
	a.city = CreateString();
	cout << "������� �����\n";
	a.street = CreateString();
	cout << "������� ����� ����\n";
	a.house = CreateInt();
	return a;
}

FIO CreateFIO()
{
	FIO a;
	cout << "������� �������\n";
	a.sName = CreateString();
	cout << "������� ���\n";
	a.name = CreateString();
	cout << "������� ��������\n";
	a.patron = CreateString();
	return a;
}

Date CreateDate()
{
	Date a;
	a.day = 0;
	a.month = 0;
	a.year = 0;
	while (a.day > 31 || a.day < 1 || a.month < 1 || a.month>12 || a.year < 2000 || a.year>2021)
	{
		bool correct = false;
		while (!correct)
		{
			system("cls");
			cout << "������� ���� � ������� (��.��.����)\n";
			char c[11];
			char d[3];
			char m[3];
			char y[5];
			scanf(" %11s", c);
			d[0] = c[0];
			d[1] = c[1];
			d[2] = '\0';
			m[0] = c[3];
			m[1] = c[4];
			m[2] = '\0';
			y[0] = c[6];
			y[1] = c[7];
			y[2] = c[8];
			y[3] = c[9];
			y[4] = '\0';
			correct = (CheckNumbers(d) && CheckNumbers(m) && CheckNumbers(y));
			if (!correct)
			{
				cout << "���� ������ ��������� ������ �����.\n";
				system("pause");
			}
			else
			{
				a.day = atoi(d);
				a.month = atoi(m);
				a.year = atoi(y);
			}
		}

		if (a.day < 1 || a.day>31 || a.month < 1 || a.month>31 || a.year < 1 || a.year>2021)
		{
			cout << "���� ������� �� ���������\n";
			system("pause");
		}
		else if (a.day > 28 && a.month == 2)
		{
			cout << "���� ������� �� ���������\n";
			system("pause");
		}
		else if (a.year < 2000 || a.year>2021)
		{
			cout << "���� ������ ���� � ��������� �� 01.01.2000 �� 31.12.2021\n";
			system("pause");
		}
	}
	return a;
}

int CompareDate(Date a, Date b)
{
	if (a.year == b.year)
	{
		if (a.month == b.month)
		{
			if (a.day == b.day)
			{
				return 0;
			}
			else return a.day > b.day ? 1 : -1;
		}
		else return a.month > b.month ? 1 : -1;
	}
	else return a.year > b.year ? 1 : -1;
}

Time CreateTime()
{
	Time a;
	a.min = -1;
	a.hour = -1;
	while (a.min > 59 || a.min < 0 || a.hour < 0 || a.hour>23)
	{
		bool correct = false;
		while (!correct)
		{
			system("cls");
			printf("������� ����� � ������� (��:��)\n");
			char c[6];
			char m[3];
			char h[3];
			scanf(" %6s", c);
			m[0] = c[0];
			m[1] = c[1];
			m[2] = '\0';
			h[0] = c[3];
			h[1] = c[4];
			h[2] = '\0';
			correct = (CheckNumbers(m) && CheckNumbers(h));
			if (!correct)
			{
				printf("���� ������ ��������� ������ �����.\n");
				system("pause");
			}
			else
			{
				a.hour = atoi(h);
				a.min = atoi(m);
			}
		}

		if (a.min > 59 || a.min < 0 || a.hour < 0 || a.hour>23)
		{
			printf("������������ ����\n");
			system("pause");
		}
	}
	return a;
}

int CompareTime(Time a, Time b)
{
	if (a.hour == b.hour)
	{
		if (a.min == b.min)
		{
			return 0;
		}
		else return a.min > b.min ? 1 : -1;
	}
	else return a.hour > b.hour ? 1 : -1;
}

long CreateId()
{
	int id = -1;
	ifstream fin;
	fin.open("id.txt", ios_base::in);
	fin >> id;
	fin.close();
	if (id == -1)
	{
		id = 0;
	}
	ofstream fout;
	fout.open("id.txt", ios_base::trunc);
	id++;
	fout << id;
	fout.close();
	return id;
}

bool LogIn(string str)
{
	Log* arr = NULL;
	int n = GetFileLog(&arr, str);
	if (n == 0)
	{
		cout << "��� ������ ����.�����������������\n";
		if (str == "admin.txt")
		{
			ID = 0;
			AddAdmin();
			return false;
		}
		else
		{
			AddUser();
			return false;
		}
	}
	int k = 3;
	while (k != 0)
	{
		string s;
		cout << "������� �����\n";
		cin >> s;
		int i;
		for (i = 0; i < n; i++)
		{
			if (strcmp(s.c_str(), arr[i].logIn.c_str()) == 0)
			{
				cout << "������� ������\n";
				char c = 0;
				char str[70];
				int it = 0;
				do
				{
					c = _getch();
					if (c == '\b')
					{
						if (it != 0)
						{
							printf("\b \b");
							it--;
						}
					}
					else if (c == 13)
					{
						str[it] = '\0';
						it++;
					}
					else
					{
						str[it] = c;
						it++;
						printf("*");
					}

				} while (c != 13);
				if (strcmp(str, arr[i].password.c_str()) == 0)
				{
					if (str == "user.txt")
					{
						ID = arr[i].id;
					}
					cout << "���� �������� �������\n";
					system("pause");
					return true;
				}
				cout << "������ ������ �������\n";
				system("pause");
				break;
			}
		}
		if (i == n)
		{
			cout << "����� ������ �������\n";
		}
		k--;
	}
	cout << "�� ��������� ��� �������\n";
	system("pause");
	return false;
}

void MenuLogIn()
{
	bool work = true;
	while (work)
	{
		ID = 0;
		char choise;
		cout << "�������� ��������\n";
		cout << "1.���� ��� ������ ��������������\n";
		cout << "2.���� ��� ������ ������������\n";
		cout << "3.����� �� ���������\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			string str = "admin.txt";
			if (LogIn(str))
			{
				MenuAdmin();
			}
		}break;
		case '2':
		{
			string str = "user.txt";
			if (LogIn(str))
			{
				MenuUser();
			}
		}break;
		case '3':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
	}
}

void MenuAdmin()
{
	bool work = true;
	while (work)
	{
		char choise;
		cout << "�������� ��������:\n";
		cout << "1.�������� ������\n";
		cout << "2.���������� ������\n";
		cout << "3.�������� ������\n";
		cout << "4.�������������� ������\n";
		cout << "5.����� ������\n";
		cout << "6.���������� ������\n";
		cout << "7.���������� ������\n";
		cout << "8.������ � �������� �� ���������� ��������\n";
		cout << "9.���������� ��������������\n";
		cout << "0.�����\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			MenuView();
		}break;
		case '2':
		{
			MenuAdd();
		}break;
		case '3':
		{
			MenuDel();
		}break;
		case '4':
		{
			MenuEdit();
		}break;
		case '5':
		{
			MenuSearch();
		}break;
		case '6':
		{
			MenuSort();
		}break;
		case '7':
		{
			MenuFilter();
		}break;
		case '8':
		{
			MenuTryOperation();
		}break;
		case '9':
		{
			MenuUserControl();
		}break;
		case '0':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
	}
}

void MenuUser()
{
	bool work = true;
	while (work)
	{
		char choise;
		cout << "�������� ��������:\n";
		cout << "1.�������� ������ \n";
		cout << "2.����� ������\n";
		cout << "3.���������� ������\n";
		cout << "4.���������� ������\n";
		cout << "5.�������� ������ �� ���������� ��������\n";
		cout << "6.������� ������� ��� ��������� ������\n";
		cout << "7.�������� ������ ������\n";
		cout << "0.�����\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			MenuViewForUser();
		}break;
		case '2':
		{
			MenuSearchForUser();
		}break;
		case '3':
		{
			MenuSortForUser();
		}break;
		case '4':
		{
			MenuFilterForUser();
		}break;
		case '5':
		{
			MenuTryOperationForUser();
		}break;
		case '6':
		{
			MenuEnd();
		}break;
		case '7':
		{
			EditUser(ID);
		}break;
		case '0':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
	}
}

void MenuView()
{
	bool work = true;
	while (work)
	{
		char choise;
		cout << "��������, ����� ������ �������������\n";
		cout << "1.������ � ��������\n";
		cout << "2.������ � ����� ��������\n";
		cout << "3.������ � �������� ��������\n";
		cout << "4.������ � ����� ���������\n";
		cout << "5.������ � �������� ���������\n";
		cout << "6.�����\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			User* arr = NULL;
			int n = GetFileUser(&arr);
			if (n == 0)
			{
				cout << "���� ����\n";
				break;
			}
			ViewUser(arr, n);
			delete[] arr;
		}break;
		case '2':
		{
			TCredit* arr = NULL;
			int n = GetFileTCredit(&arr);
			if (n == 0)
			{
				cout << "���� ����\n";
				break;
			}
			ViewTCredit(arr, n);
			delete[] arr;
		}break;
		case '3':
		{
			bool correct = false;
			Credit* arr = NULL;
			int n = 0;
			while (!correct)
			{
				cout << "������� ���������� �:\n1.������� ��������\n2.�������� ��������\n";
				char c;
				cin >> c;
				switch (c)
				{
				case '1':
				{
					n = GetFileCreditEnabled(&arr);
					correct = true;
					break;
				}
				case '2':
				{
					n = GetFileCreditDisabled(&arr);
					correct = true;
					break;
				}
				default:
					cout << "������ �����\n";
				}
			}
			if (n == 0)
			{
				cout << "���� ����\n";
				break;
			}
			ViewCredit(arr, n);
			delete[] arr;
		}break;
		case '4':
		{
			TDeposit* arr = NULL;
			int n = GetFileTDeposit(&arr);
			if (n == 0)
			{
				cout << "���� ����\n";
				break;
			}
			ViewTDeposit(arr, n);
			delete[] arr;
		}break;
		case '5':
		{
			bool correct = false;
			Deposit* arr = NULL;
			int n = 0;
			while (!correct)
			{
				cout << "������� ���������� �:\n1.������� ���������\n2.�������� ���������\n";
				char c;
				cin >> c;
				switch (c)
				{
				case '1':
				{
					n = GetFileDepositEnabled(&arr);
					correct = true;
					break;
				}
				case '2':
				{
					n = GetFileDepositDisabled(&arr);
					correct = true;
					break;
				}
				default:
					cout << "������ �����\n";
				}
			}
			if (n == 0)
			{
				cout << "���� ����\n";
				break;
			}
			ViewDeposit(arr, n);
			delete[] arr;
		}break;
		case '6':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
	}
}

void MenuAdd()
{
	bool work = true;
	while (work)
	{
		char choise;
		cout << "��������, ����� ������ ��������\n";
		cout << "1.������ � ����� ��������\n";
		cout << "2.������ � ����� ���������\n";
		cout << "3.�����\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			AddTCredit();
		}break;
		case '2':
		{
			AddTDeposit();
		}break;
		case '3':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
	}
}

void MenuDel()
{
	bool work = true;
	while (work)
	{
		char choise;
		cout << "��������, ����� ������ �������\n";
		cout << "1.������ � ����� ��������\n";
		cout << "2.������ � ����� ���������\n";
		cout << "3.�����\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			DelTCredit();
		}break;
		case '2':
		{
			DelTDeposit();
		}break;
		case '3':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
	}
}

void MenuEdit()
{
	bool work = true;
	while (work)
	{
		char choise;
		cout << "��������, ����� ������ �������������\n";
		cout << "1.������ � ����� ��������\n";
		cout << "2.������ � ����� ���������\n";
		cout << "3.�����\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			EditTCredit();
		}break;
		case '2':
		{
			EditTDeposit();
		}break;
		case '3':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
	}
}

void MenuSearch()
{
	bool work = true;
	while (work)
	{
		char choise;
		cout << "��������, ����� ������ ������\n";
		cout << "1.������ � ��������\n";
		cout << "2.������ � ����� ��������\n";
		cout << "3.������ � �������� ��������\n";
		cout << "4.������ � ����� ���������\n";
		cout << "5.������ � �������� ���������\n";
		cout << "6.�����\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			SearchUser();
		}break;
		case '2':
		{
			SearchTCredit();
		}break;
		case '3':
		{
			SearchCredit(0);
		}break;
		case '4':
		{
			SearchTDeposit();
		}break;
		case '5':
		{
			SearchDeposit(0);
		}break;
		case '6':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
	}
}

void MenuSort()
{
	bool work = true;
	while (work)
	{
		char choise;
		cout << "��������, ����� ������ �����������\n";
		cout << "1.������ � ��������\n";
		cout << "2.������ � ����� ��������\n";
		cout << "3.������ � �������� ��������\n";
		cout << "4.������ � ����� ���������\n";
		cout << "5.������ � �������� ���������\n";
		cout << "6.�����\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			SortUser();
		}break;
		case '2':
		{
			SortTCredit();
		}break;
		case '3':
		{
			SortCredit(0);
		}break;
		case '4':
		{
			SortTDeposit();
		}break;
		case '5':
		{
			SortDeposit(0);
		}break;
		case '6':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
	}
}

void MenuFilter()
{
	bool work = true;
	while (work)
	{
		char choise;
		cout << "��������, ����� ������ �����������\n";
		cout << "1.������ � ��������\n";
		cout << "2.������ � ����� ��������\n";
		cout << "3.������ � �������� ��������\n";
		cout << "4.������ � ����� ���������\n";
		cout << "5.������ � �������� ���������\n";
		cout << "6.�����\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			FilterUser();
		}break;
		case '2':
		{
			FilterTCredit();
		}break;
		case '3':
		{
			FilterCredit(0);
		}break;
		case '4':
		{
			FilterTDeposit();
		}break;
		case '5':
		{
			FilterDeposit(0);
		}break;
		case '6':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
	}
}

void MenuTryOperation()
{
	bool work = true;
	while (work)
	{
		char choise;
		cout << "��������, ����� ������ �����������\n";
		cout << "1.������ � ������� �� �������\n";
		cout << "2.������ � ������� �� ��������\n";
		cout << "3.�����\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			AcceptCredit();
		}break;
		case '2':
		{
			AcceptDeposit();
		}break;
		case '3':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
	}
}

void MenuTryOperationForUser()
{
	bool work = true;
	while (work)
	{
		char choise;
		cout << "��������, ����� ������ ���������\n";
		cout << "1.�� ������\n";
		cout << "2.�� �������\n";
		cout << "3.�����\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			MakeTryCredit();
		}break;
		case '2':
		{
			MakeTryDeposit();
		}break;
		case '3':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
	}
}

void MenuEnd()
{
	bool work = true;
	while (work)
	{
		char choise;
		cout << "��������, ��������\n";
		cout << "1.��������� ������\n";
		cout << "2.������� �������\n";
		cout << "3.�����\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			EndCredit();
		}break;
		case '2':
		{
			EndDeposit();
		}break;
		case '3':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
	}
}

void MenuViewForUser()
{
	bool work = true;
	while (work)
	{
		char choise;
		cout << "��������, ����� ������ �����������\n";
		cout << "1.������ � ����� ��������\n";
		cout << "2.������ � ����� ���������\n";
		cout << "3.������ � ������� �� �������\n";
		cout << "4.������ � ������� �� ��������\n";
		cout << "5.������ � ������ ��������\n";
		cout << "6.������ � ������ ���������\n";
		cout << "7.������ �� �������� ��������\n";
		cout << "8.������ �� �������� ���������\n";
		cout << "9.�����\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			TCredit* arr = NULL;
			int n = GetFileTCredit(&arr);
			if (n == 0)
			{
				cout << "���� ����\n";
				system("pause");
				break;
			}
			ViewTCredit(arr, n);
			system("pause");
			delete[] arr;
		}break;
		case '2':
		{
			TDeposit* arr = NULL;
			int n = GetFileTDeposit(&arr);
			if (n == 0)
			{
				cout << "���� ����\n";
				system("pause");
				break;
			}
			ViewTDeposit(arr, n);
			system("pause");
			delete[] arr;
		}break;
		case '3':
		{
			TryCredit* arr = NULL;
			int n = GetFileTryCredit(&arr);
			if (n == 0)
			{
				cout << "���� ����\n";
				system("pause");
				break;
			}
			TryCredit* arr1 = new TryCredit[n];
			int it = 0;
			for (int i = 0; i < n; i++)
			{
				if (arr[i].idUsr == ID)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������ �� �������\n";
			}
			else
			{
				ViewTryCredit(arr1, it);
			}
			system("pause");
			delete[] arr;
			delete[] arr1;
		}break;
		case '4':
		{
			TryDeposit* arr = NULL;
			int n = GetFileTryDeposit(&arr);
			if (n == 0)
			{
				cout << "���� ����\n";
				system("pause");
				break;
			}
			TryDeposit* arr1 = new TryDeposit[n];
			int it = 0;
			for (int i = 0; i < n; i++)
			{
				if (arr[i].idUsr == ID)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������ �� �������\n";
			}
			else
			{
				ViewTryDeposit(arr1, it);
			}
			system("pause");
			delete[] arr;
			delete[] arr1;
		}break;
		case '5':
		{
			Credit* arr = NULL;
			int n = GetFileCreditEnabled(&arr);
			if (n == 0)
			{
				cout << "���� ����\n";
				system("pause");
				break;
			}
			Credit* arr1 = new Credit[n];
			int it = 0;
			for (int i = 0; i < n; i++)
			{
				if (arr[i].idUsr == ID)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������ �� �������\n";
			}
			else
			{
				ViewCredit(arr1, it);
			}
			system("pause");
			delete[] arr;
			delete[] arr1;
		}break;
		case '6':
		{
			Deposit* arr = NULL;
			int n = GetFileDepositEnabled(&arr);
			if (n == 0)
			{
				cout << "���� ����\n";
				system("pause");
				break;
			}
			Deposit* arr1 = new Deposit[n];
			int it = 0;
			for (int i = 0; i < n; i++)
			{
				if (arr[i].idUsr == ID)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������ �� �������\n";
			}
			else
			{
				ViewDeposit(arr1, it);
			}
			system("pause");
			delete[] arr;
			delete[] arr1;
		}break;
		case '7':
		{
			Credit* arr = NULL;
			int n = GetFileCreditDisabled(&arr);
			if (n == 0)
			{
				cout << "���� ����\n";
				system("pause");
				break;
			}
			Credit* arr1 = new Credit[n];
			int it = 0;
			for (int i = 0; i < n; i++)
			{
				if (arr[i].idUsr == ID)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������ �� �������\n";
			}
			else
			{
				ViewCredit(arr1, it);
			}
			system("pause");
			delete[] arr;
			delete[] arr1;
		}break;
		case '8':
		{
			Deposit* arr = NULL;
			int n = GetFileDepositDisabled(&arr);
			if (n == 0)
			{
				cout << "���� ����\n";
				system("pause");
				break;
			}
			Deposit* arr1 = new Deposit[n];
			int it = 0;
			for (int i = 0; i < n; i++)
			{
				if (arr[i].idUsr == ID)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������ �� �������\n";
			}
			else
			{
				ViewDeposit(arr1, it);
			}
			system("pause");
			delete[] arr;
			delete[] arr1;
		}break;
		case '9':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
	}
}

void MenuSearchForUser()
{
	User* arr = NULL;
	int n = GetFileUser(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		system("pause");
		return;
	}
	User* arr1 = new User[n];
	int it = 0;
	bool work = true;
	while (work)
	{
		it = 0;
		char choise;
		User a;
		cout << "��������, �� ������ ���� ������\n";
		cout << "1.������� �������\n";
		cout << "2.����� �������\n";
		cout << "3.����� ��������\n";
		cout << "4.ID\n";
		cout << "5.�����\n";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{
			cout << "������� �������\n";
			a.fio.sName = CreateString();
			for (int i = 0; i < n; i++)
			{
				if (a.fio.sName == arr[i].fio.sName)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
		}break;
		case '2':
		{
			a.adress = CreateAdress();
			for (int i = 0; i < n; i++)
			{
				if (a.adress.city == arr[i].adress.city && a.adress.street == arr[i].adress.street && a.adress.house == a.adress.house)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
		}break;
		case '3':
		{
			cout << "������� ����� ��������\n";
			a.telephone = CreateTelephone();
			for (int i = 0; i < n; i++)
			{
				if (a.telephone == arr[i].telephone)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
		}break;
		case '4':
		{
			cout << "������� ID\n";
			int id = CreateInt();
			for (int i = 0; i < n; i++)
			{
				if (arr[i].id == id)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
		}break;
		case '5':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			break;
		}
		ViewUser(arr1, it);
		system("pause");
	}
	delete[] arr;
	delete[] arr1;
}

void MenuSortForUser()
{
	User* arr = NULL;
	int n = GetFileUser(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		return;
	}
	bool work = true;
	while (work)
	{
		cout << "������� ���� ��� ����������:\n";
		cout << "1.�������\n";
		cout << "2.�����\n";
		cout << "3.ID\n";
		cout << "4.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (strcmp(arr[i].fio.sName.c_str(), arr[j].fio.sName.c_str()) == -1)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewUser(arr, n);
			system("pause");
			SetFileUser(arr, n);
			break;
		case '2':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (strcmp(arr[i].adress.city.c_str(), arr[j].adress.city.c_str()) == -1)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewUser(arr, n);
			system("pause");
			SetFileUser(arr, n);
			break;
		case '3':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (arr[i].id > arr[j].id)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewUser(arr, n);
			system("pause");
			SetFileUser(arr, n);
			break;
		case '4':
			work = false;
			break;
		default:
			cout << "������ �����\n";
			system("pause");
		}
	}
	delete[] arr;
}

void EditUser(int id)
{
	User* arr = NULL;
	int n = GetFileUser(&arr);
	int z = -1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].id == id)
		{
			z = i;
		}
	}
	if (z == -1)
	{
		return;
	}
	bool work = true;
	while (work)
	{
		ViewUser(arr + z, 1);
		cout << "�������� ���� ��� ��������������\n";
		cout << "1.���\n";
		cout << "2.�����\n";
		cout << "3.����� ��������\n";
		cout << "4.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			arr[z].fio = CreateFIO();
		}break;
		case '2':
		{
			arr[z].adress = CreateAdress();
		}break;
		case '3':
		{
			cout << "������� ����� ����� ��������\n";
			arr[z].telephone = CreateTelephone();
		}break;
		case '4':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			system("pause");
		}
	}
	SetFileUser(arr, n);
	delete[] arr;
}

void MenuFilterForUser()
{
	bool work = true;
	while (work)
	{
		cout << "�������� ������ ��� ����������\n";
		cout << "1.���� ��������\n";
		cout << "2.����� ���������\n";
		cout << "3.�������\n";
		cout << "4.��������\n";
		cout << "5.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			FilterTCredit();
		}break;
		case '2':
		{
			FilterTDeposit();
		}break;
		case '3':
		{
			FilterCredit(ID);
		}break;
		case '4':
		{
			FilterDeposit(ID);
		}break;
		case '5':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			system("pause");
		}
	}
}

void MenuUserControl()
{
	bool work = true;
	while (work)
	{
		cout << "�������� ��������\n";
		cout << "1.�������� ��������������\n";
		cout << "2.�������� ������������\n";
		cout << "3.����������� ������ �� ���������������\n";
		cout << "4.����������� ������ � �������������\n";
		cout << "5.�������� ������ � �������������\n";
		cout << "6.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			AddAdmin();
		}break;
		case '2':
		{
			AddUser();
		}break;
		case '3':
		{
			Admin* arr = NULL;
			int n = GetFileAdmin(&arr);
			if (n == 0)
			{
				cout << "��� �� ������ ��������������\n";
				system("pause");
				break;
			}
			ViewAdmin(arr, n);
			delete[] arr;
		}break;
		case '4':
		{
			User* arr = NULL;
			int n = GetFileUser(&arr);
			if (n == 0)
			{
				cout << "��� �� ������ ������������\n";
				system("pause");
				break;
			}
			ViewUser(arr, n);
			system("pause");
			delete[] arr;
		}break;
		case '5':
		{
			User* arr = NULL;
			int n = GetFileUser(&arr);
			if (n == 0)
			{
				cout << "��� �� ������ ������������\n";
				system("pause");
				break;
			}
			ViewUser(arr, n);
			system("pause");
			int z = -1;
			cout << "�������� ����� ������ ��� ��������������\n";
			while (z<1 || z>n)
			{
				z = CreateInt();
			}
			EditUser(arr[z].id);
			delete[] arr;
		}break;
		case '6':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			system("pause");
		}
	}
}

int GetFileAdmin(Admin** a)
{
	ifstream f;
	f.open("admininfo.txt", ios_base::in);
	int n = 0;
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("admininfo.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		return n;
	}
	*a = new Admin[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> (*a)[i].id >> (*a)[i].fio.name >> (*a)[i].fio.patron >> (*a)[i].fio.sName;
	}
	f.close();
	SetFileAdmin(*a, n);
	return n;
}

int GetFileUser(User** a)
{
	ifstream f;
	f.open("userinfo.txt", ios_base::in);
	int n = 0;
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("userinfo.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		return n;
	}
	*a = new User[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> (*a)[i].adress.city >> (*a)[i].adress.house >> (*a)[i].adress.street >> (*a)[i].fio.name >> (*a)[i].fio.patron >> (*a)[i].fio.sName >> (*a)[i].telephone >> (*a)[i].id;
	}
	f.close();
	SetFileUser(*a, n);
	return n;
}

int GetFileLog(Log** a, string str)
{
	ifstream f;
	f.open(str, ios_base::in);
	int n = 0;
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open(str, ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		return n;
	}
	*a = new Log[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> (*a)[i].logIn >> (*a)[i].password >> (*a)[i].id;
	}
	f.close();
	SetFileLog(*a, str, n);
	return n;
}

int GetFileTCredit(TCredit** a)
{
	ifstream f;
	f.open("tcredit.txt", ios_base::in);
	int n = 0;
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("tcredit.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		return n;
	}
	(*a) = new TCredit[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> (*a)[i].maxSum >> (*a)[i].minSum >> (*a)[i].name >> (*a)[i].period >> (*a)[i].procent;
	}
	f.close();
	SetFileTCredit(*a, n);
	return n;
}

int GetFileTryCredit(TryCredit** a)
{
	ifstream f;
	f.open("trycredit.txt", ios_base::in);
	int n = 0;
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("trycredit.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		return n;
	}
	(*a) = new TryCredit[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> (*a)[i].type.maxSum >> (*a)[i].type.minSum >> (*a)[i].type.name >> (*a)[i].type.period >> (*a)[i].type.procent >> (*a)[i].end.day >> (*a)[i].end.month >> (*a)[i].end.year >> (*a)[i].idUsr;
	}
	f.close();
	SetFileTryCredit(*a, n);
	return n;
}

int GetFileCreditEnabled(Credit** a)
{
	ifstream f;
	f.open("creditenabled.txt", ios_base::in);
	int n = 0;
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("creditenabled.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		return n;
	}
	(*a) = new Credit[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> (*a)[i].type.maxSum >> (*a)[i].type.minSum >> (*a)[i].type.name >> (*a)[i].type.period >> (*a)[i].type.procent >> (*a)[i].idUsr >> (*a)[i].idAdm >> (*a)[i].timeStart.hour >> (*a)[i].timeStart.min >> (*a)[i].start.day >> (*a)[i].start.month >> (*a)[i].start.year >> (*a)[i].end.day >> (*a)[i].end.month >> (*a)[i].end.year;
	}
	f.close();
	SetFileCreditEnabled(*a, n);
	return n;
}

int GetFileCreditDisabled(Credit** a)
{
	ifstream f;
	f.open("creditdisabled.txt", ios_base::in);
	int n = 0;
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("creditdisabled.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		return n;
	}
	(*a) = new Credit[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> (*a)[i].type.maxSum >> (*a)[i].type.minSum >> (*a)[i].type.name >> (*a)[i].type.period >> (*a)[i].type.procent >> (*a)[i].idUsr >> (*a)[i].idAdm >> (*a)[i].timeStart.hour >> (*a)[i].timeStart.min >> (*a)[i].start.day >> (*a)[i].start.month >> (*a)[i].start.year >> (*a)[i].end.day >> (*a)[i].end.month >> (*a)[i].end.year;
	}
	f.close();
	SetFileCreditDisabled(*a, n);
	return n;
}

int GetFileTDeposit(TDeposit** a)
{
	ifstream f;
	f.open("tdeposit.txt", ios_base::in);
	int n = 0;
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("tdeposit.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		return n;
	}
	(*a) = new TDeposit[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> (*a)[i].maxSum >> (*a)[i].minSum >> (*a)[i].name >> (*a)[i].period >> (*a)[i].procent;
	}
	f.close();
	SetFileTDeposit(*a, n);
	return n;
}

int GetFileTryDeposit(TryDeposit** a)
{
	ifstream f;
	f.open("trydeposit.txt", ios_base::in);
	int n = 0;
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("trydeposit.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		return n;
	}
	(*a) = new TryDeposit[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> (*a)[i].type.maxSum >> (*a)[i].type.minSum >> (*a)[i].type.name >> (*a)[i].type.period >> (*a)[i].type.procent >> (*a)[i].idUsr >> (*a)[i].end.day >> (*a)[i].end.month >> (*a)[i].end.year;
	}
	f.close();
	SetFileTryDeposit(*a, n);
	return n;
}

int GetFileDepositEnabled(Deposit** a)
{
	ifstream f;
	f.open("depositenabled.txt", ios_base::in);
	int n = 0;
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("depositenabled.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		return n;
	}
	(*a) = new Deposit[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> (*a)[i].type.maxSum >> (*a)[i].type.minSum >> (*a)[i].type.name >> (*a)[i].type.period >> (*a)[i].type.procent >> (*a)[i].idUsr >> (*a)[i].idAdm >> (*a)[i].timeStart.hour >> (*a)[i].timeStart.min >> (*a)[i].start.day >> (*a)[i].start.month >> (*a)[i].start.year >> (*a)[i].end.day >> (*a)[i].end.month >> (*a)[i].end.year;
	}
	f.close();
	SetFileDepositEnabled(*a, n);
	return n;
}

int GetFileDepositDisabled(Deposit** a)
{
	ifstream f;
	f.open("depositdisabled.txt", ios_base::in);
	int n = 0;
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("depositdisabled.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		return n;
	}
	(*a) = new Deposit[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> (*a)[i].type.maxSum >> (*a)[i].type.minSum >> (*a)[i].type.name >> (*a)[i].type.period >> (*a)[i].type.procent >> (*a)[i].idUsr >> (*a)[i].idAdm >> (*a)[i].timeStart.hour >> (*a)[i].timeStart.min >> (*a)[i].start.day >> (*a)[i].start.month >> (*a)[i].start.year >> (*a)[i].end.day >> (*a)[i].end.month >> (*a)[i].end.year;
	}
	f.close();
	SetFileDepositDisabled(*a, n);
	return n;
}

void SetFileAdmin(Admin* a, int n)
{
	ofstream fout;
	fout.open("admininfo.txt", ios_base::trunc);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << a[i].id << " " << a[i].fio.name << " " << a[i].fio.patron << " " << a[i].fio.sName << endl;
	}
	fout.close();
}

void SetFileUser(User* a, int n)
{
	ofstream fout;
	fout.open("userinfo.txt", ios_base::trunc);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << a[i].adress.city << " " << a[i].adress.house << " " << a[i].adress.street << " " << a[i].fio.name << " " << a[i].fio.patron << " " << a[i].fio.sName << " " << a[i].telephone << " " << a[i].id << endl;
	}
	fout.close();
}

void SetFileLog(Log* a, string str, int n)
{
	ofstream fout;
	fout.open(str, ios_base::trunc);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << a[i].logIn << " " << a[i].password << " " << a[i].id << endl;
	}
	fout.close();
}

void SetFileTCredit(TCredit* a, int n)
{
	ofstream fout;
	fout.open("tcredit.txt", ios_base::trunc);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << a[i].maxSum << " " << a[i].minSum << " " << a[i].name << " " << a[i].period << " " << a[i].procent << endl;
	}
	fout.close();
}

void SetFileTryCredit(TryCredit* a, int n)
{
	ofstream fout;
	fout.open("trycredit.txt", ios_base::trunc);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << a[i].type.maxSum << " " << a[i].type.minSum << " " << a[i].type.name << " " << a[i].type.period << " " << a[i].type.procent << " " << a[i].end.day << " " << a[i].end.month << " " << a[i].end.year << " " << a[i].idUsr << endl;
	}
	fout.close();
}

void SetFileCreditEnabled(Credit* a, int n)
{
	ofstream fout;
	fout.open("creditenabled.txt", ios_base::trunc);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << a[i].type.maxSum << " " << a[i].type.minSum << " " << a[i].type.name << " " << a[i].type.period << " " << a[i].type.procent << " " << a[i].idUsr << " " << a[i].idAdm << " " << a[i].timeStart.hour << " " << a[i].timeStart.min << " " << a[i].start.day << " " << a[i].start.month << " " << a[i].start.year << " " << a[i].end.day << " " << a[i].end.month << " " << a[i].end.year << endl;
	}
	fout.close();
}

void SetFileCreditDisabled(Credit* a, int n)
{
	ofstream fout;
	fout.open("creditdisabled.txt", ios_base::trunc);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << a[i].type.maxSum << " " << a[i].type.minSum << " " << a[i].type.name << " " << a[i].type.period << " " << a[i].type.procent << " " << a[i].idUsr << " " << a[i].idAdm << " " << a[i].timeStart.hour << " " << a[i].timeStart.min << " " << a[i].start.day << " " << a[i].start.month << " " << a[i].start.year << " " << a[i].end.day << " " << a[i].end.month << " " << a[i].end.year << endl;
	}
	fout.close();
}

void SetFileTDeposit(TDeposit* a, int n)
{
	ofstream fout;
	fout.open("tdeposit.txt", ios_base::trunc);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << a[i].maxSum << " " << a[i].minSum << " " << a[i].name << " " << a[i].period << " " << a[i].procent << endl;
	}
	fout.close();
}

void SetFileTryDeposit(TryDeposit* a, int n)
{
	ofstream fout;
	fout.open("trydeposit.txt", ios_base::trunc);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << a[i].type.maxSum << " " << a[i].type.minSum << " " << a[i].type.name << " " << a[i].type.period << " " << a[i].type.procent << " " << a[i].end.day << " " << a[i].end.month << " " << a[i].end.year << " " << a[i].idUsr << endl;
	}
	fout.close();
}

void SetFileDepositEnabled(Deposit* a, int n)
{
	ofstream fout;
	fout.open("depositenabled.txt", ios_base::trunc);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << a[i].type.maxSum << " " << a[i].type.minSum << " " << a[i].type.name << " " << a[i].type.period << " " << a[i].type.procent << " " << a[i].idUsr << " " << a[i].idAdm << " " << a[i].timeStart.hour << " " << a[i].timeStart.min << " " << a[i].start.day << " " << a[i].start.month << " " << a[i].start.year << " " << a[i].end.day << " " << a[i].end.month << " " << a[i].end.year << endl;
	}
	fout.close();
}

void SetFileDepositDisabled(Deposit* a, int n)
{
	ofstream fout;
	fout.open("depositdisabled.txt", ios_base::trunc);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << a[i].type.maxSum << " " << a[i].type.minSum << " " << a[i].type.name << " " << a[i].type.period << " " << a[i].type.procent << " " << a[i].idUsr << " " << a[i].idAdm << " " << a[i].timeStart.hour << " " << a[i].timeStart.min << " " << a[i].start.day << " " << a[i].start.month << " " << a[i].start.year << " " << a[i].end.day << " " << a[i].end.month << " " << a[i].end.year << endl;
	}
	fout.close();
}

void ViewTCredit(TCredit* arr, int n)
{
	puts("*****************************************************************************");
	puts("| �  | �������� | ������������ | ���.����� | ����.����� | ���������� ������ |");
	puts("*****************************************************************************");

	for (int i = 0; i < n; i++)
	{
		cout << "|" << setw(4) << i + 1 << "|" << setw(10) << arr[i].name << "|" << setw(14) << arr[i].period << "|" << setw(11) << arr[i].minSum << "|" << setw(12) << arr[i].maxSum << "|" << setw(19) << arr[i].procent << "|" << endl;
		puts("*****************************************************************************");
	}
}

void ViewCredit(Credit* arr, int n)
{
	puts("*********************************************************************************");
	puts("| �  | �������� | ID ������� | ID ������� |����� �������|���� ������|���� ����� |");
	puts("*********************************************************************************");
	for (int i = 0; i < n; i++)
	{
		cout << "|" << setw(4) << i + 1 << "|" << setw(10) << arr[i].type.name << "|" << setw(12) << arr[i].idAdm << "|" << setw(12) << arr[i].idUsr << "|    "; PrintTime(arr[i].timeStart); cout << "    |"; PrintDate(arr[i].start); cout << "|"; PrintDate(arr[i].end); cout << "|\n";
		puts("*********************************************************************************");
	}
}

void ViewTryCredit(TryCredit* arr, int n)
{
	puts("*******************************************************************************************************");
	puts("| �  | �������� | ������������ | ���.����� | ����.����� | ���������� ������ |���� ���������|ID �������|");
	puts("*******************************************************************************************************");
	for (int i = 0; i < n; i++)
	{
		cout << "|" << setw(4) << i + 1 << "|" << setw(10) << arr[i].type.name << "|" << setw(14) << arr[i].type.period << "|" << setw(11) << arr[i].type.minSum << "|" << setw(12) << arr[i].type.maxSum << "|" << setw(19) << arr[i].type.procent << "|  "; PrintDate(arr[i].end); cout << " |" << setw(10) << arr[i].idUsr << endl;
		puts("*******************************************************************************************************");
	}
}

void ViewTDeposit(TDeposit* arr, int n)
{
	puts("*****************************************************************************");
	puts("| �  | �������� | ������������ | ���.����� | ����.����� | ���������� ������ |");
	puts("*****************************************************************************");

	for (int i = 0; i < n; i++)
	{
		cout << "|" << setw(4) << i + 1 << "|" << setw(10) << arr[i].name << "|" << setw(14) << arr[i].period << "|" << setw(11) << arr[i].minSum << "|" << setw(12) << arr[i].maxSum << "|" << setw(19) << arr[i].procent << "|" << endl;
		puts("*****************************************************************************");
	}
}

void ViewDeposit(Deposit* arr, int n)
{
	puts("*********************************************************************************");
	puts("| �  | �������� | ID ������� | ID ������� |����� �������|���� ������|���� ����� |");
	puts("*********************************************************************************");
	for (int i = 0; i < n; i++)
	{
		cout << "|" << setw(4) << i + 1 << "|" << setw(10) << arr[i].type.name << "|" << setw(12) << arr[i].idAdm << "|" << setw(12) << arr[i].idUsr << "|    "; PrintTime(arr[i].timeStart); cout << "    |"; PrintDate(arr[i].start); cout << "|"; PrintDate(arr[i].end); cout << "|\n";
		puts("*********************************************************************************");
	}
}

void ViewTryDeposit(TryDeposit* arr, int n)
{
	puts("*******************************************************************************************************");
	puts("| �  | �������� | ������������ | ���.����� | ����.����� | ���������� ������ |���� ���������|ID �������|");
	puts("*******************************************************************************************************");
	for (int i = 0; i < n; i++)
	{
		cout << "|" << setw(4) << i + 1 << "|" << setw(10) << arr[i].type.name << "|" << setw(14) << arr[i].type.period << "|" << setw(11) << arr[i].type.minSum << "|" << setw(12) << arr[i].type.maxSum << "|" << setw(19) << arr[i].type.procent << "|  "; PrintDate(arr[i].end); cout << " |" << setw(10) << arr[i].idUsr << endl;
		puts("*******************************************************************************************************");
	}
}

void ViewUser(User* arr, int n)
{
	puts("******************************************************************************************************");
	puts("| �  |   �������   |    ���    |  ��������  |   �������   |              �����            |ID �������|");
	puts("******************************************************************************************************");
	for (int i = 0; i < n; i++)
	{
		cout << "|" << setw(4) << i + 1 << "|" << setw(13) << arr[i].fio.sName << "|" << setw(11) << arr[i].fio.name << "|" << setw(12) << arr[i].fio.patron << "|+375" << setw(19) << arr[i].telephone << "|�." << setw(10) << arr[i].adress.city << ", ��." << arr[i].adress.street << " " << setw(4) << arr[i].adress.house << "|" << setw(10) << arr[i].id << endl;
		puts("******************************************************************************************************");
	}
}

void ViewAdmin(Admin* arr, int n)
{
	puts("********************************************************");
	puts("| �  |   �������   |    ���    |  ��������  |ID �������|");
	puts("********************************************************");
	for (int i = 0; i < n; i++)
	{
		cout << "|" << setw(4) << i + 1 << "|" << setw(13) << arr[i].fio.sName << "|" << setw(11) << arr[i].fio.name << "|" << setw(12) << arr[i].fio.patron << "|" << setw(10) << arr[i].id << endl;
		puts("********************************************************");
	}
}

void AddTCredit()
{
	TCredit* arr = NULL;
	int n = GetFileTCredit(&arr);
	if (n == 0)
	{
		arr = new TCredit[2];
	}
	TCredit a;
	cout << "������� ������������:\n";
	a.name = CreateString();
	cout << "������� ������������ � ����:\n";
	a.period = CreateInt();
	cout << "������� ����������� ����� � BYN:\n";
	a.minSum = CreateInt();
	cout << "������� ������������ ����� � BYN:\n";
	a.maxSum = CreateInt();
	cout << "������� ���������� ������:\n";
	a.procent = CreateDouble();
	arr[n] = a;
	n++;
	SetFileTCredit(arr, n);
	delete[] arr;
}

void AddTDeposit()
{
	TDeposit* arr = NULL;
	int n = GetFileTDeposit(&arr);
	if (n == 0)
	{
		arr = new TDeposit[2];
	}
	TDeposit a;
	cout << "������� ������������:\n";
	a.name = CreateString();
	cout << "������� ������������ � ����:\n";
	a.period = CreateInt();
	cout << "������� ����������� ����� � BYN:\n";
	a.minSum = CreateInt();
	cout << "������� ������������ ����� � BYN:\n";
	a.maxSum = CreateInt();
	cout << "������� ���������� ������:\n";
	a.procent = CreateDouble();
	arr[n] = a;
	n++;
	SetFileTDeposit(arr, n);
	delete[] arr;
}

void DelTCredit()
{
	TCredit* arr = NULL;
	int n = GetFileTCredit(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		return;
	}
	ViewTCredit(arr, n);
	int z = -1;
	cout << "������� ����� ������ ��� ��������\n";
	while (z < 1)
	{
		z = CreateInt();
	}
	z--;
	TCredit* arr1 = new TCredit[n];
	int it = 0;
	for (int i = 0; i < z; i++)
	{
		arr1[it] = arr[i];
		it++;
	}
	for (int i = z + 1; i < n; i++)
	{
		arr1[it] = arr[i];
		it++;
	}
	SetFileTCredit(arr1, it);
	delete[] arr;
	delete[] arr1;
}

void DelTDeposit()
{
	TDeposit* arr = NULL;
	int n = GetFileTDeposit(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		return;
	}
	ViewTDeposit(arr, n);
	int z = -1;
	cout << "������� ����� ������ ��� ��������\n";
	while (z < 1)
	{
		z = CreateInt();
	}
	z--;
	TDeposit* arr1 = new TDeposit[n];
	int it = 0;
	for (int i = 0; i < z; i++)
	{
		arr1[it] = arr[i];
		it++;
	}
	for (int i = z + 1; i < n; i++)
	{
		arr1[it] = arr[i];
		it++;
	}
	SetFileTDeposit(arr1, it);
	delete[] arr;
	delete[] arr1;
}

void EditTCredit()
{
	TCredit* arr = NULL;
	int n = GetFileTCredit(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		return;
	}
	ViewTCredit(arr, n);
	int z = -1;
	cout << "������� ����� ������ ��� ��������������\n";
	while (z < 1)
	{
		z = CreateInt();
	}
	z--;
	bool work = true;
	while (work)
	{
		cout << "������� ���� ��� ���������:\n";
		cout << "1.������������\n";
		cout << "2.������������\n";
		cout << "3.����������� �����\n";
		cout << "4.������������ �����\n";
		cout << "5.���������� ������\n";
		cout << "6.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
			cout << "������� ������������:\n";
			arr[z].name = CreateString();
			break;
		case '2':
			cout << "������� ������������ � ����:\n";
			arr[z].period = CreateInt();
			break;
		case '3':
			cout << "������� ����������� ����� � BYN:\n";
			arr[z].minSum = CreateInt();
			break;
		case '4':
			cout << "������� ������������ ����� � BYN:\n";
			arr[z].maxSum = CreateInt();
			break;
		case '5':
			cout << "������� ���������� ������:\n";
			arr[z].procent = CreateDouble();
			break;
		case '6':
			work = false;
			break;
		default:
			cout << "������ �����\n";
		}
	}
	SetFileTCredit(arr, n);
	delete[] arr;
}

void EditTDeposit()
{
	TDeposit* arr = NULL;
	int n = GetFileTDeposit(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		return;
	}
	ViewTDeposit(arr, n);
	int z = -1;
	cout << "������� ����� ������ ��� ��������������\n";
	while (z < 1)
	{
		z = CreateInt();
	}
	z--;
	bool work = true;
	while (work)
	{
		cout << "������� ���� ��� ���������:\n";
		cout << "1.������������\n";
		cout << "2.������������\n";
		cout << "3.����������� �����\n";
		cout << "4.������������ �����\n";
		cout << "5.���������� ������\n";
		cout << "6.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
			cout << "������� ������������:\n";
			arr[z].name = CreateString();
			break;
		case '2':
			cout << "������� ������������ � ����:\n";
			arr[z].period = CreateInt();
			break;
		case '3':
			cout << "������� ����������� ����� � BYN:\n";
			arr[z].minSum = CreateInt();
			break;
		case '4':
			cout << "������� ������������ ����� � BYN:\n";
			arr[z].maxSum = CreateInt();
			break;
		case '5':
			cout << "������� ���������� ������:\n";
			arr[z].procent = CreateDouble();
			break;
		case '6':
			work = false;
			break;
		default:
			cout << "������ �����\n";
		}
	}
	SetFileTDeposit(arr, n);
	delete[] arr;
}

void SearchUser()
{
	User* arr = NULL;
	int n = GetFileUser(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		return;
	}
	ViewUser(arr, n);
	system("pause");
	bool work = true;
	while (work)
	{
		User* arr1 = new User[n];
		int it = 0;
		User a;
		cout << "������� ���� ��� ������:\n";
		cout << "1.�������\n";
		cout << "2.�����\n";
		cout << "3.����� ��������\n";
		cout << "4.ID\n";
		cout << "5.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
			cout << "������� ������������:\n";
			a.fio.sName = CreateString();
			for (int i = 0; i < n; i++)
			{
				if (a.fio.sName == arr[i].fio.sName)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewUser(arr1, it);
			system("pause");
			break;
		case '2':
			a.adress = CreateAdress();
			for (int i = 0; i < n; i++)
			{
				if (a.adress.city == arr[i].adress.city && a.adress.house == arr[i].adress.house && a.adress.street == arr[i].adress.street)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewUser(arr1, it);
			system("pause");
			break;
		case '3':
			cout << "������� ����� ��������:\n";
			a.telephone = CreateTelephone();
			for (int i = 0; i < n; i++)
			{
				if (a.telephone == arr[i].telephone)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewUser(arr1, it);
			system("pause");
			break;
		case '4':
			cout << "������� ID:\n";
			a.id = CreateInt();
			for (int i = 0; i < n; i++)
			{
				if (a.id == arr[i].id)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewUser(arr1, it);
			system("pause");
			break;
		case '5':
			work = false;
			break;
		default:
			cout << "������ �����\n";
		}
	}
	SetFileUser(arr, n);
	delete[] arr;
}

void SearchTCredit()
{
	TCredit* arr = NULL;
	int n = GetFileTCredit(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		return;
	}
	bool work = true;
	while (work)
	{
		TCredit* arr1 = new TCredit[n];
		int it = 0;
		TCredit a;
		cout << "������� ���� ��� ������:\n";
		cout << "1.������������\n";
		cout << "2.������������\n";
		cout << "3.����������� �����\n";
		cout << "4.������������ �����\n";
		cout << "5.���������� ������\n";
		cout << "6.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
			cout << "������� ������������:\n";
			a.name = CreateString();
			for (int i = 0; i < n; i++)
			{
				if (a.name == arr[i].name)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTCredit(arr1, it);
			system("pause");
			break;
		case '2':
			cout << "������� ������������ � ����:\n";
			a.period = CreateInt();
			for (int i = 0; i < n; i++)
			{
				if (a.period == arr[i].period)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTCredit(arr1, it);
			system("pause");
			break;
		case '3':
			cout << "������� ����������� ����� � BYN:\n";
			a.minSum = CreateInt();
			for (int i = 0; i < n; i++)
			{
				if (a.minSum == arr[i].minSum)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTCredit(arr1, it);
			system("pause");
			break;
		case '4':
			cout << "������� ������������ ����� � BYN:\n";
			a.maxSum = CreateInt();
			for (int i = 0; i < n; i++)
			{
				if (a.maxSum == arr[i].maxSum)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTCredit(arr1, it);
			system("pause");
			break;
		case '5':
			cout << "������� ���������� ������:\n";
			a.procent = CreateDouble();
			for (int i = 0; i < n; i++)
			{
				if (a.procent == arr[i].procent)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTCredit(arr1, it);
			system("pause");
			break;
		case '6':
			work = false;
			break;
		default:
			cout << "������ �����\n";
			system("pause");
		}
		delete[] arr1;
	}
	delete[] arr;
}

void SearchCredit(int id)
{
	Credit* arr = NULL;
	int n = 0;
	bool work = true;
	while (work)
	{
		int ch = 0;
		cout << "�������� ��� ������� ��� ������\n";
		cout << "1.�������\n";
		cout << "2.��������\n";
		cout << "3.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			n = GetFileCreditEnabled(&arr);
			if (n == 0)
			{
				cout << "��� �� ����� ������\n";
				system("pause");
				return;
			}
			work = false;
		}break;
		case '2':
		{
			n = GetFileCreditDisabled(&arr);
			if (n == 0)
			{
				cout << "��� �� ����� ������\n";
				system("pause");
				return;
			}
			work = false;
		}break;
		case '3':
		{
			return;
		}
		default:
			cout << "������������ ����\n";
			system("pause");
		}
	}
	Credit a;
	work = true;
	while (work)
	{
		Credit* arr1 = new Credit[n];
		int it = 0;
		if (ID == 0)
		{
			cout << "�������� ���� ��� ������\n";
			cout << "1.ID �������\n";
			cout << "2.ID �������\n";
			cout << "3.�������� ���� �������\n";
			cout << "4.�����\n";
			char c;
			cin >> c;
			switch (c)
			{
			case '1':
			{
				cout << "������� ID �������\n";
				int x = CreateInt();
				for (int i = 0; i < n; i++)
				{
					if (arr[i].idAdm == x)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
			}break;
			case '2':
			{
				cout << "������� ID �������\n";
				int x = CreateInt();
				for (int i = 0; i < n; i++)
				{
					if (arr[i].idUsr == x)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
			}break;
			case '3':
			{
				cout << "������� �������� ���� �������\n";
				string x = CreateString();
				for (int i = 0; i < n; i++)
				{
					if (arr[i].type.name == x)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
			}break;
			case '4':
			{
				work = false;
			}break;
			default:
				cout << "������������ ����\n";
				system("pause");
			}
		}
		else
		{
			cout << "�������� ���� ��� ������\n";
			cout << "1.ID �������\n";
			cout << "2.�������� ���� �������\n";
			cout << "3.�����\n";
			char c;
			cin >> c;
			switch (c)
			{
			case '1':
			{
				cout << "������� ID �������\n";
				int x = CreateInt();
				for (int i = 0; i < n; i++)
				{
					if (arr[i].idAdm == x)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
			}break;
			case '2':
			{
				cout << "������� �������� ���� �������\n";
				string x = CreateString();
				for (int i = 0; i < n; i++)
				{
					if (arr[i].type.name == x)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
			}break;
			case '3':
			{
				work = false;
			}break;
			default:
				cout << "������������ ����\n";
				system("pause");
			}
		}
		if (it == 0)
		{
			cout << "�� ������� �� ����� ������\n";
		}
		else
		{
			ViewCredit(arr1, it);
		}
		system("pause");
		delete[] arr1;
	}
	delete[] arr;
}

void SearchTDeposit()
{
	TDeposit* arr = NULL;
	int n = GetFileTDeposit(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		return;
	}
	bool work = true;
	while (work)
	{
		TDeposit* arr1 = new TDeposit[n];
		int it = 0;
		TDeposit a;
		cout << "������� ���� ��� ������:\n";
		cout << "1.������������\n";
		cout << "2.������������\n";
		cout << "3.����������� �����\n";
		cout << "4.������������ �����\n";
		cout << "5.���������� ������\n";
		cout << "6.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
			cout << "������� ������������:\n";
			a.name = CreateString();
			for (int i = 0; i < n; i++)
			{
				if (a.name == arr[i].name)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTDeposit(arr1, it);
			system("pause");
			break;
		case '2':
			cout << "������� ������������ � ����:\n";
			a.period = CreateInt();
			for (int i = 0; i < n; i++)
			{
				if (a.period == arr[i].period)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTDeposit(arr1, it);
			system("pause");
			break;
		case '3':
			cout << "������� ����������� ����� � BYN:\n";
			a.minSum = CreateInt();
			for (int i = 0; i < n; i++)
			{
				if (a.minSum == arr[i].minSum)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTDeposit(arr1, it);
			system("pause");
			break;
		case '4':
			cout << "������� ������������ ����� � BYN:\n";
			a.maxSum = CreateInt();
			for (int i = 0; i < n; i++)
			{
				if (a.maxSum == arr[i].maxSum)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTDeposit(arr1, it);
			system("pause");
			break;
		case '5':
			cout << "������� ���������� ������:\n";
			a.procent = CreateDouble();
			for (int i = 0; i < n; i++)
			{
				if (a.procent == arr[i].procent)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTDeposit(arr1, it);
			system("pause");
			break;
		case '6':
			work = false;
			break;
		default:
			cout << "������ �����\n";
			system("pause");
		}
		delete[] arr1;
	}
	delete[] arr;
}

void SearchDeposit(int id)
{
	Deposit* arr = NULL;
	int n = 0;
	bool work = true;
	while (work)
	{
		int ch = 0;
		cout << "�������� ��� �������� ��� ������\n";
		cout << "1.�������\n";
		cout << "2.��������\n";
		cout << "3.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			n = GetFileDepositEnabled(&arr);
			if (n == 0)
			{
				cout << "��� �� ����� ������\n";
				system("pause");
				return;
			}
			work = false;
		}break;
		case '2':
		{
			n = GetFileDepositDisabled(&arr);
			if (n == 0)
			{
				cout << "��� �� ����� ������\n";
				system("pause");
				return;
			}
			work = false;
		}break;
		case '3':
		{
			return;
		}
		default:
			cout << "������������ ����\n";
			system("pause");
		}
	}
	Deposit a;
	work = true;
	while (work)
	{
		Deposit* arr1 = new Deposit[n];
		int it = 0;
		if (ID == 0)
		{
			cout << "�������� ���� ��� ������\n";
			cout << "1.ID �������\n";
			cout << "2.ID �������\n";
			cout << "3.�������� ���� ��������\n";
			cout << "4.�����\n";
			char c;
			cin >> c;
			switch (c)
			{
			case '1':
			{
				cout << "������� ID �������\n";
				int x = CreateInt();
				for (int i = 0; i < n; i++)
				{
					if (arr[i].idAdm == x)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
			}break;
			case '2':
			{
				cout << "������� ID �������\n";
				int x = CreateInt();
				for (int i = 0; i < n; i++)
				{
					if (arr[i].idUsr == x)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
			}break;
			case '3':
			{
				cout << "������� �������� ���� ��������\n";
				string x = CreateString();
				for (int i = 0; i < n; i++)
				{
					if (arr[i].type.name == x)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
			}break;
			case '4':
			{
				work = false;
			}break;
			default:
				cout << "������������ ����\n";
				system("pause");
			}
		}
		else
		{
			cout << "�������� ���� ��� ������\n";
			cout << "1.ID �������\n";
			cout << "2.�������� ���� ��������\n";
			cout << "3.�����\n";
			char c;
			cin >> c;
			switch (c)
			{
			case '1':
			{
				cout << "������� ID �������\n";
				int x = CreateInt();
				for (int i = 0; i < n; i++)
				{
					if (arr[i].idAdm == x)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
			}break;
			case '2':
			{
				cout << "������� �������� ���� ��������\n";
				string x = CreateString();
				for (int i = 0; i < n; i++)
				{
					if (arr[i].type.name == x)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
			}break;
			case '3':
			{
				work = false;
			}break;
			default:
				cout << "������������ ����\n";
				system("pause");
			}
		}
		if (it == 0)
		{
			cout << "�� ������� �� ����� ������\n";
		}
		else
		{
			ViewDeposit(arr1, it);
		}
		system("pause");
		delete[] arr1;
	}
	delete[] arr;
}

void SortUser()
{
	User* arr = NULL;
	int n = GetFileUser(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		return;
	}
	bool work = true;
	while (work)
	{
		cout << "������� ���� ��� ����������:\n";
		cout << "1.������������\n";
		cout << "2.������������\n";
		cout << "3.ID\n";
		cout << "4.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (strcmp(arr[i].fio.sName.c_str(), arr[j].fio.sName.c_str()) == -1)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewUser(arr, n);
			system("pause");
			SetFileUser(arr, n);
			break;
		case '2':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (strcmp(arr[i].adress.city.c_str(), arr[j].adress.city.c_str()) == -1)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewUser(arr, n);
			system("pause");
			SetFileUser(arr, n);
			break;
		case '3':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (arr[i].id > arr[j].id)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewUser(arr, n);
			system("pause");
			SetFileUser(arr, n);
			break;
		case '4':
			work = false;
			break;
		default:
			cout << "������ �����\n";
			system("pause");
		}
	}
	delete[] arr;
}

void SortTCredit()
{
	TCredit* arr = NULL;
	int n = GetFileTCredit(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		return;
	}
	bool work = true;
	while (work)
	{
		cout << "������� ���� ��� ����������:\n";
		cout << "1.������������\n";
		cout << "2.������������\n";
		cout << "3.����������� �����\n";
		cout << "4.������������ �����\n";
		cout << "5.���������� ������\n";
		cout << "6.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (strcmp(arr[i].name.c_str(), arr[j].name.c_str()) == 1)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewTCredit(arr, n);
			system("pause");
			SetFileTCredit(arr, n);
			break;
		case '2':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (arr[i].period > arr[j].period)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewTCredit(arr, n);
			system("pause");
			SetFileTCredit(arr, n);
			break;
		case '3':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (arr[i].minSum > arr[j].minSum)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewTCredit(arr, n);
			system("pause");
			SetFileTCredit(arr, n);
			break;
		case '4':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (arr[i].maxSum > arr[j].maxSum)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewTCredit(arr, n);
			system("pause");
			SetFileTCredit(arr, n);
			break;
		case '5':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (arr[i].procent > arr[j].procent)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewTCredit(arr, n);
			system("pause");
			SetFileTCredit(arr, n);
			break;
		case '6':
			work = false;
			break;
		default:
			cout << "������ �����\n";
			system("pause");
		}
	}
	delete[] arr;
}

void SortCredit(int id)
{
	Credit* arr = NULL;
	int n = 0;
	bool work = true;
	while (work)
	{
		int ch = 0;
		cout << "�������� ��� ������� ��� ����������\n";
		cout << "1.�������\n";
		cout << "2.��������\n";
		cout << "3.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			n = GetFileCreditEnabled(&arr);
			if (n == 0)
			{
				cout << "��� �� ����� ������\n";
				system("pause");
				return;
			}
			work = false;
		}break;
		case '2':
		{
			n = GetFileCreditDisabled(&arr);
			if (n == 0)
			{
				cout << "��� �� ����� ������\n";
				system("pause");
				return;
			}
			work = false;
		}break;
		case '3':
		{
			return;
		}
		default:
			cout << "������������ ����\n";
			system("pause");
		}
	}
	work = true;
	while (work)
	{
		cout << "�������� ���� ��� ����������\n";
		cout << "1.���� ������\n";
		cout << "2.���� ��������\n";
		cout << "3.�������� ���� �������\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':system("cls");
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (CompareDate(arr[i].start, arr[j].start) == 1)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			if (id == 0)
			{
				ViewCredit(arr, n);
				system("pause");
			}
			else
			{
				Credit* arr1 = new Credit[n];
				int it = 0;
				for (int i = 0; i < n; i++)
				{
					if (arr[i].idUsr == id)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
				if (it == 0)
				{
					cout << "� ��� ��� ������ ��������\n";
					system("pause");
				}
				else
				{
					ViewCredit(arr1, it);
					system("pause");
				}
			}
		}break;
		case '2':system("cls");
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (CompareDate(arr[i].end, arr[j].end) == 1)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			if (id == 0)
			{
				ViewCredit(arr, n);
				system("pause");
			}
			else
			{
				Credit* arr1 = new Credit[n];
				int it = 0;
				for (int i = 0; i < n; i++)
				{
					if (arr[i].idUsr == id)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
				if (it == 0)
				{
					cout << "� ��� ��� ������ ��������\n";
					system("pause");
				}
				else
				{
					ViewCredit(arr1, it);
					system("pause");
				}
			}
		}break;
		case '3':system("cls");
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (strcmp(arr[i].type.name.c_str(), arr[j].type.name.c_str()) == 1)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			if (id == 0)
			{
				ViewCredit(arr, n);
				system("pause");
			}
			else
			{
				Credit* arr1 = new Credit[n];
				int it = 0;
				for (int i = 0; i < n; i++)
				{
					if (arr[i].idUsr == id)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
				if (it == 0)
				{
					cout << "� ��� ��� ������ ��������\n";
					system("pause");
				}
				else
				{
					ViewCredit(arr1, it);
					system("pause");
				}
			}
		}break;
		default:system("cls");
			cout << "������������ ����" << endl;
			system("pause");
			break;
		}
	}
}

void SortTDeposit()
{
	TDeposit* arr = NULL;
	int n = GetFileTDeposit(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		return;
	}
	bool work = true;
	while (work)
	{
		cout << "������� ���� ��� ����������:\n";
		cout << "1.������������\n";
		cout << "2.������������\n";
		cout << "3.����������� �����\n";
		cout << "4.������������ �����\n";
		cout << "5.���������� ������\n";
		cout << "6.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (strcmp(arr[i].name.c_str(), arr[j].name.c_str()) == 1)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewTDeposit(arr, n);
			system("pause");
			SetFileTDeposit(arr, n);
			break;
		case '2':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (arr[i].period > arr[j].period)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewTDeposit(arr, n);
			system("pause");
			SetFileTDeposit(arr, n);
			break;
		case '3':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (arr[i].minSum > arr[j].minSum)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewTDeposit(arr, n);
			system("pause");
			SetFileTDeposit(arr, n);
			break;
		case '4':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (arr[i].maxSum > arr[j].maxSum)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewTDeposit(arr, n);
			system("pause");
			SetFileTDeposit(arr, n);
			break;
		case '5':
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (arr[i].procent > arr[j].procent)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			ViewTDeposit(arr, n);
			system("pause");
			SetFileTDeposit(arr, n);
			break;
		case '6':
			work = false;
			break;
		default:
			cout << "������ �����\n";
			system("pause");
		}
	}
	delete[] arr;
}

void SortDeposit(int id)
{
	Deposit* arr = NULL;
	int n = 0;
	bool work = true;
	while (work)
	{
		int ch = 0;
		cout << "�������� ��� �������� ��� ����������\n";
		cout << "1.�������\n";
		cout << "2.��������\n";
		cout << "3.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			n = GetFileDepositEnabled(&arr);
			if (n == 0)
			{
				cout << "��� �� ����� ������\n";
				system("pause");
				return;
			}
			work = false;
		}break;
		case '2':
		{
			n = GetFileDepositDisabled(&arr);
			if (n == 0)
			{
				cout << "��� �� ����� ������\n";
				system("pause");
				return;
			}
			work = false;
		}break;
		case '3':
		{
			return;
		}
		default:
			cout << "������������ ����\n";
			system("pause");
		}
	}
	work = true;
	while (work)
	{
		cout << "�������� ���� ��� ����������\n";
		cout << "1.���� ������\n";
		cout << "2.���� ��������\n";
		cout << "3.�������� ���� ��������\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':system("cls");
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (CompareDate(arr[i].start, arr[j].start) == 1)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			if (id == 0)
			{
				ViewDeposit(arr, n);
				system("pause");
			}
			else
			{
				Deposit* arr1 = new Deposit[n];
				int it = 0;
				for (int i = 0; i < n; i++)
				{
					if (arr[i].idUsr == id)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
				if (it == 0)
				{
					cout << "� ��� ��� ������ ���������\n";
					system("pause");
				}
				else
				{
					ViewDeposit(arr1, it);
					system("pause");
				}
				delete[] arr1;
			}
		}break;
		case '2':system("cls");
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (CompareDate(arr[i].end, arr[j].end) == 1)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			if (id == 0)
			{
				ViewDeposit(arr, n);
				system("pause");
			}
			else
			{
				Deposit* arr1 = new Deposit[n];
				int it = 0;
				for (int i = 0; i < n; i++)
				{
					if (arr[i].idUsr == id)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
				if (it == 0)
				{
					cout << "� ��� ��� ������ ���������\n";
					system("pause");
				}
				else
				{
					ViewDeposit(arr1, it);
					system("pause");
				}
				delete[] arr1;
			}
		}break;
		case '3':system("cls");
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (strcmp(arr[i].type.name.c_str(), arr[j].type.name.c_str()) == 1)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			if (id == 0)
			{
				ViewDeposit(arr, n);
				system("pause");
			}
			else
			{
				Deposit* arr1 = new Deposit[n];
				int it = 0;
				for (int i = 0; i < n; i++)
				{
					if (arr[i].idUsr == id)
					{
						arr1[it] = arr[i];
						it++;
					}
				}
				if (it == 0)
				{
					cout << "� ��� ��� ������ ���������\n";
					system("pause");
				}
				else
				{
					ViewDeposit(arr1, it);
					system("pause");
				}
				delete[] arr1;
			}
		}break;
		default:system("cls");
			cout << "������������ ����" << endl;
			system("pause");
			break;
		}
	}
}

void FilterUser()
{
	User* arr = NULL;
	int n = GetFileUser(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		return;
	}
	bool work = true;
	while (work)
	{
		User* arr1 = new User[n];
		int it = 0;
		cout << "������� ���� ��� ����������:\n";
		cout << "1.�������\n";
		cout << "2.�������� ������\n";
		cout << "3.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			cout << "������� ������ ����� �������:\n��: ";
			char a;
			cin >> a;
			cout << "��: ";
			char b;
			cin >> b;
			if (a > b)
			{
				swap(a, b);
			}
			for (int i = 0; i < n; i++)
			{
				if (a <= arr[i].fio.sName[0] && b >= arr[i].fio.sName[0])
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewUser(arr1, it);
			system("pause");
			break;
		}

		case '2':
		{
			cout << "������� ������ ����� �������� ������:\n��: ";
			char a;
			cin >> a;
			cout << "��: ";
			char b;
			cin >> b;
			if (a > b)
			{
				swap(a, b);
			}
			for (int i = 0; i < n; i++)
			{
				if (a <= arr[i].adress.city[0] && b >= arr[i].adress.city[0])
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewUser(arr1, it);
			system("pause");
			break;
		}
		case '3':
			work = false;
			break;
		default:
			cout << "������ �����\n";
			system("pause");
		}
		delete[] arr1;
	}
	delete[] arr;
}

void FilterTCredit()
{
	TCredit* arr = NULL;
	int n = GetFileTCredit(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		return;
	}
	bool work = true;
	while (work)
	{
		TCredit* arr1 = new TCredit[n];
		int it = 0;
		TCredit a, b;
		cout << "������� ���� ��� ����������:\n";
		cout << "1.������������\n";
		cout << "2.����������� �����\n";
		cout << "3.������������ �����\n";
		cout << "4.���������� ������\n";
		cout << "5.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
			cout << "������� ����������� ������������ � ����:\n";
			a.period = CreateInt();
			cout << "������� ������������ ������������ � ����:\n";
			b.period = CreateInt();
			if (a.period > b.period)
			{
				swap(a.period, b.period);
			}
			for (int i = 0; i < n; i++)
			{
				if (a.period <= arr[i].period && b.period >= arr[i].period)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTCredit(arr1, it);
			system("pause");
			break;
		case '2':
			cout << "������� ����������� ����� � BYN (������ ������):\n";
			a.minSum = CreateInt();
			cout << "������� ����������� ����� � BYN (������� ������):\n";
			b.minSum = CreateInt();
			if (a.minSum > b.minSum)
			{
				swap(a.minSum, b.minSum);
			}
			for (int i = 0; i < n; i++)
			{
				if (a.minSum <= arr[i].minSum && b.minSum >= arr[i].minSum)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTCredit(arr1, it);
			system("pause");
			break;
		case '3':
			cout << "������� ������������ ����� � BYN (������ ������):\n";
			a.maxSum = CreateInt();
			cout << "������� ������������ ����� � BYN (������� ������):\n";
			b.maxSum = CreateInt();
			for (int i = 0; i < n; i++)
			{
				if (a.maxSum <= arr[i].maxSum && b.maxSum >= arr[i].maxSum)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTCredit(arr1, it);
			system("pause");
			break;
		case '4':
			cout << "������� ����������� ���������� ������:\n";
			a.procent = CreateDouble();
			cout << "������� ������������ ���������� ������:\n";
			b.procent = CreateDouble();
			for (int i = 0; i < n; i++)
			{
				if (a.procent <= arr[i].procent && b.procent >= arr[i].procent)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTCredit(arr1, it);
			system("pause");
			break;
		case '5':
			work = false;
			break;
		default:
			cout << "������ �����\n";
			system("pause");
		}
		delete[] arr1;
	}
	delete[] arr;
}

void FilterCredit(int id)
{
	Credit* arr = NULL;
	int n = 0;
	bool work = true;
	while (work)
	{
		int ch = 0;
		cout << "�������� ��� ������� ��� ������\n";
		cout << "1.�������\n";
		cout << "2.��������\n";
		cout << "3.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			n = GetFileCreditEnabled(&arr);
			if (n == 0)
			{
				cout << "��� �� ����� ������\n";
				system("pause");
				return;
			}
			work = false;
		}break;
		case '2':
		{
			n = GetFileCreditDisabled(&arr);
			if (n == 0)
			{
				cout << "��� �� ����� ������\n";
				system("pause");
				return;
			}
			work = false;
		}break;
		case '3':
		{
			return;
		}
		default:
			cout << "������������ ����\n";
			system("pause");
		}
	}
	Credit a;
	work = true;
	Date b, d;
	while (work)
	{
		Credit* arr1 = new Credit[n];
		int it = 0;
		cout << "�������� ���� ��� ����������\n";
		cout << "1.���� ������\n";
		cout << "2.���� ���������\n";
		cout << "3.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			cout << "������� ����������� ���� ������\n";
			b = CreateDate();
			cout << "������� ������������ ���� ������\n";
			d = CreateDate();
			if (CompareDate(b, d) == 1)
			{
				swap(b, d);
			}
			for (int i = 0; i < n; i++)
			{
				if (CompareDate(b, arr[i].start) == -1 && CompareDate(d, arr[i].start) == 1)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
		}break;
		case '2':
		{
			cout << "������� ����������� ���� �����\n";
			b = CreateDate();
			cout << "������� ������������ ���� �����\n";
			d = CreateDate();
			if (CompareDate(b, d) == 1)
			{
				swap(b, d);
			}
			for (int i = 0; i < n; i++)
			{
				if (CompareDate(b, arr[i].end) == -1 && CompareDate(d, arr[i].end) == 1)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
		}break;
		case '3':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			system("pause");
		}
		if (it == 0)
		{
			cout << "�� ������� �� ����� ������\n";
		}
		else
		{
			if (id == 0)
			{
				ViewCredit(arr1, it);
				system("pause");
			}
			else
			{
				Credit* arr2 = new Credit[it];
				int it2 = 0;
				for (int i = 0; i < it; i++)
				{
					if (arr1[i].idUsr == id)
					{
						arr2[it2] = arr1[i];
						it2++;
					}
				}
				if (it2 == 0)
				{
					cout << "�� ������� �� ����� ������\n";
				}
				else
				{
					ViewCredit(arr2, it2);
					system("pause");
				}
				delete[] arr2;
			}
		}
		system("pause");
		delete[] arr1;
	}
	delete[] arr;
}

void FilterTDeposit()
{
	TDeposit* arr = NULL;
	int n = GetFileTDeposit(&arr);
	if (n == 0)
	{
		cout << "���� ����\n";
		return;
	}
	bool work = true;
	while (work)
	{
		TDeposit* arr1 = new TDeposit[n];
		int it = 0;
		TDeposit a, b;
		cout << "������� ���� ��� ����������:\n";
		cout << "1.������������\n";
		cout << "2.����������� �����\n";
		cout << "3.������������ �����\n";
		cout << "4.���������� ������\n";
		cout << "5.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
			cout << "������� ����������� ������������ � ����:\n";
			a.period = CreateInt();
			cout << "������� ������������ ������������ � ����:\n";
			b.period = CreateInt();
			if (a.period > b.period)
			{
				swap(a.period, b.period);
			}
			for (int i = 0; i < n; i++)
			{
				if (a.period <= arr[i].period && b.period >= arr[i].period)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTDeposit(arr1, it);
			system("pause");
			break;
		case '2':
			cout << "������� ����������� ����� � BYN (������ ������):\n";
			a.minSum = CreateInt();
			cout << "������� ����������� ����� � BYN (������� ������):\n";
			b.minSum = CreateInt();
			if (a.minSum > b.minSum)
			{
				swap(a.minSum, b.minSum);
			}
			for (int i = 0; i < n; i++)
			{
				if (a.minSum <= arr[i].minSum && b.minSum >= arr[i].minSum)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTDeposit(arr1, it);
			system("pause");
			break;
		case '3':
			cout << "������� ������������ ����� � BYN (������ ������):\n";
			a.maxSum = CreateInt();
			cout << "������� ������������ ����� � BYN (������� ������):\n";
			b.maxSum = CreateInt();
			for (int i = 0; i < n; i++)
			{
				if (a.maxSum <= arr[i].maxSum && b.maxSum >= arr[i].maxSum)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTDeposit(arr1, it);
			system("pause");
			break;
		case '4':
			cout << "������� ����������� ���������� ������:\n";
			a.procent = CreateDouble();
			cout << "������� ������������ ���������� ������:\n";
			b.procent = CreateDouble();
			for (int i = 0; i < n; i++)
			{
				if (a.procent <= arr[i].procent && b.procent >= arr[i].procent)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			if (it == 0)
			{
				cout << "������� �� �������\n";
				system("pause");
				break;
			}
			ViewTDeposit(arr1, it);
			system("pause");
			break;
		case '5':
			work = false;
			break;
		default:
			cout << "������ �����\n";
			system("pause");
		}
		delete[] arr1;
	}
	delete[] arr;
}

void FilterDeposit(int id)
{
	Deposit* arr = NULL;
	int n = 0;
	bool work = true;
	while (work)
	{
		int ch = 0;
		cout << "�������� ��� �������� ��� ������\n";
		cout << "1.�������\n";
		cout << "2.��������\n";
		cout << "3.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			n = GetFileDepositEnabled(&arr);
			if (n == 0)
			{
				cout << "��� �� ����� ������\n";
				system("pause");
				return;
			}
			work = false;
		}break;
		case '2':
		{
			n = GetFileDepositDisabled(&arr);
			if (n == 0)
			{
				cout << "��� �� ����� ������\n";
				system("pause");
				return;
			}
			work = false;
		}break;
		case '3':
		{
			return;
		}
		default:
			cout << "������������ ����\n";
			system("pause");
		}
	}
	Deposit a;
	work = true;
	Date b, d;
	while (work)
	{
		Deposit* arr1 = new Deposit[n];
		int it = 0;
		cout << "�������� ���� ��� ����������\n";
		cout << "1.���� ������\n";
		cout << "2.���� ���������\n";
		cout << "3.�����\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			cout << "������� ����������� ���� ������\n";
			b = CreateDate();
			cout << "������� ������������ ���� ������\n";
			d = CreateDate();
			if (CompareDate(b, d) == 1)
			{
				swap(b, d);
			}
			for (int i = 0; i < n; i++)
			{
				if (CompareDate(b, arr[i].start) == -1 && CompareDate(d, arr[i].start) == 1)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
		}break;
		case '2':
		{
			cout << "������� ����������� ���� �����\n";
			b = CreateDate();
			cout << "������� ������������ ���� �����\n";
			d = CreateDate();
			if (CompareDate(b, d) == 1)
			{
				swap(b, d);
			}
			for (int i = 0; i < n; i++)
			{
				if (CompareDate(b, arr[i].end) == -1 && CompareDate(d, arr[i].end) == 1)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
		}break;
		case '3':
		{
			work = false;
		}break;
		default:
			cout << "������������ ����\n";
			system("pause");
		}
		if (it == 0)
		{
			cout << "�� ������� �� ����� ������\n";
		}
		else
		{
			if (id == 0)
			{
				ViewDeposit(arr1, it);
				system("pause");
			}
			else
			{
				Deposit* arr2 = new Deposit[it];
				int it2 = 0;
				for (int i = 0; i < it; i++)
				{
					if (arr1[i].idUsr == id)
					{
						arr2[it2] = arr1[i];
						it2++;
					}
				}
				if (it2 == 0)
				{
					cout << "�� ������� �� ����� ������\n";
				}
				else
				{
					ViewDeposit(arr2, it2);
					system("pause");
				}
				delete[] arr2;
			}
		}
		system("pause");
		delete[] arr1;
	}
	delete[] arr;
}

bool CheckNumbers(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] > '9' || str[i] < '0')
		{
			return false;
		}
	}
	return true;
}
void MakeTryCredit()
{
	TCredit* arrt = NULL;
	int nt = GetFileTCredit(&arrt);
	if (nt == 0)
	{
		cout << "��� �� ������ ���� �������\n";
		system("pause");
		return;
	}
	TryCredit* arr = NULL;
	int n = GetFileTryCredit(&arr);
	if (n == 0)
	{
		arr = new TryCredit[2];
	}
	int choise = -1;
	ViewTCredit(arrt, nt);
	cout << "������� ����� ���� �������\n";
	while (choise<1 || choise>nt)
	{
		choise = CreateInt();
	}
	cout << "������� ���� ���������\n";
	arr[n].end = CreateDate();
	arr[n].idUsr = ID;
	arr[n].type = arrt[choise - 1];
	SetFileTryCredit(arr, n + 1);
	delete[] arr;
	delete[] arrt;
}
void MakeTryDeposit()
{
	TDeposit* arrt = NULL;
	int nt = GetFileTDeposit(&arrt);
	if (nt == 0)
	{
		cout << "��� �� ������ ���� ��������\n";
		system("pause");
		return;
	}
	TryDeposit* arr = NULL;
	int n = GetFileTryDeposit(&arr);
	if (n == 0)
	{
		arr = new TryDeposit[2];
	}
	int choise = -1;
	ViewTDeposit(arrt, nt);
	cout << "������� ����� ���� ��������\n";
	while (choise<1 || choise>nt)
	{
		choise = CreateInt();
	}
	cout << "������� ���� ���������\n";
	arr[n].end = CreateDate();
	arr[n].idUsr = ID;
	arr[n].type = arrt[choise - 1];
	SetFileTryDeposit(arr, n + 1);
	delete[] arr;
	delete[] arrt;
}
void AcceptCredit()
{
	TryCredit* arr = NULL;
	int n = GetFileTryCredit(&arr);
	if (n == 0)
	{
		cout << "������ �� ������� ���\n";
		system("pause");
		return;
	}
	arr = new TryCredit[n];
	ViewTryCredit(arr, n);
	cout << "������� ����� ������ ��� 0 ��� ������\n";
	int z = -1;
	while (z<0 || z>n)
	{
		z = CreateInt();
		if (z<0 || z>n)
		{
			cout << "����� ������ ���, ��������� ����\n";
		}
	}
	if (z == 0)
	{
		delete[] arr;
		return;
	}
	z--;
	system("cls");
	ViewTryCredit(arr + z, 1);
	bool work = true;
	while (work)
	{
		cout << "�������� ��������\n";
		cout << "1.������� ������\n";
		cout << "2.��������� ������\n";
		cout << "3.����� ��� ����������� �� ������\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			system("cls");
			swap(arr[z], arr[n - 1]);
			SetFileTryCredit(arr, n - 1);
			Credit* arr1 = NULL;
			int nc = GetFileCreditEnabled(&arr1);
			if (nc == 0)
			{
				arr1 = new Credit[2];
			}
			arr1[nc].type = arr[z].type;
			arr1[nc].end = arr[z].end;
			arr1[nc].idUsr = arr1[n].idUsr;
			arr1[nc].idAdm = IDADMIN;
			cout << "������� ���� �������\\n";
			arr1[nc].start = CreateDate();
			cout << "������� ����� �������\n";
			arr1[nc].timeStart = CreateTime();
			SetFileCreditEnabled(arr1, nc + 1);
			delete[] arr1;
			delete[] arr;
			work = false;
		}break;
		case '2':
		{
			system("cls");
			swap(arr[z], arr[n - 1]);
			SetFileTryCredit(arr, n - 1);
			work = false;
		}break;
		case '3':
		{
			system("cls");
			work = false;
			SetFileTryCredit(arr, n);
			delete[] arr;
		}break;
		default:
			break;
		}
	}
}
void AcceptDeposit()
{
	TryDeposit* arr = NULL;
	int n = GetFileTryDeposit(&arr);
	if (n == 0)
	{
		cout << "������ �� �������� ���\n";
		system("pause");
		return;
	}
	arr = new TryDeposit[n];
	ViewTryDeposit(arr, n);
	cout << "������� ����� ������ ��� 0 ��� ������\n";
	int z = -1;
	while (z<0 || z>n)
	{
		z = CreateInt();
		if (z<0 || z>n)
		{
			cout << "����� ������ ���, ��������� ����\n";
		}
	}
	if (z == 0)
	{
		delete[] arr;
		return;
	}
	z--;
	system("cls");
	ViewTryDeposit(arr + z, 1);
	bool work = true;
	while (work)
	{
		cout << "�������� ��������\n";
		cout << "1.������� ������\n";
		cout << "2.��������� ������\n";
		cout << "3.����� ��� ����������� �� ������\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			system("cls");
			swap(arr[z], arr[n - 1]);
			SetFileTryDeposit(arr, n - 1);
			Deposit* arr1 = NULL;
			int nc = GetFileDepositEnabled(&arr1);
			if (nc == 0)
			{
				arr1 = new Deposit[2];
			}
			arr1[nc].type = arr[z].type;
			arr1[nc].end = arr[z].end;
			arr1[nc].idUsr = arr1[n].idUsr;
			arr1[nc].idAdm = IDADMIN;
			cout << "������� ���� �������\\n";
			arr1[nc].start = CreateDate();
			cout << "������� ����� �������\n";
			arr1[nc].timeStart = CreateTime();
			SetFileDepositEnabled(arr1, nc + 1);
			delete[] arr1;
			delete[] arr;
			work = false;
		}break;
		case '2':
		{
			system("cls");
			swap(arr[z], arr[n - 1]);
			SetFileTryDeposit(arr, n - 1);
			work = false;
		}break;
		case '3':
		{
			system("cls");
			work = false;
			SetFileTryDeposit(arr, n);
			delete[] arr;
		}break;
		default:
			break;
		}
	}
}
void EndCredit()
{
	Credit* arre = NULL;
	int ne = GetFileCreditEnabled(&arre);
	if (ne != 0)
	{
		Credit* arr = new Credit[ne];
		int it = 0;
		for (int i = 0; i < ne; i++)
		{
			if (arre[i].idUsr == ID)
			{
				arr[it] = arre[i];
				it++;
			}
		}
		if (it == 0)
		{
			cout << "� ��� ��� ������ ��������\n";
			system("pause");
			return;
		}
		ViewCredit(arr, it);
		int z = -1;
		cout << "������� ����� ������ ��� �������\n";
		while (z<1 && z>it)
		{
			z = CreateInt();
		}
		z--;
		for (int i = 0; i < ne; i++)
		{
			if (memcmp(arre + i, arr + z, sizeof(Credit)) == 0)
			{
				for (int j = i; j < ne - 1; j++)
				{
					arre[i] = arre[i + 1];
				}
				ne--;
				SetFileCreditEnabled(arre, ne);
				break;
			}
		}
		delete[] arre;
		ne = GetFileCreditDisabled(&arre);
		if (ne == 0)
		{
			arre = new Credit[2];
		}
		arre[ne] = arr[z];
		SetFileCreditDisabled(arre, ne + 1);
	}
}
void EndDeposit()
{
	Deposit* arre = NULL;
	int ne = GetFileDepositEnabled(&arre);
	if (ne != 0)
	{
		Deposit* arr = new Deposit[ne];
		int it = 0;
		for (int i = 0; i < ne; i++)
		{
			if (arre[i].idUsr == ID)
			{
				arr[it] = arre[i];
				it++;
			}
		}
		if (it == 0)
		{
			cout << "� ��� ��� ������ ��������\n";
			system("pause");
			return;
		}
		ViewDeposit(arr, it);
		int z = -1;
		cout << "������� ����� ������ ��� �������\n";
		while (z<1 && z>it)
		{
			z = CreateInt();
		}
		z--;
		for (int i = 0; i < ne; i++)
		{
			if (memcmp(arre + i, arr + z, sizeof(Deposit)) == 0)
			{
				for (int j = i; j < ne - 1; j++)
				{
					arre[i] = arre[i + 1];
				}
				ne--;
				SetFileDepositEnabled(arre, ne);
				break;
			}
		}
		delete[] arre;
		ne = GetFileDepositDisabled(&arre);
		if (ne == 0)
		{
			arre = new Deposit[2];
		}
		arre[ne] = arr[z];
		SetFileDepositDisabled(arre, ne + 1);
	}
}
int CreateInt()
{
	int n = -1;
	string str = "a";
	while (!CheckNumbers(str))
	{
		cin >> str;
		if (!CheckNumbers(str))
		{
			cout << "������������ ����\n";
		}
	}
	n = atoi(str.c_str());
	return n;
}
bool CheckDouble(string c)
{
	int flag = 0;
	for (int i = 0; i < c.length(); i++)
	{

		if ((c[i] < '0' && c[i] != '.' && c[i] != ',') || (c[i] > '9' && c[i] != '.' && c[i] != ',') || (flag > 0 && c[i] == '.') || (flag > 0 && c[i] == ','))
		{
			return false;
		}
		else if (c[i] == '.' || c[i] == ',')
		{
			flag++;
		}
	}
	return true;
}
double CreateDouble()
{
	string c = "a";
	while (!CheckDouble(c))
	{
		cin >> c;
		if (!CheckDouble(c))
		{
			cout << "������������ ����\n";
		}
	}
	double a = 0;
	double b = 0;
	int i = 0;
	while (c[i] != '.' && c[i] != ',' && i != c.length())
	{
		char d[2];
		d[0] = c[i];
		d[1] = '\0';
		a *= 10;
		a += atoi(d);
		i++;
	}
	i++;
	if (i < c.length())
	{
		while (c[i] >= '0' && c[i] <= '9' && i != c.length())
		{
			char d[2];
			d[0] = c[i];
			d[1] = '\0';
			b *= 10;
			b += atoi(d);
			i++;
		}
		while (b > 1)
		{
			b = b / 10;
		}
	}

	return (a + b);
}
bool CheckLetters(string str)
{
	char abc[66] = { '�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�', '�','�','�','�','�','�','�','�','�','�','�', '�','�','�','�','�','�','�','�','�','�','�', '�','�','�','�','�','�','�','�','�','�','�', '�','�','�','�','�','�','�','�','�','�','�' };
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < 'a' || str[i] >= 'z')
		{
			if (str[i] < 'A' || str[i] >= 'Z')
			{
				int flag = 0;
				for (int j = 0; j < 66; j++)
				{
					if (str[i] == abc[j])
					{
						flag = 1;
					}
				}
				if (flag == 0)
				{
					return false;
				}
			}
		}
	}
	return true;
}
string CreateString()
{
	string str = "1";
	while (!CheckLetters(str))
	{
		cin >> str;
		if (!CheckLetters(str))
		{
			cout << "������������ ����\n";
		}
	}
	return str;
}
long CreateTelephone()
{
	cout << "������� ����� ��������\n";
	string s = "a";
	while (!CheckNumbers(s))
	{
		cout << "+375";
		cin >> s;
		if (s.length() != 9)
		{
			s = "a";
		}
	}
	return atoi(s.c_str());
}
string Encrypt(string str)
{
	string a = "";
	for (int i = 0; i < str.length(); i++)
	{
		string b = "";
		if (str[i] < 0)
		{
			b = b + (char)(rand() % 26 + 'A');
		}
		else
		{
			b = b + (char)(rand() % 26 + 'a');
		}
		int c = abs((int)str[i]);
		if (c / 128 == 1)
		{
			b = b + (char)(rand() % 26 + 'A');
			c -= 128;
		}
		else
		{
			b = b + (char)(rand() % 26 + 'a');
		}
		if (c / 64 == 1)
		{
			b = b + (char)(rand() % 26 + 'A');
			c -= 64;
		}
		else
		{
			b = b + (char)(rand() % 26 + 'a');
		}
		if (c / 32 == 1)
		{
			b = b + (char)(rand() % 26 + 'A');
			c -= 32;
		}
		else
		{
			b = b + (char)(rand() % 26 + 'a');
		}
		if (c / 16 == 1)
		{
			b = b + (char)(rand() % 26 + 'A');
			c -= 16;
		}
		else
		{
			b = b + (char)(rand() % 26 + 'a');
		}
		if (c / 8 == 1)
		{
			b = b + (char)(rand() % 26 + 'A');
			c -= 8;
		}
		else
		{
			b = b + (char)(rand() % 26 + 'a');
		}
		if (c / 4 == 1)
		{
			b = b + (char)(rand() % 26 + 'A');
			c -= 4;
		}
		else
		{
			b = b + (char)(rand() % 26 + 'a');
		}
		if (c / 2 == 1)
		{
			b = b + (char)(rand() % 26 + 'A');
			c -= 2;
		}
		else
		{
			b = b + (char)(rand() % 26 + 'a');
		}
		if (c == 1)
		{
			b = b + (char)(rand() % 26 + 'A');
			c -= 1;
		}
		else
		{
			b = b + (char)(rand() % 26 + 'a');
		}
		a = a + b;
	}
	return a;
}

string Decrypt(string a)
{
	string b = "";
	int n = a.length() / 9;
	for (int i = 0; i < n; i++)
	{
		char c = 0;
		if (a[i * 9 + 1] >= 'A' && a[i * 9 + 1] <= 'Z')
		{
			c += 128;
		}
		if (a[i * 9 + 2] >= 'A' && a[i * 9 + 2] <= 'Z')
		{
			c += 64;
		}
		if (a[i * 9 + 3] >= 'A' && a[i * 9 + 3] <= 'Z')
		{
			c += 32;
		}
		if (a[i * 9 + 4] >= 'A' && a[i * 9 + 4] <= 'Z')
		{
			c += 16;
		}
		if (a[i * 9 + 5] >= 'A' && a[i * 9 + 5] <= 'Z')
		{
			c += 8;
		}
		if (a[i * 9 + 6] >= 'A' && a[i * 9 + 6] <= 'Z')
		{
			c += 4;
		}
		if (a[i * 9 + 7] >= 'A' && a[i * 9 + 7] <= 'Z')
		{
			c += 2;
		}
		if (a[i * 9 + 8] >= 'A' && a[i * 9 + 8] <= 'Z')
		{
			c += 1;
		}
		if (a[i * 9] >= 'A' && a[i * 9] <= 'Z')
		{
			c *= -1;
		}
		b = b + c;
	}
	return b;
}
void PrintDate(Date a)
{
	if (a.day < 10)
	{
		cout << 0;
	}
	cout << a.day << ".";
	if (a.month < 10)
	{
		cout << 0;
	}
	cout << a.month << "." << a.year;
}
void PrintTime(Time a)
{
	if (a.hour < 10)
	{
		cout << 0;
	}
	cout << a.hour << ".";
	if (a.min < 0)
	{
		cout << 0;
	}
	cout << a.min;
}
void AddUser()
{
	User* arr = NULL;
	int n = GetFileUser(&arr);
	if (n == 0)
	{
		arr = new User[2];
	}
	arr[n].id = CreateId();
	arr[n].fio = CreateFIO();
	cout << "������� �����\n";
	arr[n].adress = CreateAdress();
	arr[n].telephone = CreateTelephone();
	Log* arrl = NULL;
	int nl = GetFileLog(&arrl, "user.txt");
	if (nl == 0)
	{
		arrl = new Log[2];
	}
	bool unic = false;
	cout << "������� �����\n";
	while (!unic)
	{
		unic = true;
		cin >> arrl[n].logIn;
		for (int i = 0; i < n; i++)
		{
			if (arrl[n].logIn == arrl[i].logIn)
			{
				unic = false;
				cout << "����� ����� ��� ����������\n";
				system("pause");
			}
		}
	}
	cout << "������� ������\n";
	cin >> arrl[n].password;
	arrl[n].id = arr[n].id;
	SetFileUser(arr, n + 1);
	delete[] arr;
	SetFileLog(arrl, "user.txt", nl + 1);
	delete[] arrl;
}
void AddAdmin()
{
	Admin* arr = NULL;
	int n = GetFileAdmin(&arr);
	if (n == 0)
	{
		arr = new Admin[2];
	}
	arr[n].id = CreateId();
	arr[n].fio = CreateFIO();
	Log* arrl = NULL;
	int nl = GetFileLog(&arrl, "admin.txt");
	if (nl == 0)
	{
		arrl = new Log[2];
	}
	bool unic = false;
	cout << "������� �����\n";
	while (!unic)
	{
		unic = true;
		cin >> arrl[n].logIn;
		for (int i = 0; i < n; i++)
		{
			if (arrl[n].logIn == arrl[i].logIn)
			{
				unic = false;
				cout << "����� ����� ��� ����������\n";
				system("pause");
			}
		}
	}
	cout << "������� ������\n";
	cin >> arrl[n].password;
	arrl[n].id = arr[n].id;
	SetFileAdmin(arr, n + 1);
	delete[] arr;
	SetFileLog(arrl, "admin.txt", nl + 1);
	delete[] arrl;
}
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	MenuLogIn();
	return 0;
}
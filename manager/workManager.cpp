#pragma once
#include"workManager.h"
#include<iostream>
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME ��ss.txt��
using namespace std;

	WorkManager::WorkManager()
	{
		this->m_num = 0;
		this->m_array = NULL;
		ifstream ifs;
		ifs.open("ss.txt", ios::in);
		if (!ifs.is_open())
		{
			cout << "�ļ�������" << endl;
			this->m_num = 0;
			this->m_Fisempty= true;
			this->m_array = NULL;
			ifs.close();
			return;

		}
		int num = this->get_empnum();
	
		this->m_num = num;
		this->m_array = new Worker * [this->m_num];
		init_emp();
		this->m_Fisempty = false;

	}

	WorkManager::~WorkManager()
	{
		if (this->m_array != NULL)
		{
			delete[] this->m_array;
		}
	}
	void WorkManager::showmenu()
	{
		cout << "********************" << endl;
		cout << "****   WELCOME  ****" << endl;
		cout << "**** 0:�˳�ϵͳ ****" << endl;
		cout << "**** 1:�����Ա ****" << endl;
		cout << "**** 2:��ʾ��Ա ****" << endl;
		cout << "**** 3:ɾ��ְ�� ****" << endl;
		cout << "**** 4:�޸�ְ�� ****" << endl;
		cout << "**** 5:����ְ�� ****" << endl;
		cout << "**** 6:����ְ�� ****" << endl;
		cout << "**** 7:���ְ�� ****" << endl;







	}
	void WorkManager::exitmenu()
	{
		cout << "�����˳�������" << endl;
		system("pause");
		exit(0);
	}

void	WorkManager::Add_P()
	{
	cout << "������Ҫ��ӵ���Ա����" << endl;
	int num = 0;
	cin >> num;
	if (num > 0)
	{
		int newsize = this->m_num + num;
		Worker** newspace = new Worker*[newsize];
		if (this->m_array != NULL)
		{
			for (int i = 0; i < this->m_num; i++)
			{
				newspace[i] = this->m_array[i];
			}
		}
		for (int i=0;i<num;i++)
		{
			int  id;
			string name;
			int select;
			cout << "�������" << i + 1 << "λ��ְ�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "λ��ְ������" << endl;
			cin >> name;
			cout << "������ְ����λ" << endl;
			cout << "1��Ա��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> select;
			Worker * worker = NULL;
			switch (select)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newspace [this->m_num + i] = worker;
		}
		delete[] this->m_array;
		this->m_array = newspace;
		this->m_num = newsize;
		this->m_Fisempty = false;
		cout << "�ѳɹ������" << num << "λ��ְ��" << endl; 

		save();
	}
	else
	{
		cout << "Error" << endl;
	}
	
	system("pause");
	system("cls");
	}
void WorkManager::showemp()
{
	if (this->m_Fisempty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		for (int i = 0; i < m_num; i++)
		{
			this->m_array[i]->showInfo();
			
		}

	}

	system("pause");
	system("cls");
}
int WorkManager::get_empnum()
{
	ifstream ifs;
	ifs.open("ss.txt", ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	ifs.close();
	return num;

}
void WorkManager::init_emp()
{
	ifstream ifs;
	ifs.open("ss.txt", ios::in);
	int id;
	string name;
	int did;

	int a = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;



		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else
		{
			worker = new Boss(id, name, did);
		}

		this->m_array[a] = worker;
		a++;
		

	}
}
/*void WorkManager::showemp()
{
	if (this->m_Fisempty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		for (int i = 0; i < m_num; i++)
		{
			this->m_array[i]->showInfo();
			cout << "ְ�����:" << this->m_array[i]->m_id << endl;
		}

	}

	system("pause");
	system("cls");

}*/
void WorkManager::save()
{
	ofstream ofs;

	ofs.open("ss.txt", ios::out);
	for (int i = 0; i < this->m_num; i++)
	{
		ofs << this->m_array[i]->m_id << "  "
			<< this->m_array[i]->m_name << "  "
			<< this->m_array[i]->m_did << "  " << endl;
	}

	ofs.close();

}
int  WorkManager::isexist(int id)
{

	int b = -1;
	for (int i = 0; i < this->m_num; i++)
	{
		if (this->m_array[i]->m_id == id)
		{
			b = i;
			break;
		}
	}
	return b;
}

void WorkManager::del_emp()
{

	if (this->m_Fisempty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ�����:" << endl;
		int id = 0;
		cin >> id;
		int index = this->isexist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_num; i++)
			{
				this->m_array[i] = this->m_array[i + 1];


			}
			this->m_num--;
			this->save(); 
			cout << "ɾ���ɹ�!!!!" << endl;
		}
		else
		{
			cout << "ɾ��ʧ��!!!!" << endl;
		}
		system("pause");
		system("cls");
	}

}
void WorkManager::modemp()
{
	if (this->m_Fisempty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ�����" << endl;
		int id;
		cin >> id;
		int r = this->isexist(id);
		if (r != -1)
		{

			delete this->m_array[r];
			int newid=0;
			string name="  ";
			int select=0;
			cout << "�������±��" << endl;
			cin >>newid;
			cout << "������������" << endl;
			cin >> name;
			cout << "�������¸�λ" << endl;
			cin >> select;
			Worker  *worker = NULL;
			switch (select)
			{
			case 1:
				worker = new Employee(newid, name, select);
				break;
			case 2:
				worker = new Manager(newid, name, select);
				break;
			case 3:
				worker = new Boss(newid, name, select);
				break;
			default:
				break;
			}
	
			this->m_array[r]= worker;

			cout << "�޸ĳɹ���" << endl;

		
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkManager::find_emp()
{
	if (this->m_Fisempty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;

		int select = 0;
		cin >> select;


		if (select == 1) 
		{
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = isexist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_array[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2) 
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			bool flag = false;  
			for (int i = 0; i <m_num; i++)
			{
				if (m_array[i]->m_name== name)
				{
					cout << "���ҳɹ�,ְ�����Ϊ��"
						<< m_array[i]->m_id
						<< " �ŵ���Ϣ���£�" << endl;

					flag = true;

					this->m_array[i]->showInfo();
				}
			}
			if (flag == false)
			{
		
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "Error" << endl;
		}
	}


	system("pause");
	system("cls");
}

void WorkManager::sort_emp()
{
	if (this->m_Fisempty)
	{
		cout << "�ļ�������" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < m_num; i++)
		{
			int t = i;
			for (int j = i + 1; j < m_num; j++)
			{
				if (select == 1)
				{
					if (m_array[t]->m_id > m_array[j]->m_id)
					{
						t = j;
					}
				}
				else
				{
					if (m_array[t]->m_id < m_array[j]->m_id)
					{
						t = j;
					}
				}
			}

			if (i != t)
			{
				Worker* temp = m_array[i];
				m_array[i] = m_array[t];
				m_array[t] = temp;
			}

		}

		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save();
		this->showemp();
	}

}
void WorkManager::clearfile()
{
	ofstream ofs("ss.txt", ios::trunc);
	ofs.close();

	if (this->m_array != NULL)
	{
		for (int i = 0; i < this->m_num; i++)
		{
			if (this->m_array[i] != NULL)
			{
				delete this->m_array[i];
			}
		}
		this->m_num = 0;
		delete[] this->m_array;
		this->m_array = NULL;
		this->m_Fisempty = true;
	}
	cout << "��ճɹ���" << endl;


}
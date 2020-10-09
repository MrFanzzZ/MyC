#pragma once
#include"workManager.h"
#include<iostream>
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME “ss.txt”
using namespace std;

	WorkManager::WorkManager()
	{
		this->m_num = 0;
		this->m_array = NULL;
		ifstream ifs;
		ifs.open("ss.txt", ios::in);
		if (!ifs.is_open())
		{
			cout << "文件不存在" << endl;
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
		cout << "**** 0:退出系统 ****" << endl;
		cout << "**** 1:添加人员 ****" << endl;
		cout << "**** 2:显示人员 ****" << endl;
		cout << "**** 3:删除职工 ****" << endl;
		cout << "**** 4:修改职工 ****" << endl;
		cout << "**** 5:查找职工 ****" << endl;
		cout << "**** 6:排序职工 ****" << endl;
		cout << "**** 7:清空职工 ****" << endl;







	}
	void WorkManager::exitmenu()
	{
		cout << "正在退出。。。" << endl;
		system("pause");
		exit(0);
	}

void	WorkManager::Add_P()
	{
	cout << "请输入要添加的人员数量" << endl;
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
			cout << "请输入第" << i + 1 << "位新职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "位新职工名字" << endl;
			cin >> name;
			cout << "请输入职工岗位" << endl;
			cout << "1：员工" << endl;
			cout << "2：经理" << endl;
			cout << "3：老板" << endl;
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
		cout << "已成功添加了" << num << "位新职工" << endl; 

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
		cout << "文件不存在" << endl;
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
		cout << "文件不存在" << endl;
	}
	else
	{
		for (int i = 0; i < m_num; i++)
		{
			this->m_array[i]->showInfo();
			cout << "职工编号:" << this->m_array[i]->m_id << endl;
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
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号:" << endl;
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
			cout << "删除成功!!!!" << endl;
		}
		else
		{
			cout << "删除失败!!!!" << endl;
		}
		system("pause");
		system("cls");
	}

}
void WorkManager::modemp()
{
	if (this->m_Fisempty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号" << endl;
		int id;
		cin >> id;
		int r = this->isexist(id);
		if (r != -1)
		{

			delete this->m_array[r];
			int newid=0;
			string name="  ";
			int select=0;
			cout << "请输入新编号" << endl;
			cin >>newid;
			cout << "请输入新姓名" << endl;
			cin >> name;
			cout << "请输入新岗位" << endl;
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

			cout << "修改成功！" << endl;

		
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkManager::find_emp()
{
	if (this->m_Fisempty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;
		cin >> select;


		if (select == 1) 
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = isexist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_array[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2) 
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;  
			for (int i = 0; i <m_num; i++)
			{
				if (m_array[i]->m_name== name)
				{
					cout << "查找成功,职工编号为："
						<< m_array[i]->m_id
						<< " 号的信息如下：" << endl;

					flag = true;

					this->m_array[i]->showInfo();
				}
			}
			if (flag == false)
			{
		
				cout << "查找失败，查无此人" << endl;
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
		cout << "文件不存在" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1：按职工号进行升序" << endl;
		cout << "2：按职工号进行降序" << endl;

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

		cout << "排序成功,排序后结果为：" << endl;
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
	cout << "清空成功！" << endl;


}
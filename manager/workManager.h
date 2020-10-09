
#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
class WorkManager
{
public:
	WorkManager();
	void showmenu();
	void exitmenu();
	~WorkManager();
	int m_num;
	Worker  ** m_array;
	void Add_P();
	void save();
	bool m_Fisempty;
	void showemp();
	int get_empnum();
	void init_emp();
	void del_emp();
	int isexist(int id);
	void modemp();
	void find_emp();
	void sort_emp();
	
	void clearfile();

};

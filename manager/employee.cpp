#pragma once
#include"employee.h"
#include<iostream>
#include<string>
Employee::Employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;



}
void Employee::showInfo()
{
	cout << "职工编号:" << this->m_id << "   "
	 << "职工姓名:" << this->m_name << "   "
	<< "职工部门编号:" << this->m_did << "   "
	<< "部门职责:  完成经理下发的人物" << endl;


}

string Employee::getDeptname()
{
	return  string("员工");

}


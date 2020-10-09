#pragma once
#include"manager.h"
#include<iostream>
#include<string>
Manager::Manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;



}
void Manager::showInfo()
{
	cout << "经理编号:" << this->m_id << "   "
	 << "经理姓名:" << this->m_name << "   "
	<< "经理部门编号:" << this->m_did << "   "
	<< "经理职责:  接收老板下发的人物并下发给员工" << endl;


}  
string Manager::getDeptname()
{
	return  string("经理");

}


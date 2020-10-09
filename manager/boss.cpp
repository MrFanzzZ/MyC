#pragma once
#include"boss.h"
#include<iostream>
#include<string>
Boss::Boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;



}
void Boss::showInfo()
{
	cout << "老板编号:" << this->m_id <<"   "
	 << "老板姓名:" << this->m_name << "   "
	 << "老板部门编号:" << this->m_did << "   "
	 << "老板职责:  管理公司所有事务" << endl;


}
string Boss::getDeptname()
{
	return  string("老板");
}

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
	cout << "ְ�����:" << this->m_id << "   "
	 << "ְ������:" << this->m_name << "   "
	<< "ְ�����ű��:" << this->m_did << "   "
	<< "����ְ��:  ��ɾ����·�������" << endl;


}

string Employee::getDeptname()
{
	return  string("Ա��");

}


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
	cout << "������:" << this->m_id << "   "
	 << "��������:" << this->m_name << "   "
	<< "�����ű��:" << this->m_did << "   "
	<< "����ְ��:  �����ϰ��·������ﲢ�·���Ա��" << endl;


}  
string Manager::getDeptname()
{
	return  string("����");

}


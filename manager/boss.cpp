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
	cout << "�ϰ���:" << this->m_id <<"   "
	 << "�ϰ�����:" << this->m_name << "   "
	 << "�ϰ岿�ű��:" << this->m_did << "   "
	 << "�ϰ�ְ��:  ����˾��������" << endl;


}
string Boss::getDeptname()
{
	return  string("�ϰ�");

}


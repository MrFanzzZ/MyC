
#pragma once
#include"worker.h"
#include<iostream>
#include<string>
using namespace std;
class Manager :public Worker
{
public:
	Manager(int id, string name, int did);
	virtual void showInfo();
	virtual string getDeptname();



};
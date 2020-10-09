

#pragma once
#include<iostream>
#include"workManager.h"
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
/*void test()
{
	Worker* work = NULL;
	work = new Employee(1, "员工", 1);
	work->showInfo();
	delete work;
	work = new Manager(2, "经理", 2);
	work->showInfo();
	delete work;
	work = new Boss(3, "老板", 3);
	work->showInfo();
	delete work;




}*/
int main()
{ 

	int choice = 0;
	WorkManager wm;
	void test();
	while (true)
	{
		wm.showmenu();
		cout << "请输入你的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出系统
			wm.exitmenu();
			break;
		case 1:
			wm.Add_P();
            break;
		case 2:
			wm.showemp();
			break;
		case 3:
			wm.del_emp();
		
			break;
		case 4:
			wm.modemp();
			
			break;
		case 5:
			wm.find_emp();
			break;
		case 6:
			wm.sort_emp();
			break;
		case 7:
			wm.clearfile();
			break;

		default:
			system("cls");

			break;
		}



	}

	system("pause");
	return 0;
}



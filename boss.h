#pragma once
#include<iostream>
#include"worker.h"
#include<string>
using namespace std;

class Boss :public Worker {
	public:
	//��Employeeһ��������Ҳϣ���ڴ��������ʱ��ֱ��ʵ����
	Boss(int id, string name, int deptId);

	// ��д�����еĺ���
	void showInfo();

	string getDeptName();

};
#pragma once
#include"worker.h"
#include<iostream>
#include<string>
//���������࣬�̳�Worker���е����ԣ�����д����
class Manger :public Worker {
public:
	//��Employeeһ��������Ҳϣ���ڴ��������ʱ��ֱ��ʵ����
	Manger(int id, string name, int deptId);

	// ��дWorker�еķ���

	void showInfo();

	string getDeptName();



};



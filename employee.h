
#pragma once
#include"worker.h"
#include<iostream>
#include<string>

// ��ͨԱ���࣬�̳�worker���
class Employee :public Worker {
public:
	// ���캯��������ϣ���ڴ���Ա��������ʱ��ֱ�Ӿͳ�ʼ��Ա������Ϣ
	// ����ڹ��캯���������Ҫ����ְ����š�ְ��������ְ�������������
	// ��д���´����ʱ��ǧ�򲻿��Լ�{}����������Ǻ�����ʵ�֣���cpp�ļ����ڴ�ʵ�ֻᱨ��
	Employee(int id, string name, int deptId);
	// ��д�����еķ���
	void showInfo();
	string getDeptName();



};

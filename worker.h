#pragma once
#include<iostream>
using namespace std;
#include<string>
// �����ͷ�ļ��������Ҫ����һ��ְ���Ļ��ࡣ
// ��˾��ְ����Ϊ���ࣺ��ͨԱ���������ϰ壬��ʾ��Ϣʱ����Ҫ��ʾְ����š�ְ��������ְ����λ.
// ��������ж����������ԣ���ţ����������ڲ������Ʊ��.
// ����������Ϊ����λְ����Ϣ��������ȡ��λ����
class Worker {

public:

	// ����������Ϊ,����Ϊ���麯��������������д
	// ��ʾ������Ϣ
	virtual void showInfo() = 0;
	// ��ʾ��������
	virtual string getDeptName() = 0;

	int m_Id;		  // ְ�����
	string m_Name;	  // ְ������
	int m_DeptId;	  // ���ű��

};

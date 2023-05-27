#pragma once	// ��ֹͷ�ļ��ظ�����
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manger.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager {
public:
	 WorkerManager();

	 // ��ӳ�Ա������չʾ�˵�
	 void Show_Menu();

	 // �˳�ϵͳ
	 void Exit_System();

	 // �����Ա����
	 void addEmp();

	 // ������Ա���ļ��к���
	 void save();

	 // ͳ���ļ��е�����
	 int get_EmpNUM();

	 // ��ʼ��Ա��
	 void init_Emp();

	 int m_EmpNum;	// ��¼�ļ��е���Ա����
	 /*
	 ָ��Ͷ���Ĺ�ϵ������һ���򵥵ı�������⣺
	 ָ�������һ��ң�����������Կ���һ������Ҳ���ǵ��ӻ���
	 �������Լ������Ժͷ�����������ӻ���Ʒ�ơ��ͺš���ɫ�����ԣ����п��ء���̨���������ȷ�����
	 ָ�����ͨ��ң�����ϵİ�ť�����ʻ��޸Ķ�������Ժͷ��������簴���ذ�ť���Դ򿪻�رյ��ӻ�������̨��ť�����л����ӻ���Ƶ������������ť��������
	 ָ��Ҳ���Լ��ĵ�ַ������ң��������һ����ţ������������ֲ�ͬ��ң������
	 ָ��ĵ�ַ���Դ洢����һ��ָ���У�����һ��ң�������Կ�����һ��ң�����������˫ָ��ĸ��
	 ˫ָ���������������̬�����飬����һ��ң�������Կ���һ����ӻ���
	 */

	 // ��ʾְ��
	 void Show_Emp();

	 // ɾ��ְ��
	 void Del_Emp();

	 // �ж�ְ���Ƿ����
	 int IsExist(int id);

	 // �޸�ְ������Ϣ
	 void Mod_Emp();

	 // ����ְ������Ϣ
	 void Find_Emp();

	 bool Find_mark;//����������ѭ��
	 // ����Ų���
	 void FindbyId();
	// �����ֲ���
	 void FindbyName();

	 // ���ձ�Ž�������
	 void Sort_Emp();

	 // ����ļ�����
	 void Clean_File();

	 // Worker** m_EmpArray��һ��˫ָ��
	 // ��ָ��һ��Worker���͵�ָ�����飬���������Դ洢���Worker���͵�ָ�룬ÿ��ָ����ָ��һ��Worker��Ķ���
	 // �������Ԫ����Worker*���͵�ָ�룬Ҳ����ָ��Worker������ָ�롣ÿ��Ԫ�ض������������ʻ��޸�Worker���������Ժͷ�����
	 Worker** m_EmpArray;	// ָ��Ա�������ָ�롣
	
	 // ��־�ļ��Ƿ�Ϊ��(�����ں��ڵĶ��ļ�);
	 bool m_FileIsEmpty;

	 ~WorkerManager();

};
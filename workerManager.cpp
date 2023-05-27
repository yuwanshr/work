#include"workerManager.h"

// ���ڶ��壬����������
WorkerManager::WorkerManager() {
	// �ж��ļ��Ƿ����
	this->Find_mark = true;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//�ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl; //�������
		this->m_EmpNum = 0;  //��ʼ������
		this->m_FileIsEmpty = true; //��ʼ���ļ�Ϊ�ձ�־
		this->m_EmpArray = NULL; //��ʼ������
		ifs.close(); //�ر��ļ�
		return;
	}

	// �ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		// �ļ�Ϊ��
		cout << "�ļ�Ϊ��!" << endl;
		this->m_EmpNum = 0;  //��ʼ������
		this->m_FileIsEmpty = true; //��ʼ���ļ�Ϊ�ձ�־
		this->m_EmpArray = NULL; //��ʼ������
		ifs.close(); //�ر��ļ�
		return;
	}

	// �ļ����ڲ������ݲ�Ϊ��
	this->m_FileIsEmpty = false;
	int num = this->get_EmpNUM();
	cout << "ְ��������Ϊ��" << num << endl;
	//this->init_Emp();
	this->m_EmpNum = num;
	
	// ���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// ���ļ��е����ݣ��浽������
	this->init_Emp();

	// ��������
	//for (int i = 0; i < this->m_EmpNum; i++) {
	//	cout << "Ա�����Ϊ��" << this->m_EmpArray[i]->m_Id
	//		<< "����Ϊ��" << this->m_EmpArray[i]->m_Name
	//		<< "���ű��Ϊ��" << this->m_EmpArray[i]->m_DeptId << endl;
	//}

	
}

// ʵ��Show_Menu�������ܣ�չʾҳ��
void WorkerManager::Show_Menu() {
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

// ʵ��Exit_System��������,�˳�����
void WorkerManager::Exit_System() {
	cout << "��ӭ���´�����ʹ��" << endl;
	system("pause");
	// �˳����ܵ�ʵ��.
	exit(0);
}

// ʵ��add_Emp�������ܣ�����ְ��
void WorkerManager::addEmp() {
	cout << "��������Ҫ��ӵ�Ա��������" << endl;
	// ������¼������������
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		// �����µ���Ա�ռ����
		int newSize = this->m_EmpNum + addNum;
		// ���µ���Ա�������ٵ��µĿռ���
		Worker** newSpace = new Worker * [newSize*sizeof(Worker)];
		// ���ԭ�����������ˣ�������Ҫ������ֵ���¿ռ���
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// �������������
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect; //�����û�ѡ��ְλ��
			cout << "���������" << i + 1 << "����ְ�����" << endl;
			cin >> id;
			cout << "�������������ְ��������" << endl;
			cin >> name;

			bool flag = false;
			while (!flag)
			{
				cout << "��ѡ���ְ���ĸ�λ��" << endl;
				cout << "1����ְͨ��" << endl;
				cout << "2������" << endl;
				cout << "3���ϰ�" << endl;
				cin >> dSelect;
				if (dSelect == 1 || dSelect == 2 || dSelect == 3) {
					flag = true;
				}
				else {
					cout << "��������������������" << endl;
				}
			}


			// ����Worker���͵�ָ��
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:	// ��ͨԱ��
				worker = new Employee(id, name, 1);
				break;
			case 2: // ����
				worker = new Manger(id, name, 2);
				break;
			case 3: // �ܲ�.
				worker = new Boss(id, name, 2);
				break;
			default:
				break;
			}

			// ��������ְ��ָ�뱣�浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		// �ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		// �����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		// ����ְ������
		this->m_EmpNum = newSize;

		// ����ְ����Ϊ��
		this->m_FileIsEmpty = false;

		// �����ݱ��浽�ļ���
		this->save();
		cout << "��ӳɹ���" << endl;
		// �������ݵ��ļ�Ŀ¼��
		
	}
	else {
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

// ʵ��save�������ܣ���������
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " " << this->m_EmpArray[i]->m_Name << " " << this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

// ʵ��get_EmpNUM()�������ܣ�ͳ������
int WorkerManager::get_EmpNUM() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//��¼����
		num++;
	}
	ifs.close();

	return num;
}
	/*
	getline��һ��C++��׼�⺯���������ڴ��������ж�ȡһ���ı���
	���ĵ�һ��������һ�����������󣬵ڶ���������һ���ַ����������ڴ洢��ȡ�����ı���
	�������ʾ�������У�getline(ifs, line)���file�������ж�ȡһ���ı���������洢��line�ַ����С�
	�����ȡ�ɹ���getline�����᷵��true�����򷵻�false��
	while (getline(file, line))��һ�д������˼�ǣ�
	���ܹ���file�������ж�ȡ��һ���ı�ʱ����ִ��ѭ�����ڵ���䡣���޷��ٴ��������ж�ȡ���ı�ʱ��ѭ��������
	*/

// ʵ��int init_Emp()����,���ļ��е����ݼ�¼��������
void WorkerManager::init_Emp() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (dId == 1)  // 1��ͨԱ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) //2����
		{
			worker = new Manger(id, name, dId);
		}
		else //�ܲ�
		{
			worker = new Boss(id, name, dId);
		}
		//�����������
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();

}

// ʵ�� void Show_Emp()��������ʾְ����Ա��Ϣ
void WorkerManager::Show_Emp() {

	// �ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty) {
		cout << "ְ����Ա��ϢΪ�գ�" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			//���ö�̬�����ó���Ľӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");

}

// ʵ��int IsExist(int id)���ж�ְ���Ƿ����
int WorkerManager::IsExist(int id) {
	// ���ҵ��򷵻ظ�ְ���������е�λ���������ڷ���-1
	int indiex = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			indiex = i;
			break;
		}
	}
	return indiex;
}

// ʵ��void Del_Emp()������ɾ��ְ����Ϣ��
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "��ǰû��Ա����Ϣ��" << endl;
	}
	else {
		cout << "��������Ҫɾ����Ա�����:" << endl;
		int id = 0;
		cin >> id;
		int flag = IsExist(id);
		if (flag != -1) {
			for (int i = flag; i < this->m_EmpNum - 1; i++) {
				// ����
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			// �����ļ��е�����
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else {
			cout << "���޴˱�ţ�" << endl;
		}
		
	}
	system("pause");
	system("cls");



}

// ʵ��void Mod_Emp()�������޸�ְ����Ϣ
void WorkerManager::Mod_Emp() {
	// �ж��ļ��Ƿ����
	if (this->m_FileIsEmpty) {
		cout << "��ǰû��Ա����Ϣ��" << endl;
	}
	else {
		// ���û�����id���ж�id�Ƿ����
		cout << "��������Ҫ�޸�Ա���ı�ţ�" << endl;
		int id;
		cin >> id;
		int Mod_flag = IsExist(id);
		if (Mod_flag != -1) {

			// ��������ɾ����Ա������Ϣ
			delete this->m_EmpArray[Mod_flag];

			// ���û��޸ĸ�Ա������Ϣ
			int newId;
			string newName;
			int newDeptid;

			cout << "�ɹ��鵽" << id << "��Ա�������������±��" << endl;
			cin >> newId;
			cout << "������������" << endl;
			cin >> newName;

			bool mark = true;
			while (mark)
			{
				cout << "��ѡ���ְ���ĸ�λ��" << endl;
				cout << "1����ְͨ��" << endl;
				cout << "2������" << endl;
				cout << "3���ϰ�" << endl;
				cin >> newDeptid;
				if (newDeptid == 1 || newDeptid == 2 || newDeptid == 3) {
					mark = false;
				}
				else {
					cout << "���������������������룡" << endl;
				}
			}
			Worker* work = NULL;
			switch (newDeptid)
			{
			case 1:
				work = new Employee(newId, newName, newDeptid);
				break;
			case 2:
				work = new Manger(newId, newName, newDeptid);
				break;
			case 3:
				work = new Boss(newId, newName, newDeptid);
				break;
			default:
				break;
			}

			// ���������е�����
			this->m_EmpArray[Mod_flag] = work;
			cout << "�޸ĳɹ���" << endl;
			// �����ļ��е�����
			this->save();

		}
		else {
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}

	}
	system("pause");
	system("cls");
}

// ʵ��void Find_Emp()����������ְ����Ϣ��
void WorkerManager::Find_Emp() {
	// �ж���Ա��Ϣ�Ƿ�Ϊ��
	if (this->m_FileIsEmpty) {
		cout << "��ǰû��Ա����Ϣ��" << endl;
	}
	else {
		int select = 0;
		
		while (true)
		{
			cout << "��������Ҫ���ҵķ�ʽ��" << endl;
			cout << "1������Ա����Ų���" << endl;
			cout << "2������Ա����������" << endl;
			cout << "0���˳�����" << endl;
			cin >> select;
			switch (select)
			{
			case 1:
				FindbyId();
				return;
				break;
			case 2:
				FindbyName();
				return;
				break;
			case 0:
				cout << "�˳��ɹ�" << endl;
				//this->Find_mark = false;
				system("pause");
				system("cls");
				return;
				break;
			default:
				cout << "������������������" << endl;
				break;
			}
		}
	}
	system("pause");
	system("cls");
}

// ���ձ�Ų���
void WorkerManager::FindbyId() {
	cout << "��������Ҫ���ҵ�Ա����ţ�" << endl;
	int id;
	cin >> id;
	int ret = IsExist(id);
	if (ret != -1) {
		cout << "�ɹ��ҵ�����Ա��Ϣ��" << endl;
		this->m_EmpArray[ret]->showInfo();
		//this->Find_mark = false;
	}
	else {
		cout << "���޴���" << endl;
		//this->Find_mark = false;
	}
	system("pause");
	system("cls");
}

// �������ֲ���
void WorkerManager::FindbyName() {
	string name;
	cout << "��������Ҫ���ҵ�Ա��������" << endl;
	cin >> name;
	bool flag = false;  //���ҵ��ı�־
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Name == name) {
			cout << "�Ѿ��ɹ��ҵ��������ϢΪ��" << this->m_EmpArray[i]->m_Id << "����Ϣ���£�" << endl;
			flag = true;
			this->m_EmpArray[i]->showInfo();
		}
	}
	if (!flag) {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

// ʵ�� void Sort_Emp()������Ա����Ϣ����
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������ѡ������ķ�ʽ��" << endl;
		cout << "1����������" << endl;
		cout << "2����������" << endl;
		cout << "0���˳�����" << endl;
		int select;
		bool flag = true;
		while (flag)
		{
			cout << "����������ѡ��" << endl;
			cin >> select;
			switch (select)
			{
			case 1:
				for (int i = 0; i < m_EmpNum; i++)
				{
					int minOrMax = i;
					for (int j = i + 1; j < m_EmpNum; j++)
					{
						if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
						{
							minOrMax = j;
						}
					}
					if (i != minOrMax)
					{
						Worker* temp = m_EmpArray[i];
						m_EmpArray[i] = m_EmpArray[minOrMax];
						m_EmpArray[minOrMax] = temp;
					}
				}
				cout << "����ɹ�,�������Ϊ��" << endl;
				this->save();
				this->Show_Emp();
				flag = false;
				break;
			case 2:
				for (int i = 0; i < m_EmpNum; i++)
				{
					int minOrMax = i;
					for (int j = i + 1; j < m_EmpNum; j++)
					{
						if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
						{
							minOrMax = j;
						}
					}
					if (i != minOrMax)
					{
						Worker* temp = m_EmpArray[i];
						m_EmpArray[i] = m_EmpArray[minOrMax];
						m_EmpArray[minOrMax] = temp;
					}
				}
				cout << "����ɹ�,�������Ϊ��" << endl;
				this->save();
				this->Show_Emp();
				flag = false;
				break;
			case 0:
				cout << "�˳��ɹ�" << endl;
				flag = false;
				break;
			default:
				break;
			}
		}
	}
}

// ʵ��void Clean_File()����������ļ�
void WorkerManager::Clean_File() {
	cout << "����������ѡ��" << endl;
	cout << "1�����" << endl;
	cout << "2������" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		// ��ģʽios::trunc ��������ļ���ɾ���������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		// ɾ��ά���û���Ϣ��ָ��
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			delete this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "����ɹ�" << endl;
	}
	system("pause");
	system("cls");
	
}


// ��������
WorkerManager::~WorkerManager() {

	// �ͷſ��ŵ�����������
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
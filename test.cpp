#include<iostream>
using namespace std;
void exit() {
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
}
int main() {

	int choice = 0;
	while (true)
	{
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			exit();
			break;
		case 1:
			cout << "�������Ϊ1" << endl;
			break;
		case 2:
			cout << "�������Ϊ2" << endl;
			break;
		case 3:
			cout << "�������Ϊ3" << endl;
			break;
		default:
			break;
		}
	}

	cin.get();



}
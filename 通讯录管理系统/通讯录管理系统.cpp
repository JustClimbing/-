/*ͨѶ¼����ϵͳ
1��ϵͳ����ͨѶ¼��һ�����Լ�¼���ˡ�������Ϣ�Ĺ��ߡ�
���̳���Ҫ����C++��ʵ��һ��ͨѶ¼����ϵͳϵͳ����Ҫʵ�ֵĹ������£�
�������ϵ�ˣ���ͨѶ¼��������ˣ���Ϣ�������������Ա����䡢��ϵ�绰����ͥסַ������¼1000��
����ʾ��ϵ�ˣ���ʾͨѶ¼��������ϵ����Ϣ
��ɾ����ϵ�ˣ�������������ɾ��ָ����ϵ��
��������ϵ�ˣ����������鿴ָ����ϵ����Ϣ
���޸���ϵ�ˣ��������������޸�ָ����ϵ��
�������ϵ�ˣ����ͨѶ¼��������Ϣ
���˳�ͨѶ¼���˳���ǰʹ�õ�ͨѶ¼*/
#include <iostream>
using namespace std;
#include <string>
#define MAX 1000 //����ά��

//�����ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//����
	int m_Age;
	//�Ա� ��1 Ů2
	int m_Sex;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{
	Person pesrsonArray[MAX];//ͨѶ¼�б������ϵ������
	int m_Size;//ͨѶ¼����Ա����

};
//�˵�����
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

//�����ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ���
	if (abs->m_Size >= MAX)
	{
		cout << "ͨѶ¼������" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "��������ϵ��������" << endl;
		cin >> name;
		abs->pesrsonArray[abs->m_Size].m_Name = name;
		//����
		int age;
		cout << "��������ϵ�����䣺" << endl;
		
		while (true)//�ж������Ƿ����Ҫ��
		{
			cin >> age;
			if (age > 0&&age<100)
			{
				abs->pesrsonArray[abs->m_Size].m_Age = age;
				break;
			}
			if (age >= 100)
			{
				abs->pesrsonArray[abs->m_Size].m_Age = age;
				cout << "����������ҳ����ؾ���" << endl;
				break;
			}
			cout << "�����̥�ﰡ���ϵܣ�" << endl;
			cout << "��������ȷ���䣺" << endl;
		}
		//�Ա�
		int sex;
		cout << "��������ϵ���Ա�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->pesrsonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������ֻ�������Ա��ϵ�" << endl;
			cout << "��������ȷ�Ա�" << endl;
		}
		//�绰
		string phone;
		cout << "��������ϵ�˵绰��" << endl;
		cin >> phone;
		abs->pesrsonArray[abs->m_Size].m_Phone = phone;

		//��ַ
		string address;
		cout << "��������ϵ�˵�ַ��" << endl;
		cin >> address;
		abs->pesrsonArray[abs->m_Size].m_Addr = address;

		//��ӳɹ�
		cout << "��ӳɹ�" << endl;
		
		abs->m_Size++;
		system("pause");
		system("cls");

	}
}

//��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "����ͨѶ¼����ϵ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������"<<abs->pesrsonArray[i].m_Name << "\t";//�������
			cout << "���䣺"<<abs->pesrsonArray[i].m_Age << "\t";//�������
			//����Ա�
			/*if (abs->pesrsonArray[i].m_Sex == 1)
			{
				cout << "�Ա���" << "\t";
			}
			else {
				cout << "�Ա�Ů" << "\t";
			}*/
			cout << "�Ա�" << (abs->pesrsonArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "�绰��" << abs->pesrsonArray[i].m_Phone << "\t";//����绰
			cout << "��ַ��" << abs->pesrsonArray[i].m_Addr << endl;//���סַ
		}
	}
	system("pause");
	system("cls");
}


//�����ϵ���Ƿ����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->pesrsonArray[i].m_Name == name)
		{
			return i;
		}
	}return -1;
}

//ɾ����ϵ�˹���
//�ҵ���ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "����������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) == -1)
	{
		cout << "���޴���"<<endl;
	}
	else
	{
		for (int i = isExist(abs, name); i < abs->m_Size; i++)
		{
			abs->pesrsonArray[i] = abs->pesrsonArray[i + 1];
		}
		abs->m_Size--;
		cout << "�ɹ�ɾ�����ɰ�2�鿴" << endl;
	}
	system("pause");
	system("cls");


}

//������ϵ�˹���
// �жϣ��Ҳ���������޴��ˣ��ҵ�����ʾ��ϵ��
void findPerson(Addressbooks* abs)
{
	//������Ҫ���ҵ�����
	string name;
	cout << "����������Ҫ���ҵ���ϵ�˵����֣�"<<endl;
	cin >> name;
	if (isExist(abs, name) == -1)
	{
		cout << "���޴���" << endl;
	}
	else {
		cout << "������" << abs->pesrsonArray[isExist(abs, name)].m_Name << "\t";//�������
		cout << "���䣺" << abs->pesrsonArray[isExist(abs, name)].m_Age << "\t";//�������
		cout << "�Ա�" << (abs->pesrsonArray[isExist(abs, name)].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "�绰��" << abs->pesrsonArray[isExist(abs, name)].m_Phone << "\t";//����绰
		cout << "��ַ��" << abs->pesrsonArray[isExist(abs, name)].m_Addr << endl;//���סַ
	}
	system("pause");
	system("cls");

}
//�޸���ϵ�˹���
void modifyPerson(Addressbooks* abs)
{
	cout << "����ѡ������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		//����
		string Name;
		cout << "���޸���ϵ��������" << endl;
		cin >> Name;
		abs->pesrsonArray[ret].m_Name = Name;
		//����
		int age;
		cout << "���޸���ϵ�����䣺" << endl;

		while (true)//�ж������Ƿ����Ҫ��
		{
			cin >> age;
			if (age > 0 && age < 100)
			{
				abs->pesrsonArray[ret].m_Age = age;
				break;
			}
			if (age >= 100)
			{
				abs->pesrsonArray[ret].m_Age = age;
				cout << "����������ҳ����ؾ���" << endl;
				break;
			}
			cout << "�����̥�ﰡ���ϵܣ�" << endl;
			cout << "��������ȷ���䣺" << endl;
		}
		//�Ա�
		int sex;
		cout << "���޸���ϵ���Ա�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->pesrsonArray[ret].m_Sex = sex;
				break;
			}
			cout << "������ֻ�������Ա��ϵ�" << endl;
			cout << "��������ȷ�Ա�" << endl;
		}
		//�绰
		string phone;
		cout << "���޸���ϵ�˵绰��" << endl;
		cin >> phone;
		abs->pesrsonArray[ret].m_Phone = phone;

		//��ַ
		string address;
		cout << "���޸���ϵ�˵�ַ��" << endl;
		cin >> address;
		abs->pesrsonArray[ret].m_Addr = address;
		cout << "�޸ĳɹ�" << endl;
	}
	system("pause");
	system("cls");

}
//���ͨѶ¼
void clean(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "�����" << endl;
	system("pause");
	system("cls");
}

int main()
{
	

	int select = 0;
	//����ͨѶ¼�ṹ
	Addressbooks abs;
	//��ʼ������
	abs.m_Size = 0;
	
	//ѡ����
	while (true)//ʹ��ֻ�а�0ʱ�����˳�
	{
		showMenu(); //���ò˵�
		cin >> select;
		switch (select)
		{
		case 1:// 1�������ϵ�� 
			addPerson(&abs);
			break;
		case 2:// 2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:// 3��ɾ����ϵ�� 
			deletePerson(&abs);
			break;
		case 4:// 4��������ϵ�� 
			findPerson(&abs);
			break;
		case 5:// 5���޸���ϵ�� 
			modifyPerson(&abs);
			break;
		case 6:// 6�������ϵ��
			clean(&abs);
			break;
		case 0://�˳�����
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	

	system("pause"); //������������������ó���һ������
		return 0;
}

#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;


// ��ǰ ���� 


class product
{
private:
	char* productName;
	int productPrice;

public:
	product(char* name, int price) : productPrice(price)
	{
		productName = new char[strlen(name) + 1];
		strcpy(productName, name);
	}
	~product()
	{
		delete[] productName;
	}

	void viewProduct() const
	{
		cout << "��ǰ : " << productName << endl;
		cout << "�ݾ� : " << productPrice << endl << endl;
	}
	
	void changeProduct(char* name, int price)
	{
		if (name != NULL)
			delete[] productName;

		productName = new char[strlen(name) + 1];
		strcpy(productName, name);

		productPrice = price;
	}

	char* get_name() const
	{
		return productName;
	}

};

class productContainer
{
private:
	const int maxProductNum;
	product** productArr;
	int topindex;

public:
	productContainer(int max) : maxProductNum(max)
	{
		productArr = new product * [maxProductNum];
		topindex = 0;
	}
	~productContainer()
	{
		for (int i=0; i<topindex ; i++)
			delete productArr[i];
		delete[] productArr;
	}

	void addProduct()
	{
		int price;
		char buffer[100];

		cout << "��ǰ�� : ";
		cin >> buffer;
		cout << "��ǰ�� : ";
		cin >> price;
			
		productArr[topindex] = new product(buffer, price);
		topindex++;
		cout << "��ǰ �Է� �Ϸ�" << endl;
		cout << maxProductNum - topindex << "���� �߰� ��ǰ �Է��� �����մϴ�." << endl;
	}

	// ���� ��ǰ ����Ʈ���� �̸����� �˻���.
	void modProduct()
	{
		char buffer[100];
		int price;
		int idx = 0;
		cout << "������ ����� ��ǰ���� �Է����ּ��� : ";
		cin >> buffer;

		for (idx = 0; idx < topindex; idx++)
		{
			if (strcmp(buffer, productArr[idx]->get_name()) == 0)
				break;
			if (idx == topindex - 1)
			{
				idx = -1;
				break;
			}
		}
		if (idx == -1)
		{
			cout << "�����Ͱ� �������� �ʽ��ϴ�" << endl;
			return;
		}

		productArr[idx]->viewProduct();
		cout << "������ ��ǰ�� : ";
		cin >> buffer;
		cout << "������ ��ǰ�� : ";
		cin >> price;
		productArr[idx]->changeProduct(buffer, price);
		cout << "����Ǿ����ϴ�." << endl;
		productArr[idx]->viewProduct();
	}

	void printProduct()
	{
		for (int i = 0; i < topindex; i++)
		{
			cout << '[' << i << "] ��° ��ǰ ����" << endl;
			productArr[i]->viewProduct();
		}
	}

	void printProduct(int indx)
	{
		if (indx >= topindex)
		{
			cout << "��ǰ ��ȣ �����Դϴ�" << endl;
			return;
		}

		cout << '[' << indx << "] ��° ��ǰ ����" << endl;
		productArr[indx]->viewProduct();
	}

};

int printMenu()
{
	int choice;
	cout << "***** ��ǰ �߰� / ���� / ��� * ****" << endl;
	cout << "�޴� �Է�" << endl;
	cout << "1)��ǰ�߰�" << endl;
	cout << "2)��ǰ����" << endl;
	cout << "3)�������" << endl;
	cout << "4)��ǰ���" << endl;
	cout << "5)����" << endl;
	cout << ">>";
	cin >> choice;
	return choice;
}

enum CHOICE
{
	ADD=1,
	MODI,
	PRINT_ALL,
	PRINT,
	EXIT
};


int main(void)
{
	int choice = 0;
	int temp;
	productContainer pc(3);

	

	while (choice != 5)
	{
		choice = printMenu();
		
		switch (choice)
		{
		case ADD:
			pc.addProduct();
			break;
		case MODI:
			pc.modProduct();
			break;
		case PRINT_ALL:
			pc.printProduct();
			break;
		case PRINT :
			cout << "��� ��ǰ ��ȣ :";
			cin >> temp;
			pc.printProduct(temp);
			break;
		case EXIT:
			cout << "���α׷��� �����մϴ�" << endl;
			break;

		default:
			break;
		}
		cout << endl;
	}



	return 0;
}
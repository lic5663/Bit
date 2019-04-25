#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;


// 상품 매장 


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
		cout << "상품 : " << productName << endl;
		cout << "금액 : " << productPrice << endl << endl;
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

		cout << "상품명 : ";
		cin >> buffer;
		cout << "상품가 : ";
		cin >> price;
			
		productArr[topindex] = new product(buffer, price);
		topindex++;
		cout << "상품 입력 완료" << endl;
		cout << maxProductNum - topindex << "개의 추가 상품 입력이 가능합니다." << endl;
	}

	// 기존 상품 리스트에서 이름으로 검색함.
	void modProduct()
	{
		char buffer[100];
		int price;
		int idx = 0;
		cout << "수정할 대상의 상품명을 입력해주세요 : ";
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
			cout << "데이터가 존재하지 않습니다" << endl;
			return;
		}

		productArr[idx]->viewProduct();
		cout << "변경할 상품명 : ";
		cin >> buffer;
		cout << "변경할 상품가 : ";
		cin >> price;
		productArr[idx]->changeProduct(buffer, price);
		cout << "변경되었습니다." << endl;
		productArr[idx]->viewProduct();
	}

	void printProduct()
	{
		for (int i = 0; i < topindex; i++)
		{
			cout << '[' << i << "] 번째 상품 정보" << endl;
			productArr[i]->viewProduct();
		}
	}

	void printProduct(int indx)
	{
		if (indx >= topindex)
		{
			cout << "상품 번호 오류입니다" << endl;
			return;
		}

		cout << '[' << indx << "] 번째 상품 정보" << endl;
		productArr[indx]->viewProduct();
	}

};

int printMenu()
{
	int choice;
	cout << "***** 상품 추가 / 수정 / 출력 * ****" << endl;
	cout << "메뉴 입력" << endl;
	cout << "1)상품추가" << endl;
	cout << "2)상품수정" << endl;
	cout << "3)종합출력" << endl;
	cout << "4)상품출력" << endl;
	cout << "5)종료" << endl;
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
			cout << "출력 상품 번호 :";
			cin >> temp;
			pc.printProduct(temp);
			break;
		case EXIT:
			cout << "프로그램을 종료합니다" << endl;
			break;

		default:
			break;
		}
		cout << endl;
	}



	return 0;
}
#include "complex.h"

int main(void)
{
	Complex c1, c2;			//����c1��c2������������
	cin >> c1 >> c2;		//�ֱ�����c1��c2��ʵ�����鲿
	Complex sum = c1 + c2;
	cout << sum << endl;
	Complex div = c1 / c2;
	cout << div << endl;
	if (c1 > c2)
		cout << "max:" << c1 << endl;
	else
		cout << "max:" << c2 << endl;
	system("pause");
	return 0;
}

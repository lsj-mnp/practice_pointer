#include <iostream>

//= delete_pp()
//������ �ǵ帱 �� ����.
void delete_ref(int*& ref)
{
	delete ref;
	ref = nullptr;
}

//�纻��. ������ �ǵ帱 �� ����
void delete_p(int* p)
{
	delete p;
}

void mess_ppp(int*** ppp)
{
	*ppp = nullptr;
}

void cant_mess_ppp(int** const* ppp)
{
	//*ppp = nullptr;
}

void delete_pp(int** pp)
{
	mess_ppp(&pp);

	//delete *pp;

	//*pp = nullptr;
}

int main()
{
	int* da{};
	da = new int{ 5 };

	*da = 7;

	delete_ref(da);

	{
		//�Լ��� ȣ���� �� �޾ƿ��� �μ��� ����Ǿ� �Ű������� �ȴ�.
		//���� �� ��� da�� ���� �״���̴�. = dangling pointer
		//delete_p(da);
	}

	{
		//delete_pp(&da);
		//delete da;
	}

	{
		//int* da_copy{ da };
		//delete da_copy;
		//delete da;

		//����� ��Ʃ��� ������ delete�� delete�� ������ �����ִ� �ּҸ� �ǹ̾��� �ּҷ� �ٲ�.
		//���� �ּҸ� ����Ű�� �ִ�  da, da_copy�� ���� �� �� �� �ϳ��� delete �� ���
		//���� �ϳ��� dangling pointer�� �ȴ�.
	}

	return 0;
}

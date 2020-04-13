#include <iostream>

//= delete_pp()
//원본을 건드릴 수 있음.
void delete_ref(int*& ref)
{
	delete ref;
	ref = nullptr;
}

//사본임. 원본을 건드릴 수 없음
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
		//함수를 호출할 때 받아오는 인수는 복사되어 매개변수가 된다.
		//따라서 이 경우 da의 값은 그대로이다. = dangling pointer
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

		//비쥬얼 스튜디오 내에서 delete시 delete한 변수가 갖고있던 주소를 의미없는 주소로 바꿈.
		//같은 주소를 가리키고 있던  da, da_copy가 있을 때 둘 중 하나만 delete 할 경우
		//남은 하나는 dangling pointer가 된다.
	}

	return 0;
}

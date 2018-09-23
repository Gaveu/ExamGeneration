#include"ExamGen.h"

int main()
{
	/*clExamGen cl;
	cl.ClassWork();*/


	clExamGen *p = new clExamGen();
	string s;

	for (int i = 0; i < 10; ++i)
	{
		p->CreateExamToString(lv_Hardcore,s);
		cout << s.c_str() << endl;
	}
	

	system("PAUSE");
	return 0;
}
#include"ExamGen.h"

int main()
{
	/*clExamGen cl;
	cl.ClassWork();*/


	clExamGen *p;

	for (int i = 0; i < 50; ++i)
	{
		p = new clExamGen();
		p->ClassWork();
		delete(p);
	}
	

	system("PAUSE");
	return 0;
}
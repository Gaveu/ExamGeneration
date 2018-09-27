#include"opt_handler.h"
#include<numeric>
#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	try
	{
		opt_handler a(argc, argv);
		a.opt_handler_process();
	}
	catch (exception e)
	{
		cout << e.what();
	};
	system("PAUSE");
	return 0;
}
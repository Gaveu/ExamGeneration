#pragma once
#ifndef OPT_HANDLER
#define OPT_HANDLER
#include<string>
#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<ctype.h>
#include"node.h"
#include"ExamGen.h"
using std::string;
using std::cout;
using std::endl;
class opt_handler
{
public:
	int argc = 0;
	char** argv = 0;
	unsigned int problem_num = 10;
	unsigned int problem_size = 10;
	string exercisefile = "./Exercises.txt";
	string answerfile = "./Answers.txt";
	opt_handler(int argc, char** argv);
	void help();
	unsigned int to_num(char* in);
	void opt_handler_process();
	void generate_problems();
	void compare();

};
opt_handler::opt_handler(int argc, char** argv)
{
	this->argc = argc;
	this->argv = argv;
}


void opt_handler::help()
{
	cout << "小学生暑假杀手  充实暑假时光" << endl;
	cout << "使用方法：" << endl;
	cout << " -n: 控制生成题目的个数" << endl;
	cout << " -r: 控制题目中数值" << endl;
	cout << " -e: 题目文件" << endl;
	cout << " -a: 答案文件" << endl;
	return;

}
unsigned int opt_handler::to_num(char* in)
{
	/*
	将字符串转为数字
	传入参数：数字字符串
	返回值:字符串对应的无符号整数
	*/
	unsigned int result = 0;
	for (unsigned int a = 0; a < strlen(in); a++)
		result = result * 10 + (in[a] - '0');
	return result;
}
void opt_handler::opt_handler_process()
{
	if (this->argc == 1)
	{
		help();
		return;
	}
	bool is_judge = false;
	bool is_generate = false;
	for (int pos = 0; pos < this->argc; pos++)
	{
		if (!strncmp(this->argv[pos], "-h", 2))
		{
			help();
			return;
		}
		if (!strncmp(this->argv[pos], "-n", 2))//生成题目个数
		{
			if (this->argc - 1 > pos &&  isdigit(this->argv[pos + 1][0]))
				this->problem_num = this->to_num(this->argv[pos + 1]);
			else
				this->problem_num = 10;
			is_generate = true;
			continue;
		}
		else if (!strncmp(this->argv[pos], "-r", 2))//题目数值范围
		{
			if (this->argc - 1 > pos && isdigit(this->argv[pos + 1][0]))
				this->problem_size = this->to_num(this->argv[pos + 1]);
			else
				this->problem_size = 10;
			is_generate = true;
			continue;
		}
		else if (!strncmp(this->argv[pos], "-e", 2))//题目文本文件
		{
			this->exercisefile = this->argv[pos + 1];
			continue;
		}
		else if (!strncmp(this->argv[pos], "-a", 2))//题目答案文件
		{
			this->answerfile = this->argv[pos + 1];
			is_judge = true;
			continue;
		}
	}
	if (is_generate)
		this->generate_problems();
	else if (is_judge)
		this->compare();
	else
		help();
}

void opt_handler::generate_problems()
{
	clExamGen *p = new clExamGen();
	caculator* q = new caculator();
	ofstream Answer_File;
	ofstream Exercise_File;
	Answer_File.open(this->answerfile, ios::out | ios::trunc);//创建答案文件
	Exercise_File.open(this->exercisefile, ios::out | ios::trunc);//创建题目文件
	if (!Answer_File.is_open() || !Exercise_File.is_open())
	{
		cout << "文件创建失败";
		return;
	}
	string sCout;
	string sCal;
	int lv = lv_UserDefine;
	for (unsigned int x = 1; x < this->problem_num + 1; x++)//题目生成
	{
		p->CreateExamToString1(lv_UserDefine, sCout, sCal, this->problem_size, this->problem_size, this->problem_size, 3, 1);
		q->start_process(sCal);
		if (q->result->re_granted)
		{
			x--;
			continue;
		}
		cout << to_string(x) << ". " << sCout << " = " << q->final_result << endl;
		Exercise_File << to_string(x) << ". " << sCout << " = " << endl;
		Answer_File << to_string(x) << ". " << q->final_result << endl;
	}
	delete p, q;
	return;
}

void opt_handler::compare()
{
	vector<unsigned int>correct, error;
	caculator* q = new caculator();
	ifstream AnswerFile;
	ifstream ExerciseFile;
	AnswerFile.open(this->answerfile);//打开答案文件
	ExerciseFile.open(this->exercisefile);//打开题目文件
	if (!AnswerFile.is_open() || !ExerciseFile.is_open())
	{
		cout << "文件不存在";
		return;
	}
	string ans, exe;
	unsigned int current_problem_num = 0;
	while (!AnswerFile.eof() && !ExerciseFile.eof())//读取文件内容
	{

		current_problem_num++;
		getline(AnswerFile, ans);
		getline(ExerciseFile, exe);
		unsigned int pos = ans.find('.');
		if (pos != string::npos)
			ans = ans.substr(pos + 2);
		else
			break;
		pos = exe.find('.');
		exe = exe.substr(pos + 1);
		q->start_process(exe);
		ans._Equal(q->final_result) ? correct.push_back(current_problem_num) : error.push_back(current_problem_num);//结果判定
	}
	cout << "Correct: " << correct.size() << " (";
	for (unsigned int x = 0; x < correct.size(); x++)
	{
		if (x == 0)
			cout << " " << correct[x];
		else
			cout << ", " << correct[x];
	}
	cout << " )" << endl;

	cout << "Error: " << error.size() << " (";
	for (unsigned int x = 0; x < error.size(); x++)
	{
		if (x == 0)
			cout << " " << error[x];
		else
			cout << ", " << error[x];
	};
	cout << " )" << endl;
	delete q;
	return;
}
#endif // !opt_handler


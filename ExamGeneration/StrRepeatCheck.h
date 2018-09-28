#pragma once
#ifndef STRREPEATCHECK_H
#define STRREPEATCHECK_H

#include<iostream>
#include<string>
#include<map>
using namespace std;

class clStrRepeatCheck
{
public:
	map<string, int> checkMap;				//存储string-int的字串查重map类
	map<string, int>::iterator mapIt;		//字串查重map类迭代器

	bool StrCheckAndAdd(string &s, int IN_Num);		//检查传入字串是否存在于checkMap中，不存在则将该字串及对应的int型标号插入checkMap中，返回true；
													//如果传入的IN_Num小于等于0或者字串存在则不操作并返回false。
	int isInMap(string &s);		//检查传入字串是否存在于checkMap中，是则返回其对应的int值，不存在则返回0


};

#endif
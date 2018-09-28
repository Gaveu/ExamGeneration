#include"StrRepeatCheck.h"

bool clStrRepeatCheck::StrCheckAndAdd(string &s, int IN_Num)		
//检查传入字串是否存在于checkMap中，不存在则将该字串及对应的int型标号IN_Num插入checkMap中，返回true；
//如果传入的IN_Num小于等于0或者字串存在则不操作并返回false。
{
	//传入的IN_Num小于等于0，则返回false
	//若s在checkMap中被查找到对应的int值，则返回false
	if (IN_Num <= 0 || isInMap(s) != 0)
	{
		return false;
	}

	//运行到此处则说明s在checkMap中并无重复，此时以s为索引，将对应的int标号IN_Num作为键值加入checkMap中
	checkMap[s] = IN_Num;
	return true;
}

int clStrRepeatCheck::isInMap(string &s)
//检查传入字串是否存在于checkMap中，是则返回其对应的int值，不存在则返回0
{
	mapIt = checkMap.find(s);
	if (mapIt != checkMap.end())
	{
		return mapIt->second;
	}
	else
	{
		return 0;
	}
}
#pragma once
#include <iostream>


class errorClass
{
private:
	std::string errMsg;
public:
	errorClass(std::string err);
	std::string getErrMsg();
};

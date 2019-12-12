#include "Error.h"
#include <iostream>

errorClass::errorClass(std::string err)
{
	errMsg = err;
}

std::string errorClass::getErrMsg()
{
	return errMsg;
}

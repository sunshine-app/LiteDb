#pragma once
#include <string>
#include "odb/core.hxx"  


//声明接下来的一个对象是与数据库相关的类
//odb -d mysql --generate-query --generate-schema catch_result.hxx
#pragma db object no_id table("catch_result")
class CatchResult
{
public:
	//查询需要的构造函数
	CatchResult() {};
	//插入需要的构造函数
	CatchResult(std::string request_id, std::string process_id, int msg_type, int msg_result)
	{
		RequestID = request_id;
		ProcessID = process_id;
		MsgType = msg_type;
		MsgResult = msg_result;
	};

public:
	#pragma db type("VARCHAR(36)") id
	std::string RequestID;
	#pragma db type("VARCHAR(36)") not_null
	std::string ProcessID;
	#pragma db not_null
	int MsgType;
	#pragma db not_null
	int MsgResult;
private:
	//我们将类的构造函数或者将数据成员声明为私有时，odb的access类可以访问我们的数据成员和构造函数。
	friend class odb::access;

	//编号自动增长, #pragma db object 这行代码添加了, 则该行代码一定添加, 不然用odb编译会失败
	//#pragma db id auto       
	//unsigned long id_;
};

#pragma once
#include <string>
#include "odb/core.hxx"  


//������������һ�������������ݿ���ص���
//odb -d mysql --generate-query --generate-schema catch_result.hxx
#pragma db object no_id table("catch_result")
class CatchResult
{
public:
	//��ѯ��Ҫ�Ĺ��캯��
	CatchResult() {};
	//������Ҫ�Ĺ��캯��
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
	//���ǽ���Ĺ��캯�����߽����ݳ�Ա����Ϊ˽��ʱ��odb��access����Է������ǵ����ݳ�Ա�͹��캯����
	friend class odb::access;

	//����Զ�����, #pragma db object ���д��������, ����д���һ�����, ��Ȼ��odb�����ʧ��
	//#pragma db id auto       
	//unsigned long id_;
};

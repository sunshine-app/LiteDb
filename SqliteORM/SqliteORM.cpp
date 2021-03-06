// SqliteORM.cpp: 定义控制台应用程序的入口点。
//#include <iostream>
#include <tics_db.h>

/*
namespace robotSorting {
namespace planning {

}
}
*/
using namespace robotSorting::planning;

int main(int, char **) {

	std::string sqlite_path = "E:/shineLoverDesktop/rishmi.sqlite";

	ManageLiteData manageLiteData(sqlite_path);

	manageLiteData.syncDatabase();
	manageLiteData.clearAllTable();

	for (int idx = 0; idx <100; idx++)
	{
		CatchResult catchResult;
		catchResult.request_id = "2c4688ac-f68d-4f45-9998-ad0f19a5c8" + std::to_string(idx);
		catchResult.process_id = "4bb522c3-689a-4d04-b255-bf5d8d027ca7";
		catchResult.msg_type = 200;
		catchResult.msg_result = 1000;
		manageLiteData.insertCatchResult(catchResult);
	}

	return 0;
}

// MysqlOdb.cpp: 定义控制台应用程序的入口点。
//
#include <memory>   // std::auto_ptr
#include <iostream>
#include "insert_planning_odb.h"
#include <time.h>

using namespace robotSorting::planning;

int main()
{
	PlanningOdb pdb("shine", "123456", "rishmi", "127.0.0.1", 3306, "utf8");
	clock_t start, finish;
	start = clock();
	for (int idx = 0; idx <100; idx++)
	{
		CatchResult catchResult;
		catchResult.RequestID = "2c4688ac-f68d-4f45-9998-ad0f19a5c8" + std::to_string(idx);
		catchResult.ProcessID = "4bb522c3-689a-4d04-b255-bf5d8d027ca7";
		catchResult.MsgType = 200;
		catchResult.MsgResult = 1000;
		pdb.insertCatchResult(catchResult);
	}
	finish = clock();
	printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
	return 0;
}


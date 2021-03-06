// SqliteOdb.cpp: 定义控制台应用程序的入口点。
//
#include <memory>   // std::auto_ptr
#include <iostream>

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/connection.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include "catch_result.hxx"
#include "catch_result-odb.hxx"


using std::cout;
using std::endl;

using namespace std;
using namespace odb::core;

int main()
{
	try
	{
		auto_ptr<database> db(new odb::sqlite::database("sqlite.db", SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE));
		
		CatchResult catchResult("2c4688ac-f68d-4f45-9998-ad0f19a5c8e1", "4bb522c3-689a-4d04-b255-bf5d8d027ca7", 200, 1000);
		
		transaction t(db->begin());

		schema_catalog::create_schema(*db, "", false);
		db->persist(catchResult);
		t.commit();
	}
	catch (const odb::exception& ex)
	{
		cout << "插入数据异常" << ex.what() << endl;
		return 1;
	}
    return 0;
}
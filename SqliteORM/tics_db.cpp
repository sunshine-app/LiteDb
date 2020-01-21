#include <tics_db.h>


namespace robotSorting {
	namespace planning {


		ManageLiteData::ManageLiteData(std::string &sqlite_path)
		{
			db_path_ = sqlite_path;
		}

		bool ManageLiteData::insertCatchResult(CatchResult& catch_result) {
			try
			{
				auto request_id = storage.insert(catch_result);
				cout << "插入catch_result表数据" << request_id << endl;
				return true;
			}
			catch (const std::exception& ex)
			{
				cout << "插入catch_result表数据异常" << ex.what() << endl;
				return false;
			}
		}

		bool ManageLiteData::syncDatabase() {
			try
			{
				//同步数据库
				storage.sync_schema();
				return true;
			}
			catch (const std::exception& ex)
			{
				cout << "同步数据库异常" << ex.what() << endl;
				return false;
			}
		}

		bool ManageLiteData::clearAllTable() {
			try
			{
				//清空数据表
				storage.remove_all<PositionCode>();
				storage.remove_all<RecogImpurity>();
				storage.remove_all<TargetImpurity>();
				storage.remove_all<CatchResult>();
				return true;
			}
			catch (const std::exception& ex)
			{
				cout << "清空数据表异常" << ex.what() << endl;
				return false;
			}
		}
	}
}
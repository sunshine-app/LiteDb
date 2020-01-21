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
				cout << "����catch_result������" << request_id << endl;
				return true;
			}
			catch (const std::exception& ex)
			{
				cout << "����catch_result�������쳣" << ex.what() << endl;
				return false;
			}
		}

		bool ManageLiteData::syncDatabase() {
			try
			{
				//ͬ�����ݿ�
				storage.sync_schema();
				return true;
			}
			catch (const std::exception& ex)
			{
				cout << "ͬ�����ݿ��쳣" << ex.what() << endl;
				return false;
			}
		}

		bool ManageLiteData::clearAllTable() {
			try
			{
				//������ݱ�
				storage.remove_all<PositionCode>();
				storage.remove_all<RecogImpurity>();
				storage.remove_all<TargetImpurity>();
				storage.remove_all<CatchResult>();
				return true;
			}
			catch (const std::exception& ex)
			{
				cout << "������ݱ��쳣" << ex.what() << endl;
				return false;
			}
		}
	}
}
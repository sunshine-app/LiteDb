#include "insert_planning_odb.h"

namespace robotSorting {
	namespace planning {
		PlanningOdb::PlanningOdb(const std::string& user, const std::string& passwd, const std::string& db, const std::string& host, unsigned int port, const std::string& charset) {
			auto_ptr<odb::database> mdb(
				new odb::mysql::database(
					user, passwd, db,
					host, port, "", charset
				));
			this->mdb = mdb;
		}

		bool PlanningOdb::insertCatchResult(CatchResult& catch_result) {
			try
			{
				transaction t(mdb->begin());
				mdb->persist(catch_result);
				t.commit();
				return true;
			}
			catch (const std::exception& ex)
			{
				return false;
			}
		}

	}
}
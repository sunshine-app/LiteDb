#pragma once
#include <odb/mysql/database.hxx>
#include <odb/transaction.hxx>
#include <odb/connection.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>


#include "catch_result.hxx"
#include "catch_result-odb.hxx"


using namespace std;
using namespace odb::core;

namespace robotSorting {
	namespace planning {
		class PlanningOdb
		{
		public:
			PlanningOdb(const std::string& user, const std::string& passwd, const std::string& db, const std::string& host, unsigned int port, const std::string& charset);
			bool insertCatchResult(CatchResult& catch_result);

		private:
			auto_ptr<odb::database> mdb;
		};
	}
}

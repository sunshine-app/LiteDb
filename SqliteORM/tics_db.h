#include <sqlite_orm.h>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

namespace robotSorting {
namespace planning {
	using namespace sqlite_orm;

	typedef struct STCatchResult {
		std::string request_id;
		std::string process_id;
		int msg_type;
		int msg_result;
	} CatchResult;

	static auto initStorage(const std::string &db_path) {
		using namespace sqlite_orm;
		return make_storage(db_path,
			make_table("catch_result",
				make_column("RequestID", &CatchResult::request_id, unique()),
				make_column("ProcessID", &CatchResult::process_id),
				make_column("MsgType", &CatchResult::msg_type),
				make_column("MsgResult", &CatchResult::msg_result))
		);
	}
	

	using Storage = decltype(initStorage(""));
	class ManageLiteData
	{
	public:
		ManageLiteData(std::string &sqlite_path);

		bool insertCatchResult(CatchResult& catch_result);
		bool syncDatabase();
		bool clearAllTable();
	private:
		std::string db_path_ = "/etc/riss/rishmi.sqlite";
		Storage storage = initStorage(db_path_);
		
	};
}
}

#define STRICT_R_HEADERS
#define R_NO_REMAP

#ifndef __RSQLITE_SQLITE_RESULT__
#define __RSQLITE_SQLITE_RESULT__

#include "DbResult.h"

// DbResult --------------------------------------------------------------------

class SqliteResult : public DbResult {
protected:
  SqliteResult(const DbConnectionPtr& pConn, const std::string& sql);

public:
  static DbResult* create_and_send_query(const DbConnectionPtr& con, const std::string& sql);

public:
  Rcpp::CharacterVector get_placeholder_names() const;
};

#endif

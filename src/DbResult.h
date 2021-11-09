#define STRICT_R_HEADERS
#define R_NO_REMAP


#ifndef __RDBI_DB_RESULT__
#define __RDBI_DB_RESULT__

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>

#include "DbResultImplDecl.h"


class DbConnection;
typedef boost::shared_ptr<DbConnection> DbConnectionPtr;

// DbResult --------------------------------------------------------------------

class DbResult : boost::noncopyable {
  DbConnectionPtr pConn_;

protected:
  boost::scoped_ptr<DbResultImpl> impl;

protected:
  DbResult(const DbConnectionPtr& pConn);

public:
  ~DbResult();

public:
  void close();

  bool complete() const;
  bool is_active() const;
  int n_rows_fetched();
  int n_rows_affected();

  void bind(const Rcpp::List& params);
  Rcpp::List fetch(int n_max = -1);

  Rcpp::List get_column_info();

private:
  void validate_params(const Rcpp::List& params) const;
};

#endif // __RDBI_DB_RESULT__

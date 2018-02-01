// This file is part of the "primcalc" project, http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#include <system_error>
#include <memory>
#include <utility>

class Expr;

class Parser {
 public:
  static std::pair<std::unique_ptr<Expr>, std::error_code> parse(
      const std::string& input);

 private:
  explicit Parser(const std::string& input);

  std::unique_ptr<Expr> expr();         //!< entrypoint for expressions
  std::unique_ptr<Expr> addExpr();      //!< parses + and -
  std::unique_ptr<Expr> mulExpr();      //!< parses * and /
  std::unique_ptr<Expr> primaryExpr();  //!< parses parenthisis and literals

  //! advances to the next token
  void nextToken();

 private:
  std::string expression_;
  std::string::const_iterator currentToken_;
};

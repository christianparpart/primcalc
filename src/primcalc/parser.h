// This file is part of the "primcalc" project, <http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#include <stdexcept>
#include <memory>
#include <utility>

class Expr;

class ParserError : public std::runtime_error {
 public:
  ParserError(int column, const std::string& baseMessage)
      : std::runtime_error(baseMessage), column_(column) {}

  int column() const noexcept { return column_; }

 private:
  int column_;
};

class Parser {
 public:
  static std::unique_ptr<Expr> parse(const std::string& input); 

 private:
  explicit Parser(const std::string& input);

  std::unique_ptr<Expr> expr();         //!< entrypoint for expressions
  std::unique_ptr<Expr> addExpr();      //!< parses + and -
  std::unique_ptr<Expr> mulExpr();      //!< parses * and /
  std::unique_ptr<Expr> primaryExpr();  //!< parses parenthisis and literals

  void nextToken();     //!< advances to the next token
  void validateToken(); //!< ensures current token is valid
  bool eof() const;     //!< lexer reached EOF?
  int column() const;   //!< retrieves the current column of our oneline-expression

 private:
  std::string expression_;
  std::string::const_iterator currentToken_;
};

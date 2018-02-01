// This file is part of the "primcalc" project, http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#include <primcalc/parser.h>
#include <primcalc/ast.h>

Parser::Parser(const std::string& input)
      : expression_(input), currentToken_(expression_.cbegin()) {

  // skip whitespace
  if (currentToken_ != expression_.cend() && std::isspace(*currentToken_)) {
    currentToken_++;
  }
}

std::pair<std::unique_ptr<Expr>, std::error_code> Parser::parse(const std::string& input) {
  std::pair<std::unique_ptr<Expr>, std::error_code> result;

  Parser parser(input);
  result.first = parser.expr();

  return result;
}

std::unique_ptr<Expr> Parser::expr() {
  return addExpr();
}

std::unique_ptr<Expr> Parser::addExpr() {
  auto lhs = mulExpr();

  while (currentToken_ != expression_.cend()) {
    switch (*currentToken_) {
      case '+':
        nextToken();
        lhs = std::make_unique<AddExpr>(std::move(lhs), mulExpr());
        break;
      case '-':
        nextToken();
        lhs = std::make_unique<SubExpr>(std::move(lhs), mulExpr());
        break;
      default:
        return lhs;
    }
  }
  return lhs;
}

std::unique_ptr<Expr> Parser::mulExpr() {
  auto lhs = primaryExpr();

  while (currentToken_ != expression_.cend()) {
    switch (*currentToken_) {
      case '*':
        nextToken();
        lhs = std::make_unique<MulExpr>(std::move(lhs), primaryExpr());
        break;
      case '/':
        nextToken();
        lhs = std::make_unique<DivExpr>(std::move(lhs), primaryExpr());
        break;
      default:
        return lhs;
    }
  }
  return lhs;
}

std::unique_ptr<Expr> Parser::primaryExpr() {
  if (currentToken_ == expression_.cend())
    return nullptr; // TODO EOF

  if (std::isdigit(*currentToken_)) {
    Value value = *currentToken_ - '0';
    nextToken();
    return std::make_unique<ValueExpr>(value);
  }

  if (*currentToken_ == '(') {
    nextToken();
    auto subExpr = expr();
    if (*currentToken_ == ')') {
      nextToken();
      return subExpr;
    } else {
      return nullptr; // TODO parse error
    }
  }

  return nullptr; // TODO parse error
}

void Parser::nextToken() {
  if (currentToken_ != expression_.cend())
    currentToken_++;

  // skip whitespace
  if (currentToken_ != expression_.cend() && std::isspace(*currentToken_)) {
    currentToken_++;
  }
}

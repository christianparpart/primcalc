// This file is part of the "primcalc" project, <http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#include <primcalc/parser.h>
#include <primcalc/ast.h>
#include <primcalc/utils.h>

Parser::Parser(const std::string& input)
      : expression_(input), currentToken_(expression_.cbegin()) {

  // skip whitespace
  while (!eof() && std::isspace(*currentToken_)) {
    currentToken_++;
  }

  validateToken();
}

std::unique_ptr<Expr> Parser::parse(const std::string& input) {
  Parser parser(input);
  auto expr = parser.expr();

  if (!parser.eof())
    throw ParserError(parser.column(), "Unexpected token at the end of expression.");

  return expr;
}

std::unique_ptr<Expr> Parser::expr() {
  return addExpr();
}

std::unique_ptr<Expr> Parser::addExpr() {
  auto lhs = mulExpr();

  while (!eof()) {
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

  while (!eof()) {
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
  if (eof())
    throw ParserError(column(), "Unexpected EOF in primary expression");

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
      throw ParserError(column(), "Unexpected token. Expected ')' instead.");
    }
  }

  throw ParserError(column(), "Unexpected token in primary expression");
}

void Parser::nextToken() {
  if (!eof())
    currentToken_++;

  // skip whitespace
  while (!eof() && std::isspace(*currentToken_))
    currentToken_++;

  validateToken();
}

void Parser::validateToken() {
  static std::string validSymbols = "+-*/()0123456789";

  if (eof())
    return;

  if (std::isdigit(*currentToken_)) {
    auto peek = std::next(currentToken_);
    if (peek != expression_.cend() && std::isdigit(*peek)) {
      throw ParserError(column(), "Multidigit numbers are not supported.");
    }
  } else if (validSymbols.find(*currentToken_) == std::string::npos) {
    throw ParserError(column(), "Invalid input.");
  }
}

bool Parser::eof() const {
  return currentToken_ == expression_.cend();
}

int Parser::column() const {
  return 1 + std::distance(expression_.cbegin(), currentToken_);
}

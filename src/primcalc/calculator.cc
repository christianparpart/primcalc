// This file is part of the "primcalc" project, <http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#include <primcalc/calculator.h>

Value Calculator::calculate(const Expr* expr) {
  Calculator c;
  if (expr) {
    const_cast<Expr*>(expr)->accept(c);
  }
  return c.result_;
}

void Calculator::visit(ValueExpr* e) {
  result_ = e->value();
}

void Calculator::visit(AddExpr* e) {
  result_ = calculate(e->left()) + calculate(e->right());
}

void Calculator::visit(SubExpr* e) {
  result_ = calculate(e->left()) - calculate(e->right());
}

void Calculator::visit(MulExpr* e) {
  result_ = calculate(e->left()) * calculate(e->right());
}

void Calculator::visit(DivExpr* e) {
  auto rhs = calculate(e->right());
  auto lhs = calculate(e->left());

  if (rhs == 0)
    throw std::runtime_error("Division by 0.");

  result_ = lhs / rhs;
}

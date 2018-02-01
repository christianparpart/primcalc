// This file is part of the "primcalc" project, <http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#include <primcalc/ast_printer.h>
#include <string>

std::string AstPrinter::print(const Expr* expr) {
  return print(Precedence::Lowest, const_cast<Expr*>(expr));
}

std::string AstPrinter::print(Precedence p, Expr* expr) {
  AstPrinter printer;

  if (expr->precedence() < p)
    printer.result_ += '(';

  expr->accept(printer);

  if (expr->precedence() < p)
    printer.result_ += ')';

  return printer.result_;
}

void AstPrinter::visit(AddExpr* e) {
  result_ += print(e->precedence(), e->left()) + " + " +
             print(e->precedence(), e->right());
}

void AstPrinter::visit(SubExpr* e) {
  result_ += print(e->precedence(), e->left()) + " - " +
             print(e->precedence(), e->right());
}

void AstPrinter::visit(MulExpr* e) {
  result_ += print(e->precedence(), e->left()) + " * " +
             print(e->precedence(), e->right());
}

void AstPrinter::visit(DivExpr* e) {
  result_ += print(e->precedence(), e->left()) + " / " +
             print(e->precedence(), e->right());
}

void AstPrinter::visit(ValueExpr* e) {
  result_ += std::to_string(e->value());
}


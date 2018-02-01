// This file is part of the "primcalc" project, <http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#pragma once

#include <primcalc/ast_visitor.h>
#include <primcalc/ast.h> // Value

class Calculator : public AstVisitor {
 public:
  static Value calculate(const Expr* expr);

 private:
  Calculator() : result_(0) {}

  void visit(ValueExpr*) override;
  void visit(AddExpr*) override;
  void visit(SubExpr*) override;
  void visit(MulExpr*) override;
  void visit(DivExpr*) override;

 private:
  Value result_;
};


// This file is part of the "primcalc" project, <http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#pragma once

#include <primcalc/ast_visitor.h>
#include <primcalc/ast.h> // Precedence
#include <string>

class AstPrinter : public AstVisitor {
 public:
  static std::string print(const Expr* expr);

 private:
  static std::string print(Precedence p, Expr* expr);

  void visit(AddExpr*) override;
  void visit(SubExpr*) override;
  void visit(MulExpr*) override;
  void visit(DivExpr*) override;
  void visit(ValueExpr*) override;

 private:
  std::string result_;
};


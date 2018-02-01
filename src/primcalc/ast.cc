// This file is part of the "primcalc" project, <http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#include <primcalc/ast.h>
#include <primcalc/ast_visitor.h>

void ValueExpr::accept(AstVisitor& v) {
  v.visit(this);
}

void AddExpr::accept(AstVisitor& v) {
  v.visit(this);
}

void SubExpr::accept(AstVisitor& v) {
  v.visit(this);
}

void MulExpr::accept(AstVisitor& v) {
  v.visit(this);
}

void DivExpr::accept(AstVisitor& v) {
  v.visit(this);
}


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


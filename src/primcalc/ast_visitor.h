// This file is part of the "primcalc" project, <http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#pragma once

class AddExpr;
class SubExpr;
class MulExpr;
class DivExpr;
class ValueExpr;

class AstVisitor {
 public:
  virtual ~AstVisitor() {}

  virtual void visit(AddExpr*) = 0;
  virtual void visit(SubExpr*) = 0;
  virtual void visit(MulExpr*) = 0;
  virtual void visit(DivExpr*) = 0;
  virtual void visit(ValueExpr*) = 0;
};

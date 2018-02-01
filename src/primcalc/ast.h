// This file is part of the "primcalc" project, http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#pragma once

#include <memory>

class AstVisitor;

enum class Precedence {
  Sum,
  Factor,
  // Power, ...
  Value,

  Lowest = Sum, // helper symbol, to have that more generic
};

class Expr {
 public:
  explicit Expr(Precedence p) : precedence_(p) {}
  virtual ~Expr() {}

  Precedence precedence() const noexcept { return precedence_; }

  virtual void accept(AstVisitor&) = 0;

 protected:
  Precedence precedence_;
};

using Value = long long int;

class ValueExpr : public Expr {
 public:
  explicit ValueExpr(Value v) : Expr(Precedence::Value), value_(v) {}

  Value value() const noexcept { return value_; }
  void accept(AstVisitor&) override;

 private:
  Value value_;
};

class BinaryExpr : public Expr {
 public:
  BinaryExpr(Precedence p, std::unique_ptr<Expr>&& lhs, std::unique_ptr<Expr>&& rhs)
      : Expr(p), left_(std::move(lhs)), right_(std::move(rhs)) {}

  Expr* left() const { return left_.get(); }
  Expr* right() const { return right_.get(); }

 protected:
  std::unique_ptr<Expr> left_;
  std::unique_ptr<Expr> right_;
};

class AddExpr : public BinaryExpr {
 public:
  AddExpr(std::unique_ptr<Expr>&& lhs, std::unique_ptr<Expr>&& rhs)
      : BinaryExpr(Precedence::Sum, std::move(lhs), std::move(rhs)) {}

  void accept(AstVisitor&) override;
};

class SubExpr : public BinaryExpr {
 public:
  SubExpr(std::unique_ptr<Expr>&& lhs, std::unique_ptr<Expr>&& rhs)
      : BinaryExpr(Precedence::Sum, std::move(lhs), std::move(rhs)) {}

  void accept(AstVisitor&) override;
};

class MulExpr : public BinaryExpr {
 public:
  MulExpr(std::unique_ptr<Expr>&& lhs, std::unique_ptr<Expr>&& rhs)
      : BinaryExpr(Precedence::Factor, std::move(lhs), std::move(rhs)) {}

  void accept(AstVisitor&) override;
};

class DivExpr : public BinaryExpr {
 public:
  DivExpr(std::unique_ptr<Expr>&& lhs, std::unique_ptr<Expr>&& rhs)
      : BinaryExpr(Precedence::Factor, std::move(lhs), std::move(rhs)) {}

  void accept(AstVisitor&) override;
};

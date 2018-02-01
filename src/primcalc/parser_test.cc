// This file is part of the "primcalc" project, <http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#include <primcalc/minitest.h>

int main() {
  EXPECT_PARSER_ERROR(1, "");       // empty expression
  EXPECT_PARSER_ERROR(1, ")1+1");   // misplaced token
  EXPECT_PARSER_ERROR(3, "1+");     // unbalanced expression
  EXPECT_PARSER_ERROR(5, "(1+1");   // unbalanced ()'s
  EXPECT_PARSER_ERROR(4, "1+1)");   // trailer
  EXPECT_PARSER_ERROR(1, "10 + 1"); // multi-digit: initial token
  EXPECT_PARSER_ERROR(3, "1+10");   // multi-digit: consecutive token
  EXPECT_PARSER_ERROR(1, "-10");    // sgn

  EXPECT_SUCCESS(22, "(4 + 5 * (7 - 3)) - 2");
  EXPECT_SUCCESS(12, "4+5+7/2");

  return evaluateSummary();
}

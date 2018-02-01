// This file is part of the "primcalc" project, <http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#include <primcalc/parser.h>
#include <primcalc/calculator.h>

#pragma once

// mini-testing API, losely inspired by googletest

#define EXPECT_SUCCESS(result, input) \
  expectSuccess((result), (input), __LINE__)

#define EXPECT_PARSER_ERROR(column, input) \
  expectParseError((column), (input), __LINE__)

void reportError(const std::string& error, int sourceLine);
void expectParseError(int column, const std::string& input, int sourceLine);
void expectSuccess(Value expectedResult, const std::string& input, int sourceLine);
int evaluateSummary();

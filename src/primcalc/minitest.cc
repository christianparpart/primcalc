// This file is part of the "primcalc" project, <http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#include <primcalc/minitest.h>
#include <cstdio>
#include <cstdlib>

// globals are usually discouraged, I'm making an exception here
static int errorCount_ = 0;

void reportError(const std::string& error, int sourceLine) {
  errorCount_++;
  printf("!!! Test failure in %s:%d. %s\n", __FILE__, sourceLine, error.c_str());
}

void expectParseError(int column, const std::string& input, int sourceLine) {
  printf("Checking for parser error at column %d in: \"%s\"\n", column, input.c_str());

  try {
    Parser::parse(input);
      char buf[256];
      snprintf(buf, sizeof(buf),
               "Excepted a parser error at column %d, but got none.",
               column);
      reportError(buf, sourceLine);
  } catch (const ParserError& err) {
    if (err.column() != column) {
      char buf[256];
      snprintf(buf, sizeof(buf),
               "Expected a parser error at column %d, but got one at %d instead. %s",
               column, err.column(), err.what());
      reportError(buf, sourceLine);
    }
  } catch (const std::exception& err) {
    reportError(err.what(), sourceLine);
  } catch (...) {
    reportError("Unhandled exception caught.", sourceLine);
  }
}

void expectSuccess(Value expectedResult, const std::string& input, int sourceLine) {
  printf("Checking for calculation %lli = %s\n", expectedResult, input.c_str());

  try {
    auto expr = Parser::parse(input);
    auto actualResult = Calculator::calculate(expr.get());
    if (actualResult != expectedResult) {
      char buf[256];
      snprintf(buf, sizeof(buf), "Expected calculated result %lli, but got %lli instead.",
          expectedResult, actualResult);
      reportError(buf, sourceLine);
    }
  } catch (const std::exception& err) {
    reportError(err.what(), sourceLine);
  } catch (...) {
    reportError("Unhandled exception caught.", sourceLine);
  }
}

int evaluateSummary() {
  return errorCount_ == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

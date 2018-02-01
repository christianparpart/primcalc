// This file is part of the "primcalc" project, http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#include <primcalc/parser.h>
#include <primcalc/calculator.h>
#include <primcalc/ast_printer.h>
#include <primcalc/ast.h>
#include <iostream>
#include <string>

int main(int argc, const char *argv[]) {
  for (;;) {
    std::string input;
    std::cout << "input> ";
    std::cout.flush();
    std::getline(std::cin, input);

    if (input.empty()) {
      std::cout << "\nQuit.\n";
      break;
    }

    // auto [expr, err] = Parser::parse(input);
    std::pair<std::unique_ptr<Expr>, std::error_code> parsed = Parser::parse(input);
    if (!parsed.second) {
      std::cout << "expr := " << AstPrinter::print(parsed.first.get()) << std::endl;
      std::cout << "      = " << Calculator::calculate(parsed.first.get()) << std::endl;
    } else {
      std::cout << "Error. " << parsed.second << std::endl;
    }
  }
  return 0;
}

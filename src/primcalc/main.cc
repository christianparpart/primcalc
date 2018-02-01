// This file is part of the "primcalc" project, <http://github.com/christianparpart/primcalc>
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
      std::cout << "\nBye.\n";
      break;
    }

    try {
      std::unique_ptr<Expr> expr = Parser::parse(input);
      std::cout << "expr := " << AstPrinter::print(expr.get()) << std::endl;
      const Value result = Calculator::calculate(expr.get());
      std::cout << "      = " << result << std::endl;
    } catch (const ParserError& err) {
      std::cout << "Parser error at column " << err.column() << ": "
                << err.what() << std::endl;
    } catch (const std::exception& err) {
      std::cout << "Unhandled exception: " << err.what() << std::endl;
    }
  }

  return 0;
}

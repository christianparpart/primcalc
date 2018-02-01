// This file is part of the "primcalc" project, <http://github.com/christianparpart/primcalc>
//   (c) 2018 Christian Parpart <christian@parpart.family>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#pragma once

#if __cplusplus == 201103L

// C++11 doesn't come with std::make_unique<>, so provide it, in case we're
// getting compiled in C++11 mode
#include <memory>
namespace std {
  // tested on my Clang, version 5.0.0
  template<typename T, typename... Args>
  inline std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
  }
}

#endif

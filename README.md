primcalc - a primitive interactive calculator
=============================================

How to build
------------

```!sh
git clone https://github.com/christianparpart/primcalc.git
cd primcalc
./configure
make
./primcalc
```

Capabilities
------------

Basic arithmetic operations, such as `+`, `-`, `*`, `/` on natural numbers
between `0` and `9` including. The result itself may be a outside this
restricted range.

The input may also contain whitespaces for better readability, also
sub epxressions may be grouped with parenthisis via `(` and `)`.

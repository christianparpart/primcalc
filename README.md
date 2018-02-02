primcalc - a primitive interactive calculator
=============================================

Capabilities
------------

Basic arithmetic operations, such as `+`, `-`, `*`, `/` on natural numbers
between `0` and `9` including. The result itself may be a outside this
restricted range.

The input may also contain whitespaces for better readability, also
sub epxressions may be grouped with parenthisis via `(` and `)`.

How to run with Docker
----------------------

Just run:
```!sh
docker run --rm -ti trapni/primcalc
```

Build it yourself and run:
```!sh
git clone https://github.com/christianparpart/primcalc.git
cd primcalc
docker build -t primcalc .
docker run --rm -ti primcalc
```

How to build from source
------------------------

```!sh
git clone https://github.com/christianparpart/primcalc.git
cd primcalc
./autogen.sh
./configure
make
make check   # compiles and runs unit tests
./primcalc
```

Notes
-----

- I've chosen simplicity over complexity (to only match the required capabilities)
- Error handling has been done via exceptions, I like `std::error_code` too, but
  that would have yielded into more complex code to write for parsers
- I highly prefer namespacing, however, here I chose not to, as it seemed overkill.
- the minitest API is losely inspired googletest
- I wrote this tool in two sessions.
  - in the first, everything worked, but I skipped error handling for quickness of hacking (get-it-done v1)
  - in the second session, I was integrating proper error handling alongside unit tests and some polishing.
- I find myself pretty comfortable with recursive descent parsers (I like then),
  however, I never touched shunting hard *yet*.


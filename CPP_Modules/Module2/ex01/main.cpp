#include "Fixed.hpp"

int main() {
    Fixed       a();
    Fixed const b(10);
    Fixed const c(42.2f);
    Fixed const d(b);

    a = Fixed(1234.4321f);
}

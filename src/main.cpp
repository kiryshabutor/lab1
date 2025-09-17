#include "../includes/app.h"
#include "locale.h"

int main() {
    setlocale(LC_ALL, "");

    App app;
    app.run();
    return 0;
}

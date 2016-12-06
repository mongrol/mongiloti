#include "all.h"

void updateState()
{
    //check devices for change
    processPots();
    processEncoder();
    processButton();
}

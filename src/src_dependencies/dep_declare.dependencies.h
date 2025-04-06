#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>a

#if !defined(UniversalGarbage_fdeclare) && !defined(MAKTUB_MOCK_UNIVERSAL_GARBAGE)
#include "../../dependencies/UniversalGarbage.h"
#define MAKTUB_UNIVERSAL_GARBAGE_DECLARATED
#endif
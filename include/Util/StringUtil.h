#pragma once

#include "syati.h"

namespace MR
{
    wchar_t* addPictureFontCode(wchar_t *, int);
    // more functions before this
    bool isEqualString(const char *, const char *);
    bool isEqualStringCase(const char *, const char *);
    bool isEqualSubString(const char *, const char *);
    bool hasStringSpace(const char *);
    bool isDigitStringTail(const char *, int);
    bool isExistString(const char *, const char *, u32);
};

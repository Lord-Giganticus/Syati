#pragma once

#include "syati.h"

class JSUPtrLink;

class JSUPtrList
{
public:
    JSUPtrList(bool hasBeenInit);
    ~JSUPtrList();

    void initiate();
    void setFirst(JSUPtrLink* link);
    void append(JSUPtrLink* link);
    void prepend(JSUPtrLink* link);
    void remove(JSUPtrLink* link);

    JSUPtrLink* mFirst; // _0
    JSUPtrLink* mNext; // _4
    u32 mNumPtrs; // _8
};

template<typename T>
class JSUList : public JSUPtrList
{
public:
    JSUList();
    ~JSUList();
};

class JSUPtrLink
{
public:
    JSUPtrLink(void *);
    ~JSUPtrLink();

    void* mPtr; // _0
    JSUPtrList* mPtrList; // _4
    u32 _8;
    JSUPtrLink* _C;
};

template<typename T>
class JSULink : public JSUPtrLink
{
public:
    inline JSULink(void* ptr) : JSUPtrLink(ptr) { }

    ~JSULink();
};

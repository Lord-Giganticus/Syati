#pragma once

#include "JSystem/JGeometry/TVec3.h"

namespace JGeometry
{
    template<typename T>
    class TQuat4
    {
    public:
        inline TQuat4() {}

        template<typename T>
        TQuat4(T, T, T, T);

        void getXDir(const TVec3<T> &) const;
        void getYDir(const TVec3<T> &) const;
        void getZDir(const TVec3<T> &) const;

        void getEuler(const TVec3<T> &) const;
        void setEuler(f32, f32, f32);
        // void setEulerZ(f32); does this still exist in SMG2?

        void rotate(const TVec3<T> &) const;
        void setRotate(const TVec3<T> &, f32);
        void setRotate(const TVec3<T> &, const TVec3<T> &);
        void setRotate(const TVec3<T> &, const TVec3<T> &, f32);

        void normalize();
        void normalize(const TQuat4<T> &);

        void slerp(const TQuat4<T> &, f32);
        // void slerp(const TQuat4<T> &, const TQuat4<T> &, f32); does this still exist in SMG2?

        void transform(const TVec3<T> &);
        void transform(const TVec3<T> &, const TVec3<T> &);

        void operator =(const TQuat4<T> &);

        T x; // _0
        T y; // _4
        T z; // _8
        T w; // _C
    };
};

typedef JGeometry::TQuat4<f32> TQuat4f;

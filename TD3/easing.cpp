#include<math.h>
#include"easing.h"

static const float PI = 3.14159265359;

using namespace std;

namespace EasingFunction
{
    //�C�[�W���O�֐�
    double InQuad(double t)
    {
        return t * t;
    }

    double InCubic(double t)
    {
        return t * t * t;
    }

    double InQuart(double t)
    {
        return t * t * t * t;
    }

    double InQuint(double t)
    {
        return t * t * t * t * t;
    }

    double InSine(double t)
    {
        return 1 - cos(t * PI / 2);
    }

    double InExp(double t)
    {
        return pow(2, -(1 - t) * 10);
    }

    double InCirc(double t)
    {
        return 1 - sqrt((0 > 1 - t * t) ? 0 : 1 - t * t);
    }

    double InBack(double t)
    {
        return t * t * (2.70158 * t - 1.70158);
    }
    double InSoftBack(double t)
    {
        return t * t * (2 * t - 1);
    }

    double InElastic(double t)
    {
        return 56 * t * t * t * t * t - 105 * t * t * t * t + 60 * t * t * t - 10 * t * t;
    }

    double InBounce(double t)
    {
        double pow2;
        int bounce = 4;
        while (t < ((pow2 = pow(2, --bounce)) - 1) / 11) {}
        return 1 / pow(4, 3 - bounce) - 7.5625 * pow((pow2 * 3 - 2) / 22 - t, 2);
    }

    double InLinear(double t)
    {
        return t;
    }
}

using namespace EasingFunction;
static double (*FuncPtr[12])(double t)
= {
    InQuad,InCubic,InQuart,InQuint,InSine,InExp,InCirc,InBack,InSoftBack,InElastic,InBounce,InLinear
};

double Ease(type Type, ease Ease, double t)
{
    if (Type == In)
    {
        return FuncPtr[Ease](t);
    }
    else if (Type == Out)
    {
        return 1 - FuncPtr[Ease](1 - t);
    }
    else if (Type == InOut)
    {
        if (t < 0.5)
            return FuncPtr[Ease](t * 2) / 2;

        return 1 - FuncPtr[Ease](2 - 2 * t) / 2;
    }
}
#pragma once
#include "bear.h"

class Mommabear : public Bear{ // 여기있는 퍼블릭이라는 access specifier. 부모랑 자녀 간에도 숨기고 사는 게 좋다.
                                //Bear member들에 대한 control 권한.
                                // public retains the access from the superclass
                                // protected forces the public members to become protected in the subclass
                                // private forces the public and protected members to become private in the subclass.
    public:
        Mommabear(float aWeight);
        void SetCub(Bear *aCub);
        Bear *GetCub();
        virtual float Meanness(void);
        float TotalMeanness(void);

    protected:
        Bear *cub;
        // 얘는 여기에 float weight; 안 써도 되네

    public:
        static void TestBears(void);
};
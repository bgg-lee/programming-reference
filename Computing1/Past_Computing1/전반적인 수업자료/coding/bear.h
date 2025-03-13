#pragma once

class Bear{
    public:
        Bear(float aWeight);

        void SetWeight(float aWeight);
        float GetWeight(void);

        virtual float Meanness(void); // polymorphism
    protected:
        float weight;

};
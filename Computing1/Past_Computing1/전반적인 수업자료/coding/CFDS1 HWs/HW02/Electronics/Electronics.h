#pragma once

class Electronics{
    protected:
        int Size;
    public:
        int GetSize(void);
        void SetSize(int size);
        Electronics(int size);
        virtual float GetPrice()=0;
        virtual void PrintSelf(void)=0;
};


class TV : public Electronics{
    public:
        TV(int size);
        virtual void PrintSelf(void);
        virtual float GetPrice();
};

class Computer : public Electronics{
    public:
        Computer(int size);
        virtual void PrintSelf(void);
        virtual float GetPrice();
};

class Cellphone : public Electronics{
    public:
        Cellphone(int size);
        virtual void PrintSelf(void);
        virtual float GetPrice();
};

class Laptop : public Computer{
    public:
        Laptop(int size);
        Electronics* gpu1;
        Electronics* gpu2;
        int gpunum=0;
        void AddGPU(Electronics *aGPU); // laptop only, add GPUs
        float GetTotalPrice();
        virtual float GetPrice();
        virtual void PrintSelf(void);
};

class Account{
    public:
        Account(void);
        virtual void Withdraw(float amt);
        virtual void Deposit(float amt);
        virtual float GetBalance(float amt);
        virtual void EndMonth(void) = 0; // pure virtual, foce subclasses to implement

    protected:
        float balance;
        int transactions;
        void EndMonthUtil(void);

    private:
        static void TestOneMonth(void);
};
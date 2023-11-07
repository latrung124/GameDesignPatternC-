#include <iostream>
#include <memory>
#define STRATEGY
// #define NOSTRATEGY

#ifdef NOSTRATEGY
class PaymentSystem {
public:
    void processPaymentWithPayPal() {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }

    void processPaymentWithStripe() {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }

    void processPaymentWithSquare() {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
};
#endif // !1

#ifdef STRATEGY
class PaymentGateWay {
public:
    virtual void processPayment() = 0;
};

class PaypalGateway : public PaymentGateWay {
public:
    virtual void processPayment() override {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
};

class StripeGateway : public PaymentGateWay {
public:
    virtual void processPayment() override {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
};

class SquareGateway : public PaymentGateWay {
public:
    virtual void processPayment() override {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
};

class PaymentSystem {
private:
    PaymentGateWay* mPaymentGateway = nullptr;

public:
    PaymentGateWay* getPaymentGateway() {
        return mPaymentGateway;
    }
};
#endif
int main() {
#ifdef NOSTRATEGY
    PaymentSystem paymentSystem;
    paymentSystem.processPaymentWithPayPal();
    paymentSystem.processPaymentWithStripe();
    paymentSystem.processPaymentWithSquare();
#endif
#ifdef STRATEGY
    PaymentSystem paymentSystem;
    PaymentGateWay* paymentGateway = paymentSystem.getPaymentGateway();
    paymentGateway = new PaypalGateway();
    paymentGateway->processPayment();
    delete paymentGateway;

    paymentGateway = new SquareGateway();
    paymentGateway->processPayment();
    delete paymentGateway;

    paymentGateway = new StripeGateway();
    paymentGateway->processPayment();
    delete paymentGateway;
#endif
    return 0;
}
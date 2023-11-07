#include <iostream>
#include <memory>

enum eMainClass {
    E_SAMURAI_CLASS = 0,
    E_WARRIOR_CLASS,
    E_MONK_CLASS
};

class MainClass {
public:
    MainClass() {}
    virtual ~MainClass() {}

    virtual void behavior() = 0;
    virtual void inner_skill() = 0;
    virtual void class_skill() = 0;
};

class WarriorClass : public MainClass {
public:
    WarriorClass() {};
    virtual ~WarriorClass() {}

    virtual void behavior() override {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }

    virtual void inner_skill() override {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }

    virtual void class_skill() override {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
};

class SamuraiClass : public MainClass {
public:
    SamuraiClass() {};
    virtual ~SamuraiClass() {}

    virtual void behavior() override {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }

    virtual void inner_skill() override {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }

    virtual void class_skill() override {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
};

class MonkClass : public MainClass {
public:
    MonkClass() {};
    virtual ~MonkClass() {}

    virtual void behavior() override {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }

    virtual void inner_skill() override {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }

    virtual void class_skill() override {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
};

class MainClassFactory {
public:
    static MainClass* generateClass(eMainClass _class);
};

MainClass* MainClassFactory::generateClass(eMainClass _class) {
    MainClass* mainClass = nullptr;
    switch (_class)
    {
        case E_SAMURAI_CLASS:
            mainClass = new SamuraiClass();
            break;
        case E_WARRIOR_CLASS:
            mainClass = new WarriorClass();
            break;
        case E_MONK_CLASS:
            mainClass = new MonkClass();
            break;
        default:
            break;
    }
    return mainClass;
}

int main() {
    MainClassFactory::generateClass(E_SAMURAI_CLASS)->behavior();
    return 0;
}
#ifndef FACTORYTASK_TRANSPORT_H
#define FACTORYTASK_TRANSPORT_H


#include <string>
#include <utility>
#include <iostream>

// Базовый класс для транспорта
class Transport {
protected:
    std::string name;
    int wheels;
    int maxSpeed;
public:
    Transport(std::string  name, int wheels, int maxSpeed) : name(std::move(name)), wheels(wheels), maxSpeed(maxSpeed) {}

    virtual void displayParameters() const;
};

// Классы для различных типов транспорта
class Motorcycle : public Transport {
public:
    Motorcycle() : Transport("мотоцикл", 2, 200) {}
};

class Scooter : public Transport {
public:
    Scooter() : Transport("самокат", 2, 25) {}
};

class Car : public Transport {
public:
    Car() : Transport("автомобиль", 4, 150) {}
};

class Bus : public Transport {
private:
    int maxPassengers;
public:
    Bus() : Transport("автобус", 6, 100), maxPassengers(20) {}

    void displayParameters() const override;
};

// Класс фабрики для создания объектов транспорта
class TransportFactory {
public:
    static Transport* createTransport(int type) {
        switch (type) {
            case 0:
                return new Motorcycle();
            case 1:
                return new Scooter();
            case 2:
                return new Car();
            case 3:
                return new Bus();
            default:
                return nullptr;
        }
    }
};


#endif //FACTORYTASK_TRANSPORT_H

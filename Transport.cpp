#include "Transport.h"

void Transport::displayParameters() const {
    std::cout << "Наименование транспорта: " << name << "\n";
    std::cout << "Кол-во колес: " << wheels << "\n";
    std::cout << "Максимальная скорость: " << maxSpeed << "км/ч\n";
}

void Bus::displayParameters() const {
    Transport::displayParameters();
    std::cout << "Максимальное количество пассажиров: " << maxPassengers << "\n";
}

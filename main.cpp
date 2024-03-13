#include <iostream>
#include <map>
#include "Transport.h"

int main(int argc, char* argv[]) {
    system("chcp 65001");
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <transport_types>\n";
        return 1;
    }


    std::map<int, std::string> transportTypes = {
            {0, "мотоцикл"},
            {1, "самокат"},
            {2, "автомобиль"},
            {3, "автобус"}
    };

    for (int i = 1; i < argc; ++i) {
        int type;
        try {
            type = std::stoi(argv[i]);
        }
        catch (std::invalid_argument const& e) {
            std::cout << "Bad input: std::invalid_argument thrown" << std::endl;
        }
        catch (std::out_of_range const& e) {
            std::cout << "Integer overflow: std::out_of_range thrown" << std::endl;
        }
        Transport* transport = TransportFactory::createTransport(type);
        if (transport) {
            std::cout << "Параметры для типа транспорта: " << transportTypes[type] << "\n";
            transport->displayParameters();
            delete transport;
        }
        else {
            std::cerr << "НЕИЗВЕСТНЫЙ ТИП ТРАНСПОРТА\n";
        }
    }

    return 0;
}

#include <QApplication>
#include "GUI/CourierGUI.h"
#include "GUI/CompanyGUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repository* repository = new Repository();

    Service* service = new Service(repository);

    auto couriers = service->getCouriers();

    for (auto courier : couriers)
    {
        auto gui = new CourierGUI(service, courier);
        repository->addObserver(gui);
        gui->show();
    }

    auto companyGui = new CompanyGUI(service);
    repository->addObserver(companyGui);
    companyGui->show();

    return QApplication::exec();
    
}
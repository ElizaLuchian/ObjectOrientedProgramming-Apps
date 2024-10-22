// You may need to build the project (run Qt uic code generator) to get "ui_CourierGUI.h" resolved

#include "CourierGUI.h"
#include "ui_CourierGUI.h"
#include <vector>
#include <QComboBox>
#include <sstream>

using namespace std;

CourierGUI::CourierGUI(Service* _service, Courier courier, QWidget *parent) :
        QWidget(parent), ui(new Ui::CourierGUI), service{_service}, courier{courier} {
    ui->setupUi(this);

    this->setWindowTitle(courier.getName().c_str());


    ui->zoneLabel->setText(
            (to_string(courier.getZone().first) + " " + to_string(courier.getZone().second))
            .c_str());


    string streetsString = "";
    for (auto street : courier.getStreets())
    {
        streetsString = streetsString + " " + street;
    }
    ui->streetsLabel->setText(streetsString.c_str());


    update();



    auto streets = courier.getStreets();
    for (auto courierStreet : streets)
    {
        bool found = false;
        for (auto street : streets)
            if (courierStreet == street)
                found = true;
        if (!found)
            streets.push_back(courierStreet);
    }

    for (auto street : streets)
        ui->streetsComboBox->addItem(street.c_str());


    connect(ui->streetsComboBox, &QComboBox::activated, this, &CourierGUI::selectStreet);
    connect(ui->deliverButton, &QPushButton::clicked, this, &CourierGUI::deliverPackage);
}

CourierGUI::~CourierGUI() {
    delete ui;
}

void CourierGUI::selectStreet(int row)
{
    ui->packagesListWidget->clear();

    auto packages = service->getPackages();

    auto streets = courier.getStreets();

    for (auto package : packages) {
        if (package.isDelivered())
            continue;

        auto isAssignedStreet = package.getAddress() == streets[row];


        if (!package.isDelivered() && isAssignedStreet)
        {
            QListWidgetItem listWidgetItem;
            ui->packagesListWidget->addItem(package.toString().c_str());
        }
    }
}

void CourierGUI::deliverPackage()
{
    int selectedRow = ui->packagesListWidget->currentRow();
    auto selectedPackage = ui->packagesListWidget->currentItem()->text();

    stringstream ss(selectedPackage.toStdString());
    string word;
    getline(ss, word, ' ');

    service->deliverPackage(word);
}

void CourierGUI::update() {
    ui->packagesListWidget->clear();

    auto packages = service->getPackages();
    for (auto package : packages) {
        auto streets = courier.getStreets();
        int distanceToCenter = (package.getLocation().first - courier.getZone().first) * (package.getLocation().first - courier.getZone().first) +
                               + (package.getLocation().second - courier.getZone().first) * (package.getLocation().second - courier.getZone().first);

        auto isWithinZone = distanceToCenter < courier.getZone().second * courier.getZone().second;

        auto isAssignedStreet = false;

        for (auto street : streets)
            if(street == package.getAddress())
                isAssignedStreet = true;

        if (!package.isDelivered() && (isWithinZone || isAssignedStreet))
        {
            QListWidgetItem listWidgetItem;
            ui->packagesListWidget->addItem(package.toString().c_str());
        }
    }
}

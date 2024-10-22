// You may need to build the project (run Qt uic code generator) to get "ui_CompanyGUI.h" resolved

#include <QListWidgetItem>
#include "CompanyGUI.h"
#include "ui_CompanyGUI.h"


CompanyGUI::CompanyGUI(Service* _service, QWidget *parent) :
        QWidget(parent), ui(new Ui::CompanyGUI), service{_service} {
    ui->setupUi(this);

    this->setWindowTitle("Courier Company");

    update();

    connect(ui->addButton, &QPushButton::clicked, this, &CompanyGUI::addPackage);
}

CompanyGUI::~CompanyGUI() {
    delete ui;
}

void CompanyGUI::addPackage() {
    Package package;
    package.setRecipient(ui->recipientEdit->text().toStdString());
    package.setAddress(ui->addressEdit->text().toStdString());

    int x = atoi(ui->xEdit->text().toStdString().c_str());
    int y = atoi(ui->yEdit->text().toStdString().c_str());
    package.setLocation(x, y);
    package.setDeliveryStatus(false);

    service->addPackage(package);
}

void CompanyGUI::update() {
    ui->packagesListWidget->clear();

    auto packages = service->getPackages();
    for (auto package : packages) {
        QListWidgetItem* listWidgetItem = new QListWidgetItem(package.toString().c_str());
        if(package.isDelivered() == true)
            listWidgetItem->setBackground(QBrush(QColor(Qt::green)));
        ui->packagesListWidget->addItem(listWidgetItem);
    }
}



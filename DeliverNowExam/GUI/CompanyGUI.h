#pragma once

#include <QWidget>
#include "../Service/Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class CompanyGUI; }
QT_END_NAMESPACE

class CompanyGUI : public QWidget, public Observer  {
Q_OBJECT

public:
    explicit CompanyGUI(Service* service, QWidget *parent = nullptr);

    ~CompanyGUI() override;

    void addPackage();

    void update() override;

private:
    Ui::CompanyGUI *ui;
    Service *service;
};
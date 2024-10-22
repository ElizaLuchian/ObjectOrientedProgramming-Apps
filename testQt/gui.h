//
// Created by 40745 on 28/05/2024.
//

#ifndef TESTQT_GUI_H
#define TESTQT_GUI_H

#include <QWidget>
#include "Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget {
Q_OBJECT

public:
    explicit GUI(QWidget *parent = nullptr);
    void populateList();
    void slotsSignals();
    void Filter();
    void WeatherHours();
    ~GUI() override;


private:
    Ui::GUI *ui;
    Service serv;
};


#endif //TESTQT_GUI_H

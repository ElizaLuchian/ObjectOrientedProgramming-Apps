//
// Created by 40745 on 28/05/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include <QMessageBox>
#include "gui.h"
#include "ui_GUI.h"


GUI::GUI(QWidget *parent) :
        QWidget(parent), ui(new Ui::GUI), serv(){
    ui->setupUi(this);
    serv.readFromFile();
    this->populateList();
    this->slotsSignals();

}

GUI::~GUI() {
    delete ui;
}

void GUI::populateList() {

    vector<TimeInterval>arr=serv.getAll();
    this->ui->listWidget->clear();
    for(auto el: arr)
    {
        this->ui->listWidget->addItem("["+ QString::number(el.start) + "," + QString::number(el.end) + "]" + " " + QString::number(el.temperature) + " " + QString::number(el.precipitation) + " " + QString::fromStdString(el.description));
    }

}

void GUI::slotsSignals() {

    connect(this->ui->lineEdit, &QLineEdit::textChanged, this, &GUI::Filter);
    connect(this->ui->pushButton, &QPushButton::clicked, this, &GUI::WeatherHours);
}

void GUI::Filter() {
    QString text=this->ui->lineEdit->text();
    int textGood=text.toInt();
    vector<TimeInterval>arr=serv.filter(textGood);
    this->ui->listWidget_2->clear();
    for(auto el: arr)
    {
        this->ui->listWidget_2->addItem("[" + QString::number(el.start) + "," + QString::number(el.end) + "]" + " " + QString::number(el.temperature) + " " + QString::number(el.precipitation) + " " + QString::fromStdString(el.description));
    }


}

void GUI::WeatherHours() {
    QString text1=this->ui->lineEdit_2->text();
    string textGood1=text1.toStdString();
    QString text2=this->ui->lineEdit_3->text();
    int textGood2=text2.toInt();
    vector<TimeInterval>arr=serv.weatherAndHour(textGood1, textGood2);
    this->ui->listWidget_3->clear();
    for(auto el: arr)
    {
        this->ui->listWidget_3->addItem("["+ QString::number(el.start) + "," + QString::number(el.end) + "]" + " " + QString::number(el.temperature) + " " + QString::number(el.precipitation) + " " + QString::fromStdString(el.description));
    }
    int sum=serv.totalHours(textGood1, textGood2);
    string Sum=to_string(sum);
    this->ui->lineEdit_4->clear();
    if(sum!=0)
        this->ui->lineEdit_4->setText(Sum.c_str());
    else
    {
        QMessageBox bx;
        bx.setText("There are no intervals");
        bx.exec();
    }

}

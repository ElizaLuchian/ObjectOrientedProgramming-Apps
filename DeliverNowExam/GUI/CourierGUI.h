#include <QWidget>
#include "../Service/Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class CourierGUI; }
QT_END_NAMESPACE

class CourierGUI : public QWidget, public Observer {
Q_OBJECT

public:
    explicit CourierGUI(Service* service, Courier courier, QWidget *parent = nullptr);

    ~CourierGUI() override;

    void update() override;

private:
    Ui::CourierGUI *ui;

    Service* service;
    Courier courier;

    void selectStreet(int row);

    void deliverPackage();
};

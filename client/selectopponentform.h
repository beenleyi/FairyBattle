#ifndef SELECTOPPONENTFORM_H
#define SELECTOPPONENTFORM_H

#include <QWidget>
#include "userForm.h"
#include <QJsonObject>
#include <QJsonArray>
namespace Ui {
class selectOpponentForm;
}

class selectOpponentForm : public QWidget
{
    Q_OBJECT

public:
    explicit selectOpponentForm(QWidget *parent = 0);
    ~selectOpponentForm();
    void showMyFairy(fairy*);
private:
    Ui::selectOpponentForm *ui;
private slots:
    void showBattleFairy(QJsonObject*);
    void on_userFairies_comboBox_currentIndexChanged(const QString &arg1);
    void on_serverFairies_comboBox_currentIndexChanged(const QString &arg1);
    void on_upgradeBattle_pushButton_clicked();
    void on_winLoseBattle_pushButton_clicked();
signals:
    void gotoBattlefield(int,QJsonObject*,QJsonObject*);
};

#endif // SELECTOPPONENTFORM_H

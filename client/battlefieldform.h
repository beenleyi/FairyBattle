#ifndef BATTLEFIELDFORM_H
#define BATTLEFIELDFORM_H

#include <QWidget>
#include <QTimer>
#include <stdlib.h>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
class fairy;
namespace Ui {
class battlefieldForm;
}

class battlefieldForm : public QWidget
{
    Q_OBJECT

public:
    explicit battlefieldForm(QWidget *parent = 0);
    ~battlefieldForm();
    void setBattlefieldForm(int, QJsonObject*,QJsonObject*);

private:
    int battleType;
    Ui::battlefieldForm *ui;
    int getFairyIndex(QString *tempFairyName);
    fairy* myfairy;
    fairy* opponent;
    QString* getSkillName(int index);
    fairy* createFairy(QJsonObject*,int);
    QTimer* myAttackTimer;
    QTimer* opponentAttackTimer;
    int countAttack;
    int countHurt;
    QTimer* gameOverTimer;

    int gameIsOver;
private slots:
    void on_start_pushButton_clicked();
    void myTimetoAttack();
    void opponentTimetoAttack();
    void gameOver();
    void showBattleRes(QJsonObject*);
    void on_return_pushButton_clicked();
public:

signals:
    void battleEnd(int, int, int, int, QString*, QString*);
    void sendLoseAFairyBag(QJsonObject*);
    void showUserFormReq();
};

#endif // BATTLEFIELDFORM_H

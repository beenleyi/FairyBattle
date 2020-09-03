#ifndef BATTLEFIELDFORM_H
#define BATTLEFIELDFORM_H

#include <QWidget>
#include "userForm.h"
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
    Ui::battlefieldForm *ui;
    int getFairyIndex(QString *tempFairyName);

    QString* getSkillName(int index);
};

#endif // BATTLEFIELDFORM_H

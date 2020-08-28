#ifndef UPGRADEBATTLEFORM_H
#define UPGRADEBATTLEFORM_H

#include <QWidget>

namespace Ui {
class upgradeBattleForm;
}

class upgradeBattleForm : public QWidget
{
    Q_OBJECT

public:
    explicit upgradeBattleForm(QWidget *parent = 0);
    ~upgradeBattleForm();

private:
    Ui::upgradeBattleForm *ui;
};

#endif // UPGRADEBATTLEFORM_H

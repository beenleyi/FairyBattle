/********************************************************************************
** Form generated from reading UI file 'selectopponentform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTOPPONENTFORM_H
#define UI_SELECTOPPONENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectOpponentForm
{
public:
    QGridLayout *gridLayout;
    QPushButton *winloseBattle_pushButton;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *userFairies_comboBox;
    QTextBrowser *myFairy_textBrowser;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *serverFairies_comboBox;
    QTextBrowser *opponentFairy_textBrowser;
    QPushButton *upgradeBattle_pushButton;
    QPushButton *return_pushButton;

    void setupUi(QWidget *selectOpponentForm)
    {
        if (selectOpponentForm->objectName().isEmpty())
            selectOpponentForm->setObjectName(QStringLiteral("selectOpponentForm"));
        selectOpponentForm->resize(400, 300);
        gridLayout = new QGridLayout(selectOpponentForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        winloseBattle_pushButton = new QPushButton(selectOpponentForm);
        winloseBattle_pushButton->setObjectName(QStringLiteral("winloseBattle_pushButton"));

        gridLayout->addWidget(winloseBattle_pushButton, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(selectOpponentForm);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        userFairies_comboBox = new QComboBox(selectOpponentForm);
        userFairies_comboBox->setObjectName(QStringLiteral("userFairies_comboBox"));

        verticalLayout->addWidget(userFairies_comboBox);

        myFairy_textBrowser = new QTextBrowser(selectOpponentForm);
        myFairy_textBrowser->setObjectName(QStringLiteral("myFairy_textBrowser"));

        verticalLayout->addWidget(myFairy_textBrowser);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(selectOpponentForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        serverFairies_comboBox = new QComboBox(selectOpponentForm);
        serverFairies_comboBox->setObjectName(QStringLiteral("serverFairies_comboBox"));

        verticalLayout_2->addWidget(serverFairies_comboBox);

        opponentFairy_textBrowser = new QTextBrowser(selectOpponentForm);
        opponentFairy_textBrowser->setObjectName(QStringLiteral("opponentFairy_textBrowser"));

        verticalLayout_2->addWidget(opponentFairy_textBrowser);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        upgradeBattle_pushButton = new QPushButton(selectOpponentForm);
        upgradeBattle_pushButton->setObjectName(QStringLiteral("upgradeBattle_pushButton"));

        gridLayout->addWidget(upgradeBattle_pushButton, 2, 0, 1, 1);

        return_pushButton = new QPushButton(selectOpponentForm);
        return_pushButton->setObjectName(QStringLiteral("return_pushButton"));

        gridLayout->addWidget(return_pushButton, 3, 0, 1, 1);


        retranslateUi(selectOpponentForm);

        QMetaObject::connectSlotsByName(selectOpponentForm);
    } // setupUi

    void retranslateUi(QWidget *selectOpponentForm)
    {
        selectOpponentForm->setWindowTitle(QApplication::translate("selectOpponentForm", "Form", Q_NULLPTR));
        winloseBattle_pushButton->setText(QApplication::translate("selectOpponentForm", "Win-lose Battle", Q_NULLPTR));
        label->setText(QApplication::translate("selectOpponentForm", "Your Fairy", Q_NULLPTR));
        label_2->setText(QApplication::translate("selectOpponentForm", "Opponent", Q_NULLPTR));
        upgradeBattle_pushButton->setText(QApplication::translate("selectOpponentForm", "Upgrade Battle", Q_NULLPTR));
        return_pushButton->setText(QApplication::translate("selectOpponentForm", "return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class selectOpponentForm: public Ui_selectOpponentForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTOPPONENTFORM_H

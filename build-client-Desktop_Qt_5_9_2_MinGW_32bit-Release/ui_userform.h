/********************************************************************************
** Form generated from reading UI file 'userform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERFORM_H
#define UI_USERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userForm
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *tableTitle;
    QTableWidget *fairy_tableWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *username_label;
    QLabel *NumBadge_label;
    QLabel *StageBadge_label;
    QVBoxLayout *verticalLayout_3;
    QPushButton *myFairies_pushButton;
    QPushButton *battle_pushButton;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QPushButton *lookUpOnlineUsers_pushButton;
    QPushButton *lookUpAllUsers_pushButton;
    QPushButton *signOut_pushButton;

    void setupUi(QWidget *userForm)
    {
        if (userForm->objectName().isEmpty())
            userForm->setObjectName(QStringLiteral("userForm"));
        userForm->resize(400, 300);
        gridLayout = new QGridLayout(userForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableTitle = new QLabel(userForm);
        tableTitle->setObjectName(QStringLiteral("tableTitle"));
        tableTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(tableTitle);

        fairy_tableWidget = new QTableWidget(userForm);
        fairy_tableWidget->setObjectName(QStringLiteral("fairy_tableWidget"));

        verticalLayout_2->addWidget(fairy_tableWidget);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(userForm);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        username_label = new QLabel(userForm);
        username_label->setObjectName(QStringLiteral("username_label"));

        horizontalLayout->addWidget(username_label);


        verticalLayout_4->addLayout(horizontalLayout);

        NumBadge_label = new QLabel(userForm);
        NumBadge_label->setObjectName(QStringLiteral("NumBadge_label"));

        verticalLayout_4->addWidget(NumBadge_label);

        StageBadge_label = new QLabel(userForm);
        StageBadge_label->setObjectName(QStringLiteral("StageBadge_label"));

        verticalLayout_4->addWidget(StageBadge_label);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        myFairies_pushButton = new QPushButton(userForm);
        myFairies_pushButton->setObjectName(QStringLiteral("myFairies_pushButton"));

        verticalLayout_3->addWidget(myFairies_pushButton);

        battle_pushButton = new QPushButton(userForm);
        battle_pushButton->setObjectName(QStringLiteral("battle_pushButton"));

        verticalLayout_3->addWidget(battle_pushButton);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lookUpOnlineUsers_pushButton = new QPushButton(userForm);
        lookUpOnlineUsers_pushButton->setObjectName(QStringLiteral("lookUpOnlineUsers_pushButton"));

        verticalLayout->addWidget(lookUpOnlineUsers_pushButton);

        lookUpAllUsers_pushButton = new QPushButton(userForm);
        lookUpAllUsers_pushButton->setObjectName(QStringLiteral("lookUpAllUsers_pushButton"));

        verticalLayout->addWidget(lookUpAllUsers_pushButton);

        signOut_pushButton = new QPushButton(userForm);
        signOut_pushButton->setObjectName(QStringLiteral("signOut_pushButton"));

        verticalLayout->addWidget(signOut_pushButton);


        verticalLayout_4->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(verticalLayout_4);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(userForm);

        QMetaObject::connectSlotsByName(userForm);
    } // setupUi

    void retranslateUi(QWidget *userForm)
    {
        userForm->setWindowTitle(QApplication::translate("userForm", "Form", Q_NULLPTR));
        tableTitle->setText(QApplication::translate("userForm", "FAIRIES I HAVE", Q_NULLPTR));
        label->setText(QApplication::translate("userForm", "user", Q_NULLPTR));
        username_label->setText(QString());
        NumBadge_label->setText(QApplication::translate("userForm", "textlabel", Q_NULLPTR));
        StageBadge_label->setText(QApplication::translate("userForm", "TextLabel", Q_NULLPTR));
        myFairies_pushButton->setText(QApplication::translate("userForm", "My Fairies", Q_NULLPTR));
        battle_pushButton->setText(QApplication::translate("userForm", "Battle", Q_NULLPTR));
        lookUpOnlineUsers_pushButton->setText(QApplication::translate("userForm", "Look up online users", Q_NULLPTR));
        lookUpAllUsers_pushButton->setText(QApplication::translate("userForm", "Look up ALL users", Q_NULLPTR));
        signOut_pushButton->setText(QApplication::translate("userForm", "Sign out", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class userForm: public Ui_userForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERFORM_H

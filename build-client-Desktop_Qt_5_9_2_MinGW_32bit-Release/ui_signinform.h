/********************************************************************************
** Form generated from reading UI file 'signinform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINFORM_H
#define UI_SIGNINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signInForm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *global_verticalLayout;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *username_lineEdit;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QLineEdit *password_lineEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *signIn_pushButton;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QPushButton *signUp_pushButton;
    QHBoxLayout *horizontalLayout_5;

    void setupUi(QWidget *signInForm)
    {
        if (signInForm->objectName().isEmpty())
            signInForm->setObjectName(QStringLiteral("signInForm"));
        signInForm->resize(400, 300);
        gridLayout = new QGridLayout(signInForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        global_verticalLayout = new QVBoxLayout();
        global_verticalLayout->setObjectName(QStringLiteral("global_verticalLayout"));
        label_2 = new QLabel(signInForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        global_verticalLayout->addWidget(label_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        global_verticalLayout->addItem(verticalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(signInForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        username_lineEdit = new QLineEdit(signInForm);
        username_lineEdit->setObjectName(QStringLiteral("username_lineEdit"));

        horizontalLayout_2->addWidget(username_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_4 = new QLabel(signInForm);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        password_lineEdit = new QLineEdit(signInForm);
        password_lineEdit->setObjectName(QStringLiteral("password_lineEdit"));

        verticalLayout->addWidget(password_lineEdit);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        signIn_pushButton = new QPushButton(signInForm);
        signIn_pushButton->setObjectName(QStringLiteral("signIn_pushButton"));

        horizontalLayout_3->addWidget(signIn_pushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);


        global_verticalLayout->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(signInForm);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label);

        signUp_pushButton = new QPushButton(signInForm);
        signUp_pushButton->setObjectName(QStringLiteral("signUp_pushButton"));

        horizontalLayout_4->addWidget(signUp_pushButton);


        global_verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));

        global_verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(global_verticalLayout, 0, 0, 1, 1);


        retranslateUi(signInForm);

        QMetaObject::connectSlotsByName(signInForm);
    } // setupUi

    void retranslateUi(QWidget *signInForm)
    {
        signInForm->setWindowTitle(QApplication::translate("signInForm", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("signInForm", "Sign in to FairyBattle", Q_NULLPTR));
        label_3->setText(QApplication::translate("signInForm", "Username", Q_NULLPTR));
        label_4->setText(QApplication::translate("signInForm", "Password", Q_NULLPTR));
        signIn_pushButton->setText(QApplication::translate("signInForm", "Sign in", Q_NULLPTR));
        label->setText(QApplication::translate("signInForm", "New to FairyBattle?", Q_NULLPTR));
        signUp_pushButton->setText(QApplication::translate("signInForm", "Sign up", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class signInForm: public Ui_signInForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINFORM_H

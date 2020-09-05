/********************************************************************************
** Form generated from reading UI file 'signupform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPFORM_H
#define UI_SIGNUPFORM_H

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

class Ui_signUpForm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *username_lineEdit;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_4;
    QLineEdit *password_lineEdit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *signUp_pushButton;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QPushButton *signIn_pushButton;

    void setupUi(QWidget *signUpForm)
    {
        if (signUpForm->objectName().isEmpty())
            signUpForm->setObjectName(QStringLiteral("signUpForm"));
        signUpForm->resize(400, 300);
        gridLayout = new QGridLayout(signUpForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(signUpForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_3 = new QLabel(signUpForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        username_lineEdit = new QLineEdit(signUpForm);
        username_lineEdit->setObjectName(QStringLiteral("username_lineEdit"));

        horizontalLayout_2->addWidget(username_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_4 = new QLabel(signUpForm);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        password_lineEdit = new QLineEdit(signUpForm);
        password_lineEdit->setObjectName(QStringLiteral("password_lineEdit"));

        verticalLayout->addWidget(password_lineEdit);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        signUp_pushButton = new QPushButton(signUpForm);
        signUp_pushButton->setObjectName(QStringLiteral("signUp_pushButton"));

        horizontalLayout_3->addWidget(signUp_pushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(signUpForm);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label);

        signIn_pushButton = new QPushButton(signUpForm);
        signIn_pushButton->setObjectName(QStringLiteral("signIn_pushButton"));

        horizontalLayout_4->addWidget(signIn_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(signUpForm);

        QMetaObject::connectSlotsByName(signUpForm);
    } // setupUi

    void retranslateUi(QWidget *signUpForm)
    {
        signUpForm->setWindowTitle(QApplication::translate("signUpForm", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("signUpForm", "Sign up to FairyBattle", Q_NULLPTR));
        label_3->setText(QApplication::translate("signUpForm", "Username", Q_NULLPTR));
        label_4->setText(QApplication::translate("signUpForm", "Password", Q_NULLPTR));
        signUp_pushButton->setText(QApplication::translate("signUpForm", "Sign up", Q_NULLPTR));
        label->setText(QApplication::translate("signUpForm", "Already have an account?", Q_NULLPTR));
        signIn_pushButton->setText(QApplication::translate("signUpForm", "Sign in", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class signUpForm: public Ui_signUpForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPFORM_H

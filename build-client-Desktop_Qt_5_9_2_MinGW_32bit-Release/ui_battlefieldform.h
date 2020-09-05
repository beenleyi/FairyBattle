/********************************************************************************
** Form generated from reading UI file 'battlefieldform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLEFIELDFORM_H
#define UI_BATTLEFIELDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_battlefieldForm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *gameType_label;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *myFairyName_label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QLabel *myskill_label;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_13;
    QProgressBar *myBlood_progressBar;
    QLabel *myCase_label;
    QLabel *myFig_label;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *opponentName_label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_11;
    QLabel *opponent_skill;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_14;
    QProgressBar *opponentBlood_progressBar;
    QLabel *opponentCase_label;
    QLabel *opponentFig_label;
    QPushButton *start_pushButton;
    QPushButton *return_pushButton;

    void setupUi(QWidget *battlefieldForm)
    {
        if (battlefieldForm->objectName().isEmpty())
            battlefieldForm->setObjectName(QStringLiteral("battlefieldForm"));
        battlefieldForm->resize(400, 300);
        gridLayout = new QGridLayout(battlefieldForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gameType_label = new QLabel(battlefieldForm);
        gameType_label->setObjectName(QStringLiteral("gameType_label"));
        gameType_label->setMaximumSize(QSize(16777215, 15));
        gameType_label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(gameType_label);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(battlefieldForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        myFairyName_label = new QLabel(battlefieldForm);
        myFairyName_label->setObjectName(QStringLiteral("myFairyName_label"));

        horizontalLayout->addWidget(myFairyName_label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_9 = new QLabel(battlefieldForm);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_2->addWidget(label_9);

        myskill_label = new QLabel(battlefieldForm);
        myskill_label->setObjectName(QStringLiteral("myskill_label"));

        horizontalLayout_2->addWidget(myskill_label);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_13 = new QLabel(battlefieldForm);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_6->addWidget(label_13);

        myBlood_progressBar = new QProgressBar(battlefieldForm);
        myBlood_progressBar->setObjectName(QStringLiteral("myBlood_progressBar"));
        myBlood_progressBar->setValue(24);

        horizontalLayout_6->addWidget(myBlood_progressBar);


        verticalLayout->addLayout(horizontalLayout_6);

        myCase_label = new QLabel(battlefieldForm);
        myCase_label->setObjectName(QStringLiteral("myCase_label"));

        verticalLayout->addWidget(myCase_label);

        myFig_label = new QLabel(battlefieldForm);
        myFig_label->setObjectName(QStringLiteral("myFig_label"));

        verticalLayout->addWidget(myFig_label);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(battlefieldForm);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        opponentName_label = new QLabel(battlefieldForm);
        opponentName_label->setObjectName(QStringLiteral("opponentName_label"));

        horizontalLayout_3->addWidget(opponentName_label);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_11 = new QLabel(battlefieldForm);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_4->addWidget(label_11);

        opponent_skill = new QLabel(battlefieldForm);
        opponent_skill->setObjectName(QStringLiteral("opponent_skill"));

        horizontalLayout_4->addWidget(opponent_skill);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_14 = new QLabel(battlefieldForm);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_7->addWidget(label_14);

        opponentBlood_progressBar = new QProgressBar(battlefieldForm);
        opponentBlood_progressBar->setObjectName(QStringLiteral("opponentBlood_progressBar"));
        opponentBlood_progressBar->setValue(24);

        horizontalLayout_7->addWidget(opponentBlood_progressBar);


        verticalLayout_2->addLayout(horizontalLayout_7);

        opponentCase_label = new QLabel(battlefieldForm);
        opponentCase_label->setObjectName(QStringLiteral("opponentCase_label"));

        verticalLayout_2->addWidget(opponentCase_label);

        opponentFig_label = new QLabel(battlefieldForm);
        opponentFig_label->setObjectName(QStringLiteral("opponentFig_label"));

        verticalLayout_2->addWidget(opponentFig_label);


        horizontalLayout_5->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_5);

        start_pushButton = new QPushButton(battlefieldForm);
        start_pushButton->setObjectName(QStringLiteral("start_pushButton"));

        verticalLayout_3->addWidget(start_pushButton);

        return_pushButton = new QPushButton(battlefieldForm);
        return_pushButton->setObjectName(QStringLiteral("return_pushButton"));

        verticalLayout_3->addWidget(return_pushButton);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(battlefieldForm);

        QMetaObject::connectSlotsByName(battlefieldForm);
    } // setupUi

    void retranslateUi(QWidget *battlefieldForm)
    {
        battlefieldForm->setWindowTitle(QApplication::translate("battlefieldForm", "Form", Q_NULLPTR));
        gameType_label->setText(QApplication::translate("battlefieldForm", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("battlefieldForm", "My Fairy:", Q_NULLPTR));
        myFairyName_label->setText(QApplication::translate("battlefieldForm", "Fairy Name", Q_NULLPTR));
        label_9->setText(QApplication::translate("battlefieldForm", "Skill:", Q_NULLPTR));
        myskill_label->setText(QApplication::translate("battlefieldForm", "Skill Name", Q_NULLPTR));
        label_13->setText(QApplication::translate("battlefieldForm", "Blood:", Q_NULLPTR));
        myCase_label->setText(QApplication::translate("battlefieldForm", "case", Q_NULLPTR));
        myFig_label->setText(QApplication::translate("battlefieldForm", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("battlefieldForm", "Opponent Fairy:", Q_NULLPTR));
        opponentName_label->setText(QApplication::translate("battlefieldForm", "Fairy Name", Q_NULLPTR));
        label_11->setText(QApplication::translate("battlefieldForm", "Skill:", Q_NULLPTR));
        opponent_skill->setText(QApplication::translate("battlefieldForm", "Skill Name", Q_NULLPTR));
        label_14->setText(QApplication::translate("battlefieldForm", "Blood", Q_NULLPTR));
        opponentCase_label->setText(QApplication::translate("battlefieldForm", "case", Q_NULLPTR));
        opponentFig_label->setText(QApplication::translate("battlefieldForm", "TextLabel", Q_NULLPTR));
        start_pushButton->setText(QApplication::translate("battlefieldForm", "Start to battle", Q_NULLPTR));
        return_pushButton->setText(QApplication::translate("battlefieldForm", "return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class battlefieldForm: public Ui_battlefieldForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLEFIELDFORM_H

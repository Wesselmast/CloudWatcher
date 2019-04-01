/********************************************************************************
** Form generated from reading UI file 'renderingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDERINGWINDOW_H
#define UI_RENDERINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenderingWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSlider *AggresivenessSlider;
    QLabel *label_2;
    QSlider *IrregularitySlider;
    QLabel *label_3;
    QSlider *ComplexitySlider;
    QPushButton *generateButton;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *RenderingWindow)
    {
        if (RenderingWindow->objectName().isEmpty())
            RenderingWindow->setObjectName(QString::fromUtf8("RenderingWindow"));
        RenderingWindow->resize(742, 599);
        centralWidget = new QWidget(RenderingWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setContextMenuPolicy(Qt::NoContextMenu);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label);

        AggresivenessSlider = new QSlider(groupBox);
        AggresivenessSlider->setObjectName(QString::fromUtf8("AggresivenessSlider"));
        AggresivenessSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(AggresivenessSlider);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label_2);

        IrregularitySlider = new QSlider(groupBox);
        IrregularitySlider->setObjectName(QString::fromUtf8("IrregularitySlider"));
        IrregularitySlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(IrregularitySlider);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label_3);

        ComplexitySlider = new QSlider(groupBox);
        ComplexitySlider->setObjectName(QString::fromUtf8("ComplexitySlider"));
        ComplexitySlider->setMinimum(5);
        ComplexitySlider->setMaximum(30);
        ComplexitySlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(ComplexitySlider);

        generateButton = new QPushButton(groupBox);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        sizePolicy1.setHeightForWidth(generateButton->sizePolicy().hasHeightForWidth());
        generateButton->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(generateButton);


        horizontalLayout->addWidget(groupBox);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(graphicsView);

        RenderingWindow->setCentralWidget(centralWidget);

        retranslateUi(RenderingWindow);

        QMetaObject::connectSlotsByName(RenderingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RenderingWindow)
    {
        RenderingWindow->setWindowTitle(QApplication::translate("RenderingWindow", "RenderingWindow", nullptr));
        groupBox->setTitle(QApplication::translate("RenderingWindow", "Shape Designer", nullptr));
        label->setText(QApplication::translate("RenderingWindow", "Aggresiveness", nullptr));
        label_2->setText(QApplication::translate("RenderingWindow", "Irregularity", nullptr));
        label_3->setText(QApplication::translate("RenderingWindow", "Complexity", nullptr));
        generateButton->setText(QApplication::translate("RenderingWindow", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RenderingWindow: public Ui_RenderingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERINGWINDOW_H

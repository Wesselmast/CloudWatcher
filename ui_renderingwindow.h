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
#include <QtWidgets/QGridLayout>
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
    QPushButton *exportButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QSlider *AggresivenessSmallSlider;
    QLabel *label_3;
    QLabel *label;
    QSlider *ComplexitySmallSlider;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QSlider *ComplexityMediumSlider;
    QLabel *label_7;
    QSlider *AggresivenessMediumSlider;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QSlider *ComplexityBigSlider;
    QLabel *label_8;
    QLabel *label_10;
    QSlider *AggresivenessBigSlider;
    QLabel *label_4;
    QSlider *LineThickSlider;
    QPushButton *randomizeButton;
    QPushButton *generateButton;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *RenderingWindow)
    {
        if (RenderingWindow->objectName().isEmpty())
            RenderingWindow->setObjectName(QString::fromUtf8("RenderingWindow"));
        RenderingWindow->resize(968, 701);
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
        exportButton = new QPushButton(groupBox);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(exportButton->sizePolicy().hasHeightForWidth());
        exportButton->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(exportButton);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        AggresivenessSmallSlider = new QSlider(groupBox_2);
        AggresivenessSmallSlider->setObjectName(QString::fromUtf8("AggresivenessSmallSlider"));
        AggresivenessSmallSlider->setMaximum(70);
        AggresivenessSmallSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(AggresivenessSmallSlider, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        ComplexitySmallSlider = new QSlider(groupBox_2);
        ComplexitySmallSlider->setObjectName(QString::fromUtf8("ComplexitySmallSlider"));
        ComplexitySmallSlider->setMinimum(4);
        ComplexitySmallSlider->setMaximum(15);
        ComplexitySmallSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(ComplexitySmallSlider, 3, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        ComplexityMediumSlider = new QSlider(groupBox_3);
        ComplexityMediumSlider->setObjectName(QString::fromUtf8("ComplexityMediumSlider"));
        ComplexityMediumSlider->setMinimum(4);
        ComplexityMediumSlider->setMaximum(25);
        ComplexityMediumSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(ComplexityMediumSlider, 5, 0, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_7, 4, 0, 1, 1);

        AggresivenessMediumSlider = new QSlider(groupBox_3);
        AggresivenessMediumSlider->setObjectName(QString::fromUtf8("AggresivenessMediumSlider"));
        AggresivenessMediumSlider->setMaximum(90);
        AggresivenessMediumSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(AggresivenessMediumSlider, 2, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        ComplexityBigSlider = new QSlider(groupBox_4);
        ComplexityBigSlider->setObjectName(QString::fromUtf8("ComplexityBigSlider"));
        ComplexityBigSlider->setMinimum(4);
        ComplexityBigSlider->setMaximum(25);
        ComplexityBigSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(ComplexityBigSlider, 3, 0, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        AggresivenessBigSlider = new QSlider(groupBox_4);
        AggresivenessBigSlider->setObjectName(QString::fromUtf8("AggresivenessBigSlider"));
        AggresivenessBigSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(AggresivenessBigSlider, 1, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_4);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label_4);

        LineThickSlider = new QSlider(groupBox);
        LineThickSlider->setObjectName(QString::fromUtf8("LineThickSlider"));
        LineThickSlider->setMinimum(2);
        LineThickSlider->setMaximum(15);
        LineThickSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(LineThickSlider);

        randomizeButton = new QPushButton(groupBox);
        randomizeButton->setObjectName(QString::fromUtf8("randomizeButton"));
        sizePolicy1.setHeightForWidth(randomizeButton->sizePolicy().hasHeightForWidth());
        randomizeButton->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(randomizeButton);

        generateButton = new QPushButton(groupBox);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        sizePolicy2.setHeightForWidth(generateButton->sizePolicy().hasHeightForWidth());
        generateButton->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(generateButton);


        horizontalLayout->addWidget(groupBox);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(graphicsView);

        RenderingWindow->setCentralWidget(centralWidget);

        retranslateUi(RenderingWindow);

        QMetaObject::connectSlotsByName(RenderingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RenderingWindow)
    {
        RenderingWindow->setWindowTitle(QApplication::translate("RenderingWindow", "CloudWatcher", nullptr));
        groupBox->setTitle(QApplication::translate("RenderingWindow", "Shape Designer", nullptr));
        exportButton->setText(QApplication::translate("RenderingWindow", "Export", nullptr));
        groupBox_2->setTitle(QApplication::translate("RenderingWindow", "Small", nullptr));
        label_3->setText(QApplication::translate("RenderingWindow", "Complexity", nullptr));
        label->setText(QApplication::translate("RenderingWindow", "Aggressiveness", nullptr));
        groupBox_3->setTitle(QApplication::translate("RenderingWindow", "Medium", nullptr));
        label_5->setText(QApplication::translate("RenderingWindow", "Aggressiveness", nullptr));
        label_7->setText(QApplication::translate("RenderingWindow", "Complexity", nullptr));
        groupBox_4->setTitle(QApplication::translate("RenderingWindow", "Big", nullptr));
        label_8->setText(QApplication::translate("RenderingWindow", "Aggressiveness", nullptr));
        label_10->setText(QApplication::translate("RenderingWindow", "Complexity", nullptr));
        label_4->setText(QApplication::translate("RenderingWindow", "Line thickness", nullptr));
        randomizeButton->setText(QApplication::translate("RenderingWindow", "Randomize", nullptr));
        generateButton->setText(QApplication::translate("RenderingWindow", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RenderingWindow: public Ui_RenderingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERINGWINDOW_H

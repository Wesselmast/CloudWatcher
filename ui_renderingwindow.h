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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenderingWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_4;
    QLabel *label_12;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QSlider *ComplexityMediumSlider;
    QLabel *label_14;
    QSpinBox *AmountOfMediumShapes;
    QSlider *AggresivenessMediumSlider;
    QLabel *label_5;
    QLabel *label_7;
    QSlider *CurvynessMediumlSlider;
    QLabel *label_17;
    QLabel *label_6;
    QSlider *RadiusMediumSlider;
    QLabel *label_11;
    QPushButton *exportButton;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QLabel *label_18;
    QSlider *CurvynessBigSlider;
    QSlider *AggresivenessBigSlider;
    QSlider *ComplexityBigSlider;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_15;
    QLabel *label_8;
    QSpinBox *AmountOfBigShapes;
    QSlider *RadiusBigSlider;
    QSlider *LineThickSlider;
    QPushButton *generateButton;
    QLabel *label_19;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_13;
    QSpinBox *AmountOfSmallShapes;
    QLabel *label_16;
    QSlider *RadiusSmallSlider;
    QLabel *label;
    QSlider *AggresivenessSmallSlider;
    QLabel *label_2;
    QSlider *CurvynessSmallSlider;
    QLabel *label_3;
    QSlider *ComplexitySmallSlider;
    QPushButton *randomizeButton;
    QLabel *label_4;
    QSlider *VerticalDiagonalSlider;
    QSlider *CenterOfBalanceSlider;
    QSlider *OuterMarginSlider;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *RenderingWindow)
    {
        if (RenderingWindow->objectName().isEmpty())
            RenderingWindow->setObjectName(QString::fromUtf8("RenderingWindow"));
        RenderingWindow->resize(968, 701);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RenderingWindow->sizePolicy().hasHeightForWidth());
        RenderingWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(RenderingWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(150, 0));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -355, 133, 1085));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 7, 0, 1, 1);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ComplexityMediumSlider = new QSlider(groupBox_3);
        ComplexityMediumSlider->setObjectName(QString::fromUtf8("ComplexityMediumSlider"));
        ComplexityMediumSlider->setMinimum(4);
        ComplexityMediumSlider->setMaximum(25);
        ComplexityMediumSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(ComplexityMediumSlider, 10, 0, 1, 1);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 0, 0, 1, 1);

        AmountOfMediumShapes = new QSpinBox(groupBox_3);
        AmountOfMediumShapes->setObjectName(QString::fromUtf8("AmountOfMediumShapes"));
        AmountOfMediumShapes->setMinimumSize(QSize(50, 20));
        AmountOfMediumShapes->setMaximumSize(QSize(50, 20));
        AmountOfMediumShapes->setMaximum(10);
        AmountOfMediumShapes->setValue(5);

        gridLayout_2->addWidget(AmountOfMediumShapes, 1, 0, 1, 1);

        AggresivenessMediumSlider = new QSlider(groupBox_3);
        AggresivenessMediumSlider->setObjectName(QString::fromUtf8("AggresivenessMediumSlider"));
        AggresivenessMediumSlider->setMaximum(90);
        AggresivenessMediumSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(AggresivenessMediumSlider, 6, 0, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(label_7, 9, 0, 1, 1);

        CurvynessMediumlSlider = new QSlider(groupBox_3);
        CurvynessMediumlSlider->setObjectName(QString::fromUtf8("CurvynessMediumlSlider"));
        CurvynessMediumlSlider->setMinimum(1);
        CurvynessMediumlSlider->setMaximum(10);
        CurvynessMediumlSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(CurvynessMediumlSlider, 8, 0, 1, 1);

        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_2->addWidget(label_17, 2, 0, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 7, 0, 1, 1);

        RadiusMediumSlider = new QSlider(groupBox_3);
        RadiusMediumSlider->setObjectName(QString::fromUtf8("RadiusMediumSlider"));
        RadiusMediumSlider->setMinimum(15);
        RadiusMediumSlider->setMaximum(60);
        RadiusMediumSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(RadiusMediumSlider, 3, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 2, 0, 1, 1);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 4, 0, 1, 1);

        exportButton = new QPushButton(scrollAreaWidgetContents);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));
        sizePolicy3.setHeightForWidth(exportButton->sizePolicy().hasHeightForWidth());
        exportButton->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(exportButton, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 2, 0, 1, 1);

        CurvynessBigSlider = new QSlider(groupBox_4);
        CurvynessBigSlider->setObjectName(QString::fromUtf8("CurvynessBigSlider"));
        CurvynessBigSlider->setMinimum(1);
        CurvynessBigSlider->setMaximum(10);
        CurvynessBigSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(CurvynessBigSlider, 7, 0, 1, 1);

        AggresivenessBigSlider = new QSlider(groupBox_4);
        AggresivenessBigSlider->setObjectName(QString::fromUtf8("AggresivenessBigSlider"));
        AggresivenessBigSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(AggresivenessBigSlider, 5, 0, 1, 1);

        ComplexityBigSlider = new QSlider(groupBox_4);
        ComplexityBigSlider->setObjectName(QString::fromUtf8("ComplexityBigSlider"));
        ComplexityBigSlider->setMinimum(4);
        ComplexityBigSlider->setMaximum(25);
        ComplexityBigSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(ComplexityBigSlider, 9, 0, 1, 1);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy4.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(label_10, 8, 0, 1, 1);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 6, 0, 1, 1);

        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 0, 0, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(label_8, 4, 0, 1, 1);

        AmountOfBigShapes = new QSpinBox(groupBox_4);
        AmountOfBigShapes->setObjectName(QString::fromUtf8("AmountOfBigShapes"));
        AmountOfBigShapes->setMaximumSize(QSize(50, 20));
        AmountOfBigShapes->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        AmountOfBigShapes->setMaximum(10);
        AmountOfBigShapes->setValue(5);

        gridLayout_3->addWidget(AmountOfBigShapes, 1, 0, 1, 1);

        RadiusBigSlider = new QSlider(groupBox_4);
        RadiusBigSlider->setObjectName(QString::fromUtf8("RadiusBigSlider"));
        RadiusBigSlider->setMinimum(30);
        RadiusBigSlider->setMaximum(120);
        RadiusBigSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(RadiusBigSlider, 3, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_4, 3, 0, 1, 1);

        LineThickSlider = new QSlider(scrollAreaWidgetContents);
        LineThickSlider->setObjectName(QString::fromUtf8("LineThickSlider"));
        LineThickSlider->setMinimum(2);
        LineThickSlider->setMaximum(15);
        LineThickSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(LineThickSlider, 12, 0, 1, 1);

        generateButton = new QPushButton(scrollAreaWidgetContents);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(generateButton->sizePolicy().hasHeightForWidth());
        generateButton->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(generateButton, 14, 0, 1, 1);

        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_4->addWidget(label_19, 9, 0, 1, 1);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 0, 0, 1, 1);

        AmountOfSmallShapes = new QSpinBox(groupBox_2);
        AmountOfSmallShapes->setObjectName(QString::fromUtf8("AmountOfSmallShapes"));
        sizePolicy3.setHeightForWidth(AmountOfSmallShapes->sizePolicy().hasHeightForWidth());
        AmountOfSmallShapes->setSizePolicy(sizePolicy3);
        AmountOfSmallShapes->setMinimumSize(QSize(50, 20));
        AmountOfSmallShapes->setMaximum(10);
        AmountOfSmallShapes->setValue(5);

        gridLayout->addWidget(AmountOfSmallShapes, 1, 0, 1, 1);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 2, 0, 1, 1);

        RadiusSmallSlider = new QSlider(groupBox_2);
        RadiusSmallSlider->setObjectName(QString::fromUtf8("RadiusSmallSlider"));
        RadiusSmallSlider->setMinimum(5);
        RadiusSmallSlider->setMaximum(25);
        RadiusSmallSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(RadiusSmallSlider, 3, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label, 4, 0, 1, 1);

        AggresivenessSmallSlider = new QSlider(groupBox_2);
        AggresivenessSmallSlider->setObjectName(QString::fromUtf8("AggresivenessSmallSlider"));
        AggresivenessSmallSlider->setMaximum(70);
        AggresivenessSmallSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(AggresivenessSmallSlider, 5, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 6, 0, 1, 1);

        CurvynessSmallSlider = new QSlider(groupBox_2);
        CurvynessSmallSlider->setObjectName(QString::fromUtf8("CurvynessSmallSlider"));
        CurvynessSmallSlider->setMinimum(1);
        CurvynessSmallSlider->setMaximum(10);
        CurvynessSmallSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(CurvynessSmallSlider, 7, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_3, 8, 0, 1, 1);

        ComplexitySmallSlider = new QSlider(groupBox_2);
        ComplexitySmallSlider->setObjectName(QString::fromUtf8("ComplexitySmallSlider"));
        ComplexitySmallSlider->setMinimum(4);
        ComplexitySmallSlider->setMaximum(15);
        ComplexitySmallSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(ComplexitySmallSlider, 9, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        randomizeButton = new QPushButton(scrollAreaWidgetContents);
        randomizeButton->setObjectName(QString::fromUtf8("randomizeButton"));
        sizePolicy3.setHeightForWidth(randomizeButton->sizePolicy().hasHeightForWidth());
        randomizeButton->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(randomizeButton, 13, 0, 1, 1);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(label_4, 11, 0, 1, 1);

        VerticalDiagonalSlider = new QSlider(scrollAreaWidgetContents);
        VerticalDiagonalSlider->setObjectName(QString::fromUtf8("VerticalDiagonalSlider"));
        VerticalDiagonalSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(VerticalDiagonalSlider, 10, 0, 1, 1);

        CenterOfBalanceSlider = new QSlider(scrollAreaWidgetContents);
        CenterOfBalanceSlider->setObjectName(QString::fromUtf8("CenterOfBalanceSlider"));
        CenterOfBalanceSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(CenterOfBalanceSlider, 8, 0, 1, 1);

        OuterMarginSlider = new QSlider(scrollAreaWidgetContents);
        OuterMarginSlider->setObjectName(QString::fromUtf8("OuterMarginSlider"));
        OuterMarginSlider->setMinimum(-40);
        OuterMarginSlider->setMaximum(60);
        OuterMarginSlider->setValue(-40);
        OuterMarginSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(OuterMarginSlider, 6, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy6);

        horizontalLayout->addWidget(graphicsView);

        RenderingWindow->setCentralWidget(centralWidget);

        retranslateUi(RenderingWindow);

        QMetaObject::connectSlotsByName(RenderingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RenderingWindow)
    {
        RenderingWindow->setWindowTitle(QApplication::translate("RenderingWindow", "CloudWatcher", nullptr));
        label_12->setText(QApplication::translate("RenderingWindow", "Center of Balance", nullptr));
        groupBox_3->setTitle(QApplication::translate("RenderingWindow", "Medium Shapes", nullptr));
        label_14->setText(QApplication::translate("RenderingWindow", "Amount", nullptr));
        label_5->setText(QApplication::translate("RenderingWindow", "Spikeyness", nullptr));
        label_7->setText(QApplication::translate("RenderingWindow", "Complexity", nullptr));
        label_17->setText(QApplication::translate("RenderingWindow", "Radius", nullptr));
        label_6->setText(QApplication::translate("RenderingWindow", "Curvyness", nullptr));
        label_11->setText(QApplication::translate("RenderingWindow", "Spacing", nullptr));
        exportButton->setText(QApplication::translate("RenderingWindow", "Export", nullptr));
        groupBox_4->setTitle(QApplication::translate("RenderingWindow", "Big Shapes", nullptr));
        label_18->setText(QApplication::translate("RenderingWindow", "Radius", nullptr));
        label_10->setText(QApplication::translate("RenderingWindow", "Complexity", nullptr));
        label_9->setText(QApplication::translate("RenderingWindow", "Curvyness", nullptr));
        label_15->setText(QApplication::translate("RenderingWindow", "Amount", nullptr));
        label_8->setText(QApplication::translate("RenderingWindow", "Spikeyness", nullptr));
        generateButton->setText(QApplication::translate("RenderingWindow", "Generate", nullptr));
        label_19->setText(QApplication::translate("RenderingWindow", "Vertical / Diagonal", nullptr));
        groupBox_2->setTitle(QApplication::translate("RenderingWindow", "Small Shapes", nullptr));
        label_13->setText(QApplication::translate("RenderingWindow", "Amount", nullptr));
        label_16->setText(QApplication::translate("RenderingWindow", "Radius", nullptr));
        label->setText(QApplication::translate("RenderingWindow", "Spikeyness", nullptr));
        label_2->setText(QApplication::translate("RenderingWindow", "Curvyness", nullptr));
        label_3->setText(QApplication::translate("RenderingWindow", "Complexity", nullptr));
        randomizeButton->setText(QApplication::translate("RenderingWindow", "Randomize", nullptr));
        label_4->setText(QApplication::translate("RenderingWindow", "Line thickness", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RenderingWindow: public Ui_RenderingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERINGWINDOW_H

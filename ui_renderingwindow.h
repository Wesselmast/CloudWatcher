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
#include <QtWidgets/QFormLayout>
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
    QFormLayout *formLayout;
    QPushButton *exportButton;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLabel *label_13;
    QSpinBox *AmountOfSmallShapes;
    QLabel *label;
    QSlider *AggresivenessSmallSlider;
    QLabel *label_2;
    QSlider *CurvynessSmallSlider;
    QLabel *label_3;
    QSlider *ComplexitySmallSlider;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QSlider *AggresivenessMediumSlider;
    QSlider *ComplexityMediumSlider;
    QSlider *CurvynessMediumlSlider;
    QLabel *label_5;
    QLabel *label_14;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *AmountOfMediumShapes;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QSlider *CurvynessBigSlider;
    QSlider *AggresivenessBigSlider;
    QLabel *label_9;
    QSlider *ComplexityBigSlider;
    QLabel *label_10;
    QLabel *label_8;
    QLabel *label_15;
    QSpinBox *AmountOfBigShapes;
    QLabel *label_11;
    QSlider *OuterMarginSlider;
    QLabel *label_12;
    QSlider *CenterOfBalanceSlider;
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
        scrollAreaWidgetContents->setGeometry(QRect(0, -226, 133, 909));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        exportButton = new QPushButton(scrollAreaWidgetContents);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(exportButton->sizePolicy().hasHeightForWidth());
        exportButton->setSizePolicy(sizePolicy3);

        formLayout->setWidget(0, QFormLayout::LabelRole, exportButton);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_13);

        AmountOfSmallShapes = new QSpinBox(groupBox_2);
        AmountOfSmallShapes->setObjectName(QString::fromUtf8("AmountOfSmallShapes"));
        sizePolicy3.setHeightForWidth(AmountOfSmallShapes->sizePolicy().hasHeightForWidth());
        AmountOfSmallShapes->setSizePolicy(sizePolicy3);
        AmountOfSmallShapes->setMinimumSize(QSize(50, 20));
        AmountOfSmallShapes->setMaximum(10);
        AmountOfSmallShapes->setValue(5);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, AmountOfSmallShapes);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label);

        AggresivenessSmallSlider = new QSlider(groupBox_2);
        AggresivenessSmallSlider->setObjectName(QString::fromUtf8("AggresivenessSmallSlider"));
        AggresivenessSmallSlider->setMaximum(70);
        AggresivenessSmallSlider->setOrientation(Qt::Horizontal);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, AggresivenessSmallSlider);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_2);

        CurvynessSmallSlider = new QSlider(groupBox_2);
        CurvynessSmallSlider->setObjectName(QString::fromUtf8("CurvynessSmallSlider"));
        CurvynessSmallSlider->setMinimum(1);
        CurvynessSmallSlider->setMaximum(10);
        CurvynessSmallSlider->setOrientation(Qt::Horizontal);

        formLayout_2->setWidget(6, QFormLayout::LabelRole, CurvynessSmallSlider);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_3);

        ComplexitySmallSlider = new QSlider(groupBox_2);
        ComplexitySmallSlider->setObjectName(QString::fromUtf8("ComplexitySmallSlider"));
        ComplexitySmallSlider->setMinimum(4);
        ComplexitySmallSlider->setMaximum(15);
        ComplexitySmallSlider->setOrientation(Qt::Horizontal);

        formLayout_2->setWidget(8, QFormLayout::LabelRole, ComplexitySmallSlider);


        formLayout->setWidget(2, QFormLayout::LabelRole, groupBox_2);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        AggresivenessMediumSlider = new QSlider(groupBox_3);
        AggresivenessMediumSlider->setObjectName(QString::fromUtf8("AggresivenessMediumSlider"));
        AggresivenessMediumSlider->setMaximum(90);
        AggresivenessMediumSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(AggresivenessMediumSlider, 4, 0, 1, 1);

        ComplexityMediumSlider = new QSlider(groupBox_3);
        ComplexityMediumSlider->setObjectName(QString::fromUtf8("ComplexityMediumSlider"));
        ComplexityMediumSlider->setMinimum(4);
        ComplexityMediumSlider->setMaximum(25);
        ComplexityMediumSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(ComplexityMediumSlider, 8, 0, 1, 1);

        CurvynessMediumlSlider = new QSlider(groupBox_3);
        CurvynessMediumlSlider->setObjectName(QString::fromUtf8("CurvynessMediumlSlider"));
        CurvynessMediumlSlider->setMinimum(1);
        CurvynessMediumlSlider->setMaximum(10);
        CurvynessMediumlSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(CurvynessMediumlSlider, 6, 0, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 5, 0, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(label_7, 7, 0, 1, 1);

        AmountOfMediumShapes = new QSpinBox(groupBox_3);
        AmountOfMediumShapes->setObjectName(QString::fromUtf8("AmountOfMediumShapes"));
        AmountOfMediumShapes->setMinimumSize(QSize(50, 20));
        AmountOfMediumShapes->setMaximumSize(QSize(50, 20));
        AmountOfMediumShapes->setMaximum(10);
        AmountOfMediumShapes->setValue(5);

        gridLayout_2->addWidget(AmountOfMediumShapes, 1, 0, 1, 1);


        formLayout->setWidget(3, QFormLayout::LabelRole, groupBox_3);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        CurvynessBigSlider = new QSlider(groupBox_4);
        CurvynessBigSlider->setObjectName(QString::fromUtf8("CurvynessBigSlider"));
        CurvynessBigSlider->setMinimum(1);
        CurvynessBigSlider->setMaximum(10);
        CurvynessBigSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(CurvynessBigSlider, 5, 0, 1, 1);

        AggresivenessBigSlider = new QSlider(groupBox_4);
        AggresivenessBigSlider->setObjectName(QString::fromUtf8("AggresivenessBigSlider"));
        AggresivenessBigSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(AggresivenessBigSlider, 3, 0, 1, 1);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 4, 0, 1, 1);

        ComplexityBigSlider = new QSlider(groupBox_4);
        ComplexityBigSlider->setObjectName(QString::fromUtf8("ComplexityBigSlider"));
        ComplexityBigSlider->setMinimum(4);
        ComplexityBigSlider->setMaximum(25);
        ComplexityBigSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(ComplexityBigSlider, 7, 0, 1, 1);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy4.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(label_10, 6, 0, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 0, 0, 1, 1);

        AmountOfBigShapes = new QSpinBox(groupBox_4);
        AmountOfBigShapes->setObjectName(QString::fromUtf8("AmountOfBigShapes"));
        AmountOfBigShapes->setMaximumSize(QSize(50, 20));
        AmountOfBigShapes->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        AmountOfBigShapes->setMaximum(10);
        AmountOfBigShapes->setValue(5);

        gridLayout_3->addWidget(AmountOfBigShapes, 1, 0, 1, 1);


        formLayout->setWidget(4, QFormLayout::LabelRole, groupBox_4);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_11);

        OuterMarginSlider = new QSlider(scrollAreaWidgetContents);
        OuterMarginSlider->setObjectName(QString::fromUtf8("OuterMarginSlider"));
        OuterMarginSlider->setMinimum(0);
        OuterMarginSlider->setMaximum(99);
        OuterMarginSlider->setValue(0);
        OuterMarginSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(6, QFormLayout::LabelRole, OuterMarginSlider);

        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_12);

        CenterOfBalanceSlider = new QSlider(scrollAreaWidgetContents);
        CenterOfBalanceSlider->setObjectName(QString::fromUtf8("CenterOfBalanceSlider"));
        CenterOfBalanceSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(8, QFormLayout::LabelRole, CenterOfBalanceSlider);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);

        formLayout->setWidget(9, QFormLayout::LabelRole, label_4);

        LineThickSlider = new QSlider(scrollAreaWidgetContents);
        LineThickSlider->setObjectName(QString::fromUtf8("LineThickSlider"));
        LineThickSlider->setMinimum(2);
        LineThickSlider->setMaximum(15);
        LineThickSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(10, QFormLayout::LabelRole, LineThickSlider);

        randomizeButton = new QPushButton(scrollAreaWidgetContents);
        randomizeButton->setObjectName(QString::fromUtf8("randomizeButton"));
        sizePolicy3.setHeightForWidth(randomizeButton->sizePolicy().hasHeightForWidth());
        randomizeButton->setSizePolicy(sizePolicy3);

        formLayout->setWidget(11, QFormLayout::LabelRole, randomizeButton);

        generateButton = new QPushButton(scrollAreaWidgetContents);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(generateButton->sizePolicy().hasHeightForWidth());
        generateButton->setSizePolicy(sizePolicy5);

        formLayout->setWidget(12, QFormLayout::SpanningRole, generateButton);

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
        exportButton->setText(QApplication::translate("RenderingWindow", "Export", nullptr));
        groupBox_2->setTitle(QApplication::translate("RenderingWindow", "Small", nullptr));
        label_13->setText(QApplication::translate("RenderingWindow", "Amount", nullptr));
        label->setText(QApplication::translate("RenderingWindow", "Spikeyness", nullptr));
        label_2->setText(QApplication::translate("RenderingWindow", "Curvyness", nullptr));
        label_3->setText(QApplication::translate("RenderingWindow", "Complexity", nullptr));
        groupBox_3->setTitle(QApplication::translate("RenderingWindow", "Medium", nullptr));
        label_5->setText(QApplication::translate("RenderingWindow", "Spikeyness", nullptr));
        label_14->setText(QApplication::translate("RenderingWindow", "Amount", nullptr));
        label_6->setText(QApplication::translate("RenderingWindow", "Curvyness", nullptr));
        label_7->setText(QApplication::translate("RenderingWindow", "Complexity", nullptr));
        groupBox_4->setTitle(QApplication::translate("RenderingWindow", "Big", nullptr));
        label_9->setText(QApplication::translate("RenderingWindow", "Curvyness", nullptr));
        label_10->setText(QApplication::translate("RenderingWindow", "Complexity", nullptr));
        label_8->setText(QApplication::translate("RenderingWindow", "Spikeyness", nullptr));
        label_15->setText(QApplication::translate("RenderingWindow", "Amount", nullptr));
        label_11->setText(QApplication::translate("RenderingWindow", "Spacing", nullptr));
        label_12->setText(QApplication::translate("RenderingWindow", "Center of Balance", nullptr));
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

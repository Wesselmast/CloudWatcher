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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenderingWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSlider *verticalSlider;
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
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalSlider->sizePolicy().hasHeightForWidth());
        verticalSlider->setSizePolicy(sizePolicy);
        verticalSlider->setMaximum(99);
        verticalSlider->setSingleStep(1);
        verticalSlider->setPageStep(1);
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider);

        generateButton = new QPushButton(centralWidget);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(generateButton->sizePolicy().hasHeightForWidth());
        generateButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(generateButton);

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
        generateButton->setText(QApplication::translate("RenderingWindow", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RenderingWindow: public Ui_RenderingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERINGWINDOW_H

#include "notewidget.h"
#include "ui_notewidget.h"

#include <QFile>

NoteWidget::NoteWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NoteWidget)
{
    ui->setupUi(this);
    readLoginWidgetQss();
}

NoteWidget::~NoteWidget()
{
    delete ui;
}

void NoteWidget::readLoginWidgetQss()
{
    QFile file(":/Qss/note/default.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    this->setStyleSheet(styleSheet);
    file.close();
}

#include "uniblog.h"
#include "ui_uniblog.h"

#include <QFile>
#include <QGridLayout>
#include <QDebug>
#include <QLineEdit>
#include <QSplitter>
#include <QScrollBar>
#include "MyWidgets/NoteWidget/notewidget.h"
UniBlog::UniBlog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UniBlog)
{
    ui->setupUi(this);
    readUniBlogWidgetQss();
    initUniBlog();
}

UniBlog::~UniBlog()
{
    delete ui;
}
//------------------------------------------------------------------
/*                          窗口移动重写                             */
void UniBlog::mouseMoveEvent(QMouseEvent *e)
{
    if (m_mousePressed && (e->buttons() && Qt::LeftButton)) {
        this->move(e->globalPos() - mousePoint);
        e->accept();
    }
}
void UniBlog::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        m_mousePressed = true;
        mousePoint = e->globalPos() - this->pos();
        e->accept();
    }
}
void UniBlog::mouseReleaseEvent(QMouseEvent *)
{
    m_mousePressed = false;
}
//------------------------------------------------------------------
void UniBlog::on_needDealBt_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void UniBlog::on_accelerateBt_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void UniBlog::readUniBlogWidgetQss()
{
    //这是在Qt的资源下的文件,可以不用在资源下
    QFile file(":/Qss/Uniblog/default.qss");
    //只读方式打开文件
    file.open(QFile::ReadOnly);
    //读取文件的所有内容，并转换成QString类型
    QString styleSheet = tr(file.readAll());
    //当前窗口设置样式表
    this->setStyleSheet(styleSheet);
    file.close();

    QFile file1(":/Qss/util/QScrollBar.qss");
    file1.open(QFile::ReadOnly);
    QString styleSheet1 = tr(file1.readAll());
    ui->notelistWidget->verticalScrollBar()->setStyleSheet(styleSheet1);
    file1.close();
}

void UniBlog::initUniBlog()
{
    //设置无边框
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    QAction *searchAction = new QAction(ui->searchlineEdit);
    searchAction->setIcon(QIcon(":/Image/Uniblog/搜索.png"));
    ui->searchlineEdit->addAction(searchAction,QLineEdit::LeadingPosition);
}

void UniBlog::on_newBuildBt_clicked()
{
    NoteWidget* note = new NoteWidget();
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(QSize(note->width(),note->height()));
    ui->notelistWidget->addItem(item);
    ui->notelistWidget->setItemWidget(item,note);
    ui->notelistWidget->update();
}

void UniBlog::on_closeBt_clicked()
{
    this->close();
}

void UniBlog::on_zoomBt_clicked()
{
    if(widgetChange)
    {
        this->setWindowState(Qt::WindowMaximized);
        ui->zoomBt->setStyleSheet("border-image: url(:/Image/Uniblog/最大化.png);");
    }
    else
    {
        this->showNormal();
        ui->zoomBt->setStyleSheet("border-image: url(:/Image/Uniblog/全屏.png);");
    }
    widgetChange = widgetChange ? false : true;
}

void UniBlog::on_minimizeBt_clicked()
{
    this->showMinimized();
}

#ifndef UNIBLOG_H
#define UNIBLOG_H

#include <QMainWindow>
#include <QMouseEvent>
namespace Ui {
class UniBlog;
}

class UniBlog : public QMainWindow
{
    Q_OBJECT

public:
    explicit UniBlog(QWidget *parent = 0);
    ~UniBlog();
protected:
    QPoint mousePoint;
    bool m_mousePressed;
    void mouseMoveEvent(QMouseEvent *e);//鼠标移动事件
    void mousePressEvent(QMouseEvent *e);//鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *);//鼠标松开事件
private slots:
    void on_needDealBt_clicked();

    void on_accelerateBt_clicked();
    void on_newBuildBt_clicked();

    void on_closeBt_clicked();

    void on_zoomBt_clicked();

    void on_minimizeBt_clicked();

private:
    void readUniBlogWidgetQss();
    void initUniBlog();
private:
    Ui::UniBlog *ui;
    //窗口缩放
    bool widgetChange;
};

#endif // UNIBLOG_H

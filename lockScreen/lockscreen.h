#ifndef LOCKSCREEN_H
#define LOCKSCREEN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class lockScreen; }
QT_END_NAMESPACE

class lockScreen : public QMainWindow
{
    Q_OBJECT

public:
    lockScreen(QWidget *parent = nullptr);
    ~lockScreen();

//protected:
//    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_pushButton_clicked();

    void on_Pin0_cursorPositionChanged();
    void on_Pin1_cursorPositionChanged();
    void on_Pin2_cursorPositionChanged();
    void on_Pin3_cursorPositionChanged();




private:
    Ui::lockScreen *ui;
};
#endif // LOCKSCREEN_H

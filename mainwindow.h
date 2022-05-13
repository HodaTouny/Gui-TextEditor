#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionMerge_triggered();

    void on_actionNum_of_Words_triggered();

    void on_actionNum_of_lines_triggered();

    void on_actionNum_of_characters_triggered();

    void on_actionSearch_a_word_triggered();

    void on_actioncount_the_times_the_word_exist_triggered();

    void on_actionEncrypt_triggered();

    void on_actionDecrypt_triggered();

    void on_actionEmpty_the_file_triggered();

    void on_actionAdd_Text_triggered();

    void on_actionAll_Upper_triggered();

    void on_actionAll_Lower_triggered();

    void on_actionFirst_Upper_triggered();

private:
    Ui::MainWindow *ui;
    QString filestream;
};
#endif // MAINWINDOW_H

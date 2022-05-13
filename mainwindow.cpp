#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QInputDialog>
#include<QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    filestream ="";
    ui->textEdit->setText("");

}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(filename);
    filestream = filename;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{

    QFile file(filestream);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();

}


void MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,"Open the file");
    QFile file(filename);
    filestream = filename;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}
 // lesa
void MainWindow::on_actionMerge_triggered()
{    QString string,text2,res;
    QFile file(filestream);


    QString filename2 = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file2(filename2);
    if(!(file.open(QFile::ReadOnly | QFile::Text) && file2.open(QFile::ReadOnly | QFile::Text))){
        QMessageBox::warning(this,"..","problem in opening one of the two files");
        return;
    }
    QTextStream read(&file);
    string = read.readAll();

     QTextStream read2(&file2);
     text2 = read2.readAll();

     res=string + text2;
     ui->textEdit->setText(res);


    file.flush();
    file.close();
    file2.close();


}


void MainWindow::on_actionNum_of_Words_triggered()
{
    int count = 1;
    QString string;
    QFile file(filestream);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QTextStream read(&file);
    string = read.readAll();

    for(int i =0 ; i<string.size()-3;i++){
        if(string[i] == ' ' || string[i] == '\n'){
            count++;
    }
    }

    file.close();
    QString message =QString::number(count);
    QMessageBox:: warning(this,"number of words = ",message);
}


void MainWindow::on_actionNum_of_lines_triggered()
{
    int count =0;
    QFile file(filestream);
    if(file.open(QFile::ReadOnly | QFile::Text)){
        QTextStream take(&file);
        while(!take.atEnd()){
            take.readLine();
            count++;
        }

    }
    file.close();
    QString message =QString::number(count);
    QMessageBox:: warning(this,"number of Lines = ",message);

}


void MainWindow::on_actionNum_of_characters_triggered()
{
    int count =0;
    QString string = ui->textEdit->toPlainText();
    for(int i=0;i<string.size();i++){
        count++;
    }    QString message =QString::number(count);
    QMessageBox:: warning(this,"number of characters = ",message);
}


void MainWindow::on_actionSearch_a_word_triggered()
{
    QString word = QInputDialog ::getText(this,"Search","Enter the word");
    QString string = ui->textEdit->toPlainText();

     if(string.contains(word)){
           QMessageBox:: information(this,"Search","The word Exist" );
     }else{
         QMessageBox:: information(this,"..","The word does not Exist" );
     }
}


void MainWindow::on_actioncount_the_times_the_word_exist_triggered()
{
    QString word = QInputDialog ::getText(this,"Count","Enter the word");
    QString string = ui->textEdit->toPlainText();
    if(string.contains(word)){
         QString s = QString::number(string.count(word));
          QMessageBox::information(this,"Times = ",s );
    }else{
        QMessageBox:: information(this,"..","The word does not Exist" );
    }
}


void MainWindow::on_actionEncrypt_triggered()
{
    QString encrtext="";
    QString string = ui->textEdit->toPlainText();
    for(int i = 0;i<string.size();i++){
        if(string[i] =='z'){
            encrtext +='a';
        }else if(string[i]=='Z'){
            encrtext+='A';
        }else{
            int chara = string[i].unicode();
            encrtext +=(QChar)(chara+1);
        }

    }
    ui->textEdit->setText(encrtext);
}


void MainWindow::on_actionDecrypt_triggered()
{
    QString decrtext="";
    QString string = ui->textEdit->toPlainText();
    for(int i = 0;i<string.size();i++){
        if(string[i] =='a'){
            decrtext +='z';
        }else if(string[i]=='A'){
            decrtext+='Z';
        }else{
            int chara = string[i].unicode();
            decrtext +=(QChar)(chara-1);
        }

    }
    ui->textEdit->setText(decrtext);

}


void MainWindow::on_actionEmpty_the_file_triggered()
{
    QString delet =" ";
     ui->textEdit->setText(delet);
}


void MainWindow::on_actionAdd_Text_triggered()
{
    QFile file(filestream);
    QString text = QInputDialog ::getText(this,"text","Enter the text you want to add");

    if(!(file.open(QIODevice::WriteOnly | QIODevice::Append) )){
        QMessageBox::warning(this,"..","problem in opening the file");
        return;
    }
    ui-> textEdit->insertPlainText (text);

    file.flush();
    file.close();

}


void MainWindow::on_actionAll_Upper_triggered()
{
    QFile file(filestream);
    QString string = ui->textEdit->toPlainText();
    QString upper ="";
    for(int i = 0;i<string.size();i++){
        upper+= string[i].toUpper();
    }
    ui->textEdit->setText(upper);

}


void MainWindow::on_actionAll_Lower_triggered()
{
    QFile file(filestream);
    QString string = ui->textEdit->toPlainText();
    QString lower ="";
    for(int i = 0;i<string.size();i++){
        lower+= string[i].toLower();
    }
    ui->textEdit->setText(lower);
}


void MainWindow::on_actionFirst_Upper_triggered()
{
    QFile file(filestream);
    QString string = ui->textEdit->toPlainText();
    QString newtext =" ";
    for(int i = 0 ; i<string.size();i++){
        if(string[i] == ' '){
            newtext += string[i+1].toUpper();
            i++;
        }else{
        newtext += string[i];
       }}


    ui->textEdit->setText(newtext);
}


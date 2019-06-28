#include "file.h"
#include "ui_file.h"
#include <QPushButton>
#include <mainwindow.h>
#include <ui_mainwindow.h>

int call[11];
File::File(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::File)
{
    ui->setupUi(this);
    for (int i=0;i<11;i++){
        check[i]=call[i];
    }
}

File::~File()
{
    delete ui;
}

/* Метод, вызывающий диалоговое окно выбора файла для чтения данных */
void File::on_dialogReadButton_clicked()
{
    /* Вызываем диалог выбора файла для чтения */
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Xml"), ".", tr("Xml files (*.xml)"));
   /* Устанавливаем в lineEditRead путь к файлу, с которым будем работать */
    if(filename != ""){
        ui->lineEditRead->setText(filename);
    }
}

void File::on_readButton_clicked()
{


    /* Открываем файл для Чтения с помощью пути, указанного в lineEditWrite */
    QFile file(ui->lineEditRead->text());
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,
                             "Ошибка файла",
                             "Не удалось открыть файл",
                             QMessageBox::Ok);
    } else {
        /* Создаем объект, с помощью которого осуществляется чтение из файла */
        QXmlStreamReader xmlReader;
        xmlReader.setDevice(&file);
        xmlReader.readNext();   // Переходит к первому элементу в файле

        /* Крутимся в цикле до тех пор, пока не достигнем конца документа */
        while(!xmlReader.atEnd())
        {
            /* Проверяем, является ли элемент началом тега */
            if(xmlReader.isStartElement())
            {
                /* Проверяем, относится ли тег к одному из чекбоксов. Если "ДА", то выполняем проверку атрибута чекбокса и записи для lineEdit */
                if(xmlReader.name() == "node_0")
                {
                    /* Забираем все атрибуты тега и перебираем их для проверки на соответствие нужному нам атрибуту */
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                        /* Если найден нужный атрибут, то по его значению устанавливаем состояние чекбокса */
                        if (attr.value().toString() == "true"){
                            call[0]=1;
                        }
                    }
                }
                else if(xmlReader.name() == "prog_0")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                        if (attr.value().toString() == "true") {
                            call[1]=1;
                        }
                    }
                }
                else if(xmlReader.name() == "con_0")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                        if (attr.value().toString() == "true") {
                            call[2]=1;
                        }
                    }
                }
                else if(xmlReader.name() == "con_3")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                        if (attr.value().toString() == "true") {
                            call[3]=1;
                        }
                    }
                }
                else if(xmlReader.name() == "prog_2")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                        if (attr.value().toString() == "true") {
                            call[4]=1;
                        }
                    }
                }
                else if(xmlReader.name() == "node_1")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                        if (attr.value().toString() == "true") {
                            call[5]=1;
                        }
                    }
                }
                else if(xmlReader.name() == "prog_1")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                        if (attr.value().toString() == "true") {
                            call[6]=1;
                        }
                    }
                }
                else if(xmlReader.name() == "con_1")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                        if (attr.value().toString() == "true") {
                            call[7]=1;
                        }
                    }
                }
                else if(xmlReader.name() == "node_2")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                        if (attr.value().toString() == "true") {
                            call[8]=1;
                        }
                    }
                }
                else if(xmlReader.name() == "prog_3")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                        if (attr.value().toString() == "true") {
                            call[9]=1;
                        }
                    }
                }
                else if(xmlReader.name() == "con_2")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                        if (attr.value().toString() == "true") {
                            call[10]=1;
                        }
                    }
                }
            }
            xmlReader.readNext(); // Переходим к следующему элементу файла
        }
        file.close(); // Закрываем файл
    }
    MainWindow *w = new MainWindow(this);
    w->show();
}


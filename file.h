#ifndef FILE_H
#define FILE_H

#include <QDialog>
#include <QFileDialog>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QMessageBox>
#include <QFile>

namespace Ui {
class File;
}
class File : public QDialog
{
    Q_OBJECT

public:
    explicit File(QWidget *parent = nullptr);
    int check[11];
    File *file;
    ~File();

private:
    Ui::File *ui;
private slots:
    void on_dialogReadButton_clicked();
    void on_readButton_clicked();
};

extern int call[11];

#endif // FILE_H

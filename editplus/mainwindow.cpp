#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QTreeWidget>
#include <QVector>
#include <QHash>
#include <QTreeWidgetItem>
#include "file.h"
#include <QScrollBar>
#include <QFontDatabase>
#include <QLabel>
#include <QToolBar>
#include <QSpacerItem>


class Path_data
{
public:
    static QString path;
};

void func01(QStringList dirs,QString path,QHash<QString,QStringList>& hash);
void func00(QString dir,QString path,QHash<QString,QStringList> &hash)
{
    QDir dir00(path+"/"+dir);
    QStringList _files=dir00.entryList(QDir::Files);
    QStringList _dirs=dir00.entryList(QDir::Dirs|QDir::NoDotAndDotDot);
    hash[path+"/"+dir]=_dirs+_files;
    return func01(_dirs,dir00.path(),hash);
}
void func01(QStringList dirs,QString path,QHash<QString,QStringList>& hash)
{

    for(int i=0;i<dirs.size();i++)
    {
        func00(dirs.at(i),path,hash);
    }

}

void func02(QString key,QTreeWidgetItem* &___qtreewidgetitem1,QHash<QString,QStringList> &hash,QTreeWidgetItem* __qtreewidgetitem)
{
    if(hash.count(key)==0)
    {
        return;
    }
    else
    {
        QTreeWidgetItem* ___qQTreeWidgetItem1;
        QTreeWidgetItem* ___qtreewidgetitem2;
        QVector<QString> v;
        QVector<QTreeWidgetItem*> v1;
        QString key1;
        for(int j=0;j<hash[key].size();j++)
        {
            ___qQTreeWidgetItem1=new QTreeWidgetItem(__qtreewidgetitem);
            ___qtreewidgetitem2 = ___qtreewidgetitem1->child(j);
            ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow",hash[key][j].toStdString().c_str(), nullptr));
            key1=key+"/"+hash[key][j];
            if(hash.count(key1)!=0)
            {
                v.push_back(key1);
                v1.push_back(___qtreewidgetitem2);
                v1.push_back(___qQTreeWidgetItem1);
            }

        }
        for(int i=0;i<v.size();i++)
        {
            return func02(v[i],v1[i*2],hash,v1[i*2+1]);
        }

    }

}

void filetree(Ui::MainWindow* &ui,QTreeWidgetItem* &___qtreewidgetitem)
{

    QFile file("./aa.txt");
    file.open(QIODeviceBase::ReadOnly|QIODeviceBase::Text);
    QString addr;
    addr=file.readLine();
    QString aaaa="";
    if(addr==aaaa)
    {
        file.close();
        return;
    }
    file.close();

    QString aa="Project   "+addr;
    ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow",aa.toStdString().c_str(), nullptr));

    QDir dir(addr);
    QStringList files=dir.entryList(QDir::Files);
    QStringList dirs=dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot);
    QVector<QString> key;
    // QString path=dir.path();
    QHash<QString,QStringList> hash;
    func01(dirs,dir.path(),hash);


    const bool __sortingEnabled = ui->treeWidget->isSortingEnabled();
    ui->treeWidget->setSortingEnabled(false);
    int i=0;
    if(dirs.size()==0||files.size()==0)
    {
        QFileInfo f(addr);
        QString filename=f.fileName();
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(ui->treeWidget);
        QTreeWidgetItem *___qtreewidgetitem1 = (QTreeWidgetItem*)ui->treeWidget->topLevelItem(i);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow",filename.toStdString().c_str(), nullptr));
        // ___qtreewidgetitem1->absloute_path_=addr;
        return;
    }


    while(dirs.size()-i)
    {
        // qDebug()<<dirs.at(i);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(ui->treeWidget);
        QTreeWidgetItem *___qtreewidgetitem1 = (QTreeWidgetItem*)ui->treeWidget->topLevelItem(i);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow",dirs.at(i).toStdString().c_str(), nullptr));
        // ___qtreewidgetitem1->absloute_path_=addr+"/"+dirs.at(i);
        func02(dir.path()+"/"+dirs[i],___qtreewidgetitem1,hash,__qtreewidgetitem);
        i++;
    }
    for(int ii=0;ii<files.size();ii++)
    {
        new QTreeWidgetItem(ui->treeWidget);
        QTreeWidgetItem *___qtreewidgetitem1 = (QTreeWidgetItem*)ui->treeWidget->topLevelItem(ii+dirs.size());
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow",files.at(ii).toStdString().c_str(), nullptr));
        // ___qtreewidgetitem1->absloute_path_=addr+"/"+files.at(ii);
    }

    // new QTreeWidgetItem(treeWidget);
    ui->treeWidget->setSortingEnabled(__sortingEnabled);


}

void save_file(QString &path,Ui::MainWindow* &ui)
{
    QString content=ui->plainTextEdit->toPlainText();
    QFile file(Path_data::path);
    file.open(QIODeviceBase::WriteOnly|QIODeviceBase::Text);
    file.write(content.toStdString().c_str());
    file.close();
}

QString Path_data::path="";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    int fontId = QFontDatabase::addApplicationFont(":/font/fonts/ttf/JetBrainsMono-Regular.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font(fontName, 12);
    ui->setupUi(this);

    ui->plainTextEdit->setFont(font);
    QApplication::setFont(font);

    this->setCentralWidget(ui->plainTextEdit);
    this->___qtreewidgetitem = ui->treeWidget->headerItem();
    this->___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "project    ", nullptr));

    filetree(ui,this->___qtreewidgetitem);
    QFont font__=ui->plainTextEdit->font();
    ui->plainTextEdit->setTabStopDistance(font__.pointSize()*3);
    ui->plainTextEdit->setReadOnly(true);


    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    tool_label->setText("not file open");

    int wid=ui->dockWidget->width();
    widget_1->setFixedWidth(wid*2.7);
    QWidget* widget_2=new QWidget(this);
    widget_2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    toolBar->addWidget(widget_1);
    toolBar->addWidget(tool_label);
    toolBar->addWidget(widget_2);
    this->addToolBar(Qt::TopToolBarArea, toolBar);
    toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));

    connect(ui->actionopen_file,&QAction::triggered,this,open_file_triggerd);
    connect(ui->actionopen_directory,&QAction::triggered,this,open_dir_triggerd);
    // connect(ui->dockWidget,&QDockWidget::resize,this,dockwidget_size_slot);
}



void MainWindow::open_file_triggerd()
{
    QFile file2("./aa.txt");
    file2.open(QIODeviceBase::ReadOnly|QIODeviceBase::Text);
    QString addr=file2.readLine();
    file2.close();
    QString filename=QFileDialog::getOpenFileName(this,"open file",addr,"汇编文件(*.asm)");
    if(!filename.isEmpty())
    {
        file2.open(QIODeviceBase::WriteOnly|QIODeviceBase::Text);
        file2.write(filename.toStdString().c_str());
        file2.close();
        ui->treeWidget->clear();
        filetree(this->ui,this->___qtreewidgetitem);
    }


}

void MainWindow::open_dir_triggerd()
{
    QFile file2("./aa.txt");
    file2.open(QIODeviceBase::ReadOnly|QIODeviceBase::Text);
    QString addr=file2.readLine();
    file2.close();
    QFileInfo fileinfo(addr.toStdString().c_str());
    QString filename=QFileDialog::getExistingDirectory(this,"open directory",fileinfo.path());
    if(!filename.isEmpty())
    {
        file2.open(QIODeviceBase::WriteOnly|QIODeviceBase::Text);
        file2.write(filename.toStdString().c_str());
        file2.close();
        ui->treeWidget->clear();
        filetree(this->ui,this->___qtreewidgetitem);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QString path=item->text(0);
    QString name=path;
    while(item->parent())
    {
        item=item->parent();
        path=item->text(0)+"/"+path;
    }

    QFile file1("./aa.txt");
    file1.open(QIODeviceBase::ReadOnly|QIODeviceBase::Text);

    QString addr_=file1.readLine();

    path=addr_+"/"+path;
    file1.close();
    QFileInfo fileinfo(path);
    if(fileinfo.isFile()==false)
        return;
    if(Path_data::path!="")
        save_file(Path_data::path,ui);
    tool_label->setText(name.toStdString().c_str());
    Path_data::path=path;
    ui->plainTextEdit->setReadOnly(false);
    QFile file2(path);
    file2.open(QIODeviceBase::ReadWrite|QIODeviceBase::Text);
    QString buffer;
    int i=0;
    QString str;
    ui->plainTextEdit->clear();
    while(1)
    {
        buffer=file2.readLine();
        str+=buffer;
        if(buffer=="")
            break;
        i++;
        if(i%200==0 && i!=0)
            ui->plainTextEdit->appendPlainText(str);
    }
    if(i%50!=0)
        ui->plainTextEdit->appendPlainText(str);

    file2.close();
}

void MainWindow::dockwidget_size_slot()
{
    int wid=this->ui->dockWidget->width();
    this->widget_1->setFixedWidth(wid*2.7);
}




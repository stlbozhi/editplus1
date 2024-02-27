#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include<QTreeWidgetItem>
#include <QLabel>
#include <QToolBar>


// class TreeWidgetItem_:public QTreeWidgetItem
// {
// public:
//     explicit TreeWidgetItem_(int type = Type):QTreeWidgetItem(type){};
//     explicit TreeWidgetItem_(const QStringList &strings, int type = Type):QTreeWidgetItem( strings, type){}
//     explicit TreeWidgetItem_(QTreeWidget *treeview, int type = Type):QTreeWidgetItem(treeview, type){}
//     TreeWidgetItem_(QTreeWidget *treeview, const QStringList &strings, int type = Type):QTreeWidgetItem(treeview,strings,type){}
//     TreeWidgetItem_(QTreeWidget *treeview, QTreeWidgetItem *after, int type = Type):QTreeWidgetItem(treeview,after,type ){}
//     explicit TreeWidgetItem_(QTreeWidgetItem *parent, int type = Type):QTreeWidgetItem(parent, type){}
//     TreeWidgetItem_(QTreeWidgetItem *parent, const QStringList &strings, int type = Type):QTreeWidgetItem(parent,strings, type){}
//     TreeWidgetItem_(QTreeWidgetItem *parent, QTreeWidgetItem *after, int type = Type):QTreeWidgetItem(parent,after,type){}
//     TreeWidgetItem_(const QTreeWidgetItem &other):QTreeWidgetItem(other){}
//     QString absloute_path_;

//     TreeWidgetItem_* child(int index) const
//     {
//         TreeWidgetItem_* a=(TreeWidgetItem_*)this->QTreeWidgetItem::child(index);
//         return a;
//     }

// };

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTreeWidgetItem* ___qtreewidgetitem;
    QToolBar* toolBar = new QToolBar(this);
    QLabel* tool_label=new QLabel(this);
    QWidget* widget_1=new QWidget(this);

public slots:
    void open_file_triggerd();
    void open_dir_triggerd();
    void dockwidget_size_slot();

private slots:

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

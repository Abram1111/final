#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include<QtCore>
#include<QtGui>
#include<QGraphicsScene>
#include<QMessageBox>
#include<QGraphicsEllipseItem>
#include<QVector>
#include<vector>
#include"Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int clc ;
    vector<Shape*> shapes;
     vector <Shape*> redo ;
      vector<QGraphicsItem*> item_list;
       vector<QGraphicsItem*> redo_item_list;


private slots:





    void on_btn_draw_clicked();

    void on_btn_circle_clicked();


    void on_btn_cancel_clicked();

    void on_btn_line_clicked();

    void on_btn_rect_clicked();

    void on_btn_redo_clicked();

    void on_btn_search_clicked();

    void on_btn_do_search_clicked();

    void on_btn_save_clicked();

    void on_btn_sort_clicked();

    void on_btn_undo_clicked();

private:
    Ui::Dialog *ui;
    QGraphicsScene * scene ;
    QGraphicsEllipseItem * ellipse;
     QGraphicsRectItem * rect;
     QGraphicsLineItem * line;


};
#endif // DIALOG_H

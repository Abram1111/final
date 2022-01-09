#include "dialog.h"
#include "ui_dialog.h"
#include "Shape.h"
#include <string>
#include <algorithm>
#include<QFileDialog>
#include <QImageReader>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
     ui->setupUi(this);

    ellipse = new QGraphicsEllipseItem  ;
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    // hide all lable and text input
    ui->btn_do_search->hide();
    ui->lab_x_pos->hide();
    ui->lab_color->hide();
    ui->label_y_pos->hide();
    ui->lab_width->hide();
    ui->label_legth->hide();
    ui->lineEdit_x_pos->hide();
    ui->lab_outline->hide();
    ui->lineEdit_width->hide();
    ui->lineEdit_y_pos->hide();
    ui->lineEdit_length->hide();
    ui->lineEdit_radius->hide();
    ui->label_radius->hide();
    ui->btn_draw->hide();
    ui->btn_cancel->hide();
    ui->label_name->hide();
    ui->lineEdit_name->hide();
    ui->lineEdit_y_pos_final->hide();
    ui->label_y_pos_final->hide();
    ui->lineEdit_x_pos_final->hide();
    ui->label_x_pos_final->hide();
    ui->comboBox->hide();
    ui->spinBox->hide();
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_btn_draw_clicked()
{
    QString name = ui->lineEdit_name->text();
    for (int i = 0 ; i<shapes.size();i++)
    {
        if(name.toStdString() == shapes[i]->getName())
        {
             QMessageBox::warning(this,"Error","Duplicate Name");
             return;
        }
    }
    if (name==""||name==" ")
    {
        QMessageBox::warning(this,"Error","No Name");
        return;
    }
    // create two  bollen
    bool ok ;
    bool ook ;
    // take the input from the text box in a form of string
    QString x_pos =ui->lineEdit_x_pos->text();
    QString y_pos =ui->lineEdit_y_pos->text();

    // convert string to int
    int x_posint = x_pos.toInt(&ok);
    // check if the opration is done or not
    if (!ok)
    { //if not show error message
         QMessageBox::warning(this,"errooor","invaled x postion");
         return; // stop function
    }
    // convert string to int
    int y_posint = y_pos.toInt(&ook);
     // check if the opration is done or not
    if (!ook)
    {//if not show error message
         QMessageBox::warning(this,"errooor","invaled y postion");
         return;// stop function
    }
    // take color from the text box

    QString color =   ui->comboBox->currentText();
    int fontValue =ui->spinBox->value();
    // creat new pen and brush
    QPen outlinepen (Qt::black);
    outlinepen.setWidth(fontValue);
    QBrush redbrush(Qt::red);
    // make color of the brush same as input
    redbrush.setColor(color);

    if (clc==1)
    {// that mean the circle btn is pushed
        //take the radius  in form of string
       QString radius =ui->lineEdit_radius->text();
       // covert it to double
       double radius_double = radius.toDouble(&ok);
        // check if the opration is done or not
       if (!ok||radius_double<=0)
       { //if not or if it -  show error message
           QMessageBox::warning(this,"Error","Invaled Radius");
           return;
       }
       Shape * clc = new Circle( name.toStdString() ,  color.toStdString() ,  radius_double ,  radius_double);
       shapes.push_back(clc);
       // draw ellipse and add it to the scene
       ellipse = scene->addEllipse(x_posint,y_posint ,radius_double*2,radius_double*2,outlinepen,redbrush);
       // make  ellipse movable
       ellipse->setFlag(QGraphicsItem::ItemIsMovable);
       item_list.push_back(ellipse);
    }
    else if (clc==2)
    { // that mean the rect btn is pushed
        // same as before
        QString length =ui->lineEdit_width->text();
        QString width = ui->lineEdit_length->text();
        double width_double = width .toDouble(&ok);
        if (!ok||width_double<=0)
        {
             QMessageBox::warning(this,"Error","Invaled Width");
             return;
        }
        double length_double = length .toDouble(&ok);
        if (!ok||length_double<=0)
        {
             QMessageBox::warning(this,"Error","Invaled Length");
             return;
        }
        Shape * rec = new Rectangl( name.toStdString() ,  color.toStdString() ,  length_double ,  width_double);
        shapes.push_back(rec);
        rect = scene->addRect(x_posint,y_posint,length_double,width_double,outlinepen,redbrush);
        rect->setFlag(QGraphicsItem::ItemIsMovable);
        item_list.push_back(rect);

     }
     else if (clc==3)
        { // that mean the line btn is pushed
         // same as before
        QString x_posfinal =ui->lineEdit_x_pos_final->text();
        QString y_posfinal =ui->lineEdit_y_pos_final->text();
        int x_posfinalint = x_posfinal.toInt(&ok);
        if (!ok)
        {
             QMessageBox::warning(this,"Error","Invaled Final X Postion");
             return;
        }
        int y_posfinalint = y_posfinal.toInt(&ok);
        if (!ok)
        {
             QMessageBox::warning(this,"Error"," Invaled Final Y Postion");
             return;
        }
        outlinepen.setColor(color);
        Shape * line2 = new Line(name.toStdString() , color.toStdString(),x_posint,y_posint,x_posfinalint ,y_posfinalint);
        shapes.push_back(line2);
        line = scene->addLine(x_posint,y_posint,x_posfinalint,y_posfinalint,outlinepen);
         line->setFlag(QGraphicsItem::ItemIsMovable);
         item_list.push_back(line);

     }
    // after all hide all lable and text box
     ui->comboBox->hide();
     ui->lab_x_pos->hide();
     ui->lab_color->hide();
     ui->label_y_pos->hide();
     ui->lab_width->hide();
     ui->label_legth->hide();
     ui->lineEdit_x_pos->hide();
     ui->lab_outline->hide();
     ui->lineEdit_width->hide();
     ui->lineEdit_y_pos->hide();
     ui->lineEdit_length->hide();
     ui->btn_draw->hide();
     ui->btn_cancel->hide();
     ui->label_name->hide();
     ui->lineEdit_name->hide();
     ui->lineEdit_y_pos_final->hide();
     ui->label_y_pos_final->hide();
     ui->lineEdit_x_pos_final->hide();
     ui->label_x_pos_final->hide();
     ui->label_radius->hide();
     ui->lineEdit_radius->hide();
     ui->btn_do_search->hide();
     // empty text box from prev input
     ui->lineEdit_x_pos->setText("");
     ui->lineEdit_width->setText("");
     ui->lineEdit_y_pos->setText("");
     ui->lineEdit_length->setText("");
     ui->lineEdit_name->setText("");
     ui->lineEdit_y_pos_final->setText("");
     ui->lineEdit_x_pos_final->setText("");
     ui->lineEdit_radius->setText("");
     ui->spinBox->setValue(1);
     ui->spinBox->hide();
}
void Dialog::on_btn_circle_clicked()
{
    ui->btn_do_search->hide();
    ui->comboBox->show();
    ui->lab_x_pos->show();
    ui->lab_color->show();
    ui->lab_outline->show();
    ui->label_y_pos->show();
    ui->lineEdit_x_pos->show();
    ui->lineEdit_y_pos->show();
    ui->btn_draw->show();
    ui->btn_cancel->show();
    ui->label_name->show();
    ui->lineEdit_name->show();
    ui->lineEdit_radius->show();
    ui->label_radius->show();
    ui->spinBox->show();
     //empty text box from prev input
    ui->lineEdit_x_pos->setText("");
    ui->lineEdit_y_pos->setText("");
    ui->lineEdit_name->setText("");
    ui->lineEdit_radius->setText("");
   // hide lable and text box we do not need it
    ui->lineEdit_length->hide();
    ui->label_legth->hide();
    ui->lineEdit_width->hide();
    ui->lab_width->hide();
    ui->lineEdit_y_pos_final->hide();
    ui->label_y_pos_final->hide();
    ui->lineEdit_x_pos_final->hide();
    ui->label_x_pos_final->hide();

                 clc = 1;
}
void Dialog::on_btn_cancel_clicked()
{
     // hide all
    ui->btn_do_search->hide();
    ui->lab_x_pos->hide();
    ui->lab_color->hide();
    ui->label_y_pos->hide();
    ui->lab_width->hide();
    ui->label_legth->hide();
    ui->lineEdit_x_pos->hide();
    ui->lineEdit_x_pos->setText("");
    ui->lab_outline->hide();
    ui->lineEdit_width->hide();
    ui->lineEdit_width->setText("");
    ui->lineEdit_y_pos->hide();
    ui->lineEdit_y_pos->setText("");
    ui->lineEdit_length->hide();
    ui->lineEdit_length->setText("");
    ui->lineEdit_name->hide();
    ui->lineEdit_name->setText("");
    ui->btn_draw->hide();
    ui->btn_cancel->hide();
    ui->label_name->hide();
    ui->lineEdit_y_pos_final->hide();
    ui->lineEdit_y_pos_final->setText("");
    ui->label_y_pos_final->hide();
    ui->lineEdit_x_pos_final->hide();
    ui->lineEdit_x_pos_final->setText("");
    ui->label_x_pos_final->hide();
    ui->label_radius->hide();
    ui->lineEdit_radius->hide();
    ui->lineEdit_radius->setText("");
    ui->spinBox->hide();
    ui->comboBox->hide();
}
void Dialog::on_btn_line_clicked()
{

    ui->comboBox->show();
    ui->lab_color->show();
    ui->lab_x_pos->show();
    ui->lab_outline->show();
    ui->label_y_pos->show();
    ui->lineEdit_x_pos->show();
    ui->lineEdit_y_pos->show();
    ui->lineEdit_x_pos_final->show();
    ui->lineEdit_name->show();
    ui->lineEdit_y_pos_final->show();
    ui->btn_draw->show();
    ui->btn_cancel->show();
    ui->label_name->show();
    ui->label_y_pos_final->show();
    ui->label_x_pos_final->show();
    ui->spinBox->show();
    //////////////////////////////
    ui->lineEdit_x_pos->setText("");
    ui->lineEdit_y_pos->setText("");
    ui->lineEdit_x_pos_final->setText("");
    ui->lineEdit_name->setText("");
    ui->lineEdit_y_pos_final->setText("");
    ///////////////////////////////
    ui->lineEdit_radius->hide();
    ui->label_radius->hide();
    ui->lineEdit_width->hide();
    ui->lab_width->hide();
    ui->lineEdit_length->hide();
    ui->label_legth->hide();
    ui->btn_do_search->hide();
    clc = 3;
}
void Dialog::on_btn_rect_clicked()
{
    ui->btn_do_search->hide();
    ui->comboBox->show();
    ui->lab_x_pos->show();
    ui->lab_outline->show();
    ui->label_y_pos->show();
    ui->lab_width->show();
    ui->label_legth->show();
    ui->lineEdit_x_pos->show();
    ui->lab_color->show();
    ui->lineEdit_width->show();
    ui->lineEdit_y_pos->show();
    ui->btn_draw->show();
    ui->btn_cancel->show();
    ui->label_name->show();
    ui->lineEdit_name->show();
    ui->lineEdit_length->show();
    ui->spinBox->show();
    //////////////////////////////////
    ui->lineEdit_x_pos->setText("");
    ui->lineEdit_width->setText("");
    ui->lineEdit_y_pos->setText("");
    ui->lineEdit_length->setText("");
    ui->lineEdit_name->setText("");
    ui->lineEdit_x_pos_final->setText("");
    ui->lineEdit_y_pos_final->setText("");
    ///////////////////////////////
    ui->lineEdit_radius->hide();
    ui->label_radius->hide();
    ui->lineEdit_y_pos_final->hide();
    ui->label_y_pos_final->hide();
    ui->lineEdit_x_pos_final->hide();
    ui->label_x_pos_final->hide();

    clc = 2;
}

void Dialog::on_btn_search_clicked()
{
    ui->lab_x_pos->hide();
    ui->lab_color->hide();
    ui->label_y_pos->hide();
    ui->lab_width->hide();
    ui->label_legth->hide();
    ui->lineEdit_x_pos->hide();
    ui->lab_outline->hide();
    ui->lineEdit_width->hide();
    ui->lineEdit_y_pos->hide();
    ui->lineEdit_length->hide();
    ui->lineEdit_radius->hide();
    ui->label_radius->hide();
    ui->btn_draw->hide();
    ui->btn_cancel->hide();
    ui->spinBox->hide();
    ui->comboBox->hide();
    ui->lineEdit_y_pos_final->hide();
    ui->label_y_pos_final->hide();
    ui->lineEdit_x_pos_final->hide();
    ui->label_x_pos_final->hide();
    ////////////////////////
    ui->label_name->show();
    ui->lineEdit_name->show();
    ui->btn_do_search->show();
    ui->lineEdit_name->setText("");


}


void Dialog::on_btn_do_search_clicked()
{
     QString name = ui->lineEdit_name->text();
     ui->btn_do_search->hide();
     ui->lineEdit_name->setText("");
     ui->lineEdit_name->hide();
     ui->label_name->hide();
     for(int i =0 ; i<shapes.size();i++)
     {
         if(name.toStdString()==shapes[i]->getName())
         {
            string s =  "Name->" + shapes[i]->getName() +'\n' +"color->" +shapes[i]->getColor() +'\n' + "primeter->" +to_string(shapes[i]->getperimeter()) ;
            QString ss = QString::fromStdString(s);
            QMessageBox::information(this,"data of shape ", ss);
             return;
          }
      }
      QMessageBox::information(this,"data of shape", "item not found");
}


void Dialog::on_btn_save_clicked()
{

}
void Dialog::on_btn_sort_clicked()
{
    if (shapes.empty())
    {
    QMessageBox::warning(this,"shapes sorted", "no shapes to sort");
    return;
    }
    Shape * min;
    vector<Shape *> v ;
    for (int i = 0 ;i < shapes.size();i++)
    {
        v.push_back(shapes[i]);
    }
    for(int i = 0 ;i < v.size();i++)
    {
       for (int j = i+1; j< v.size();j++)
       {
           if (v[j]->getperimeter()<v[i]->getperimeter())
           {
              min = v[i];
              v[i]=v[j];
              v[j]=min;
           }
       }
    }
      string s;
     for (int i =0; i <v.size(); i++){
       s  = s + "Name    "+ v[i]->getName()+'\n'+"Perimeter"+to_string(v[i]->getperimeter()) +'\n' ;
     }
     QString ss = QString::fromStdString(s);
      QMessageBox::information(this,"Shapes Sorted", ss);
}


void Dialog::on_btn_undo_clicked()
{

    if (item_list.empty())
    {
         QMessageBox::warning(this," Error","No Shape To Undo" );
         return;
    }
    else{

          Shape * temp = shapes[shapes.size()-1];
          shapes.pop_back();
          redo.push_back(temp);
          scene->removeItem(item_list[item_list.size()-1]);
          QGraphicsItem * curr = item_list[item_list.size()-1];
          item_list.pop_back();
          redo_item_list.push_back(curr);
         }
}
void Dialog::on_btn_redo_clicked()
{
    if (redo_item_list.empty())
    {
         QMessageBox::warning(this," Error","No Shape To Redo" );
         return;
    }
    else{

            Shape * temp = redo[redo.size()-1];
            redo.pop_back();
            shapes.push_back(temp);
            scene->addItem(redo_item_list[redo_item_list.size()-1]);
            QGraphicsItem * curr = redo_item_list[redo_item_list.size()-1];
            redo_item_list.pop_back();
            item_list.push_back(curr);

        }
}

#include "board.h"
#include<QPainter>

Board::Board(QWidget *parent) : QWidget(parent)
{
   for(int i = 0 ; i < 32 ; i ++){
       stone[i].init(i);
   }

}


void Board::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    int d = 40 ;
    r = d/2 ;
    for(int i = 1 ; i <= 10 ; i++){
        painter.drawLine(QPoint(d,i*d),QPoint(9*d,i*d));
    }


    for(int i = 1 ; i < 10 ; i++ ){
        if(i == 1 || i == 9)
            painter.drawLine(QPoint(i*d ,d),QPoint(i*d,10*d));
        else {
            painter.drawLine(QPoint(i*d ,d),QPoint(i*d,5*d));
            painter.drawLine(QPoint(i*d ,6*d),QPoint(i*d,10*d));
        }
    }

    painter.drawLine(QPoint(4*d ,d),QPoint(6*d,3*d));
    painter.drawLine(QPoint(6*d ,d),QPoint(4*d,3*d));

    painter.drawLine(QPoint(4*d ,8*d),QPoint(6*d,10*d));
    painter.drawLine(QPoint(6*d ,8*d),QPoint(4*d,10*d));


    ///
    for(int i = 0 ; i < 32 ; i++){
        drawStone(painter,i);
    }


}

void Board::drawStone(QPainter & painter,int id){

    QPoint c = center(id);
    QRect rect = QRect(c.x() -r ,c.y()-r,r*2,r*2);

    painter.setBrush(QBrush(QColor(255,255,0)));
    painter.setPen(Qt::black);

    painter.drawEllipse(center(id),r,r);

    if(stone[id].isRed) painter.setPen(Qt::red);
    else painter.setPen(Qt::black);

    painter.setFont(QFont("system",r,700));
    painter.drawText(rect ,stone[id].getText(),QTextOption(Qt::AlignCenter));
}


QPoint Board::center(int row, int col){
    QPoint rect ;
    rect.rx() = (col +1)*r*2 ;
    rect.ry() = (row +1)*r*2 ;
    return rect ;
}
QPoint Board::center(int id){

    return center(stone[id].row,stone[id].col) ;
}

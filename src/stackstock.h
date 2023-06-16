#ifndef STACKSTOCK_H
#define STACKSTOCK_H

#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QSqlDatabase>
#include "news.h"
class StockCanvas;
class StockKlineViewData;
namespace Ui {
class stackStock;
}

class stackStock : public QWidget
{
    Q_OBJECT

public:
    explicit stackStock(QWidget *parent = nullptr);
    ~stackStock();
    void setData(QString code);

private slots:
//    void openformat();
    void opennews();
private:
    Ui::stackStock *ui;
    //void initDB();
    StockCanvas *m_Stock{nullptr};

    StockKlineViewData *m_KlineDay{nullptr};
    StockKlineViewData *m_KlineWeek{nullptr};
    StockKlineViewData *m_KlineMonth{nullptr};

    virtual void contextMenuEvent(QContextMenuEvent *event);

    QString m_codec;
    QString m_codeNum;
    QMenu *m_rightButtonMenu;
//    QAction *seeformat;
    QAction *seenews;
//    format *formatDialog;
    news *newsDialog;
    //QSqlDatabase news_db;
};

#endif // STACKSTOCK_H

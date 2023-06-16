#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMap>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QCloseEvent>
#include "data.h"
class QNetworkReply;
class QSystemTrayIcon;
class QNetworkAccessManager;
class QTimer;
class QMutex;
class QTableWidgetItem;
class StockCanvas;
class QLabel;
class stackStock;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initLeftMenu();
//    void initLevelMenu();
    void refreshNormalWidget();
    void refreshMyhaveWidget();

    void refreshLabel();
private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_miniTable_doubleClicked(const QModelIndex &index);

    void on_normalBtn_clicked();

    void on_detailedBtn_clicked();

    void on_myBtn_clicked();

    void on_addMyBtn_clicked();

    void slotDataGPsChange(MapdataGP map);
    void slotDataHaveGPsChange(MapdataHaveGP map);
    void slotDataAllDPChange(DataAllDP data);
    void on_miniTable_customContextMenuRequested(const QPoint &pos);

    void on_tableWidget_customContextMenuRequested(const QPoint &pos);


    void on_myTable_customContextMenuRequested(const QPoint &pos);

    void on_myTable_cellDoubleClicked(int row, int column);

    void on_miniTable_cellDoubleClicked(int row, int column);

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_pushButton_level_clicked();

    //void on_comboBox_level_currentIndexChanged(const QString &arg1);

    void on_comboBox_level_currentIndexChanged(int index);

    void on_tableView_level_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
//    QSystemTrayIcon *m_trayIcon{nullptr};
    QNetworkAccessManager *manager {nullptr};
    QNetworkAccessManager *manager2 {nullptr};
    QNetworkReply *reply {nullptr};
    QNetworkReply *reply2 {nullptr};
    QMap <QString,DataGP> m_mGp;
    QMap <QString,DataHaveGP> m_mMyGp;
    QMap <QString,levelGP> m_mLevelGp;
    QMap <QString,judgeGP> m_mJudgeGp;
    QMap <int, judgeGP> m_mJudgeMap;
    QTimer * m_timer{nullptr};
    QSqlQueryModel *model;

    DataAllDP m_myAllDP;
    QString m_currentZQ="sh";
    QString cureentInfo;
//    QSqlDatabase m_db;

    QMenu *m_normalLeftMenu{nullptr};
    QMenu *m_myLeftMenu{nullptr};

//    StockCanvas *m_stockWidget{nullptr};
    stackStock *m_stockWidget{nullptr};

    stackStock *m_szStock{nullptr};//深圳
    stackStock *m_shStock{nullptr};//上证
    stackStock *m_cyStock{nullptr};//创业

    QLabel *m_szLabel{nullptr};
    QLabel *m_shLabel{nullptr};
    QLabel *m_cyLabel{nullptr};

};

#endif // MAINWINDOW_H
